#pragma once
/* === 1度きりのギミックのヘッダファイル === */

#include "DxLib.h"
#include "ContactGimmick.h"


/* --- 1度きりのギミックのクラス(ContactGimmickクラスの派生クラス) --- */
class OneShotGimmick : public ContactGimmick
{
protected:


public:
	OneShotGimmick(int id, int x, int y, int state, int target);	// コンストラクタ
	~OneShotGimmick() override;										// デストラクタ

	virtual void Init() = 0;	// 1度きりのギミックの初期化メソッド
	virtual void Update() = 0;	// 1度きりのギミックの更新メソッド
	virtual void Draw() = 0;	// 1度きりのギミックの描画メソッド
};