#pragma once
/* === スイッチギミックのヘッダファイル === */

#include "DxLib.h"
#include "Gimmick.h"


#define SwitchStateMax	2	// スイッチの状態の種類

/* --- スイッチギミックのクラス(Gimmickクラスの派生クラス) --- */
class Switch : public Gimmick
{
public:
	Switch(int id, int x, int y, int state, int target);	// コンストラクタ
	~Switch() override;										// デストラクタ

	int Init() override;					// スイッチギミックの初期化メソッド
	void Update(Player* player) override;	// スイッチギミックの更新メソッド
	void Draw() override;					// スイッチギミックの描画メソッド
};