#pragma once

#include "Scene.h"

enum class SceneResult
{
    None,
    Clear,
    GameOver
};

class StageScene : public Scene
{
private:
    int stageNumber;
    SceneResult result;

public:
    StageScene(int stage);

    void Init() override;
    void Update() override;
    void Draw() override;
    void End() override;

    SceneResult GetResult() const;
    int GetStageNumber() const;
};