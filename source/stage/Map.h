#pragma once
/* === マップ関連の処理のヘッダファイル === */

#include "DxLib.h"


#define MapWidth        60  // マップの横幅
#define MapHeight       30  // マップの縦幅
#define TileSize        32  // タイルサイズ
#define TileSetWidth    3   // タイルセットの横方向のタイル数(タイルセットの画像のサイズ/タイルサイズ)

class Map
{
private:
    int mapData[MapWidth][MapHeight];   // マップデータを格納する2次元配列

    int width;      // マップの横幅(タイル数)
    int height;     // マップの縦幅(タイル数)

    int tileImage;  // タイルセットの画像ハンドルを格納する変数

public:
    Map();      // コンストラクタ
    ~Map();     // デストラクタ

    bool Load(const char* csvPath);             // csvファイルからマップデータを読み込むメソッド
    bool LoadTileImage(const char* imagePath);  // タイルセットの画像を読み込むメソッド

    void Draw() const;  // マップの描画を行うメソッド

    int GetTile(int x, int y) const;    // 引数で渡した位置のタイルを取得するメソッド
    int GetWidth() const;               // マップの横幅を取得するメソッド
    int GetHeight() const;              // マップの縦幅を取得するメソッド
};