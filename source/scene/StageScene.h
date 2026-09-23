#pragma once

#include "Scene.h"


class StageScene : public Scene
{
private:
    SceneTransition transition;

    int stageNumber;

public:
    StageScene(int stage);

    void Init() override;
    void Update() override;
    void Draw() override;
    void End() override;

    SceneTransition GetTransition() const override;
    int GetStageNumber() const;
};