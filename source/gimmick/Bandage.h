#pragma once
/* === 包帯のヘッダファイル === */

#include "DxLib.h"
#include "ContactGimmick.h"


#define BandageStateMax	2	// 包帯の状態の種類

/* --- 包帯クラス(ContactGimmickクラスの派生クラス) --- */
class Bandage : public ContactGimmick
{
public:
	Bandage(int id, int x, int y, int state, int target);	// コンストラクタ
	~Bandage() override;									// デストラクタ

	int Init() override;					// 包帯の初期化メソッド
	void Update(Player* player) override;	// 包帯の更新メソッド
	void Draw() override;					// 包帯の描画メソッド

	bool IsGoal() override;		// ゴール判定のメソッド(このギミックでは使用しない)
};