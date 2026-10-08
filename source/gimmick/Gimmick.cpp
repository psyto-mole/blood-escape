/* === ギミッククラスのソースファイル === */

#include "Gimmick.h"


/* --- コンストラクタ --- */
Gimmick::Gimmick(int id, int x, int y)
{
	gimmickID = id;		// ギミックのIDの初期化

	gimmickType = GimmickType::None;	// ギミックの種類を「なし」に設定

	positionX = 0;	// ギミックのX座標の初期化
	positionY = 0;	// ギミックのY座標の初期化

	gimmickImage = -1;	// ギミックの画像ハンドルの初期化

	gimmickState = 0;		// ギミックの状態の初期化
	maxState = 0;			// 最後の状態を0に設定
	isRoopState = false;	// 状態がループしないように設定

	targetID = -1;	// 連動するギミックのIDの初期化

	isPassable = false;		// ギミックを「通行不可」に設定
}

/* --- デストラクタ --- */
Gimmick::~Gimmick()
{
	if (gimmickImage != -1)
	{
		DeleteGraph(gimmickImage);
	}
}

/* --- ギミックのIDを取得するメソッド --- */
int Gimmick::GetGimmickID()
{
	return gimmickID;	// IDを返す
}

/* --- ギミックの種類を取得するメソッド --- */
GimmickType Gimmick::GetGimmickType()
{
	return gimmickType;		// ギミックの種類を返す
}

/* --- ギミックの位置をPOINT型で取得するメソッド --- */
POINT Gimmick::GetGimmickPosition()
{
	POINT position;		// POINT型の変数

	position.x = positionX;		// POINT型の変数のX座標にギミックのX座標を代入
	position.y = positionY;		// POINT型の変数のY座標にギミックのY座標を代入

	return position;	// POINT型変数を返す
}

/* --- ギミックの状態を取得するメソッド --- */
int Gimmick::GetGimmickState()
{
	return gimmickState;	// ギミックの状態を返す
}

// ギミックを指定した状態に変える
void Gimmick::SetGimmickState(int state)
{
	gimmickState = state;	// ギミックを指定した状態に設定

	return;
}

// ギミックの状態を進める
void Gimmick::AdvanceGimmickState()
{
	gimmickState = gimmickState + 1;	// 状態を1つ進める

	if (gimmickState > maxState)	// 状態がそのギミックの撮り得る最後の状態を超えたなら
	{
		if (isRoopState)	// 状態がループするギミックなら
		{
			gimmickState = 0;	// 状態を初期化する
		}
		else
		{
			gimmickState = maxState;	// 状態を最後の状態に設定
		}
	}

	return;
}

/* --- ギミックが通行可能かを取得するメソッド-- - */
bool Gimmick::GetGimmickIsPassable()
{
	return isPassable;
}