/* === ドアギミックのソースファイル === */

#include "Door.h"
#include "Geometry.h"
#include "Image.h"
#include "Sound.h"


/* --- コンストラクタ --- */
Door::Door(int id, int x, int y, int state, int target) : Gimmick(id, x, y, state, target)
{
	gimmickTag = GimmickTag::Normal;	// ギミックのタグを「通常ギミック」に設定

	gimmickType = GimmickType::Door;	// ギミックの種類を「ドアギミック」に設定

	maxState = DoorStateMax;	// 最後の状態を1設定
}

/* --- デストラクタ --- */
Door::~Door()
{
	
}

/* --- ドアギミックの初期化メソッド --- */
int Door::Init()
{
	gimmickImage[0] = LoadGraph(PathOfDoorImage1);		// 状態1の時の画像の読み込み・ハンドル取得
	gimmickImage[1] = LoadGraph(PathOfDoorImage2);		// 状態2の時の画像の読み込み・ハンドル取得

	if (gimmickImage[0] == -1 || gimmickImage[1] == -1)		// 読み込めていない画像があるなら
	{
		/* +++ エラーメッセージの表示 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"Door.cpp: Can not load Door's image.",
			"Image Error",
			MB_OK
		);

		return -1;	// -1を返す(初期化失敗)
	}

	return 0;
}

/* --- ドアギミックの更新メソッド --- */
void Door::Update(Player* player)
{
	if (gimmickState == maxState)	// ドアが最後の状態(開門済み)なら
	{
		if (isActive)	// ドアが起動状態なら
		{
			Inactivate();	// ドアを停止状態にする
		}

		return;		// 処理を終了
	}

	if (isActive)	// ドアが起動しているなら
	{
		SetGimmickState(maxState);	// ドアを最後の状態にする

		isPassable = true;	// 通行可能にする

		//Inactivate();	// ドアを停止する

		Sound_Play(SE_Door);	// ドアのSEを再生
	}

	return;
}

/* --- ドアギミックの描画メソッド --- */
void Door::Draw()
{
	POINT drawPoint = GetPoint(positionX, positionY);	// 描画する座標をPOINT型で取得

	/* +++ 状態に応じてドアを描画する +++ */
	switch (gimmickState)
	{
	case 1:
		/* +++ 状態1なら +++*/

		DrawGraphOnPoint(drawPoint, GimmickSize, GimmickSize, gimmickImage[0], TRUE);	// 状態1で描画
		break;
	case 2:
		/* +++ 状態2なら +++ */

		DrawGraphOnPoint(drawPoint, GimmickSize, GimmickSize, gimmickImage[1], TRUE);	// 状態2で描画
		break;
	}

	return;
}

/* --- ゴール判定のメソッド(このギミックでは使用しない) --- */
bool Door::IsGoal()
{
	return false;
}