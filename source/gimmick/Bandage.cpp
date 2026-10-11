/* === 包帯のソースファイル === */

#include "Bandage.h"


/* --- コンストラクタ-- - */
Bandage::Bandage(int id, int x, int y, int state, int target) : ContactGimmick(id, x, y, state, target)
{
	gimmickType = GimmickType::Bandage;		// ギミックの種類を「包帯」に設定

	gimmickImage = -1;	// ギミックの画像ハンドルの初期化

	maxState = BandageStateMax;		// 最後の状態を設定
}

/* --- デストラクタ-- - */
Bandage::~Bandage()
{

}

/* --- 包帯の初期化メソッド-- - */
void Bandage::Init()
{
	return;
}

/* --- 包帯の更新メソッド-- - */
void Bandage::Update(Player* player)
{
	if (gimmickState == maxState)	// 最後の状態(取得済み)なら
	{
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
	// 描画

	return;
}