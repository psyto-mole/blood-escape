/* === 透明床ギのソースファイル === */

#include "TransparentFloor.h"
#include "GameManager.h"
#include "Geometry.h"
#include "Image.h"
#include "Color.h"


/* --- コンストラクタ-- - */
TransparentFloor::TransparentFloor(int id, int x, int y, int state, int target) : BloodGimmick(id, x, y, state, target)
{
	gimmickType = GimmickType::TransparentFloor;	// ギミックの種類を「透明床」に設定

	maxState = TransparentFloorSateMax;		// 最後の状態を設定

	isPassable = true;	// ギミックを「通行可能」に設定
}

/* --- デストラクタ-- - */
TransparentFloor::~TransparentFloor()
{

}

/* --- ギミックの初期化メソッド --- */
int TransparentFloor::Init()
{
	gimmickImage[0] = LoadGraph(PathOfTransparentFloorImage1);	// 状態1の時の画像の読み込み・ハンドル取得
	gimmickImage[1] = LoadGraph(PathOfTransparentFloorImage2);	// 状態2の時の画像の読み込み・ハンドル取得

	if (gimmickImage[0] == -1 || gimmickImage[1] == -1)		// 読み込めていない画像があるなら
	{
		/* +++ エラーメッセージの表示 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"TransparentFloor.cpp: Can not load TransparentFloor's image.",
			"Image Error",
			MB_OK
		);

		return -1;	// -1を返す(初期化失敗)
	}

	return 0;
}

/* --- ギミックの更新メソッド --- */
void TransparentFloor::Update(Player* player)
{
	if (gimmickState == maxState)	// ギミックが最後の状態なら
	{
		if (isActive)	// 透明床が起動状態なら
		{
			Inactivate();	// 透明床を停止状態にする
		}

		return;		// 何もせずに終了
	}

	if (isActive)	// 起動状態なら
	{
		SetGimmickState(maxState);	// ギミックを最後の状態に設定

		//Inactivate();	// ギミックを停止する
	}

	return;
}

/* --- ギミックの描画メソッド --- */
void TransparentFloor::Draw()
{
	if (GameDebug == 2)
	{
		DrawRect(GetRect(positionX - GimmickSize / 2, positionY - GimmickSize / 2, positionX + GimmickSize / 2 + 1, positionY + GimmickSize / 2 + 1), Color_Green, false, 3);
	
		//return;
	}

	POINT drawPoint = GetPoint(positionX, positionY);	// 描画する座標をPOINT型で取得

	/* +++ ギミックの状態に応じて透明床の描画処理を行う +++ */
	switch (gimmickState)
	{
	case 1:
		/* +++ 状態1なら +++ */

		DrawGraphOnPoint(drawPoint, GimmickSize, GimmickSize, gimmickImage[0], TRUE);	// 状態1で描画
		break;
	case 2:
		/* +++ 状態2なら +++ */

		DrawGraphOnPoint(drawPoint, GimmickSize, GimmickSize, gimmickImage[1], TRUE);	// 状態1で描画
		break;
	}

	return;
}

/* --- ゴール判定のメソッド(このギミックでは使用しない) --- */
bool TransparentFloor::IsGoal()
{
	return false;
}