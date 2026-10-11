/* === 透明床ギのソースファイル === */

#include "TransparentFloor.h"


/* --- コンストラクタ-- - */
TransparentFloor::TransparentFloor(int id, int x, int y, int state, int target) : BloodGimmick(id, x, y, state, target)
{
	gimmickType = GimmickType::TransparentFloor;	// ギミックの種類を「透明床」に設定

	gimmickImage = -1;	// ギミックの画像ハンドルの初期化

	maxState = TransparentFloorSateMax;		// 最後の状態を設定

	isPassable = true;	// ギミックを「通行可能」に設定
}

/* --- デストラクタ-- - */
TransparentFloor::~TransparentFloor()
{

}

/* --- ギミックの初期化メソッド --- */
void TransparentFloor::Init()
{
	return;
}

/* --- ギミックの更新メソッド --- */
void TransparentFloor::Update(Player* player)
{
	if (gimmickState == maxState)	// ギミックが最後の状態なら
	{
		return;		// 何もせずに終了
	}

	if (isActive)
	{
		SetGimmickState(maxState);	// ギミックを最後の状態に設定

		Inactivate();	// ギミックを停止する
	}

	return;
}

/* --- ギミックの描画メソッド --- */
void TransparentFloor::Draw()
{
	return;
}