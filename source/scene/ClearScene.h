#pragma once
/* === クリアシーンのクラスのヘッダファイル === */

#include "DxLib.h"
#include "Scene.h"


/* --- クリアシーンのクラス(Sceneクラスの派生クラス) --- */
class ClearScene : public Scene
{
public:
    int Init() override;    // クリアシーンの初期化メソッド
    void Update() override;  // クリアシーンの更新メソッド
    void Draw() override;    // クリアシーンの描画メソッド
    void End() override;     // クリアシーンの終了メソッド
};