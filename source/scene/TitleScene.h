#pragma once
/* === タイトルシーンのクラスのヘッダファイル === */

#include "DxLib.h"
#include "Scene.h"


/* --- タイトルシーンのクラス(Sceneクラスの派生クラス) --- */
class TitleScene : public Scene
{
public:
    int Init() override;        // タイトルシーンの初期化メソッド
    void Update() override;     // タイトルシーンの更新メソッド
    void Draw() override;       // タイトルシーンの描画メソッド
    void End() override;        // タイトルシーンの終了メソッド
};