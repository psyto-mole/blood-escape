/* === チュートリアルシーンのクラスのソースファイル === */

#include "TutorialScene.h"


/* --- チュートリアルシーンの初期化メソッド --- */
void TutorialScene::Init()
{
    transition = {};    // 遷移情報をクリア
}

/* --- チュートリアルシーンの更新メソッド --- */
void TutorialScene::Update()
{
    if (/* ステージ1に移動する条件 */)   // でステージ1へ
    {
        transition.transitionType = TransitionType::ChangeScene;    // 遷移の状態をシーン切り替えにする

        transition.sceneType = SceneType::Stage;    // シーンの種類をステージにする

        transition.stageNum = 1;    // ステージ番号を1にする
    }
}

/* --- チュートリアルシーンの描画メソッド --- */
void TutorialScene::Draw()
{
    /*DrawString(
        500,
        150,
        "TUTORIAL",
        GetColor(255, 255, 255)
    );

    DrawString(
        400,
        300,
        "ここに操作方法を表示",
        GetColor(255, 255, 255)
    );

    DrawString(
        450,
        500,
        "Press Space to Start",
        GetColor(255, 255, 255)
    );*/

    return;
}

/* --- チュートリアルシーンの終了メソッド --- */
void TutorialScene::End()
{
    return;
}

/* --- 遷移情報の取得メソッド --- */
SceneTransition TutorialScene::GetTransition() const
{
    return transition;  // チュートリアルシーンの遷移情報を返す
}