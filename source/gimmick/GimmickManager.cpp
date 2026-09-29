/* === ギミックを管理する処理のソースファイル === */

#include <stdio.h>
#include <string.h>
#include "GimmickManager.h"


/* --- コンストラクタ --- */
GimmickManager::GimmickManager()
{
	/* +++ ギミックオブジェクトのポインタ配列の初期化 +++ */
	for (int x = 0; x < GimmickNumberMax; x++)
	{
		gimmick[x] = NULL;
	}

	gimmickNumber = 0;	// ギミック数を0に初期化
}

/* --- デストラクタ --- */
GimmickManager::~GimmickManager()
{
	gimmickNumber = 0;
}

/* --- csvファイルからギミックデータを読み込むメソッド --- */
int GimmickManager::Load(const char* csvPath)
{
    FILE* fp;     // ファイルポインタ

    char line[1024];  // csvファイルから読み込んだ文字列を格納する配列

    /* +++ csvファイルを読み込みモードで開く +++ */
    if ((fp = fopen(csvPath, "r")) == NULL)     // csvファイルへのポインタがNULL(ファイルを開けなかった)なら
    {
        /* +++ メッセージボックスでエラーの発生を報告 +++ */
        MessageBox(
            GetMainWindowHandle(),
            "Cannot open the gimmick csv path.",
            "File Error",
            MB_OK
        );

        return -1;   // -1(読み込み失敗)を返す
    }

    fgets(line, sizeof(line), fp);  // csvファイルの1行目のヘッダーを読み飛ばす

    /* +++ csvファイルからデータを1行ずつ読み込む +++ */
    while (fgets(line, sizeof(line), fp) != NULL)   // csvファイルから文字列を読み込める限りループ
    {
        if (gimmickNumber >= GimmickNumberMax)  // ギミックの数が最大値以上なら
        {
            break;  // ループを終了
        }

        int x = 0      // 2次元配列の行番号
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

             = atoi(token);    // 部分文字列をマップデータ(整数)として格納

            x++;    // x(行番号)を1加算

            token = strtok(NULL, ",");  // 次のカンマまでの部分文字列を取得
        }
    }

    fclose(fp);     // ファイルを閉じる

    return true;    // true(読み込み完了)を返す

	return true;
}

/* --- ギミックの更新を行うメソッド --- */
void GimmickManager::Update()
{
    /* +++ ギミックを順に更新 +++ */
    for (int i = 0; i < gimmickNumber; i++)
    {
        gimmick[i]->Update();
    }

    return;
}

/* --- ギミックの描画を行うメソッド-- - */
void GimmickManager::Draw() const
{
    /* +++ ギミックを順に描画 +++ */
    for (int i = 0; i < gimmickNumber; i++)
    {
        gimmick[i]->Update();
    }

	return;
}

/* --- ギミックをIDで検索 --- */
Gimmick* GimmickManager::GetGimmickWithID(int targetID)
{
    /* +++ IDが一致するギミックのポインタを返す +++ */
    for (int i = 0; i < gimmickNumber; i++)
    {
        if (gimmick[i]->GetGimmickID() == targetID)     // ギミックIDが指定したIDと一致するなら
        {
            return gimmick[i];  // ギミックのポインタを返す
        }
    }

    return NULL;    // NULLを返す(検索失敗)
}

/* --- 指定した位置のギミックを取得 --- */
Gimmick* GimmickManager::GetGimmickWithPos(int x, int y)
{
    POINT gimmickPos;    // ギミックの位置のPOINT型変数

    /* +++ 位置が一致するギミックのポインタを返す +++ */
    for (int i = 0; i < gimmickNumber; i++)
    {
        gimmickPos = gimmick[i]->GetGimmickPosition();

        if (gimmickPos.x == x && gimmickPos.y == y)     // ギミックの座標が指定した座標と一致する
        {
            return gimmick[i];  // ギミックのポインタを返す
        }
    }

    return NULL;    // NULLを返す(取得失敗)
}

/* -- - ギミックの状態を変える-- - */
void GimmickManager::ChangeGimmickState(int targetID, int state)
{
    Gimmick* targetGimmick;  // 対象とするギミックのポインタ

    targetGimmick = GetGimmickWithID(targetID);     // 状態を変えるギミックをIDから取得

    if (targetGimmick == NULL)  // ポインタがNULLなら
    {
        return;     // 処理を終了する
    }

    targetGimmick->SetGimmickState(state);  // ギミックの状態を変更

    return;
}

/* --- ギミックの状態を取得-- - */
int GimmickManager::GetGimmickState(int targetID)
{
    int targetState;    // 状態を格納する変数

    /* +++ IDが一致するギミックの状態を返す +++ */
    for (int i = 0; i < gimmickNumber; i++)
    {
        if (gimmick[i]->GetGimmickID() == targetID)     // ギミックのIDが指定したIDと同じなら
        {
            targetState = gimmick[i]->GetGimmickState();    // ギミックの状態を取得

            return targetState;     // 状態を返す
        }
    }

    return -1;     // -1を返す(取得失敗)
}