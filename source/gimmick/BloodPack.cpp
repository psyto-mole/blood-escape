/* === 輸血パックのソースファイル === */

#include "BloodPack.h"


/* --- コンストラクタ --- */
BloodPack::BloodPack(int id, int x, int y, int state, int target) : ContactGimmick(id, x, y, state, target)
{
	gimmickType = GimmickType::BloodPack;	// ギミックの種類を「輸血パック」に設定

	gimmickImage = -1;	// ギミックの画像ハンドルの初期化

	maxState = BloodPackStateMax;	// 最後の状態を設定
}

/* --- デストラクタ --- */
BloodPack::~BloodPack()
{

}

/* --- 輸血パックの初期化メソッド --- */
int BloodPack::Init()
{
	return;
}

/* --- 輸血パックの更新メソッド --- */
void BloodPack::Update(Player* player)
{
	if (gimmickState == maxState)	// ギミックの状態が最後の状態(取得済み)なら
	{
		if (isActive)	// ドアが起動状態なら
		{
			Inactivate();	// ドアを停止状態にする
		}

		return;	// 何もせずに終了
	}

	if (isActive)
	{
		player->Transfusion(BloodPackTransfusion);	// 輸血のメソッドを実行

		SetGimmickState(maxState);	// ギミックを最後の状態(取得済み)に設定

		//SE_Play();
	}

	return;
}

/* --- 輸血パックの描画メソッド-- - */
void BloodPack::Draw()
{
	return;
}