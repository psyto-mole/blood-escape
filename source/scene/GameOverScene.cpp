/* === ゲームオーバーシーンのクラスのソースファイル === */

#include "GameOverScene.h"
#include "GameManager.h"
#include "Key.h"
#include "Color.h"
#include "Font.h"
#include "Sound.h"
#include "Geometry.h"
#include "Message.h"
#include "RectParameter.h"


/* --- コンストラクタ --- */
GameOverScene::GameOverScene(int stage)
    : gameoverNumber(stage),    // ゲームオーバーになったステージ番号に引数の値を代入
    selectedIndex(1)            // 選択肢の初期値を0(リトライ)に設定
{
    option1Button = GetRectOnPoint(GameOverOption1CenterX, GameOverOptionCenterY, GameOverOptionWidth, GameOverOptionHeight);
    option2Button = GetRectOnPoint(GameOverOption2CenterX, GameOverOptionCenterY, GameOverOptionWidth, GameOverOptionHeight);
}

/* --- デストラクタ --- */
GameOverScene::~GameOverScene()
{
}

/* --- ゲームオーバーシーンの初期化メソッド --- */
int GameOverScene::Init()
{
    selectedIndex = 1;  // 選択肢の初期値を0(リトライ)に設定

    transition = {};    // 遷移情報をクリア

    sceneElapsedFrame = 0;  // 経過フレームをリセット

    Sound_Play(BGM_GameOver);   // ゲームオーバー画面のBGMを再生

    return 0;
}

/* --- ゲームオーバーシーンの更新メソッド --- */
void GameOverScene::Update()
{
    if (sceneElapsedFrame >= GameFPS)   // シーン切り替えから1秒が経過した
    {
        if (Key_Check_Click(KEY_INPUT_LEFT))    // 左キーがクリックされたら
        {
            selectedIndex--;    // 選択肢の値を1減らす(1つ前の選択肢にする)

            if (selectedIndex <= 0)  // 選択肢の値が0以下になったら
            {
                selectedIndex = NumberOfGameoverOption;  // 選択肢の値をMaxにする(最後の選択肢にする)
            }

            Sound_Play(SE_Select);   // 選択肢を変更した時のSEを再生
        }
        else if (Key_Check_Click(KEY_INPUT_RIGHT))   // 右キーがクリックされたら
        {
            selectedIndex++;    // 選択肢の値を1増やす(次の選択肢にする)

            if (selectedIndex > NumberOfGameoverOption)  // 選択肢の値が選択肢の個数を超えたら
            {
                selectedIndex = 1;  // 選択肢を最初に戻す
            }

            Sound_Play(SE_Select);   // 選択肢を変更した時のSEを再生
        }

        if (Key_Check_Click(KEY_INPUT_RETURN))     // エンターがクリックされた
        {
            transition.transitionType = TransitionType::ChangeScene;    // 遷移の状態をシーン切り替えにする

            if (selectedIndex == 1)     // 選択肢が1(リトライ)なら
            {
                transition.sceneType = SceneType::Stage;    // 遷移情報のシーンの種類をステージにする

                transition.stageNum = gameoverNumber;  // 遷移情報のステージ番号にゲームオーバーになったステージの番号を代入
            }
            else if(selectedIndex == 2)     // 選択肢が1(タイトル)の場合
            {
                transition.sceneType = SceneType::Title;    // 遷移情報のシーンの種類をステージにする
            }

            Sound_Play(SE_Enter);   // エンターキーを押した時のSEを再生
        }
    }

    sceneElapsedFrame += 1;     // 経過フレームを1加算

    return;
}

/* --- ゲームオーバーシーンの描画メソッド --- */
void GameOverScene::Draw()
{
    DrawRect(GetRect(0, 0, GameWindowWidth, GameWindowHeight), Color_DarkRed, true, 1);     // 背景を暗い赤にする

    DrawFormatStringToHandleAlign(GameWindowWidth / 2, 300, FAlign_AllCenter, Color_Violet, KHDot_200_9, "%s", StringGameOver);

    if (selectedIndex == 1)
    {
        DrawRect(option1Button, Color_White, true, 2);
        DrawRect(option2Button, Color_White, false, 2);

        DrawFormatStringToHandleAlign(GameOverOption1CenterX, GameOverOptionCenterY, FAlign_AllCenter, Color_Black, KHDot_30_1, "%s", StringRetry);
        DrawFormatStringToHandleAlign(GameOverOption2CenterX, GameOverOptionCenterY, FAlign_AllCenter, Color_White, KHDot_30_1, "%s", StringBackTitle);
    }
    else if (selectedIndex == 2)
    {
        DrawRect(option1Button, Color_White, false, 2);
        DrawRect(option2Button, Color_White, true, 2);

        DrawFormatStringToHandleAlign(GameOverOption1CenterX, GameOverOptionCenterY, FAlign_AllCenter, Color_White, KHDot_30_1, "%s", StringRetry);
        DrawFormatStringToHandleAlign(GameOverOption2CenterX, GameOverOptionCenterY, FAlign_AllCenter, Color_Black, KHDot_30_1, "%s", StringBackTitle);
    }

    return;
}

/* --- ゲームオーバーシーンの終了メソッド ---*/
void GameOverScene::End()
{
    Sound_Stop(&BGM_GameOver);  // ゲームオーバー画面のBGMの再生を停止

    return;
}