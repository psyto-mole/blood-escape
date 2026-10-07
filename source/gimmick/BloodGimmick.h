#pragma once
/* === 出血ギミックのヘッダファイル === */

#include "DxLib.h"
#include "Gimmick.h"


class BloodGimmick : public Gimmick
{
protected:
	

public:
	BloodGimmick(int id, int x, int y);		// コンストラクタ
	~BloodGimmick() override;				// デストラクタ

	virtual void Init() = 0;	// ギミックの初期化メソッド
	virtual void Update() = 0;	// ギミックの更新メソッド
	virtual void Draw() = 0;	// ギミックの描画メソッド
};