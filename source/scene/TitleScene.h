#pragma once
/* === タイトルシーンのクラスのヘッダファイル === */

#include "DxLib.h"
#include "Scene.h"


/* --- タイトルシーンのクラス(Sceneクラスの派生クラス) --- */
class TitleScene : public Scene
{
private:
    SceneTransition transition;     // シーンの遷移情報

public:
    void Init() override;       // タイトルシーンの初期化メソッド
    void Update() override;     // タイトルシーンの更新メソッド
    void Draw() override;       // タイトルシーンの描画メソッド
    void End() override;        // タイトルシーンの終了メソッド

    SceneTransition GetTransition() const override;     // 遷移情報を取得するメソッド
};