/* === チュートリアルシーンのクラスのソースファイル === */

#include "TutorialScene.h"
#include "GameManager.h"
#include "Key.h"
#include "Color.h"
#include "Font.h"
#include "Sound.h"


/* --- デストラクタ --- */
TutorialScene::~TutorialScene()
{
}

/* --- チュートリアルシーンの初期化メソッド --- */
int TutorialScene::Init()
{
    transition = {};    // 遷移情報をクリア

    sceneElapsedFrame = 0;  // 経過フレームをリセット

    if (gameMasterObject.Init() == -1)  // ゲームマスターオブジェクトの初期化に失敗したら
    {
        return -1;  // -1を返す(初期化失敗)
    }

    /* +++ 表示する文章を設定 +++ */
    textPrinter.SetMessages(
        {
            "おはようございます...よくねむれましたか？",
            "これからあなたには...いのちがけのだっしゅつゲームにいどんでいただきます",
            "ルールはシンプル...",
            "すべてのへやからだっしゅつできればゲームはクリア...あなたはかいほうされる...",
            "しかし...いのちをおとしてしまえば...それでおわり...",
            "あまたのしょうがいが...あなたのみちをはばむでしょう...",
            "なかには...「ただ」ではどうにもできないものも...",
            "そのときは...「血」があなたをみちびくでしょう...",
            "ごけんとうをおいのりします..."
        });

    Sound_Play(BGM_Tutorial);   // チュートリアル画面のBGMを再生

    return 0;
}

/* --- チュートリアルシーンの更新メソッド --- */
void TutorialScene::Update()
{
    textPrinter.Update();   // 文字送りを更新

    if (Key_Check_Click(KEY_INPUT_RETURN))  // Enterキーがクリックされたら
    {
        textPrinter.AdvanceText();  // 文章を進める
    }

    if (textPrinter.GetCurrentMessageNumber() >= 7)     // 「血が...」のくだり以降が表示されている
    {
        gameMasterObject.SetDrawImage(3);   // ゲームマスターオブジェクトの描画する画像の要素番号を3に設定
    }
    else
    {
        gameMasterObject.Update();  // ゲームマスターオブジェクトの更新メソッドを実行
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

    gameMasterObject.Draw();    // ゲームマスターオブジェクトの描画メソッドを実行

    textPrinter.Draw(GameWindowWidth / 2, 900, FAlign_AllCenter,  Color_White, KHDot_40_2);  // 文章を文字送り機能付きで表示

    return;
}

/* --- チュートリアルシーンの終了メソッド --- */
void TutorialScene::End()
{
    Sound_Stop(&BGM_Tutorial);  // チュートリアル画面のBGMの再生を停止

    return;
}