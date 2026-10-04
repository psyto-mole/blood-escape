/* === タイトルシーンのクラスのソースファイル === */

#include "TitleScene.h"
#include "GameManager.h"
#include "Key.h"
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
    if (Key_Check_Click(KEY_INPUT_RETURN) && sceneElapsedFrame >= GameFPS)  // シーンが切り替わってから1秒以上が経過しEnterキーがクリックされた
    {
        transition.transitionType = TransitionType::ChangeScene;    // 遷移の状態をシーン切り替えにする

        transition.sceneType = SceneType::Tutorial;     // 遷移情報のシーンの種類をチュートリアルシーンにする
    }
    else
    {
        sceneElapsedFrame += 1; // 経過フレームを1増加
    }

    return;
}

/* --- タイトルシーンの描画処理 --- */
void TitleScene::Draw()
{
    /* +++ 描画処理 +++ */
    DrawFormatStringToHandleAlign(GameWindowWidth / 2, 300, FAlign_AllCenter, Color_Red, KHDot_100_9, "%s", StringGameTitle);
    DrawFormatStringToHandleAlign(GameWindowWidth / 2, 600, FAlign_AllCenter, Color_White, KHDot_30_1, "%s", StringPressEnter);

    return;
}

/* --- タイトルシーンの終了処理 --- */
void TitleScene::End()
{
    return;
}