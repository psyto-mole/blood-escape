/* === 輸血パックのソースファイル === */

#include "BloodPack.h"


/* --- コンストラクタ --- */
BloodPack::BloodPack(int id, int x, int y, int state, int target) : OneShotGimmick(id, x, y, state, target)
{
	gimmickType = GimmickType::BloodPack;	// ギミックの種類を「輸血パック」に設定

	gimmickImage = -1;	// ギミックの画像ハンドルの初期化
}

/* --- デストラクタ --- */
BloodPack::~BloodPack()
{

}

/* --- 輸血パックの初期化メソッド --- */
void BloodPack::Init()
{
	return;
}

/* --- 輸血パックの更新メソッド --- */
void BloodPack::Update()
{
	return;
}

/* --- 輸血パックの描画メソッド-- - */
void BloodPack::Draw()
{
	return;
}