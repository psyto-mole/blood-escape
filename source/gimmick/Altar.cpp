/* === 祭壇ギミックのソースファイル === */

#include "Altar.h"


/* --- コンストラクタ --- */
Altar::Altar(int id, int x, int y, int state, int target) : BloodGimmick(id, x, y, state, target)
{
	gimmickType = GimmickType::Altar;	// ギミックの種類を「祭壇」に設定

	gimmickImage = -1;	// ギミックの画像ハンドルの初期化

	maxState = AltarStateMax;	// 最後の状態を設定
}

/* --- デストラクタ --- */
Altar::~Altar()
{

}

/* --- 祭壇の初期化メソッド --- */
void Altar::Init()
{
	return;
}

/* --- 祭壇の更新メソッド --- */
void Altar::Update(Player* player)
{
	if (gimmickState == maxState)	// ギミックの状態が最後の状態(起動済み)なら
	{
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