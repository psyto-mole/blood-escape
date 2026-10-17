#pragma once
/* === ギミッククラスのヘッダファイル === */

#include "DxLib.h"
#include "Player.h"


#define GimmickSize	32		// ギミックの大きさ
#define GimmickStateMax	10	// ギミックの状態の種類の最大

/* --- ギミックのタグの列挙型 --- */
enum class GimmickTag
{
	None,		// 未分類
	Normal,		// 通常ギミック(プレイヤーの「インタラクト」で起動できるギミック)
	Blood,		// 出血ギミック(プレイヤーの「自傷」により起動できるギミック)
	Contact		// 接触ギミック(プレイヤーが接触と効果を受けるギミック)
};

/* --- ギミックの種類の列挙型 --- */
enum class GimmickType
{
	None,				// なし
	Altar,				// 祭壇
	Bandage,			// 包帯
	BloodPack,			// 輸血パック
	Door,				// ドア
	GoalPoint,			// ゴール
	NeedleFloor,		// 針床
	Switch,				// スイッチ
	TransparentFloor	// 透明床
};

class Gimmick
{
protected:
	int gimmickID;	// ギミックのID(割り当てなしは-1)

	GimmickTag gimmickTag;	// ギミックのタグ

	GimmickType gimmickType;	// ギミックの種類

	int positionX;	// ギミックのX座標
	int positionY;	// ギミックのY座標

	int gimmickImage[GimmickStateMax];	// ギミックの画像ハンドルの配列

	int gimmickState;	// ギミックの状態(1で初期状態)
	int maxState;		// 最後の状態
	bool isRoopState;	// 状態がループするか

	int targetID;	// 連動するギミックのID

	bool isPassable;	// 通行可能か

	bool isActive;	// 起動しているか

public:
	Gimmick(int id, int x, int y, int state, int target);		// コンストラクタ
	virtual ~Gimmick();											// デストラクタ

	virtual int Init() = 0;						// ギミックの初期化メソッド
	virtual void Update(Player* player) = 0;	// ギミックの更新メソッド
	virtual void Draw() = 0;					// ギミックの描画メソッド

	int GetGimmickID();				// ギミックのIDを取得するメソッド
	GimmickTag GetGimmickTag();		// ギミックのタグを取得するメソッド
	GimmickType GetGimmickType();	// ギミックの種類を取得するメソッド
	POINT GetGimmickPosition();		// ギミックの位置をPOINT型で取得するメソッド
	int GetGimmickState();			// ギミックの状態を取得するメソッド
	int GetGimmickTargetID();		// 連動するギミックのIDを取得するメソッド
	bool GetGimmickIsPassable();	// ギミックが通行可能かを取得するメソッド
	bool GetGimmickIsActive();		// ギミックが起動しているかを取得するメソッド

	void SetGimmickState(int state);	// ギミックを指定した状態に変えるメソッド
	void AdvanceGimmickState();			// ギミックの状態を1つ進めるメソッド

	void Activate();	// ギミックの起動メソッド
	void Inactivate();	// ギミックの停止メソッド

	bool CheckContactPoint(POINT point);	// 引数で渡した座標との接触を判定するメソッド

	virtual bool IsGoal() = 0;	// ゴール判定のメソッド
};