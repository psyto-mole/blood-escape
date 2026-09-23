#pragma once

#include "Scene.h"

class TutorialScene : public Scene
{
private:
    SceneTransition transition;

public:
    TutorialScene();

    void Init() override;
    void Update() override;
    void Draw() override;
    void End() override;

    SceneTransition GetTransition() const override;
};