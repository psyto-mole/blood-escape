/* === ステージのクラスのソースファイル === */

#include "StageScene.h"
#include "GameManager.h"
#include "Key.h"
#include "Color.h"
#include "Font.h"
#include "Sound.h"


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
int StageScene::Init()
{
    char filePath[256];     // ファイルパス用の配列

    transition = {};    // 遷移情報をリセット

    sceneElapsedFrame = 0;  // 経過フレームをリセット

    /* +++ ステージ番号に応じたマップデータのファイルのパスを生成 +++ */
    if (sprintf_s(filePath, sizeof(filePath), ".\\game-data\\map\\Stage%d_Map.csv", stageNumber) == -1)     // ファイルパスの生成に失敗したら
    {
        /* +++ エラーメッセージを表示 +++ */
        MessageBox(
            GetMainWindowHandle(),
            "SatgeScene::Init() : Failed to generate Stage_Map.csv Path",
            "StageScene Error",
            MB_OK
        );

        return -1;  // -1を返す(初期化失敗)
    }

    mapManager.Load(filePath);  // csvファイルからマップデータを読み込む

    /* +++ ギミックデータのファイルパスを生成 +++ */
    if (sprintf_s(filePath, sizeof(filePath), ".\\game-data\\gimmick\\Stage%d_Gimmick.csv", stageNumber) == -1)    // ファイルパスを生成できなかったら
    {
        /* +++ エラーメッセージを表示 +++ */
        MessageBox(
            GetMainWindowHandle(),
            "SatgeScene::Init() : Failed to generate Stage_Gimmick.csv Path",
            "StageScene Error",
            MB_OK
        );

        return -1;  // -1を返す(初期化失敗)
    }

    if (gimmickManager.Load(filePath) == -1)  // ギミックデータを読み込むのに失敗したら
    {
        return -1;  // -1を返す(初期化失敗)
    }

    if (gimmickManager.Init() == -1)    // ギミックの初期化に失敗したら
    {
        return -1;  // -1を返す(初期化失敗)
    }

    playerObject.Init(gimmickManager.GetPlayerStartPosition());    // スタート地点の座標を渡してプレイヤーオブジェクトの初期化メソッドを実行

    Sound_Play(BGM_Stage);  // ステージのBGMを再生

    return 0;
}

/* --- ステージの更新メソッド --- */
void StageScene::Update()
{
    // --------------------
    // ゲーム更新
    // --------------------

    playerObject.Update(&mapManager, &gimmickManager);  // プレイヤーオブジェクトの更新メソッドを実行

    gimmickManager.Update(&playerObject);    // ギミックの更新
    // 当たり判定

    // -----------------
    // クリア判定
    // -----------------

    if (GameDebug)
    {
        if (Key_Check_Click(KEY_INPUT_N))
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
    }

    if (gimmickManager.CheckStageClear())    // 　プレイヤーがゴールに到達したら
    {
        transition.transitionType = TransitionType::ChangeScene;    // 遷移の状態をシーン切り替えにする

        if (stageNumber >= NumberOfStage)     // ステージ番号がステージ数以上なら(最終ステージなら)
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

    // --------------------------
    // ゲームオーバー判定
    // --------------------------

    if (GameDebug)
    {
        if (Key_Check_Click(KEY_INPUT_SPACE))  // ゲームオーバーになったら
        {
            transition.transitionType = TransitionType::ChangeScene;    // 遷移の状態をシーン切り替えにする

            transition.sceneType = SceneType::GameOver;     // 遷移情報のシーンの種類をゲームオーバーシーンにする

            transition.stageNum = stageNumber;  // 遷移情報のステージ番号に自身の番号を代入する

            return;
        }
    }

    if (playerObject.IsGameOver())  // 　ゲームオーバーなら
    {
        transition.transitionType = TransitionType::ChangeScene;    // 遷移の状態をシーン切り替えにする

        transition.sceneType = SceneType::GameOver;     // 遷移情報のシーンの種類をゲームオーバーシーンにする

        transition.stageNum = stageNumber;  // 遷移情報のステージ番号に自身の番号を代入する

        return;
    }

    sceneElapsedFrame++;    // 経過フレームを1加算
}

/* --- ステージの描画メソッド --- */
void StageScene::Draw()
{
    mapManager.Draw();      // マップの描画
    gimmickManager.Draw();  // ギミックの描画
    playerObject.Draw();    // プレイヤー描画

    return;
}

/* --- ステージの終了メソッド --- */
void StageScene::End()
{
    Sound_Stop(&BGM_Stage);  // ステージのBGMの再生を停止

    return;
}

/* --- ステージ番号の取得メソッド --- */
int StageScene::GetStageNumber() const
{
    return stageNumber;     // 自身のステージ番号を返す
}