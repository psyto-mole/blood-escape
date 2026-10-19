/* === シーンの管理を行うクラスのソースファイル === */

#include "SceneManager.h"
#include "TitleScene.h"
#include "TutorialScene.h"
#include "StageScene.h"
#include "GameOverScene.h"
#include "ClearScene.h"
#include "Key.h"
#include "Color.h"
#include "Font.h"

/* --- シーンの初期化メソッド --- */
int SceneManager::Init()
{
    currentScene = std::make_unique<TitleScene>();  // タイトル画面のポインタを取得

    if (currentScene == nullptr)
    {
        /* +++ エラーメッセージを表示 +++ */
        MessageBox(
        );

        return -1;  // -1を返す(初期化失敗)
    }

    if (currentScene->Init() == -1)   // 現在のシーンの初期化に失敗したら
    {
        /* +++ エラーメッセージを表示 +++ */
        MessageBox(
        );

        return -1;  // -1を返す(初期化失敗)
    }

    menuManager.Init();     // メニューを初期化

    fadeManager.FadeInit(255, 10);  // フェードの透明度とスピードを設定
    fadeManager.SetStateFadeIn();   // フェードの状態を設定

    gameEnd = false;

    return 0;
}


int SceneManager::Update()
{
    if (menuManager.IsGameEnd())    // ゲーム終了が選択されているなら
    {
        return -1;  // -1を返す
    }

    /* +++ フェード処理 +++ */
    if (fadeManager.GetFadeState() != FadeState::None)  // フェード処理中なら(フェードの状態が「フェードしない」でなければ)
    {
        if (fadeManager.GetFadeState() == FadeState::FadeTrans)
        {
            ApplySceneChange();     // シーンの切り替えを行う
        }

        fadeManager.FadeUpdate();   // フェードを更新する

        return 0;
    }

    if (menuManager.IsMenuOpen())    // メニューを開いているなら
    {
        menuManager.Update();   // メニューの更新メソッドを実行

        return 0;
    }

    if (currentScene == nullptr)    // 現在のシーンに何も割り当てられていなければ
    {
        return -1;     // -1を返す(更新処理を終了する)
    }

    currentScene->Update();     // 現在のシーンの更新メソッドを実行

    SceneTransition transition = currentScene->GetTransition();     // 現在のシーンから遷移情報を取得

    if (Key_Check_Click(KEY_INPUT_Q))
    {
        gameEnd = true;
    }

    if (transition.transitionType == TransitionType::None)  // 遷移しない場合
    {
        return 0;     // 処理を終了
    }

    if (transition.transitionType == TransitionType::ChangeScene)   // シーンを変える場合
    {
        RequestSceneChange(transition);     // 遷移情報を渡してシーンの遷移を要請する
    }

    return 0;
}

/* --- シーンの描画メソッド --- */
void SceneManager::Draw()
{
    if (menuManager.IsMenuOpen())    // メニューを開いているなら
    {
        menuManager.Draw();   // メニューの更新メソッドを実行

        return;
    }

    if (currentScene == nullptr)    // 現在のシーンに何も割り当てられていないなら
    {
        return;     // 処理を終了
    }

    currentScene->Draw();   // 現在のシーンの描画処理を行う

    fadeManager.FadeDraw();     // フェードの描画を行う

    return;
}

/* --- シーンの終了メソッド --- */
void SceneManager::End()
{
    if (currentScene != nullptr)    // 現在のシーンに割り当てられているシーンがあるなら
    {
        currentScene->End();    // 現在のシーンの終了メソッドを実行

        currentScene.reset();   // 現在のシーンの割り当てを無くす(nullptrにする)
    }

    nextScene.reset();  // 次のシーンの割り当てをなくす(nullptrにする)

    return;
}

/* --- シーン遷移要請メソッド --- */
void SceneManager::RequestSceneChange(const SceneTransition& transition)
{
    nextScene = CreateScene(transition);    // 遷移情報を元に次のシーンを生成

    if (nextScene == nullptr)   // 次のシーンに割り当てられているシーンがないなら
    {
        return;     // 処理を終了する
    }

    fadeManager.SetFadeAlpha(0);    // フェードの透明度を0に設定
    fadeManager.SetStateFadeOut();  // フェードの状態を「フェードアウト」に設定

    return;
}

/* --- シーンの生成メソッド(返り値はScene型のポインタ) --- */
std::unique_ptr<Scene> SceneManager::CreateScene(const SceneTransition& transition)
{
    /* +++ 遷移情報のシーンの種類に応じて処理を変える +++ */
    switch (transition.sceneType)
    {
    case SceneType::Title:
        /* +++ タイトルシーンの場合 +++ */

        return std::make_unique<TitleScene>();  // タイトルシーン型のポインタを返す
    case SceneType::Tutorial:
        /* +++ チュートリアルシーンの場合 +++ */

        return std::make_unique<TutorialScene>();   // チュートリアルシーン型のポインタを返す
    case SceneType::Stage:
        /* +++ ステージの場合 +++ */

        return std::make_unique<StageScene>(transition.stageNum);   // 指定した番号のステージ型のポインタを返す
    case SceneType::GameOver:
        /* +++ ゲームオーバーシーンの場合 +++ */

        return std::make_unique<GameOverScene>(transition.stageNum);    // ゲームオーバーシーン型のポインタを返す
    case SceneType::Clear:
        /* +++ クリアシーンの場合 +++ */

        return std::make_unique<ClearScene>();    // クリアシーン型のポインタを返す
    }


    return nullptr;     // nullポインタを返す
}

/* --- シーン切り換えメソッド --- */
void SceneManager::ApplySceneChange()
{
    if (currentScene != nullptr)    // 現在のシーンに割り当てられているシーンがあるなら
    {
        currentScene->End();    // 現在のシーンの終了メソッドを実行
    }

    currentScene = std::move(nextScene);    // 現在のシーンに次のシーンを割り当てる(所有権の移動)

    if (currentScene != nullptr)    // 現在のシーンに割り当てられているシーンがあるなら
    {
        currentScene->Init();   // 現在のシーンの初期化メソッドを実行
    }

    return;
}


//void SceneManager::UpdateFade()
//{
//    // --------------------------------
//    // Fade Out
//    // --------------------------------
//
//    if (fadeState == FadeState::FadeOut)
//    {
//        fadeAlpha += fadeSpeed;
//
//
//        if (fadeAlpha >= 255)
//        {
//            fadeAlpha = 255;
//
//
//            ApplySceneChange();
//
//
//            fadeState =
//                FadeState::FadeIn;
//        }
//
//
//        return;
//    }
//
//
//    // --------------------------------
//    // Fade In
//    // --------------------------------
//
//    if (fadeState == FadeState::FadeIn)
//    {
//        fadeAlpha -= fadeSpeed;
//
//
//        if (fadeAlpha <= 0)
//        {
//            fadeAlpha = 0;
//
//            fadeState =
//                FadeState::None;
//        }
//
//
//        return;
//    }
//}
//
//
//void SceneManager::DrawFade()
//{
//    if (fadeAlpha <= 0)
//    {
//        return;
//    }
//
//
//    SetDrawBlendMode(
//        DX_BLENDMODE_ALPHA,
//        fadeAlpha
//    );
//
//
//    DrawBox(
//        0,
//        0,
//        1280,
//        720,
//        GetColor(0, 0, 0),
//        TRUE
//    );
//
//
//    SetDrawBlendMode(
//        DX_BLENDMODE_NOBLEND,
//        0
//    );
//
//    return;
//}