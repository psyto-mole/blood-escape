#pragma once
/* +++ 起動ギミックのヘッダファイル1 +++ */

#include "DxLib.h"
#include "Gimmick.h"

class Player;


/* --- 起動ギミックのクラス(Gimmickクラスの派生クラス) --- */
class BootGimmick : public Gimmick
{
public:
	BootGimmick(int id, int x, int y, int state, int target);	// コンストラクタ
	~BootGimmick() override;									// デストラクタ

	virtual int Init() = 0;						// 起動ギミックの初期化メソッド
	virtual void Update(Player* player) = 0;	// 起動ギミックの更新メソッド
	virtual void Draw() = 0;					// 起動ギミックの描画メソッド

	virtual bool IsGoal() = 0;	// ゴール判定のメソッド
};