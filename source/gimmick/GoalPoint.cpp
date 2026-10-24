/* === ゴール地点のソースファイル === */

#include "GoalPoint.h"
#include "GameManager.h"
#include "Geometry.h"
#include "Color.h"
#include "Sound.h"


/* --- ゴール地点のコンストラクタ-- - */
GoalPoint::GoalPoint(int id, int x, int y, int state, int target) : ContactGimmick(id, x, y, state, target)
{
	gimmickType = GimmickType::GoalPoint;	// ギミックの種類を「ゴール地点」に設定

	maxState = GoalPointStateMax;	// 最後の状態を設定

	isGoal = false;
}

/* --- ゴール地点のデストラクタ-- - */
GoalPoint::~GoalPoint()
{
}

/* --- ゴール地点の初期化メソッド --- */
int GoalPoint::Init()
{
	return 0;
}

/* --- ゴール地点の更新メソッド --- */
void GoalPoint::Update(Player* player)
{
	if (isGoal)		// ゴールしているなら
	{
		if (isActive)	// ゴール地点が起動状態なら
		{
			Inactivate();	// ゴール地点を停止状態にする
		}

		return;
	}

	if (isActive)	// 起動しているなら
	{
		isGoal = true;	// ゴール判定をtrue(ゴールした)に設定

		Sound_Play(SE_GoalPoint);	// ゴール地点のSEを再生
	}

	return;
}

/* --- ゴール地点の描画メソッド --- */
void GoalPoint::Draw()
{
	if (GameDebug >= 2)
	{
		DrawRect(GetRect(positionX - GimmickSize / 2, positionY - GimmickSize / 2, positionX + GimmickSize / 2 + 1, positionY + GimmickSize / 2 + 1), Color_Green, false, 3);
	}

	return;
}

/* --- ゴールしたか判定するメソッド --- */
bool GoalPoint::IsGoal()
{
	return isGoal;	// ゴールしたかどうかを返す
}