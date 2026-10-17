#pragma once
/* === 接触ギミックのヘッダファイル === */

#include "DxLib.h"
#include "Gimmick.h"
#include "Player.h"


/* --- 接触ギミッククラス(Gimmickクラスの派生クラス) --- */
class ContactGimmick : public Gimmick
{
protected:
	bool isContact;		// プレイヤーと接触しているか

public:
	ContactGimmick(int id, int x, int y, int state, int target);	// コンストラクタ
	~ContactGimmick() override;										// デストラクタ

	virtual int Init() = 0;						// 接触ギミックの初期化メソッド
	virtual void Update(Player* player) = 0;	// 接触ギミックの更新メソッド
	virtual void Draw() = 0;					// 接触ギミックの描画メソッド

	virtual bool IsGoal() = 0;	// ゴール判定のメソッド
};