/* === チュートリアルシーンのクラスのソースファイル === */

#include "TutorialScene.h"
#include "GameManager.h"
#include "Key.h"
#include "Color.h"
#include "Font.h"


/* --- デストラクタ --- */
TutorialScene::~TutorialScene()
{
}

/* --- チュートリアルシーンの初期化メソッド --- */
void TutorialScene::Init()
{
    transition = {};    // 遷移情報をクリア

    sceneElapsedFrame = 0;  // 経過フレームをリセット

    textPrinter.SetMessages(
        {
            "なぜストレートを投げないのか",
            "投げられないのか",
            "投げたくないのか",
            "投げる度胸もないのか",
        });

    return;
}

/* --- チュートリアルシーンの更新メソッド --- */
void TutorialScene::Update()
{
    textPrinter.Update();   // 文字送りを更新

    if (Key_Check_Click(KEY_INPUT_RETURN))  // Enterキーがクリックされたら
    {
        textPrinter.AdvanceText();  // 文章を進める
    }

    if (textPrinter.IsAllMessageFinished() && sceneElapsedFrame >= GameFPS)   // シーンが切り替わってから1秒が経過し、文字送りが終了したらステージ1へ
    {
        transition.transitionType = TransitionType::ChangeScene;    // 遷移の状態をシーン切り替えにする

        transition.sceneType = SceneType::Stage;    // シーンの種類をステージにする

        transition.stageNum = 1;    // ステージ番号を1にする
    }

    sceneElapsedFrame += 1;     // 経過フレームを1加算
}

/* --- チュートリアルシーンの描画メソッド --- */
void TutorialScene::Draw()
{
    textPrinter.Draw(100, 900, Color_White, CathodeTube_30_1);  // 文章を文字送り機能付きで表示

    return;
}

/* --- チュートリアルシーンの終了メソッド --- */
void TutorialScene::End()
{
    return;
}