#pragma once
/* === チュートリアルシーンのクラスのヘッダファイル === */

#include "DxLib.h"
#include "Scene.h"


/* --- チュートリアルシーンのクラス(Sceneクラスの派生クラス) --- */
class TutorialScene : public Scene
{
private:
    SceneTransition transition;     // 遷移情報

public:
    void Init() override;       // チュートリアルシーンの初期化メソッド
    void Update() override;     // チュートリアルシーンの更新メソッド
    void Draw() override;       // チュートリアルシーンの描画メソッド
    void End() override;        // チュートリアルシーンの終了メソッド

    SceneTransition GetTransition() const override;     // 遷移情報の取得メソッド
};