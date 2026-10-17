/* === 透明床ギのソースファイル === */

#include "TransparentFloor.h"
#include "Geometry.h"
#include "Image.h"


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

	return;
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
	return;
}