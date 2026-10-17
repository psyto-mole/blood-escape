/* === 祭壇ギミックのソースファイル === */

#include "Altar.h"
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
		if (isActive)	// ドアが起動状態なら
		{
			Inactivate();	// ドアを停止状態にする
		}

		return;		// 何もせずに終了
	}

	if (isActive)	// 祭壇が起動しているなら
	{
		SetGimmickState(maxState);	// ギミックを最後の状態にする

		Inactivate();	// 祭壇を停止状態にする

		//SE_Play();
	}

	return;
}

/* --- 祭壇の描画メソッド --- */
void Altar::Draw()
{
	return;
}