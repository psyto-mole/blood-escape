/* === 針床のクラスのソースファイル === */

#include "NeedleFloor.h"
#include "Geometry.h"
#include "Image.h"
#include "Sound.h"


/* --- コンストラクタ --- */
NeedleFloor::NeedleFloor(int id, int x, int y, int state, int target) : ContactGimmick(id, x, y, state, target)
{
	gimmickType = GimmickType::NeedleFloor;	// ギミックの種類を「針床」に設定

	maxState = NeedleFloorStateMax;		// 最後の状態を設定
}

/* --- デストラクタ --- */
NeedleFloor::~NeedleFloor()
{

}

/* --- 針床の初期化メソッド --- */
int NeedleFloor::Init()
{
	gimmickImage[0] = LoadGraph(PathOfNeedleFloorImage1);	// 状態1の時の画像の読み込み・ハンドル取得
	gimmickImage[1] = LoadGraph(PathOfNeedleFloorImage2);	// 状態2の時の画像の読み込み・ハンドル取得

	if (gimmickImage[0] == -1 || gimmickImage[1] == -1)		// 読み込めていない画像があるなら
	{
		/* +++ エラーメッセージの表示 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"NeedleFloor.cpp: Can not load NeedleFloor's image.",
			"Image Error",
			MB_OK
		);

		return -1;	// -1を返す(初期化失敗)
	}

	return 0;
}

/* --- 針床の更新メソッド --- */
void NeedleFloor::Update(Player* player)
{
	if (isActive)	// 起動しているなら
	{
		if (isContact)	// プレイヤーと接触しているなら
		{
			return;		// 何もせずに終了
		}
		else
		{
			player->TakeDamage(NeedleFloorDamage);	// プレイヤーにダメージを与える

			SetGimmickState(maxState);	// ギミックの状態を最後の状態に設定

			Sound_Play(SE_NeedleFloor);		// 針床のSEを再生

			isContact = true;	// 接触状態にする
		}
	}
	else
	{
		isContact = false;	// 接触状態を解除する
	}

	return;
}

/* --- 針床の描画メソッド --- */
void NeedleFloor::Draw()
{
	POINT drawPoint = GetPoint(positionX, positionY);	// 描画する座標をPOINT型で取得

	/* +++ 状態に応じて針床を描画する +++ */
	switch (gimmickState)
	{
	case 1:
		/* +++ 状態1(初期状態)の場合 +++ */

		DrawGraphOnPoint(drawPoint, GimmickSize, GimmickSize, gimmickImage[0], FALSE);	// 状態1で描画
		break;
	case 2:
		/* +++ 状態2の場合 +++ */

		DrawGraphOnPoint(drawPoint, GimmickSize, GimmickSize, gimmickImage[1], FALSE);	//状態2で描画
		break;
	}

	return;
}

/* --- ゴール判定のメソッド(このギミックでは使用しない) --- */
bool NeedleFloor::IsGoal()
{
	return false;
}