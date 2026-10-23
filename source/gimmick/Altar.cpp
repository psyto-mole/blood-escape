/* === 祭壇ギミックのソースファイル === */

#include "Altar.h"
#include "Geometry.h"
#include "Image.h"


/* --- コンストラクタ --- */
Altar::Altar(int id, int x, int y, int state, int target) : BloodGimmick(id, x, y, state, target)
{
	gimmickType = GimmickType::Altar;	// ギミックの種類を「祭壇」に設定

	maxState = AltarStateMax;	// 最後の状態を設定
}

/* --- デストラクタ --- */
Altar::~Altar()
{

}

/* --- 祭壇の初期化メソッド --- */
int Altar::Init()
{
	gimmickImage[0] = LoadGraph(PathOfAltarImage1);		// 状態1の時の画像の読み込み・ハンドル取得
	gimmickImage[1] = LoadGraph(PathOfAltarImage2);		// 状態2の時の画像の読み込み・ハンドル取得

	if (gimmickImage[0] == -1 || gimmickImage[1] == -1)		// 読み込めていない画像があるなら
	{
		/* +++ エラーメッセージの表示 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"Altar.cpp: Can not load altar's image.",
			"Image Error",
			MB_OK
		);

		return -1;	// -1を返す(初期化失敗)
	}

	return 0;
}

/* --- 祭壇の更新メソッド --- */
void Altar::Update(Player* player)
{
	if (gimmickState == maxState)	// ギミックの状態が最後の状態(起動済み)なら
	{
		if (isActive)	// 祭壇が起動状態なら
		{
			Inactivate();	// 祭壇を停止状態にする
		}

		return;		// 何もせずに終了
	}

	if (isActive)	// 祭壇が起動しているなら
	{
		SetGimmickState(maxState);	// ギミックを最後の状態にする

		//Inactivate();	// 祭壇を停止状態にする

		//SE_Play();
	}

	return;
}

/* --- 祭壇の描画メソッド --- */
void Altar::Draw()
{
	POINT drawPoint = GetPoint(positionX, positionY);	// 描画を行う座標をPOINT型で取得

	/* +++ ギミックの状態に応じて描画処理を行う +++ */
	switch (gimmickState)
	{
	case 1:
		/* +++ 状態1なら +++ */

		DrawGraphOnPoint(drawPoint, GimmickSize, GimmickSize, gimmickImage[0], TRUE);	// 祭壇を状態1で描画
		break;
	case 2:
		/* +++ 状態2なら +++ */

		DrawGraphOnPoint(drawPoint, GimmickSize, GimmickSize, gimmickImage[1], TRUE);	// 祭壇を状態1で描画
		break;
	}

	return;
}

/* --- ゴール判定のメソッド(このギミックでは使用しない) --- */
bool Altar::IsGoal()
{
	return false;
}