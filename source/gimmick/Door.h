#pragma once
/* === ドアギミックのヘッダファイル === */

#include "DxLib.h"
#include "BootGimmick.h"


#define DoorStateMax	2	// ドアの状態の種類

/* --- ドアギミッククラス(Gimmickクラスの派生クラス) --- */
class Door : public BootGimmick
{
public:
	Door(int id, int x, int y, int state, int target);	// コンストラクタ
	~Door() override;									// デストラクタ

	int Init() override;					// ドアギミックの初期化メソッド
	void Update(Player* player) override;	// ドアギミックの更新メソッド
	void Draw() override;					// ドアギミックの描画メソッド

	bool IsGoal() override;		// ゴール判定のメソッド(このギミックでは使用しない)
};