#pragma once
/* === 包帯のヘッダファイル === */

#include "DxLib.h"
#include "OneShotGimmick.h"


/* --- 包帯クラス(ContactGimmickクラスの派生クラス) --- */
class Bandage : public OneShotGimmick
{
private:


public:
	Bandage(int id, int x, int y, int state, int target);	// コンストラクタ
	~Bandage() override;									// デストラクタ

	void Init() override;		// 包帯の初期化メソッド
	void Update() override;		// 包帯の更新メソッド
	void Draw() override;		// 包帯の描画メソッド
};