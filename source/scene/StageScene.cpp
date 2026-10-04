/* === ステージのクラスのソースファイル === */

#include "StageScene.h"
#include "GameManager.h"
#include "Key.h"
#include "Color.h"
#include "Font.h"


/* --- Stageクラスのコンストラクタ --- */
StageScene::StageScene(int stage)
    : stageNumber(stage)    // ステージ番号に引数で渡された値を代入
{
}

/* --- デストラクタ --- */
StageScene::~StageScene()
{
}

/* --- ステージの初期化メソッド --- */
void StageScene::Init()
{
    char filePath[256];

    transition = {};    // 遷移情報をリセット

    sceneElapsedFrame = 0;  // 経過フレームをリセット

    //if (sprintf_s(filePath, sizeof(filePath), ".\\game-data\\map\\Stage%d_Map.csv", stageNumber) == -1)
    //{
    //    /* +++ エラーメッセージを表示 +++ */
    //    MessageBox(
    //        GetMainWindowHandle(),
    //        "SatgeScene::Init() : Failed to generate Stage_Map.csv Path",
    //        "StageScene Error",
    //        MB_OK
    //    );

    //    return;
    //}

    //mapManager.Load(filePath);  // csvファイルからマップデータを読み込む

    //if (sprintf_s(filePath, sizeof(filePath), ".\\game-data\\gimmick\\Stage%d_Gimmick.csv", stageNumber) == -1)
    //{
    //    /* +++ エラーメッセージを表示 +++ */
    //    MessageBox(
    //        GetMainWindowHandle(),
    //        "SatgeScene::Init() : Failed to generate Stage_Gimmick.csv Path",
    //        "StageScene Error",
    //        MB_OK
    //    );

    //    return;
    //}

    //gimmickManager.Load(filePath);

    return;
}

/* --- ステージの更新メソッド --- */
void StageScene::Update()
{
    // --------------------
    // ゲーム更新
    // --------------------

    // プレイヤーの更新
    //gimmickManager.Update();    // ギミックの更新
    // 当たり判定

    // -----------------
    // クリア判定
    // -----------------

    if (Key_Check_Click(KEY_INPUT_RETURN))
    {
        transition.transitionType = TransitionType::ChangeScene;    // 遷移の状態をシーン切り替えにする

        if (stageNumber >= NumberOfStage)
        {
            transition.sceneType = SceneType::Clear;    // 遷移情報のシーンの種類をクリアシーンにする
        }
        else
        {
            transition.sceneType = SceneType::Stage;    // 遷移情報のシーンの種類をステージにする

            transition.stageNum = stageNumber + 1;  //  遷移情報のステージ番号に自身の番号 + 1を代入
        }

        return;
    }

    //if (/* パズルをクリアした */)    // 　プレイヤーがゴールに到達したら
    //{
    //    transition.transitionType = TransitionType::ChangeScene;    // 遷移の状態をシーン切り替えにする

    //    if (stageNumber >= NumberOfStage)     // ステージ番号がステージ数以上なら(最終ステージなら)
    //    {
    //        transition.sceneType = SceneType::Clear;    // 遷移情報のシーンの種類をクリアシーンにする
    //    }
    //    else
    //    {
    //        transition.sceneType = SceneType::Stage;    // 遷移情報のシーンの種類をステージにする

    //        transition.stageNum = stageNumber + 1;  //  遷移情報のステージ番号に自身の番号 + 1を代入
    //    }

    //    return;
    //}

    // --------------------------
    // ゲームオーバー判定
    // --------------------------

    if (Key_Check_Click(KEY_INPUT_SPACE))  // ゲームオーバーになったら
    {
        transition.transitionType = TransitionType::ChangeScene;    // 遷移の状態をシーン切り替えにする

        transition.sceneType = SceneType::GameOver;     // 遷移情報のシーンの種類をゲームオーバーシーンにする

        transition.stageNum = stageNumber;  // 遷移情報のステージ番号に自身の番号を代入する

        return;
    }

    //if (/* ゲームオーバー */)  // 　ゲームオーバーになったら
    //{
    //    transition.transitionType = TransitionType::ChangeScene;    // 遷移の状態をシーン切り替えにする

    //    transition.sceneType = SceneType::GameOver;     // 遷移情報のシーンの種類をゲームオーバーシーンにする

    //    transition.stageNum = stageNumber;  // 遷移情報のステージ番号に自身の番号を代入する

    //    return;
    //}

    sceneElapsedFrame++;    // 経過フレームを1加算
}

/* --- ステージの描画メソッド --- */
void StageScene::Draw()
{
    //mapManager.Draw();      // マップの描画
    //gimmickManager.Draw();  // ギミックの描画
    // プレイヤー描画
    // UI描画

    DrawFormatStringToHandleAlign(GameWindowWidth / 2, 300, FAlign_AllCenter, Color_White, KHDot_100_9, "Stage %d", stageNumber);

    return;
}

/* --- ステージの終了メソッド --- */
void StageScene::End()
{
    // ステージ固有のリソース解放
}

/* --- ステージ番号の取得メソッド --- */
int StageScene::GetStageNumber() const
{
    return stageNumber;     // 自身のステージ番号を返す
}