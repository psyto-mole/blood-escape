#pragma once
/* === シーンの管理を行うクラスのヘッダファイル === */

#include <memory>
#include "DxLib.h"
#include "Scene.h"
#include "Menu.h"
#include "Fade.h"


class Scene;

/* --- シーンマネージャークラス(シーンの処理を管理する) --- */
class SceneManager
{
private:
    std::unique_ptr<Scene> currentScene;    // 現在のシーンのポインタ
    std::unique_ptr<Scene> nextScene;       // 次のシーンのポインタ

    Menu menuManager;   // メニューの処理を管理する変数

    Fade fadeManager;   // フェード処理を管理する変数

    bool gameEnd;   // ゲームの起動状態を管理する変数

public:
    int Init();     // シーンの初期化メソッド
    int Update();   // シーンの更新メソッド
    void Draw();    // シーンの描画メソッド
    void End();     // シーンの終了メソッド

private:
    void RequestSceneChange(const SceneTransition& transition);             // シーン遷移要請メソッド(切り換えは行わない)
    std::unique_ptr<Scene> CreateScene(const SceneTransition& transition);  // シーン生成メソッド
    void ApplySceneChange();                                                // シーン切り替えメソッド
};