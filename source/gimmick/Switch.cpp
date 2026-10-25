/* === スイッチギミックのソースファイル === */

#include "Switch.h"
#include "GameManager.h"
#include "Geometry.h"
#include "Color.h"
#include "Font.h"
#include "Image.h"
#include "Sound.h"


/* --- コンストラクタ-- - */
Switch::Switch(int id, int x, int y, int state, int target) : Gimmick(id, x, y, state, target)
{
	gimmickTag = GimmickTag::Normal;	// ギミックのタグを「通常ギミック」に設定

	gimmickType = GimmickType::Switch;	// ギミックの種類を「スイッチ」に設定

	maxState = SwitchStateMax;	// 最後の状態を設定
}

/* --- デストラクタ-- - */
Switch::~Switch()
{

}

/* --- スイッチギミックの初期化メソッド-- - */
int Switch::Init()
{
	gimmickImage[0] = LoadGraph(PathOfSwitchImage1);		// 状態1の時の画像の読み込み・ハンドル取得
	gimmickImage[1] = LoadGraph(PathOfSwitchImage2);		// 状態2の時の画像の読み込み・ハンドル取得

	if (gimmickImage[0] == -1 || gimmickImage[1] == -1)		// 読み込めていない画像があるなら
	{
		/* +++ エラーメッセージの表示 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"Switch.cpp: Can not load Switch's image.",
			"Image Error",
			MB_OK
		);

		return -1;	// -1を返す(初期化失敗)
	}

	return 0;
}

/* --- スイッチギミックの更新メソッド-- - */
void Switch::Update(Player* player)
{
	if (gimmickState == maxState)	// ギミックが最後の像体(起動済み)なら
	{
		if (isActive)	// ドアが起動状態なら
		{
			Inactivate();	// ドアを停止状態にする
		}

		return;		// 何もせずに終了
	}

	if (isActive)	// 起動状態なら
	{
		SetGimmickState(maxState);	// ギミックを最後の状態にする

		//Inactivate();	// 停止状態にする

		 Sound_Play(SE_Switch);		// スイッチのSEを再生
	}

	return;
}

/* --- スイッチギミックの描画メソッド-- - */
void Switch::Draw()
{
	POINT drawPoint = GetPoint(positionX, positionY);	// 描画する座標をPOINT型で取得

	/* +++ 状態に応じてスイッチを描画する +++ */
	switch (gimmickState)
	{
	case 1:
		/* +++ 状態1なら +++ */

		DrawGraphOnPoint(drawPoint, GimmickSize, GimmickSize, gimmickImage[0], TRUE);	// 状態1で描画
		break;
	case 2:
		/* +++ 状態2なら +++ */

		DrawGraphOnPoint(drawPoint, GimmickSize, GimmickSize, gimmickImage[1], TRUE);	// 状態2で描画
		break;
	}

	if (GameDebug >= 2)
	{
		DrawFormatStringToHandleAlign(positionX, positionY, FAlign_AllCenter, Color_LightGreen, KHDot_20_1, "%d", gimmickID);
	}

	return;
}

/* --- ゴール判定のメソッド(このギミックでは使用しない) --- */
bool Switch::IsGoal()
{
	return false;
}