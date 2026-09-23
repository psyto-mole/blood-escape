/* === タイトルシーンのクラスのソースファイル === */

#include "TitleScene.h"


/* --- タイトルシーンの初期化メソッド --- */
void TitleScene::Init()
{
    transition = {};    // 遷移情報をクリア

    return;
}

/* --- タイトルシーンの更新メソッド --- */
void TitleScene::Update()
{
    if (CheckHitKey(KEY_INPUT_RETURN))  // Enterキーが押された
    {
        transition.transitionType = TransitionType::ChangeScene;    // 遷移の状態をシーン切り替えにする

        transition.sceneType = SceneType::Tutorial;     // 遷移情報のシーンの種類をチュートリアルシーンにする
    }

    return;
}

/* --- タイトルシーンの描画処理 --- */
void TitleScene::Draw()
{
    /* +++ 描画処理 +++ */

    return;
}

/* --- タイトルシーンの終了処理 --- */
void TitleScene::End()
{
    return;
}

/* --- 遷移情報を取得するメソッド --- */
SceneTransition TitleScene::GetTransition() const
{
    return transition;  // タイトルシーンの遷移情報を返す
}