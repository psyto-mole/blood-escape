/* === スタート地点のソースファイル === */

#include "StartPoint.h"


/* --- スタート地点のコンストラクタ --- */
StartPoint::StartPoint(int id, int x, int y, int state, int target) : Gimmick(id, x, y, state, target)
{	
	gimmickTag = GimmickTag::Normal;	// ギミックのタグを「通常ギミック」に設定

	gimmickType = GimmickType::StartPoint;	// ギミックの種類を「スタート地点」に設定

	maxState = StartPointStateMax;	// 最後の状態を設定

	isPassable = true;		// 通行可能に設定
}

/* --- スタート地点のデストラクタ --- */
StartPoint::~StartPoint()
{

}

/* --- スタート地点の初期化メソッド --- */
int StartPoint::Init()
{
	return 0;
}

/* --- スタート地点の更新メソッド --- */
void StartPoint::Update(Player* player)
{
	return;
}

/* --- スタート地点の描画メソッド --- */
void StartPoint::Draw()
{
	return;
}

/* --- ゴール判定のメソッド(このギミックでは使用しない) --- */
bool StartPoint::IsGoal()
{
	return false;
}