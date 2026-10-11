/* === スイッチギミックのソースファイル === */

#include "Switch.h"


/* --- コンストラクタ-- - */
Switch::Switch(int id, int x, int y, int state, int target) : Gimmick(id, x, y, state, target)
{
	gimmickTag = GimmickTag::Normal;	// ギミックのタグを「通常ギミック」に設定

	gimmickType = GimmickType::Switch;	// ギミックの種類を「スイッチ」に設定

	gimmickImage = -1;	// ギミックの画像ハンドルの初期化

	maxState = SwitchStateMax;	// 最後の状態を設定
}

/* --- デストラクタ-- - */
Switch::~Switch()
{

}

/* --- スイッチギミックの初期化メソッド-- - */
void Switch::Init()
{
	return;
}

/* --- スイッチギミックの更新メソッド-- - */
void Switch::Update(Player* player)
{
	if (gimmickState == maxState)	// ギミックが最後の像体(起動済み)なら
	{
		return;		// 何もせずに終了
	}

	if (isActive)
	{
		SetGimmickState(maxState);	// ギミックを最後の状態にする

		Inactivate();	// 停止状態にする

		// SE_Play();
	}

	return;
}

/* --- スイッチギミックの描画メソッド-- - */
void Switch::Draw()
{
	return;
}