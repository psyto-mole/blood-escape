/* === ゴール地点のソースファイル === */

#include "GoalPoint.h"
#include "Image.h"


/* --- ゴール地点のコンストラクタ-- - */
GoalPoint::GoalPoint(int id, int x, int y, int state, int target) : ContactGimmick(id, x, y, state, target)
{
	gimmickType = GimmickType::GoalPoint;	// ギミックの種類を「ゴール地点」に設定

	gimmickImage = -1;	// ギミックの画像ハンドルの初期化

	maxState = GoalPointStateMax;	// ゴール地点の状態の最大値を設定

	isGoal = false;
}

/* --- ゴール地点のデストラクタ-- - */
GoalPoint::~GoalPoint()
{
}

/* --- ゴール地点の初期化メソッド --- */
void GoalPoint::Init()
{
	return;
}

/* --- ゴール地点の更新メソッド --- */
void GoalPoint::Update(Player* player)
{
	if (isActive)
	{
		isGoal = true;	// ゴール判定をtrue(ゴールした)に設定

		//SE_Play();
	}

	return;
}

/* --- ゴール地点の描画メソッド --- */
void GoalPoint::Draw()
{
	// 描画

	return;
}

/* --- ゴールしたか判定するメソッド --- */
bool GoalPoint::IsGoal()
{
	return isGoal;	// ゴールしたかどうかを返す
}