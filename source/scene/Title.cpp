#include "Title.h"

TitleScene::TitleScene()
{
}

void TitleScene::Init()
{
    // 遷移情報をリセット
    transition = {};
}

void TitleScene::Update()
{
    // Enterキー
    if (CheckHitKey(KEY_INPUT_RETURN))
    {
        transition.transitionType =
            TransitionType::ChangeScene;

        transition.sceneType =
            SceneType::Tutorial;
    }
}

void TitleScene::Draw()
{
    DrawString(
        500,
        200,
        "ACTION PUZZLE",
        GetColor(255, 255, 255)
    );

    DrawString(
        500,
        400,
        "Press Enter",
        GetColor(255, 255, 255)
    );
}

void TitleScene::End()
{
}

SceneTransition TitleScene::GetTransition() const
{
    return transition;
}