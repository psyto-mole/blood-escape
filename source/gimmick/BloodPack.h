#pragma once
/* === 輸血パックのヘッダファイル === */

#include "DxLib.h"
#include "ContactGimmick.h"


#define BloodPackStateMax		2	// 輸血パックの状態の種類
#define BloodPackTransfusion	15	// 輸血(回復)の量

/* --- 輸血パッククラス(ContactGimmickクラスの派生クラス) --- */
class BloodPack : public ContactGimmick
{
public:
	BloodPack(int id, int x, int y, int state, int target);		// コンストラクタ
	~BloodPack() override;										// デストラクタ

	void Init() override;					// 輸血パックの初期化メソッド
	void Update(Player* player) override;	// 輸血パックの更新メソッド
	void Draw() override;					// 輸血パックの描画メソッド
};