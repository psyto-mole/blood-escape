#pragma once
/* === クリアシーンのクラスのヘッダファイル === */

#include "DxLib.h"
#include "Scene.h"


/* --- クリアシーンのクラス(Sceneクラスの派生クラス) --- */
class ClearScene : public Scene
{
private:
	SceneTransition transition;		// 遷移情報
	
	int sceneElapsedFrame;	// シーンの経過フレーム

public:
    void Init() override;    // クリアシーンの初期化メソッド
    void Update() override;  // クリアシーンの更新メソッド
    void Draw() override;    // クリアシーンの描画メソッド
    void End() override;     // クリアシーンの終了メソッド

    SceneTransition GetTransition() const override;  // 遷移情報を取得するメソッド(読み取り専用なのでconst)

};