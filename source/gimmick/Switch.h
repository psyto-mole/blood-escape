#pragma once
/* === スイッチギミックのヘッダファイル === */

#include "DxLib.h"
#include "Gimmick.h"


class Switch : public Gimmick
{
private:

public:
	Switch(int id, int x, int y);	// コンストラクタ
	~Switch() override;				// デストラクタ

	void Init() override;		// スイッチギミックの初期化メソッド
	void Update() override;		// スイッチギミックの更新メソッド
	void Draw() override;		// スイッチギミックの描画メソッド
};