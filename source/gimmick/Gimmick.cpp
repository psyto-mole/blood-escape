/* === ギミッククラスのソースファイル === */

#include "Gimmick.h"

#include "Geometry.h"


/* --- コンストラクタ --- */
Gimmick::Gimmick(int id, int x, int y, int state, int target)
{
	gimmickID = id;		// ギミックのIDの初期化

	gimmickTag = GimmickTag::None;	// ギミックのタグを「未分類」に設定

	gimmickType = GimmickType::None;	// ギミックの種類を「なし」に設定

	positionX = x;	// ギミックのX座標の初期化
	positionY = y;	// ギミックのY座標の初期化

	gimmickImage = -1;	// ギミックの画像ハンドルの初期化

	gimmickState = state;	// ギミックの状態の初期化
	maxState = 1;			// 最後の状態を1に設定
	isRoopState = false;	// 状態がループしないように設定

	targetID = target;	// 連動するギミックのIDの初期化

	isPassable = false;		// ギミックを「通行不可」に設定

	isActive = false;
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

/* --- ギミックのタグを取得するメソッド --- */
GimmickTag Gimmick::GetGimmickTag()
{
	return gimmickTag;	// ギミックのタグを取得
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

/* --- 連動するギミックのIDを取得するメソッド --- */
int Gimmick::GetGimmickTargetID()
{
	return targetID;	// 連動するギミックのIDを返す
}

/* --- ギミックが通行可能かを取得するメソッド-- - */
bool Gimmick::GetGimmickIsPassable()
{
	return isPassable;
}

/* --- ギミックを指定した状態に変える --- */
void Gimmick::SetGimmickState(int state)
{
	gimmickState = state;	// ギミックを指定した状態に設定

	if (gimmickState >= maxState)	// 状態がそのギミックの撮り得る最後の状態を超えたなら
	{
		gimmickState = maxState;	// 最後の状態にする
	}
	else if (gimmickState < 1)	// ギミックの状態が1を下回るなら
	{
		gimmickState = 1;	// ギミックの状態を初期化(1に設定)
	}

	return;
}

/* --- ギミックの状態を1つ進める --- */
void Gimmick::AdvanceGimmickState()
{
	gimmickState = gimmickState + 1;	// 状態を1つ進める

	if (gimmickState >= maxState)	// 状態がそのギミックの撮り得る最後の状態を超えたなら
	{
		if (isRoopState)	// 状態がループするギミックなら
		{
			gimmickState = 1;	// 状態を初期化する
		}
		else
		{
			gimmickState = maxState;	// 状態を最後の状態に設定
		}
	}

	return;
}

/* --- ギミックの起動メソッド --- */
void Gimmick::Activate()
{
	isActive = true;

	return;
}

/* --- 引数で渡した座標との接触を判定 --- */
bool Gimmick::CheckContactPoint(POINT point)
{
	RECT gimmickRect;

	gimmickRect = GetRectOnPoint(positionX, positionY, GimmickSize, GimmickSize);

	if (CollisionRectToPoint(gimmickRect, point))
	{
		return true;
	}

	return false;
}