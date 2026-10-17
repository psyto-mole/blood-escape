/* === 包帯のソースファイル === */

#include "Bandage.h"
#include "Geometry.h"
#include "Image.h"


/* --- コンストラクタ-- - */
Bandage::Bandage(int id, int x, int y, int state, int target) : ContactGimmick(id, x, y, state, target)
{
	gimmickType = GimmickType::Bandage;		// ギミックの種類を「包帯」に設定

	maxState = BandageStateMax;		// 最後の状態を設定
}

/* --- デストラクタ-- - */
Bandage::~Bandage()
{

}

/* --- 包帯の初期化メソッド-- - */
int Bandage::Init()
{
	gimmickImage[0] = LoadGraph(PathOfBandageImage);		// 画像の読み込み・ハンドル取得

	if (gimmickImage[0] == -1)		// 画像が読み込めていないなら
	{
		/* +++ エラーメッセージの表示 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"Bandage.cpp: Can not load Bandage's image.",
			"Image Error",
			MB_OK
		);

		return -1;	// -1を返す(初期化失敗)
	}

	return;
}

/* --- 包帯の更新メソッド-- - */
void Bandage::Update(Player* player)
{
	if (gimmickState == maxState)	// 最後の状態(取得済み)なら
	{
		if (isActive)	// 包帯が起動状態なら
		{
			Inactivate();	// 包帯を停止状態にする
		}

		return;		// 何もせずに処理を終了
	}

	if (isActive)	// 起動していれば
	{
		player->SetBleedingFalse();		// 出血状態を解除

		SetGimmickState(maxState);	// ギミックを最後の状態(取得済み)に設定

		//SE_Play();
	}

	return;
}

/* --- 包帯の描画メソッド-- - */
void Bandage::Draw()
{
	if (gimmickState == 2)	// 最後の状態(取得済み)なら
	{
		return;		// 何もせずに終了
	}

	POINT drawPoint = GetPoint(positionX, positionY);

	DrawGraphOnPoint(drawPoint, GimmickSize, GimmickSize, gimmickImage[0], FALSE);	// 包帯を描画

	return;
}