/* === ギミックを管理する処理のソースファイル === */

#include <stdio.h>
#include <string.h>
#include "GimmickManager.h"
#include "Geometry.h"
#include "NeedleFloor.h"


/* --- コンストラクタ --- */
GimmickManager::GimmickManager()
{
	/* +++ ギミックオブジェクトのポインタ配列の初期化 +++ */
	for (int x = 0; x < MaxNumberOfGimmick; x++)
	{
		gimmicks[x] = NULL;
	}

	gimmickNumber = 0;	// ギミック数を0に初期化
}

/* --- デストラクタ --- */
GimmickManager::~GimmickManager()
{
}

/* --- csvファイルからギミックデータを読み込むメソッド --- */
int GimmickManager::Load(const char* csvPath)
{
    FILE* fp;     // ファイルポインタ

    char line[1024];  // csvファイルから読み込んだ文字列を格納する配列

    /* +++ csvファイルを読み込みモードで開く +++ */
    if ((fopen_s(&fp, csvPath, "r")) != 0)     // csvファイルを開けなかったら
    {
        /* +++ メッセージボックスでエラーの発生を報告 +++ */
        MessageBox(
            GetMainWindowHandle(),
            "Cannot open the gimmick csv file.",
            "File Error",
            MB_OK
        );

        return -1;   // -1(読み込み失敗)を返す
    }

    if (fgets(line, sizeof(line), fp) != NULL)  // csvファイルの1行目のヘッダーを読み飛ばす(NULLの場合次の処理を実行)
    {
        /* +++ メッセージボックスでエラーの発生を報告 +++ */
        MessageBox(
            GetMainWindowHandle(),
            "Cannot load data from the gimmick csv file.",
            "Load Error",
            MB_OK
        );

        fclose(fp);     // 開いたファイルを閉じる
        return - 1;     // -1(読み込み失敗)を返す
    }

    /* +++ csvファイルからデータを1行ずつ読み込む +++ */
    while (fgets(line, sizeof(line), fp) != NULL)   // csvファイルから文字列を読み込める限りループ
    {
        if (gimmickNumber >= MaxNumberOfGimmick)  // ギミックの数が最大値以上なら
        {
            break;  // ループを終了
        }

        int id, x, y, state, target;    // ギミックのID、座標、状態、連携対象を一時的に格納する変数
        char type[64];                  // ギミックの種類を一時的に格納する配列

        // 読み込んだ文字列からギミックのデータを取得
        int result = sscanf_s(
            line,
            "%d,%63[^,],%d,%d,%d,%d",
            &id,
            type,
            &x, &y,
            &state,
            &target
        );

        if (result != 6)    // 取得したデータに過不足があれば
        {
            continue;   // そのデータを無視(次のループに移行)
        }

        Gimmick* gimmick = CreateGimmick(type, id, x, y);   // データを基にギミックを生成

        if (gimmick == NULL)    // 生成したギミックが未対応なら
        {
            continue;   // 生成したギミックを無視(次のループに移行)
        }

        gimmicks[gimmickNumber] = gimmick;  // ギミックの配列に登録

        gimmickNumber++;    // ステージ中のギミック数を1増やす
    }

    fclose(fp);     // ファイルを閉じる

    return 0;    // 0(読み込み完了)を返す
}

/* --- ギミックの更新を行うメソッド --- */
void GimmickManager::Update()
{
    /* +++ ギミックを順に更新 +++ */
    for (int i = 0; i < gimmickNumber; i++)
    {
        if (gimmicks[i] == NULL)    // ギミックが未対応なら
        {
            continue;   // そのギミックを無視(次のループに移行)
        }

        gimmicks[i]->Update();  // ギミックの更新メソッドを実行
    }

    return;
}

/* --- ギミックの描画を行うメソッド-- - */
void GimmickManager::Draw() const
{
    /* +++ ギミックを順に描画 +++ */
    for (int i = 0; i < gimmickNumber; i++)
    {
        if (gimmicks[i] == NULL)    // ギミックが未対応なら
        {
            continue;   // そのギミックを無視(次のループに移行)
        }

        gimmicks[i]->Draw();    // ギミックの描画処理を実行
    }

	return;
}

/* --- ギミックを生成するメソッド-- - */
Gimmick* GimmickManager::CreateGimmick(const char* type, int id, int x, int y)
{
    if (type == NULL)
    {
        return NULL;
    }

    if (strcmp(type, "NeedleFloor") == 0)
    {
        NeedleFloor createNeedle(id, x, y);

        return &createNeedle;
    }

    return NULL;
}

/* --- ギミックをIDで検索 --- */
Gimmick* GimmickManager::GetGimmickWithID(int targetID)
{
    /* +++ IDが一致するギミックのポインタを返す +++ */
    for (int i = 0; i < gimmickNumber; i++)
    {
        if (gimmicks[i] == NULL)    // ギミックが未対応なら
        {
            continue;   // そのギミックを無視(次のループに移行)
        }

        if (gimmicks[i]->GetGimmickID() == targetID)     // ギミックIDが指定したIDと一致するなら
        {
            return gimmicks[i];  // ギミックのポインタを返す
        }
    }

    return NULL;    // NULLを返す(検索失敗)
}

/* --- 指定した位置のギミックを取得 --- */
Gimmick* GimmickManager::GetGimmickWithPos(int x, int y)
{
    for (int i = 0; i < gimmickNumber; i++)
    {
        if (gimmicks[i] == NULL)    // ギミックが未対応なら
        {
            continue;   // そのギミックを無視(次のループに移行)
        }

        POINT gimmickPos;    // ギミックの位置のPOINT型変数

        /* +++ 位置が一致するギミックのポインタを返す +++ */
        gimmickPos = gimmicks[i]->GetGimmickPosition();

        if (gimmickPos.x == x && gimmickPos.y == y)     // ギミックの座標が指定した座標と一致する
        {
            return gimmicks[i];  // ギミックのポインタを返す
        }
    }

    return NULL;    // NULLを返す(取得失敗)
}

/* --- 指定した範囲のギミックのうち、中心に近いものを取得-- - */
Gimmick* GimmickManager::GetGimmickWithinRange(RECT range)
{
    int arrayNumber = -1;     // ギミック配列の要素番号
    double minDistance;         // ギミックと範囲の中心の最短距離

    for (int i = 0; i < gimmickNumber; i++)
    {
        if (gimmicks[i] == NULL)    // ギミックが未対応なら
        {
            continue;   // そのギミックを無視(次のループに移行)
        }

        POINT gimmickPos;    // ギミックの位置のPOINT型変数

        /* +++ 位置が一致するギミックのポインタを返す +++ */
        gimmickPos = gimmicks[i]->GetGimmickPosition();     // ギミックの位置を取得

        if (gimmickPos.x >= range.left && gimmickPos.x <= range.right       // ギミックの座標が指定した範囲内にあるなら
            && gimmickPos.y >= range.top && gimmickPos.y <= range.bottom)
        {
            double calcResult;  // 距離の計算結果
            POINT rectCenter;   // 範囲の中心

            rectCenter = GetRectCenter(range);  // 範囲の中心を取得

            calcResult = sqrt(pow((double)(rectCenter.x - gimmickPos.x), 2) + pow((double)(rectCenter.y - gimmickPos.y), 2));   // 範囲の中心との距離を計算

            if (calcResult < minDistance)
            {
                minDistance = calcResult;   // ギミックと範囲中心の最短距離を更新
                arrayNumber = i;          // ギミック配列の要素番号を保存
            }
        }
    }

    if (arrayNumber != -1)
    {
        return gimmicks[arrayNumber];  // 範囲の中心に最も近いギミックのポインタを返す
    }

    return NULL;    // NULLを返す
}

/* --- 指定した範囲内のギミックのIDを取得-- - */
int GimmickManager::GetGimmickIDWithinRange(RECT range)
{
    int id;             // 取得するギミックのID
    Gimmick* gimmick;   // IDを取得するギミック

    gimmick = GetGimmickWithinRange(range);     // 範囲内のギミックを取得

    id = gimmick->GetGimmickID();   // 取得したギミックのIDを取得

    return id;  // IDを返す
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
        if (gimmicks[i]->GetGimmickID() == targetID)     // ギミックのIDが指定したIDと同じなら
        {
            targetState = gimmicks[i]->GetGimmickState();    // ギミックの状態を取得

            return targetState;     // 状態を返す
        }
    }

    return -1;     // -1を返す(取得失敗)
}

/* --- 引数で渡した座標が通行可能かを判定するメソッド-- - */
bool GimmickManager::IsPassable(POINT position)
{
    POINT gimmickPosition;    // ギミックの座標

    /* +++ 各ギミックの座標ｗｐ取得 +++ */
    for (int i = 0; i < gimmickNumber; i++)
    {
        gimmickPosition = gimmicks[i]->GetGimmickPosition();    // ギミックの座標を取得

        if (position.x >= gimmickPosition.x - GimmickSize / 2
            && position.x <= gimmickPosition.x + GimmickSize / 2
            && position.y >= gimmickPosition.y - GimmickSize / 2
            && position.y <= gimmickPosition.y + GimmickSize / 2
            )
        {
            if (gimmicks[i]->GetGimmickIsPassable())
            {
                return true;
            }

            return false;
        }
    }

    return false;
}