/* === ゲームオーバーシーンのクラスのソースファイル === */

#include "GameOverScene.h"
#include "GameManager.h"
#include "Key.h"
#include "Color.h"
#include "Font.h"
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
void GameOverScene::Init()
{
    selectedIndex = 1;  // 選択肢の初期値を0(リトライ)に設定

    transition = {};    // 遷移情報をクリア

    sceneElapsedFrame = 0;  // 経過フレームをリセット

    return;
}

/* --- ゲームオーバーシーンの更新メソッド --- */
void GameOverScene::Update()
{
    if (sceneElapsedFrame >= GameFPS)   // シーン切り替えから1秒が経過した
    {
        if (Key_Check_Click(KEY_INPUT_LEFT))    // 左キーがクリックされたら
        {
            selectedIndex--;    // 選択肢の値を1減らす(1つ前の選択肢にする)

            if (selectedIndex < 0)  // 選択肢の値が0を下回ったら
            {
                selectedIndex = NumberOfGameoverOption;  // 選択肢の値をMaxにする(最後の選択肢にする)
            }
        }

        if (Key_Check_Click(KEY_INPUT_RIGHT))   // 右キーがクリックされたら
        {
            selectedIndex++;    // 選択肢の値を1増やす(次の選択肢にする)

            if (selectedIndex > NumberOfGameoverOption)  // 選択肢の値が選択肢の個数を超えたら
            {
                selectedIndex = 0;  // 選択肢を最初に戻す
            }
        }

        if (Key_Check_Click(KEY_INPUT_RETURN))     // エンターがクリックされた
        {
            transition.transitionType = TransitionType::ChangeScene;    // 遷移の状態をシーン切り替えにする

            if (selectedIndex == 0)     // 選択肢が0(リトライ)なら
            {
                transition.sceneType = SceneType::Stage;    // 遷移情報のシーンの種類をステージにする

                transition.stageNum = gameoverNumber;  // 遷移情報のステージ番号にゲームオーバーになったステージの番号を代入
            }
            else       // 選択肢が1(タイトル)の場合
            {
                transition.sceneType = SceneType::Title;    // 遷移情報のシーンの種類をステージにする
            }
        }
    }

    sceneElapsedFrame += 1;     // 経過フレームを1加算

    return;
}

/* --- ゲームオーバーシーンの描画メソッド --- */
void GameOverScene::Draw()
{
    DrawFormatStringToHandleAlign(GameWindowWidth / 2, 300, FAlign_AllCenter, Color_Violet, CathodeTube_100_9, "%s", StringGameOver);

    if (selectedIndex == 1)
    {
        DrawRect(option1Button, Color_White, true, 1);
        DrawRect(option2Button, Color_White, false, 1);

        DrawFormatStringToHandleAlign(GameOverOption1CenterX, GameOverOptionCenterY, FAlign_AllCenter, Color_Black, CathodeTube_30_1, "%s", StringRetry);
        DrawFormatStringToHandleAlign(GameOverOption2CenterX, GameOverOptionCenterY, FAlign_AllCenter, Color_White, CathodeTube_30_1, "%s", StringRetry);
    }
    else if (selectedIndex == 2)
    {
        DrawRect(option1Button, Color_White, false, 1);
        DrawRect(option2Button, Color_White, true, 1);

        DrawFormatStringToHandleAlign(GameOverOption1CenterX, GameOverOptionCenterY, FAlign_AllCenter, Color_White, CathodeTube_30_1, "%s", StringRetry);
        DrawFormatStringToHandleAlign(GameOverOption1CenterX, GameOverOptionCenterY, FAlign_AllCenter, Color_Black, CathodeTube_30_1, "%s", StringRetry);
    }

    return;
}

/* --- ゲームオーバーシーンの終了メソッド ---*/
void GameOverScene::End()
{
    return;
}