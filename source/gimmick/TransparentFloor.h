#pragma once
/* === 透明床のヘッダファイル === */

#include "DxLib.h"
#include "BloodGimmick.h"


#define TransparentFloorSateMax	2	// 透明床の状態の種類

/* --- 透明床クラス(BloodGimmickクラスの派生クラス) --- */
class TransparentFloor : public BloodGimmick
{
public:
	TransparentFloor(int id, int x, int y, int state, int target);	// コンストラクタ
	~TransparentFloor() override;									// デストラクタ

	void Init() override;					// ギミックの初期化メソッド
	void Update(Player* palyer) override;	// ギミックの更新メソッド
	void Draw() override;					// ギミックの描画メソッド
};