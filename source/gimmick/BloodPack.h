#pragma once
/* === 輸血パックのヘッダファイル === */

#include "DxLib.h"
#include "OneShotGimmick.h"


/* --- 輸血パッククラス(ContactGimmickクラスの派生クラス) --- */
class BloodPack : public OneShotGimmick
{
private:


public:
	BloodPack(int id, int x, int y, int state, int target);		// コンストラクタ
	~BloodPack() override;										// デストラクタ

	void Init() override;	// 輸血パックの初期化メソッド
	void Update() override;	// 輸血パックの更新メソッド
	void Draw() override;	// 輸血パックの描画メソッド
};