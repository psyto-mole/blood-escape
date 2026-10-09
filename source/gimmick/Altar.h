#pragma once
/* === 祭壇ギミックのヘッダファイル === */

#include "DxLib.h"
#include "BloodGimmick.h"


/* --- 祭壇クラス(BloodGimmickクラスの派生クラス) --- */
class Altar : public BloodGimmick
{
private:


public:
	Altar(int id, int x, int y);	// コンストラクタ
	~Altar() override;				// デストラクタ

	void Init();	// 祭壇の初期化メソッド
	void Update();	// 祭壇の更新メソッド
	void Draw();	// 祭壇の描画メソッド
};