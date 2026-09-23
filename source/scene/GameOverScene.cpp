#include "GameOverScene.h"

#include "DxLib.h"

GameOverScene::GameOverScene(int stage)
    : stageNumber(stage),
    selectedIndex(0)
{
}

void GameOverScene::Init()
{
    // 最初はリトライを選択
    selectedIndex = 0;

    transition = {};
}

void GameOverScene::Update()
{
    // -----------------------------
    // 上
    // -----------------------------

    if (CheckHitKey(KEY_INPUT_UP))
    {
        selectedIndex--;

        if (selectedIndex < 0)
        {
            selectedIndex = 1;
        }
    }


    // -----------------------------
    // 下
    // -----------------------------

    if (CheckHitKey(KEY_INPUT_DOWN))
    {
        selectedIndex++;

        if (selectedIndex > 1)
        {
            selectedIndex = 0;
        }
    }


    // -----------------------------
    // 決定
    // -----------------------------

    if (CheckHitKey(KEY_INPUT_RETURN))
    {
        transition.transitionType =
            TransitionType::ChangeScene;


        // リトライ
        if (selectedIndex == 0)
        {
            transition.sceneType =
                SceneType::Stage;

            transition.stageNum =
                stageNumber;
        }

        // タイトルへ
        else
        {
            transition.sceneType =
                SceneType::Title;
        }
    }
}

void GameOverScene::Draw()
{
    int white =
        GetColor(255, 255, 255);

    int red =
        GetColor(255, 80, 80);

    int yellow =
        GetColor(255, 255, 0);


    // GAME OVER
    DrawString(
        500,
        150,
        "GAME OVER",
        red
    );


    // リトライ
    if (selectedIndex == 0)
    {
        DrawString(
            500,
            350,
            "> リトライ",
            yellow
        );
    }
    else
    {
        DrawString(
            500,
            350,
            "  リトライ",
            white
        );
    }


    // タイトルへ
    if (selectedIndex == 1)
    {
        DrawString(
            500,
            420,
            "> タイトルに戻る",
            yellow
        );
    }
    else
    {
        DrawString(
            500,
            420,
            "  タイトルに戻る",
            white
        );
    }
}

void GameOverScene::End()
{
}

SceneTransition GameOverScene::GetTransition() const
{
    return transition;
}