/* === タイトルシーンのクラスのソースファイル === */

#include "TitleScene.h"
#include "GameManager.h"
#include "Key.h"
#include "Color.h"
#include "Font.h"
#include "Sound.h"
#include "Message.h"


/* --- タイトルシーンの初期化メソッド --- */
int TitleScene::Init()
{
    transition = {};    // 遷移情報をクリア

    sceneElapsedFrame = 0;

    Sound_Play(BGM_Title);  // タイトル画面のBGMを再生

    return 0;
}

/* --- タイトルシーンの更新メソッド --- */
void TitleScene::Update()
{
    if (Key_Check_Click(KEY_INPUT_RETURN) && sceneElapsedFrame >= GameFPS)  // シーンが切り替わってから1秒以上が経過しEnterキーがクリックされた
    {
        transition.transitionType = TransitionType::ChangeScene;    // 遷移の状態をシーン切り替えにする

        transition.sceneType = SceneType::Tutorial;     // 遷移情報のシーンの種類をチュートリアルシーンにする

        Sound_Play(SE_Enter);   // エンターキーを押した時のSEを再生
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
    DrawFormatStringToHandleAlign(GameWindowWidth / 2, 300, FAlign_AllCenter, Color_Red, KHDot_200_9, "%s", StringGameTitle);
    DrawFormatStringToHandleAlign(GameWindowWidth / 2, 600, FAlign_AllCenter, Color_SW_Rainbow, KHDot_50_2, "%s", StringPressEnter);

    return;
}

/* --- タイトルシーンの終了処理 --- */
void TitleScene::End()
{
    Sound_Stop(&BGM_Title);     // タイトル画面のBGMの再生を停止

    return;
}