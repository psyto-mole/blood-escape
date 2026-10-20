/* === ギミックを管理する処理のソースファイル === */

#include <stdio.h>
#include <string.h>
#include "GimmickManager.h"

#include "Geometry.h"

#include "GoalPoint.h"
#include "NeedleFloor.h"
#include "TransparentFloor.h"
#include "Altar.h"
#include "Bloodpack.h"
#include "Bandage.h"
#include "Switch.h"
#include "StartPoint.h"
#include "Door.h"


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

    gimmickNumber = 0;  // ギミック数を初期化

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

        Gimmick* gimmick = CreateGimmick(type, id, x, y, state, target);   // データを基にギミックを生成

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

/* --- ギミックの初期化をおこなうメソッド --- */
int GimmickManager::Init()
{
    /* +++ ギミックを順に更新 +++ */
    for (int i = 0; i < gimmickNumber; i++)
    {
        if (gimmicks[i] == NULL)    // ギミックが未対応なら
        {
            continue;   // そのギミックを無視(次のループに移行)
        }

        if (gimmicks[i]->Init() == -1)  // ギミックの初期化に失敗したら
        {
            return -1;  // -1を返す(初期化失敗)
        }
    }

    return 0;
}

/* --- ギミックの更新を行うメソッド --- */
void GimmickManager::Update(Player* player)
{
    /* +++ ギミックを順に更新 +++ */
    for (int i = 0; i < gimmickNumber; i++)
    {
        if (gimmicks[i] == NULL)    // ギミックが未対応なら
        {
            continue;   // そのギミックを無視(次のループに移行)
        }

        if (gimmicks[i]->GetGimmickType() == GimmickType::Switch
            && gimmicks[i]->GetGimmickType() == GimmickType::Altar)
        {
            if (gimmicks[i]->GetGimmickIsActive())
            {
                int searchTargetID;  // 探す対象ID

                searchTargetID = gimmicks[i]->GetGimmickTargetID();    //連動するギミックのIDを取得

                ActivateGimmick(searchTargetID);   // 連動するギミックを起動
            }
        }

        gimmicks[i]->Update(player);  // プレイヤーを渡しギミックの更新メソッドを実行
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
Gimmick* GimmickManager::CreateGimmick(const char* type, int id, int x, int y, int state, int target)
{
    if (type == NULL)
    {
        return NULL;
    }

    if (strcmp(type, "GoalPoint") == 0)
    {
        GoalPoint createGoal(id, x, y, state, target);

        return &createGoal;
    }
    else if (strcmp(type, "NeedleFloor") == 0)
    {
        NeedleFloor createNeedle(id, x, y, state, target);

        return &createNeedle;
    }
    else if (strcmp(type, "TransprentFloor") == 0)
    {
        TransparentFloor createTransparentFkoor(id, x, y, state, target);

        return &createTransparentFkoor;
    }
    else if (strcmp(type, "Altar") == 0)
    {
        Altar createAltar(id, x, y, state, target);

        return &createAltar;
    }
    else if (strcmp(type, "Bloodpack") == 0)
    {
        BloodPack createBloodPack(id, x, y, state, target);

        return &createBloodPack;
    }
    else if (strcmp(type, "Bandage") == 0)
    {
        Bandage createBandage(id, x, y, state, target);

        return &createBandage;
    }
    else if (strcmp(type, "StartPoint") == 0)
    {
        StartPoint createStart(id, x, y, state, target);

        return &createStart;
    }
    else if (strcmp(type, "Switch") == 0)
    {
        Switch createSwitch(id, x, y, state, target);

        return &createSwitch;
    }
    else if (strcmp(type, "Door") == 0)
    {
        Door createDoor(id, x, y, state, target);

        return &createDoor;
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
    int arrayNumber = -1;       // ギミック配列の要素番号
    double minDistance = 32.;   // ギミックと範囲の中心の最短距離

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

/* --- ギミックを種類で検索 ^--- */
Gimmick* GimmickManager::GetGimmickWithType(GimmickType gimmickType)
{
    /* +++ 最初に見つかった指定した種類のギミックを返す +++ */
    for (int i = 0; i < gimmickNumber; i++)
    {
        if (gimmicks[i]->GetGimmickType() == gimmickType)    // ギミックの種類が指定したものと同じなら
        {
            return gimmicks[i];     // そのギミックを返す
        }
    }

    return NULL;    // NULLを返す
}

/* --- 指定した範囲内のギミックのIDを取得-- - */
int GimmickManager::GetGimmickIDWithinRange(RECT range)
{
    int id;             // 取得するギミックのID
    Gimmick* gimmick;   // IDを取得するギミック

    gimmick = GetGimmickWithinRange(range);     // 範囲内のギミックを取得

    if (gimmick == NULL)    // ギミックが取得されていなければ
    {
        return -1;  // -1を返す
    }

    id = gimmick->GetGimmickID();   // 取得したギミックのIDを取得

    return id;  // IDを返す
}

/* --- ギミックのタグを取得するメソッド-- - */
GimmickTag GimmickManager::GetGimmickTag(int targetID)
{
    GimmickTag targetGroup;    // 取得した属性を格納する変数

    /* +++ IDが一致するギミックの属性を返す +++ */
    for (int i = 0; i < gimmickNumber; i++)
    {
        if (gimmicks[i]->GetGimmickID() == targetID)     // ギミックのIDが指定したIDと同じなら
        {
            targetGroup = gimmicks[i]->GetGimmickTag();    // ギミックの属性を取得

            return targetGroup;     // 属性を返す
        }
    }

    return GimmickTag::None;  // 未分類を返す
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

/* --- ギミックの状態を進める-- - */
void GimmickManager::AdvanceGimmickState(int targetID)
{
    Gimmick* targetGimmick;  // 対象とするギミックのポインタ

    targetGimmick = GetGimmickWithID(targetID);     // 状態を変えるギミックをIDから取得

    if (targetGimmick == NULL)  // ポインタがNULLなら
    {
        return;     // 処理を終了する
    }

    targetGimmick->AdvanceGimmickState();  // ギミックの状態を進める

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

/* --- IDで指定したギミックを起動する --- */
void GimmickManager::ActivateGimmick(int targetID)
{
    /* +++ IDが一致するギミックの状態を返す +++ */
    for (int i = 0; i < gimmickNumber; i++)
    {
        if (gimmicks[i]->GetGimmickID() == targetID)     // ギミックのIDが指定したIDと同じなら
        {
            gimmicks[i]->Activate();    // ギミックの状態を取得
        }
    }

    return;
}

/* --- 引数で渡した座標が通行可能かを判定するメソッド-- - */
bool GimmickManager::IsPassable(POINT playerPosition)
{
    /* +++ 各ギミックについてプレイヤーとの接触状態と通行の可不可を調べる +++ */
    for (int i = 0; i < gimmickNumber; i++)
    {
        if(gimmicks[i]->CheckContactPoint(playerPosition))  // ギミックがプレイヤーと接触していたら
        {
            if (gimmicks[i]->GetGimmickTag() == GimmickTag::Contact)    // ギミックが接触ギミックなら
            {
                gimmicks[i]->Activate();    // ギミックを起動
            }

            if (gimmicks[i]->GetGimmickIsPassable())    // ギミックが通行可能であれば
            {
                return true;    // true(通行可能)を返す
            }

            return false;   // false(通行不可)を返す
        }
    }

    return true;   // true(通行可能)を返す
}

/* --- プレイヤーのスタート地点を取得するメソッド --- */
POINT GimmickManager::GetPlayerStartPosition()
{
    POINT playerStartPosition;  // プレイヤーのスタート地点の座標
    Gimmick* startGimmick;      // スタート地点のギミックのポインタを格納する変数

    startGimmick = GetGimmickWithType(GimmickType::StartPoint);     // スタート地点のギミックを取得

    playerStartPosition = startGimmick->GetGimmickPosition();   // スタート地点の座標を取得

    return playerStartPosition;     // プレイヤーのスタート地点の座標を返す
}

/* --- ステージクリアを確認するメソッド --- */
bool GimmickManager::CheckStageClear()
{
    Gimmick* goalGimmick;   // ゴールのギミックのポインタを格納する変数

    goalGimmick = GetGimmickWithType(GimmickType::GoalPoint);   // ゴール地点のギミックを取得

    if (goalGimmick->IsGoal())  // ゴールしているなら
    {
        return true;    // trueを返す
    }

        return false;   // falseを返す
}