#pragma once
/* === 祭壇ギミックのヘッダファイル === */

#include "DxLib.h"
#include "BloodGimmick.h"


#define AltarStateMax	2	// 祭壇の状態の種類

/* --- 祭壇クラス(BloodGimmickクラスの派生クラス) --- */
class Altar : public BloodGimmick
{
public:
	Altar(int id, int x, int y, int state, int target);		// コンストラクタ
	~Altar() override;										// デストラクタ

	int Init() override;					// 祭壇の初期化メソッド
	void Update(Player* player) override;	// 祭壇の更新メソッド
	void Draw() override;					// 祭壇の描画メソッド

	bool IsGoal() override;		// ゴール判定のメソッド(このギミックでは使用しない)
};