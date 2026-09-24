/* === ゲームオーバーシーンのクラスのソースファイル === */

#include "GameOverScene.h"
#include "GameManager.h"


/* --- コンストラクタ --- */
GameOverScene::GameOverScene(int stage)
    : gameoverNumber(stage),    // ゲームオーバーになったステージ番号に引数の値を代入
    selectedIndex(0)            // 選択肢の初期値を0(リトライ)に設定
{
}

/* --- ゲームオーバーシーンの初期化メソッド --- */
void GameOverScene::Init()
{
    selectedIndex = 0;  // 選択肢の初期値を0(リトライ)に設定

    transition = {};    // 遷移情報をクリア

    sceneElapsedFrame = 0;  // 経過フレームをリセット

    return;
}

/* --- ゲームオーバーシーンの更新メソッド --- */
void GameOverScene::Update()
{
    sceneElapsedFrame += 1;     // 経過フレームを1加算

    // -----------------------------
    // 上
    // -----------------------------

    if (/* キーがクリックされた */)    // キーがクリックされたら
    {
        selectedIndex--;    // 選択肢の値を1減らす(1つ前の選択肢にする)

        if (selectedIndex < 0)  // 選択肢の値が0を下回ったら
        {
            selectedIndex = SelectMax;  // 選択肢の値をMaxにする(最後の選択肢にする)
        }
    }


    // -----------------------------
    // 下
    // -----------------------------

    if (/* キーがクリックされた */)   // キーがクリックされたら
    {
        selectedIndex++;    // 選択肢の値を1増やす(次の選択肢にする)

        if (selectedIndex > SelectMax)  // 選択肢の値が選択肢の個数を超えたら
        {
            selectedIndex = 0;  // 選択肢を最初に戻す
        }
    }


    // -----------------------------
    // 決定
    // -----------------------------

    if (/* エンターがクリックされた */ && sceneElapsedFrame >= GameFPS)     // シーン切り替えから1秒が経過しエンターがクリックされた
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

    return;
}

/* --- ゲームオーバーシーンの描画メソッド --- */
void GameOverScene::Draw()
{
    //int white =
    //    GetColor(255, 255, 255);

    //int red =
    //    GetColor(255, 80, 80);

    //int yellow =
    //    GetColor(255, 255, 0);


    //// GAME OVER
    //DrawString(
    //    500,
    //    150,
    //    "GAME OVER",
    //    red
    //);


    //// リトライ
    //if (selectedIndex == 0)
    //{
    //    DrawString(
    //        500,
    //        350,
    //        "> リトライ",
    //        yellow
    //    );
    //}
    //else
    //{
    //    DrawString(
    //        500,
    //        350,
    //        "  リトライ",
    //        white
    //    );
    //}


    //// タイトルへ
    //if (selectedIndex == 1)
    //{
    //    DrawString(
    //        500,
    //        420,
    //        "> タイトルに戻る",
    //        yellow
    //    );
    //}
    //else
    //{
    //    DrawString(
    //        500,
    //        420,
    //        "  タイトルに戻る",
    //        white
    //    );
    //}

    return;
}

/* --- ゲームオーバーシーンの終了メソッド ---*/
void GameOverScene::End()
{
    return;
}

/* --- 遷移情報を取得するメソッド --- */
SceneTransition GameOverScene::GetTransition() const
{
    return transition;  // ゲームオーバーシーンの遷移情報を取得
}