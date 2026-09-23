#include "SceneManager.h"

#include "DxLib.h"

#include "Scene.h"

#include "TitleScene.h"
#include "TutorialScene.h"
#include "StageScene.h"
#include "GameOverScene.h"


SceneManager::SceneManager()
    : fadeState(FadeState::None),
    fadeAlpha(0),
    fadeSpeed(10)
{
}

SceneManager::~SceneManager()
{
}


void SceneManager::Init()
{
    // 最初はタイトル画面
    currentScene =
        std::make_unique<TitleScene>();

    currentScene->Init();


    // 黒画面からフェードイン
    fadeAlpha = 255;

    fadeState =
        FadeState::FadeIn;
}


void SceneManager::Update()
{
    // --------------------------------
    // フェード中
    // --------------------------------

    if (fadeState != FadeState::None)
    {
        UpdateFade();
        return;
    }


    // --------------------------------
    // Scene更新
    // --------------------------------

    if (currentScene == nullptr)
    {
        return;
    }

    currentScene->Update();


    // --------------------------------
    // Sceneから遷移情報を取得
    // --------------------------------

    SceneTransition transition =
        currentScene->GetTransition();


    // --------------------------------
    // 遷移なし
    // --------------------------------

    if (transition.transitionType ==
        TransitionType::None)
    {
        return;
    }


    // --------------------------------
    // Scene変更
    // --------------------------------

    if (transition.transitionType ==
        TransitionType::ChangeScene)
    {
        RequestSceneChange(transition);
    }
}


void SceneManager::Draw()
{
    if (currentScene == nullptr)
    {
        return;
    }


    currentScene->Draw();

    DrawFade();
}


void SceneManager::End()
{
    if (currentScene != nullptr)
    {
        currentScene->End();

        currentScene.reset();
    }

    nextScene.reset();
}


void SceneManager::RequestSceneChange(
    const SceneTransition& transition)
{
    nextScene =
        CreateScene(transition);


    if (nextScene == nullptr)
    {
        return;
    }


    fadeAlpha = 0;

    fadeState =
        FadeState::FadeOut;
}


std::unique_ptr<Scene>
SceneManager::CreateScene(
    const SceneTransition& transition)
{
    switch (transition.sceneType)
    {
    case SceneType::Title:

        return std::make_unique<TitleScene>();


    case SceneType::Tutorial:

        return std::make_unique<TutorialScene>();


    case SceneType::Stage:

        return std::make_unique<StageScene>(
            transition.stageNum
        );


    case SceneType::GameOver:

        return std::make_unique<GameOverScene>(
            transition.stageNum
        );
    }


    return nullptr;
}


void SceneManager::ApplySceneChange()
{
    if (currentScene != nullptr)
    {
        currentScene->End();
    }


    currentScene =
        std::move(nextScene);


    if (currentScene != nullptr)
    {
        currentScene->Init();
    }
}


void SceneManager::UpdateFade()
{
    // --------------------------------
    // Fade Out
    // --------------------------------

    if (fadeState == FadeState::FadeOut)
    {
        fadeAlpha += fadeSpeed;


        if (fadeAlpha >= 255)
        {
            fadeAlpha = 255;


            ApplySceneChange();


            fadeState =
                FadeState::FadeIn;
        }


        return;
    }


    // --------------------------------
    // Fade In
    // --------------------------------

    if (fadeState == FadeState::FadeIn)
    {
        fadeAlpha -= fadeSpeed;


        if (fadeAlpha <= 0)
        {
            fadeAlpha = 0;

            fadeState =
                FadeState::None;
        }


        return;
    }
}


void SceneManager::DrawFade()
{
    if (fadeAlpha <= 0)
    {
        return;
    }


    SetDrawBlendMode(
        DX_BLENDMODE_ALPHA,
        fadeAlpha
    );


    DrawBox(
        0,
        0,
        1280,
        720,
        GetColor(0, 0, 0),
        TRUE
    );


    SetDrawBlendMode(
        DX_BLENDMODE_NOBLEND,
        0
    );
}