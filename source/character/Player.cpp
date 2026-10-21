/* === プレイヤークラスのソースファイル === */

#include "Player.h"
#include "Image.h"
#include "Key.h"
#include "Color.h"
#include "Font.h"
#include "Sound.h"
#include "Geometry.h"
#include "RectParameter.h"
#include "Animation.h"


/* --- コンストラクタ --- */
Player::Player()
{
	SetCharacterPosition(0, 0);		// キャラクターの現在位置の初期化

	maxHP = PlayerMaxHP;	// 最大HPを初期化
	hp = maxHP;				// HPを最大HPに設定
	speed = PlayerSpeed;	// 移動速度を初期化

	maxHPBar = GetRect(PlayerHPBarUpperLeftX, PlayerHPBarUpperLeftY, PlayerHPBarUpperLeftX + maxHP + 1, PlayerHPBarLowerRightY);
	hpBar = GetRect(PlayerHPBarUpperLeftX, PlayerHPBarUpperLeftY, PlayerHPBarUpperLeftX + hp + 1, PlayerHPBarLowerRightY);

	interactCollider = GetRect(0, 0, 0, 0);

	isBleeding = false;

	inputVector = 5;			// 入力方向を5(ニュートラル)に設定
	pastFacingDirection = 5;	// プレイヤーが前に向いていた向きを5に設定

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
	hp = maxHP;
	speed = PlayerSpeed;

	maxHPBar = GetRect(PlayerHPBarUpperLeftX, PlayerHPBarUpperLeftY, PlayerHPBarUpperLeftX + maxHP + 1, PlayerHPBarLowerRightY);
	hpBar = GetRect(PlayerHPBarUpperLeftX, PlayerHPBarUpperLeftY, PlayerHPBarUpperLeftX + hp + 1, PlayerHPBarLowerRightY);

	isBleeding = false;

	inputVector = 5;			// 入力方向を5(ニュートラル)に設定
	pastFacingDirection = 5;	// プレイヤーが前に向いていた向きを5に設定

	return;
}

/* --- プレイヤーの更新メソッド --- */
void Player::Update(Map* mapManager, GimmickManager* gimmickManager)
{
	if (hp <= 0)	// HPが0以下なら
	{
		return;		// 何もせずに終了
	}

	int interactGimmickID;		// インタラクトを行うギミックのID

	inputVector = GetInputVector();		// プレイヤーの入力方向を取得

	if (inputVector != 5)	// 入力方向が5(ニュートラル)でないなら
	{
		pastFacingDirection = inputVector;	// プレイヤーが向いていた方向を更新
	}

	MovePlayer(mapManager, gimmickManager);		// 移動処理を行う

	if (mapManager->IsThereTile(characterPosition) != true)		// 移動後の位置に足場が無ければ
	{
		Falling();	// 落下メソッドを実行

		return;		// 処理を終了
	}

	interactCollider = GenerateInteractCollision();		// インタラクトの判定を生成

	interactGimmickID = gimmickManager->GetGimmickIDWithinRange(interactCollider);	// インタラクトの範囲にあるギミックのIDを取得

	if (Key_Check_Click(KEY_INPUT_RETURN))	// エンターキーがクリックされたら
	{
		InteractGimmick(gimmickManager, interactGimmickID);		// インタラクトメソッドを実行
	}
	else if (Key_Check_Click(KEY_INPUT_SPACE))	// スペースキーがクリックされたら
	{
		SelfHarm(gimmickManager, interactGimmickID);	// 自傷メソッドを実行
	}

	ProcessBleeding();	// 出血の処理を行う

	hpBar = GetRect(PlayerHPBarUpperLeftX, PlayerHPBarUpperLeftY, PlayerHPBarUpperLeftX + hp + 1, PlayerHPBarLowerRightY);	// HPバーのサイズを再定義

	return;
}

/* --- プレイヤーの描画メソッド-- - */
void Player::Draw()
{
	if (hp <= 0)	// HPが0以下なら
	{
		return;		// 何もせずに終了
	}

	PlayerAnimation();	// アニメーションを描画

	DrawInteractCollision();	// インタラクトの判定を描画

	DrawPlayerUI();

	return;
}

/* --- プレイヤーの移動メソッド --- */
void Player::MovePlayer(Map* mapManager, GimmickManager* gimmickManager)
{	
	/* +++ 入力方向に応じてキャラクターを移動 +++ */
	switch (inputVector)
	{
	case 1:
		/* +++ 1方向(左下)なら +++ */

		/* +++ 左下に移動 +++ */
		MoveCharacter(mapManager, gimmickManager, -1 * speed, 0);
		MoveCharacter(mapManager, gimmickManager, 0, speed);
		break;
	case 2:
		/* +++ 2方向(下)なら +++ */

		MoveCharacter(mapManager, gimmickManager, 0, speed);	// 下に移動
		break;
	case 3:
		/* +++ 3方向(右下)なら +++ */

		/* +++ 右下に移動 +++ */
		MoveCharacter(mapManager, gimmickManager, speed, 0);
		MoveCharacter(mapManager, gimmickManager, 0, speed);
		break;
	case 4:
		/* +++ 4方向(左)なら +++ */

		MoveCharacter(mapManager, gimmickManager, -1 * speed, 0);	// 左に移動
		break;
	case 6:
		/* +++ 6方向(右)なら +++ */

		MoveCharacter(mapManager, gimmickManager, speed, 0);	// 右に移動
		break;
	case 7:
		/* +++ 7方向(左上)なら +++ */

		/* +++ 左上に移動 +++ */
		MoveCharacter(mapManager, gimmickManager, -1 * speed, 0);
		MoveCharacter(mapManager, gimmickManager, 0, -1 * speed);
		break;
	case 8:
		/* +++ 8方向(上)なら +++ */

		MoveCharacter(mapManager, gimmickManager, 0, -1 * speed);	// 上に移動
		break;
	case 9:
		/* +++ 9方向(右上)なら +++ */

		/* +++ 右上に移動 +++ */
		MoveCharacter(mapManager, gimmickManager, speed, 0);
		MoveCharacter(mapManager, gimmickManager, 0, -1 * speed);
		break;
	default:
		break;
	}

	return;
}

/* --- インタラクト(通常ギミックに作用する)メソッド-- - */
void Player::InteractGimmick(GimmickManager* gimmickManager, int gimmickID)
{
	if (gimmickManager->GetGimmickTag(gimmickID) == GimmickTag::Normal)		// ギミックが通常ギミックなら
	{
		gimmickManager->ActivateGimmick(gimmickID);		// ギミックの状態を進める

		Sound_Play(SE_Interact);	// ギミック操作時のSEを再生
	}

	return;
}

/* --- 自傷(出血ギミックに作用する)メソッド-- - */
void Player::SelfHarm(GimmickManager* gimmickManager, int gimmickID)
{
	TakeDamage(DamageOfSelfHarm);	// 自傷の被ダメージを受ける

	if (gimmickManager->GetGimmickTag(gimmickID) == GimmickTag::Blood)		// ギミックが出血ギミックなら
	{
		gimmickManager->ActivateGimmick(gimmickID);		// ギミックの状態を進める
	}

	Sound_Play(SE_SelfHarm);	// 自傷のSEを再生

	return;
}

/* --- 出血の処理メソッド-- - */
void Player::ProcessBleeding()
{
	if (isBleeding)		// 出血状態なら
	{
		Calc_HP(1, TRUE);	// 1のスリップダメージを受ける

		Sound_Play(SE_Bleeding);	// 出血のSEを再生
	}

	return;
}

/* --- 出血状態にするメソッド-- - */
void Player::SetBleedingTrue()
{
	isBleeding = true;	// 出血状態にする

	return;
}

/* --- 出血状態を解除するメソッド-- - */
void Player::SetBleedingFalse()
{
	isBleeding = false;		// 出血状態にする

	return;
}

/* --- 被ダメージのメソッド-- - */
void Player::TakeDamage(int value)
{
	Calc_HP(value, TRUE);	// HPを減らす

	SetBleedingTrue();	// 出血状態にする

	return;
}

/* --- 輸血メソッド --- */
void Player::Transfusion(int value)
{
	Calc_HP(value, FALSE);	// HPを増やす

	return;
}

/* --- 落下のメソッド --- */
void Player::Falling()
{
	Set_HP(0);	// プレイヤーのHPを0にする

	return;
}

/* --- ゲームオーバーの判定メソッド --- */
bool Player::IsGameOver()
{
	if (hp <= 0)	// HPが0以下なら
	{
		// ゲームオーバーの演出

		//SE_Play()

		return true;	// true(ゲームオーバー)を返す
	}

	return false;	// falseを返す
}

/* --- プレイヤーのアニメーションメソッド-- - */
void Player::PlayerAnimation()
{
	/* +++ 入力方向に応じてキャラクターを描画 +++ */
	switch (inputVector)
	{
	case 1:
		/* +++ 1方向(左下)なら +++ */

		DrawTurnGraphOnPoint(characterPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[3], FALSE);
		break;
	case 2:
		/* +++ 2方向(下)なら +++ */

		if (isBleeding)
		{
			DrawGraphOnPoint(characterPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[2], FALSE);
		}
		else
		{
			DrawGraphOnPoint(characterPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[1], FALSE);
		}
		break;
	case 3:
		/* +++ 3方向(右下)なら +++ */

		if (isBleeding)
		{
			DrawGraphOnPoint(characterPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[4], FALSE);
		}
		else
		{
			DrawGraphOnPoint(characterPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[3], FALSE);
		}
		break;
	case 4:
		/* +++ 4方向(左)なら +++ */

		DrawTurnGraphOnPoint(characterPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[5], FALSE);
		break;
	case 6:
		/* +++ 6方向(右)なら +++ */

		if (isBleeding)
		{
			DrawGraphOnPoint(characterPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[6], FALSE);
		}
		else
		{
			DrawGraphOnPoint(characterPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[5], FALSE);
		}
		break;
	case 7:
		/* +++ 7方向(左上)なら +++ */

		DrawTurnGraphOnPoint(characterPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[7], FALSE);
		break;
	case 8:
		/* +++ 8方向(上)なら +++ */

		DrawGraphOnPoint(characterPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[8], FALSE);
		break;
	case 9:
		/* +++ 9方向(右上)なら +++ */

		DrawGraphOnPoint(characterPosition, PlayerAnimationSizeX, PlayerAnimationSizeY, playerAnimation[7], FALSE);
		break;
	default:
		break;
	}

	return;
}

/* --- プレイヤーのインタラクト判定の生成メソッド --- */
RECT Player::GenerateInteractCollision()
{
	int interactX = 0;	// インタラクト判定の中心のX座標
	int interactY = 0;	// インタラクト判定の中心のY座標
	RECT collision;		// インタラクト判定

	/* +++ プレイヤーが向いている(向いていた)向きに応じてインタラクト判定の座標を設定 +++ */
	switch (pastFacingDirection)
	{
	case 1:
		/* +++ 1方向なら +++ */

		/* +++ プレイヤーの左側に中心座標を設定 +++ */
		interactX = characterPosition.x - (PlayerInteractRextWidth / 2);
		interactY = characterPosition.y;
		break;
	case 2:
		/* +++ 2方向なら +++ */

		/* +++ プレイヤーの下側に中心座標を設定 +++ */
		interactX = characterPosition.x;
		interactY = characterPosition.y + (PlayerInteractRextHeight / 2);
		break;
	case 3:
		/* +++ 3方向なら +++ */

		/* +++ プレイヤーの右側に中心座標を設定 +++ */
		interactX = characterPosition.x + (PlayerInteractRextWidth / 2);
		interactY = characterPosition.y;
		break;
	case 4:
		/* +++ 4方向なら +++ */

		/* +++ プレイヤーの左側に中心座標を設定 +++ */
		interactX = characterPosition.x - (PlayerInteractRextWidth / 2);
		interactY = characterPosition.y;
		break;
	case 6:
		/* +++ 6方向なら +++ */

		/* +++ プレイヤーの右側に中心座標を設定 +++ */
		interactX = characterPosition.x + (PlayerInteractRextWidth / 2);
		interactY = characterPosition.y;
		break;
	case 7:
		/* +++71方向なら +++ */

		/* +++ プレイヤーの左側に中心座標を設定 +++ */
		interactX = characterPosition.x - (PlayerInteractRextWidth / 2);
		interactY = characterPosition.y;
		break;
	case 8:
		/* +++ 8方向なら +++ */

		/* +++ プレイヤーの上側に中心座標を設定 +++ */
		interactX = characterPosition.x;
		interactY = characterPosition.y - (PlayerInteractRextHeight / 2);
		break;
	case 9:
		/* +++ 9方向なら +++ */

		/* +++ プレイヤーの右側に中心座標を設定 +++ */
		interactX = characterPosition.x + (PlayerInteractRextWidth / 2);
		interactY = characterPosition.y;
		break;
	}

	collision = GetRectOnPoint(interactX, interactY, PlayerInteractRextWidth, PlayerInteractRextHeight);		// インタラクト判定を取得

	return collision;	// 生成した判定を返す
}

/* --- プレイヤーのインタラクト判定の描画メソッド-- - */
void Player::DrawInteractCollision()
{
	DrawRect(interactCollider, Color_LightGreen, false, 1);		// インタラクト判定を緑の枠で描画
	
	return;
}

/* --- プレイヤーのUIの描画メソッド-- - */
void Player::DrawPlayerUI()
{
	DrawFormatStringToHandleAlign(							// 「HP/最大HP」を描画
		PlayerHPBarUpperLeftX - 50, PlayerHPBarCenterY,
		FAlign_AllCenter, Color_White, KHDot_30_1,
		"%d/%d", hp, maxHP
	);
	DrawRect(maxHPBar, Color_Purple, true, 1);	// 最大HPを描画
	DrawRect(hpBar, Color_Red, true, 1);		// HPを描画

	return;
}