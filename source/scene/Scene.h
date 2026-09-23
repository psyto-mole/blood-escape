#pragma once
/* === 全シーン共通のインターフェース === */



enum class SceneType
{
    Title,
    Tutorial,
    Stage,
    GameOver,
    Clear
};


enum class TransitionType
{
    None,
    ChangeScene
};


class Scene
{
public:
    virtual ~Scene() = default;

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void End() = 0;

    virtual SceneTransition GetTransition() const = 0;
};


struct SceneTransition
{
    SceneType sceneType = SceneType::Title;
    TransitionType transitionType = TransitionType::None;

    int stageNum = 0;
};