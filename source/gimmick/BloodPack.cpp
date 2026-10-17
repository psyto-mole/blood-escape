/* === 輸血パックのソースファイル === */

#include "BloodPack.h"
#include "Geometry.h"
#include "Image.h"


/* --- コンストラクタ --- */
BloodPack::BloodPack(int id, int x, int y, int state, int target) : ContactGimmick(id, x, y, state, target)
{
	gimmickType = GimmickType::BloodPack;	// ギミックの種類を「輸血パック」に設定

	maxState = BloodPackStateMax;	// 最後の状態を設定
}

/* --- デストラクタ --- */
BloodPack::~BloodPack()
{

}

/* --- 輸血パックの初期化メソッド --- */
int BloodPack::Init()
{
	gimmickImage[0] = LoadGraph(PathOfBloodPackImage);		// 画像の読み込み・ハンドル取得

	if (gimmickImage[0] == -1)	// 画像が読み込めていないなら
	{
		/* +++ エラーメッセージの表示 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"BloodPack.cpp: Can not load BloodPaxk's image.",
			"Image Error",
			MB_OK
		);

		return -1;	// -1を返す(初期化失敗)
	}

	return;
}

/* --- 輸血パックの更新メソッド --- */
void BloodPack::Update(Player* player)
{
	if (gimmickState == maxState)	// ギミックの状態が最後の状態(取得済み)なら
	{
		if (isActive)	// 輸血パックが起動状態なら
		{
			Inactivate();	// 輸血パックを停止状態にする
		}

		return;	// 何もせずに終了
	}

	if (isActive)	// 起動状態なら
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