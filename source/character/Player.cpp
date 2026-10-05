/* === プレイヤークラスのソースファイル === */

#include "Player.h"
#include"Image.h"
#include "Key.h"
#include "Geometry.h"
#include "Animation.h"


/* --- コンストラクタ --- */
Player::Player()
{
	SetCharacterNowPosition(0, 0);		// キャラクターの現在位置のX座標の初期化
	SetCharacterNextPosition(0, 0);		// キャラクターの現在位置のY座標の初期化

	hp = PlayerMaxHP;		// HPを初期化
	speed = PlayerSpeed;	// 移動速度を初期化

	isBleeding = false;

	inputVector = 5;		// 入力方向を5(ニュートラル)に設定

	// アニメーション画像を読み込み
	LoadDivGraph(
		PlayerAnimationPath, 
		PlayerAnimationDivNum, 
		PlayerAnimationDivX, PlayerAnimationDivY, 
		PlayerAnimationSizeX, PlayerAnimationSizeY, 
		playerAnimation
	);
}

/* --- プレイヤーの初期化メソッド-- - */
void Player::Init()
{
	hp = PlayerMaxHP;
	speed = PlayerSpeed;

	isBleeding = false;

	inputVector = 5;

	return;
}

/* --- プレイヤーの更新メソッド --- */
void Player::Update(Map* mapManager, GimmickManager* gimmickManager)
{
	inputVector = GetInputVector();		// プレイヤーの入力方向を取得

	MovePlayer();

	if (mapManager->GetTile(nextPosition) == 1)		// 移動後の座標が侵入可能なら
	{
		SetCharacterNowPosition(nextPosition);
	}

	return;
}

/* --- プレイヤーの描画メソッド-- - */
void Player::Draw()
{
	PlayerAnimation();	// アニメーションを描画

	return;
}

/* --- プレイヤーの移動メソッド --- */
void Player::MovePlayer()
{	
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

/* --- プレイヤーのアニメーションメソッド-- - */
void Player::PlayerAnimation()
{
	/* +++ 入力方向に応じてキャラクターを描画 +++ */
	switch (inputVector)
	{
	case 1:
		/* +++ 1方向(左下)なら +++ */

		DrawTurnGraphOnPoint(nowPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[3], FALSE);
		break;
	case 2:
		/* +++ 2方向(下)なら +++ */

		if (isBleeding)
		{
			DrawGraphOnPoint(nowPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[2], FALSE);
		}
		else
		{
			DrawGraphOnPoint(nowPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[1], FALSE);
		}
		break;
	case 3:
		/* +++ 3方向(右下)なら +++ */

		if (isBleeding)
		{
			DrawGraphOnPoint(nowPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[4], FALSE);
		}
		else
		{
			DrawGraphOnPoint(nowPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[3], FALSE);
		}
		break;
	case 4:
		/* +++ 4方向(左)なら +++ */

		DrawTurnGraphOnPoint(nowPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[5], FALSE);
		break;
	case 6:
		/* +++ 6方向(右)なら +++ */

		if (isBleeding)
		{
			DrawGraphOnPoint(nowPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[6], FALSE);
		}
		else
		{
			DrawGraphOnPoint(nowPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[5], FALSE);
		}
		break;
	case 7:
		/* +++ 7方向(左上)なら +++ */

		DrawTurnGraphOnPoint(nowPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[7], FALSE);
		break;
	case 8:
		/* +++ 8方向(上)なら +++ */

		DrawGraphOnPoint(nowPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[8], FALSE);
		break;
	case 9:
		/* +++ 9方向(右上)なら +++ */

		DrawGraphOnPoint(nowPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[7], FALSE);
		break;
	default:
		break;
	}

	return;
}