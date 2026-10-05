/* === キャラクタークラスのソースファイル === */

#include "Character.h"


/* --- コンストラクタ --- */
Character::Character()
{
	SetCharacterNowPosition(0, 0);		// キャラクターの現在位置の初期化
	SetCharacterNextPosition(0, 0);		// キャラクターの現在位置の初期化

	maxHP = 0;		// 最大1HPを初期化
	hp = maxHP;		// キャラクターのHPを最大HPに設定
	speed = 0;		// キャラクターの移動速度の初帰化
}

/* --- デストラクタ-- - */
Character::~Character()
{
}

/* --- キャラクターの現在位置を取得するメソッド-- - */
POINT Character::GetCharacterNowPosition()
{
	return nowPosition;		// 現在位置を返す
}

/* --- キャラクターの移動後の位置を取得するメソッド　-- - */
POINT Character::GetCharacterNextPosition()
{
	return nextPosition;	// 移動後の位置を返す
}

/* --- キャラクターの現在位置を設定するメソッド --- */
void Character::SetCharacterNowPosition(int x, int y)
{
	nowPosition.x = x;	// プレイヤーの現在のX座標を設定
	nowPosition.y = y;	// プレイヤーの現在のY座標を設定

	return;
}

/* --- キャラクターの移動後の位置を設定するメソッド-- - */
void Character::SetCharacterNextPosition(int x, int y)
{
	nextPosition.x = x;		// プレイヤーの移動後のX座標を設定
	nextPosition.y = y;		// プレイヤーの移動後のY座標を設定

	return;
}

/* --- 引数で渡した値だけキャラクターを動かすメソッド-- - */
void Character::MoveCharacter(int x, int y)
{
	int newX, newY;		// 移動後の座標

	newX = nowPosition.x + x;	// 現在のX座標に引数の値を加算
	newY = nowPosition.y + y;	// 現在のY座標に引数の値を加算

	SetCharacterNextPosition(newX, newY);	// 移動後の位置を変更する

	return;
}

/* --- キャラクターの現在位置を設定するメソッド(引数がPOINT型) -- - */
void Character::SetCharacterNowPosition(POINT position)
{
	nowPosition.x = position.x;		// プレイヤーの現在のX座標を設定
	nowPosition.y = position.y;		// プレイヤーの現在のY座標を設定

	return;
}

/* --- キャラクターの移動後の位置を設定するメソッド(引数がPOINT型) -- - */
void Character::SetCharacterNextPosition(POINT position)
{
	nextPosition.x = position.x;	// プレイヤーの移動後のX座標を設定
	nextPosition.y = position.y;	// プレイヤーの移動後のY座標を設定

	return;
}

/* --- 引数で渡した値だけキャラクターを動かすメソッド(引数がPOINT型) -- - */
void Character::MoveCharacter(POINT position)
{
	int newX, newY;		// 移動後の座標

	newX = nowPosition.x + position.x;	// 現在のX座標に引数の値を加算
	newY = nowPosition.y + position.y;	// 現在のY座標に引数の値を加算

	SetCharacterNextPosition(newX, newY);	// 移動後の位置を変更する

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