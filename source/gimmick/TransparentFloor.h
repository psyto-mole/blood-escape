#pragma once
/* === 透明床のヘッダファイル === */

#include "DxLib.h"
#include "BloodGimmick.h"


/* --- 透明床クラス(BloodGimmickクラスの派生クラス) --- */
class TransparentFloor : public BloodGimmick
{
public:
	TransparentFloor(int id, int x, int y);		// コンストラクタ
	~TransparentFloor() override;				// デストラクタ

	void Init() override;		// ギミックの初期化メソッド
	void Update() override;		// ギミックの更新メソッド
	void Draw() override;		// ギミックの描画メソッド
};