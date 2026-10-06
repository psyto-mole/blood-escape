#pragma once
/* === ステージシーンのUIのヘッダファイル === */

#include "DxLib.h"
#include "UI.h"
#include "Player.h"


class StageUI : public UserInterface
{
private:
	Player* player;		// プレイヤーのポインタ

public:
	void Init() override;		// ステージシーンのUIの初期化メソッド
	void Update() override;		// ステージシーンのUIの更新メソッド
	void Draw() override;		// ステージシーンのUIの描画メソッド
	void End() override;		// ステージシーンのUIの終了メソッド
};