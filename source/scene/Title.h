#pragma once

#include "DxLib.h"
#include "Scene.h"

class TitleScene : public Scene
{
private:
    SceneTransition transition;

public:
    TitleScene();

    void Init() override;
    void Update() override;
    void Draw() override;
    void End() override;

    SceneTransition GetTransition() const override;
};