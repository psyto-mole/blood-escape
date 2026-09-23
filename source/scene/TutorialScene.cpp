#include "TutorialScene.h"

#include "DxLib.h"

TutorialScene::TutorialScene()
{
}

void TutorialScene::Init()
{
    transition = {};
}

void TutorialScene::Update()
{
    // Spaceキーでステージ1へ
    if (CheckHitKey(KEY_INPUT_SPACE))
    {
        transition.transitionType =
            TransitionType::ChangeScene;

        transition.sceneType =
            SceneType::Stage;

        transition.stageNum = 1;
    }
}

void TutorialScene::Draw()
{
    DrawString(
        500,
        150,
        "TUTORIAL",
        GetColor(255, 255, 255)
    );

    DrawString(
        400,
        300,
        "ここに操作方法を表示",
        GetColor(255, 255, 255)
    );

    DrawString(
        450,
        500,
        "Press Space to Start",
        GetColor(255, 255, 255)
    );
}

void TutorialScene::End()
{
}

SceneTransition TutorialScene::GetTransition() const
{
    return transition;
}