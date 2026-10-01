/* === マップ関連の処理のソースファイル === */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Map.h"


/* --- コンストラクタ --- */
Map::Map()
{
    width = 0;          // マップの横幅の初期化
    height = 0;         // マップの縦幅の初期化
    tileImage = -1;     // タイルセットの画像ハンドルの初期化

    /* +++ マップデータの初期化 +++ */
    for (int y = 0; y < MapHeight; y++)
    {
        for (int x = 0; x < MapWidth; x++)
        {
            mapData[y][x] = 0;
        }
    }
}

/* --- デストラクタ --- */
Map::~Map()
{
    /* +++ タイルセットの画像ハンドルを削除 +++ */
    if (tileImage != -1)
    {
        DeleteGraph(tileImage);
    }
}

/* --- csvファイルからマップデータを読み込むメソッド --- */
int Map::Load(const char* csvPath)
{
    FILE* fp;     // ファイルポインタ

    int y = 0;  // 2次元配列の列番号

    char line[1024];  // csvファイルから読み込んだ文字列を格納する配列

    /* +++ csvファイルを読み込みモードで開く +++ */
    if ((fp = fopen(csvPath, "r")) == NULL)     // csvファイルへのポインタがNULL(ファイルを開けなかった)なら
    {
        /* +++ メッセージボックスでエラーの発生を報告 +++ */
        MessageBox(
            GetMainWindowHandle(),
            "Cannot open the map csv path.",
            "File Error",
            MB_OK
        );

        return -1;   // -1(読み込み失敗)を返す
    }

    /* +++ csvファイルからデータを1行ずつ読み込む +++ */
    while (fgets(line, sizeof(line), fp) != NULL)   // csvファイルから文字列を読み込める限りループ
    {
        int x = 0;      // 2次元配列の行番号
        char* token;    // 部分文字列を格納するポインタ

        line[strcspn(line, "\r\n")] = '\0';     // 改行を削除(文字列の改行までの長さを取得しインデックスとして指定)

        /* +++ 空行は無視 +++ */
        if (line[0] == '\0')
        {
            continue;
        }


        /*　+++ カンマで区切る +++ */
        //* 例：
        //*
        //* 0,0,0,0,0
        //*
        //* ↓
        //*
        //* 0
        //* 0
        //* 0
        //* 0
        //* 0
        token = strtok(line, ",");  // カンマまでの部分文字列を取得

        /* +++ 部分文字列をマップデータとして格納 +++ */
        while (token != NULL)   // 部分文字列が存在する限りループ
        {
            if (x >= MapWidth)   // x(行番号)がマップの横幅以上なら
            {
                break;  // ループを終了
            }

            mapData[y][x] = atoi(token);    // 部分文字列をマップデータ(整数)として格納

            x++;    // x(行番号)を1加算

            token = strtok(NULL, ",");  // 次のカンマまでの部分文字列を取得
        }


        /* +++ 1行目の横幅を決定 +++ */
        if (width == 0)
        {
            width = x;
        }

        y++;    // y(列番号)を1加算

        if (y >= MapHeight)     // y(列番号)がマップの縦幅以上なら
        {
            break;  // ループを終了
        }
    }


    height = y;     // 縦幅を取得

    fclose(fp);     // ファイルを閉じる

    return 0;    // 0(読み込み完了)を返す
}

/* --- タイルセットの画像を読み込むメソッド --- */
int Map::LoadTileImage(const char* imagePath)
{
    tileImage = LoadGraph(imagePath);   // タイルセットの画像のハンドルを取得

    if (tileImage == -1)    // タイルセットの画像ハンドルが-1(読み込み失敗)なら
    {
        /* +++ メッセージボックスでエラーを報告 +++ */
        MessageBox(
            GetMainWindowHandle(),
            "Cannot load map image.",
            "Load Error",
            MB_OK
        );

        return -1;   // -1(読み込み失敗)を返す
    }

    return 0;    // 0(読み込み成功)を返す
}

/* --- マップの描画メソッド --- */
void Map::Draw() const
{
    int x;  // 2次元配列の行番号
    int y;  // 2次元配列の列番号

    if (tileImage == -1)    // タイルセットの画像が読み込めていないなら
    {
        return;     // 処理を終了
    }

    /* +++ マップの描画 +++ */
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            int tile;   // タイルの値を格納する変数

            int tileX;  // タイルセット上の横方向野位置
            int tileY;  // タイルセット上の縦方向野位置

            int sourceX;    // タイルセット画像から切り出す横方向の位置
            int sourceY;    // タイルセット画像から切り出す縦方向の位置

            int screenX;    // ゲーム画面上の描画位置のX座標
            int screenY;    // ゲーム画面上の描画位置のY座標


            tile = mapData[y][x];   // マップデータから値を取得

            /* +++ 0を「何もない」として扱う場合 +++ */
            // *
            // * 0番タイルも描画する場合はこのifを削除
            // 
            //if (tile == 0)
            //{
            //    continue;
            //}


            /* +++ タイルセット上の位置を計算 +++ */
            // * 横4個, tile == 6の場合
            // *
            // * 0  1  2  3
            // * 4  5  6  7
            // * 8  9 10 11
            // * 
            // * tileX = 6 % 4 = 2
            // * tileY = 6 / 4 = 1
            tileX = tile % TileSetWidth;    // タイルセット上の横方向の位置を算出
            tileY = tile / TileSetWidth;    // タイルセット上の縦方向の位置を算出


            /* +++ タイルセット画像から切り出す位置の計算 +++ */
            sourceX = tileX * TileSize;     // タイルセット画像から切り出す横方向の位置を算出
            sourceY = tileY * TileSize;     // タイルセット画像から切り出す縦方向の位置を算出


            /* +++ ゲーム画面上の描画位置の計算 +++ */
            screenX = x * TileSize;     // 画面上の描画位置のX座標
            screenY = y * TileSize;     // 画面上の描画位置Yの座標

            DrawRectGraph(screenX, screenY, sourceX, sourceY, TileSize, TileSize, tileImage, TRUE);     // タイルセットから32x32サイズのタイルチップを切り出して描画
        }
    }
}

/* --- 引数で渡した位置のタイルを取得するメソッド --- */
int Map::GetTile(int x, int y) const
{
    if (x < 0 || x >= width || y < 0 || y >= height)    // 引数で受け取った位置がマップの範囲外なら
    {
        return -1;  // -1を返す
    }

    return mapData[y][x];   // マップデータの該当の位置のデータを返す
}

/* --- マップの横幅を取得するメソッド --- */
int Map::GetWidth() const
{
    return width;   // マップの横幅を返す
}

/* --- マップの縦幅を取得するメソッド --- */
int Map::GetHeight() const
{
    return height;  // マップの縦幅を返す
}