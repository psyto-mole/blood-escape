#pragma once
/* === ギミッククラスのヘッダファイル === */

#include "DxLib.h"


/* --- ギミックの属性の列挙型 --- */
enum class GimmickGroup
{
	None,		// 未分類
	Normal,		// 通常ギミック(プレイヤーの「インタラクト」で起動できるギミック)
	Blood,		// 吸血ギミック(プレイヤーの「自傷」により起動できるギミック)
	Contaxt		// 接触ギミック(プレイヤーが接触と効果を受けるギミック)
};

/* --- ギミックの種類の列挙型 --- */
enum class GimmickType
{
	None,				// なし
	Goal,				// ゴール
	NeedleFloor,		// 針床
	InvisibleFloor,		// 透明床
	Altar,				// 祭壇
	BloodPack,			// 輸血パック
	Bandage,			// 包帯
	WoodenDoor,			// 木製ドア
	Key,				// 鍵
	MetalDoor			// 金属製ドア
};

class Gimmick
{
protected:
	int gimmickID;	// ギミックのID(割り当てなしは-1)

	GimmickType gimmickType;	// ギミックの種類

	GimmickGroup gimmickGroup;	// ギミックの属性

	int positionX;	// ギミックのX座標
	int positionY;	// ギミックのY座標

	int gimmickImage;	// ギミックの画像ハンドル

	int gimmickState;	// ギミックの状態(0で初期状態)
	int maxState;		// 最後の状態
	bool isRoopState;	// 状態がループするか

	int targetID;	// 連動するギミックのID

	bool isPassable;	// 通行可能か

public:
	Gimmick(int id, int x, int y);	// コンストラクタ
	virtual ~Gimmick();				// デストラクタ

	virtual void Init() = 0;	// ギミックの初期化メソッド
	virtual void Update() = 0;	// ギミックの更新メソッド
	virtual void Draw() = 0;	// ギミックの描画メソッド

	int GetGimmickID();					// ギミックのIDを取得するメソッド
	GimmickType GetGimmickType();		// ギミックの種類を取得するメソッド
	GimmickGroup GetGimmickGroup();		// ギミックの属性を取得するメソッド
	POINT GetGimmickPosition();			// ギミックの位置をPOINT型で取得するメソッド
	int GetGimmickState();				// ギミックの状態を取得するメソッド

	void SetGimmickState(int state);	// ギミックを指定した状態に変える
	void AdvanceGimmickState();			// ギミックの状態を進める

	bool GetGimmickIsPassable();	// ギミックが通行可能かを取得するメソッド
};