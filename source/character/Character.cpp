/* === キャラクタークラスのソースファイル === */

#include "Character.h"
#include "GameManager.h"
#include "Font.h"
#include "Color.h"
#include "GimmickManager.h"
#include "Map.h"


/* --- コンストラクタ --- */
Character::Character()
{
	SetCharacterPosition(0, 0);		// キャラクターの現在位置の初期化

	maxHP = 0;		// 最大1HPを初期化
	hp = maxHP;		// キャラクターのHPを最大HPに設定
	speed = 0;		// キャラクターの移動速度の初帰化

	width = 0;		// キャラクターの幅を初期化
	height = 0;		// キャラクターの高さを初期化
}

/* --- デストラクタ-- - */
Character::~Character()
{
}

/* --- キャラクターの現在位置を取得するメソッド-- - */
POINT Character::GetCharacterPosition()
{
	return characterPosition;		// 現在位置を返す
}

/* --- キャラクターの現在位置を設定するメソッド --- */
void Character::SetCharacterPosition(int x, int y)
{
	characterPosition.x = x;	// プレイヤーの現在のX座標を設定
	characterPosition.y = y;	// プレイヤーの現在のY座標を設定

	return;
}

/* --- キャラクターの現在位置を設定するメソッド(引数がPOINT型) -- - */
void Character::SetCharacterPosition(POINT position)
{
	characterPosition.x = position.x;		// プレイヤーの現在のX座標を設定
	characterPosition.y = position.y;		// プレイヤーの現在のY座標を設定

	return;
}

/* --- 引数で渡した値だけキャラクターを動かすメソッド-- - */
void Character::MoveCharacter(Map* mapManager, GimmickManager* gimmickManager,int x, int y)
{
	POINT nextPosition;	// 移動後の座標

	nextPosition.x = characterPosition.x + x;		// 現在のX座標に引数の値を加算
	nextPosition.y = characterPosition.y + y;		// 現在のY座標に引数の値を加算


	if (mapManager->IsPassable(nextPosition) && gimmickManager->IsPassable(nextPosition))	// 移動後の座標が侵入可能なら
	{
		SetCharacterPosition(nextPosition);	// 現在位置を移動後の座標に変更
	}
	else
	{
		if (GameDebug == 2)
		{
			if (mapManager->IsPassable(nextPosition) != true)
			{
				DrawFormatStringToHandleAlign(GameWindowWidth - 300, GameWindowHeight / 2 + 200, FAlign_AllCenter, Color_Red, KHDot_30_1, "Map is not Passable");
			}

			if (gimmickManager->IsPassable(nextPosition) != true)
			{
				DrawFormatStringToHandleAlign(GameWindowWidth - 300, GameWindowHeight / 2 + 250, FAlign_AllCenter, Color_Violet, KHDot_30_1, "Gimmick is not Passable");
			}
		}
	}

	return;
}

/* --- 引数で渡した値だけキャラクターを動かすメソッド(引数がPOINT型) -- - */
void Character::MoveCharacter(Map* mapManager, GimmickManager* gimmickManager, POINT position)
{
	POINT nextPosition;	// 移動後の座標

	nextPosition.x = characterPosition.x + position.x;	// 現在のX座標に引数の値を加算
	nextPosition.y = characterPosition.y + position.y;	// 現在のY座標に引数の値を加算


	if (mapManager->IsPassable(nextPosition) && gimmickManager->IsPassable(nextPosition))	// 移動後の座標が侵入可能なら
	{
		SetCharacterPosition(nextPosition);	// 現在位置を移動後の座標に変更
	}

	return;
}

/* --- HPを指定した値に設定する --- */
void Character::Set_HP(int value)
{
	hp = value;		// HPを引数で渡した値に設定する

	if (hp >= maxHP)	// HPが最大HP以上なら
	{
		hp = maxHP;		// HPを最大HPの値にする
	}
	else if (hp < 0)	// HPが0以下であれば
	{
		hp = 0;		// HPを0にする
	}

	return;
}

/* --- HPを増減させるメソッド-- - */
void Character::Calc_HP(int value, int isDamage)
{
	if (isDamage == TRUE)
	{
		hp -= value;

		if (hp <= 0)
		{
			hp = 0;
		}
	}
	else
	{
		hp += value;

		if (hp >= maxHP)
		{
			hp = maxHP;
		}
	}

	return;
}

/* --- HPを取得するメソッド-- - */
int Character::Get_HP()
{
	return hp;
}

/* --- 最大HPを取得するメソッド-- - */
int Character::Get_MaxHP()
{
	return maxHP;
}