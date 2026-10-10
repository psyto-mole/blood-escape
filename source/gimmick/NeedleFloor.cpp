/* === 針床のクラスのソースファイル === */

#include "NeedleFloor.h"


/* --- コンストラクタ --- */
NeedleFloor::NeedleFloor(int id, int x, int y, int state, int target) : ContactGimmick(id, x, y, state, target)
{
	gimmickType = GimmickType::NeedleFloor;	// ギミックの種類を「針床」に設定

	gimmickImage = -1;	// ギミックの画像ハンドルの初期化

	maxState = NeedleFloorStateMax;		// 最後の状態を0に設定
}

/* --- デストラクタ --- */
NeedleFloor::~NeedleFloor()
{

}

/* --- 針床の初期化メソッド --- */
void NeedleFloor::Init()
{
	return;
}

/* --- 針床の更新メソッド --- */
void NeedleFloor::Update(Player* player)
{
	if (isActive)
	{
		if (isContact)
		{
			return;
		}
		else
		{
			player->TakeDamage(NeedleFloorDamage);

			SetGimmickState(1);		// ギミックの状態を1に設定

			//SE_Play();

			isContact = true;
		}
	}
	else
	{
		isContact = false;
	}

	return;
}

/* --- 針床の描画メソッド --- */
void NeedleFloor::Draw()
{
	/* +++ 針床の状態に応じて描画を変える +++ */
	switch (gimmickState)
	{
	case 0:
		/* +++ 状態0(初期状態)の場合 +++ */

		// 通常の針床を描画
		break;
	case 1:
		/* +++ 状態1の場合 +++ */

		//血濡れの針床を描画
		break;
	}

	return;
}