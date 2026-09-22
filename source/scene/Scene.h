#pragma once
/* === 全シーン共通のインターフェース === */


class Scene
{
public:
    virtual ~Scene() = default;

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void End() = 0;
};