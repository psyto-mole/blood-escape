#pragma once

#include "Scene.h"

class GameOverScene : public Scene
{
private:
    // ゲームオーバーになったステージ
    int stageNumber;

    // 0 = リトライ
    // 1 = タイトル
    int selectedIndex;

    SceneTransition transition;

public:
    GameOverScene(int stage);

    void Init() override;
    void Update() override;
    void Draw() override;
    void End() override;

    SceneTransition GetTransition() const override;
};