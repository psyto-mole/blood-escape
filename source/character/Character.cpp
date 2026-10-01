/* === キャラクタークラスのソースファイル === */

#include "Character.h"


/* --- コンストラクタ --- */
Character::Character()
{
	positionX = 0;	// キャラクターの現在位置のX座標の初期化
	positionY = 0;	// キャラクターの現在位置のY座標の初期化

	characterImage = -1;		// キャラクターの画像ハンドルの初期化

	hp = 0;		// キャラクターのHPの初期化
	speed = 0;	// キャラクターの移動速度の初帰化
}

/* --- デストラクタ-- - */
Character::~Character()
{
	if (characterImage != -1)
	{
		DeleteGraph(characterImage);
	}
}

/* --- キャラクターの位置を設定するメソッド --- */
void Character::SetCharacterPosition(int x, int y)
{
	if()	// 移動先に障害物がなければ
	positionX = x;
	positionY = y;

	return;
}

/* --- 引数で渡した値だけキャラクターを動かすメソッド-- - */
void Character::MoveCharacter(int x, int y)
{
	int newX, newY;		// 移動後の座標

	newX = positionX + x;	// 現在のX座標に引数の値を加算
	newY = positionY + y;	// 現在のY座標に引数の値を加算

	SetCharacterPosition(newX, newY);

	return;
}