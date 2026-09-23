#pragma once

#include <memory>

#include "Scene.h"

class Scene;

class SceneManager
{
private:
    // 現在のScene
    std::unique_ptr<Scene> currentScene;

    // 次のScene
    std::unique_ptr<Scene> nextScene;


    // --------------------------------
    // フェード
    // --------------------------------

    enum class FadeState
    {
        None,
        FadeOut,
        FadeIn
    };

    FadeState fadeState;

    int fadeAlpha;
    int fadeSpeed;


public:
    SceneManager();
    ~SceneManager();


    void Init();
    void Update();
    void Draw();
    void End();


private:

    // Scene遷移要求
    void RequestSceneChange(
        const SceneTransition& transition
    );

    // Scene生成
    std::unique_ptr<Scene> CreateScene(
        const SceneTransition& transition
    );

    // Scene切り替え
    void ApplySceneChange();


    // フェード
    void UpdateFade();
    void DrawFade();
};