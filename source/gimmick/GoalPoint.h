#pragma once
/* === ゴール地点のヘッダファイル === */

#include "DxLib.h"
#include "ContactGimmick.h"
#include "Player.h"


#define GoalPointStateMax	1	// ゴール地点の状態の種類

/* --- ゴール地点ギミックのクラス(ContactGimmickクラスの派生クラス) --- */
class GoalPoint : public ContactGimmick
{
private:
	bool isGoal;	// ゴールの判定フラグ

public:
	GoalPoint(int id, int x, int y, int state, int target);		// ゴール地点のコンストラクタ
	~GoalPoint() override;										// ゴール地点のデストラクタ

	void Init() override;					// ゴール地点の初期化メソッド
	void Update(Player* player) override;	// ゴール地点の更新メソッド
	void Draw() override;					// ゴール地点の描画メソッド

	bool IsGoal();	// ゴールしたか判定するメソッド
};