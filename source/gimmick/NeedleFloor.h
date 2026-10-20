#pragma once
/* === 針床のクラスのヘッダファイル === */

#include "DxLib.h"
#include "ContactGimmick.h"


#define NeedleFloorStateMax	2	// 針床の状態の種類
#define NeedleFloorDamage	10	// 針床のダメージ量

/* --- 針床のクラス(ContactGimmickクラスの派生クラス) --- */
class NeedleFloor : public ContactGimmick
{
public:
	NeedleFloor(int id, int x, int y, int state, int target);	// コンストラクタ
	~NeedleFloor() override;									// デストラクタ

	int Init() override;					// 針床の初期化メソッド
	void Update(Player* player) override;	// 針床の更新メソッド
	void Draw() override;					// 針床の描画メソッド

	bool IsGoal() override;		// ゴール判定のメソッド(このギミックでは使用しない)
};