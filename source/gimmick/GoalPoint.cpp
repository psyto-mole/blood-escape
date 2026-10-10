/* === ゴール地点のソースファイル === */

#include "GoalPoint.h"
#include "Image.h"


/* --- ゴール地点のコンストラクタ-- - */
GoalPoint::GoalPoint(int id, int x, int y, int state, int target) : ContactGimmick(id, x, y, state, target)
{
	gimmickType = GimmickType::GoalPoint;	// ギミックの種類を「ゴール地点」に設定

	gimmickImage = -1;	// ギミックの画像ハンドルの初期化

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
	return;
}

/* --- ゴール地点の描画メソッド --- */
void GoalPoint::Draw()
{
	return;
}

/* --- ゴールしたか判定するメソッド --- */
bool GoalPoint::IsGoal()
{
	return isGoal;	// ゴールしたかどうかを返す
}