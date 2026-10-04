/* === プレイヤークラスのソースファイル === */

#include "Player.h"
#include "Key.h"


/* --- コンストラクタ --- */
Player::Player()
{
	hp = PlayerMaxHP;
	speed = PlayerSpeed;

	inputVector = 5;
}

/* --- プレイヤーの初期化メソッド-- - */
void Player::Init()
{
	hp = PlayerMaxHP;
	speed = PlayerSpeed;

	inputVector = 5;

	return;
}

/* --- プレイヤーの更新メソッド --- */
void Player::Update()
{
	return;
}

/* --- プレイヤーの描画メソッド-- - */
void Player::Draw()
{
	return;
}

/* --- プレイヤーの移動メソッド --- */
void Player::MovePlayer()
{
	inputVector = GetInputVector();		// プレイヤーの入力方向を取得
	
	/* +++ 入力方向に応じてキャラクターを移動 +++ */
	switch (inputVector)
	{
	case 1:
		/* +++ 1方向(左下)なら +++ */

		MoveCharacter(-1 * speed, speed);	// 左下に移動
		break;
	case 2:
		/* +++ 2方向(下)なら +++ */

		MoveCharacter(0, speed);	// 下に移動
		break;
	case 3:
		/* +++ 3方向(右下)なら +++ */

		MoveCharacter(speed, speed);	// 右下に移動
		break;
	case 4:
		/* +++ 4方向(左)なら +++ */

		MoveCharacter(-1 * speed, 0);	// 左に移動
		break;
	case 6:
		/* +++ 6方向(右)なら +++ */

		MoveCharacter(speed, 0);	// 右に移動
		break;
	case 7:
		/* +++ 7方向(左上)なら +++ */

		MoveCharacter(-1 * speed, -1 * speed);	// 左上に移動
		break;
	case 8:
		/* +++ 8方向(上)なら +++ */

		MoveCharacter(0, -1 * speed);	// 上に移動
		break;
	case 9:
		/* +++ 9方向(右上)なら +++ */

		MoveCharacter(speed, -1 * speed);	// 右上に移動
		break;
	default:
		break;
	}

	return;
}
