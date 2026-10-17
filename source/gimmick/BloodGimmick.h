#pragma once
/* === 出血ギミックのヘッダファイル === */

#include "DxLib.h"
#include "Gimmick.h"


class BloodGimmick : public Gimmick
{
public:
	BloodGimmick(int id, int x, int y, int state, int target);	// コンストラクタ
	~BloodGimmick() override;									// デストラクタ

	virtual int Init() = 0;						// ギミックの初期化メソッド
	virtual void Update(Player* player) = 0;	// ギミックの更新メソッド
	virtual void Draw() = 0;					// ギミックの描画メソッド
};