/* === ドアギミックのソースファイル === */

#include "Door.h"


/* --- コンストラクタ --- */
Door::Door(int id, int x, int y, int state, int target) : Gimmick(id, x, y, state, target)
{
	gimmickTag = GimmickTag::Normal;	// ギミックのタグを「通常ギミック」に設定

	gimmickType = GimmickType::Door;	// ギミックの種類を「ドアギミック」に設定

	gimmickImage = -1;	// ギミックの画像ハンドルの初期化

	maxState = DoorStateMax;	// 最後の状態を1設定
}

/* --- デストラクタ --- */
Door::~Door()
{
	
}

/* --- ドアギミックの初期化メソッド --- */
int Door::Init()
{
	return;
}

/* --- ドアギミックの更新メソッド --- */
void Door::Update(Player* player)
{
	if (gimmickState == maxState)	// ドアが最後の状態(開門済み)なら
	{
		if (isActive)	// ドアが起動状態なら
		{
			Inactivate();	// ドアを停止状態にする
		}

		return;		// 処理を終了
	}

	if (isActive)	// ドアが起動しているなら
	{
		SetGimmickState(maxState);	// ドアを最後の状態にする

		Inactivate();	// ドアを停止する

		//SEW_Play();
	}

	return;
}

/* --- ドアギミックの描画メソッド --- */
void Door::Draw()
{
	return;
}