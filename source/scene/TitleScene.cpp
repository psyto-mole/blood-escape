/* === タイトルシーンのクラスのソースファイル === */

#include "TitleScene.h"
#include "GameManager.h"
#include "Color.h"
#include "Font.h"
#include "Message.h"


/* --- タイトルシーンの初期化メソッド --- */
void TitleScene::Init()
{
    transition = {};    // 遷移情報をクリア

    sceneElapsedFrame = 0;

    return;
}

/* --- タイトルシーンの更新メソッド --- */
void TitleScene::Update()
{
    sceneElapsedFrame += 1; // 経過フレームを1増加

    if (/* エンターがクリックされた */&& sceneElapsedFrame >= GameFPS)  // シーンが切り替わってから1秒以上が経過しEnterキーがクリックされた
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
    DrawFormatStringToHandleAlign(GameWindowWidth / 2, 300, FAlign_AllCenter, Color_White, CathodeTube_100_9, "%s", GameTitle);

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