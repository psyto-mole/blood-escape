#pragma once
/* === 針床ギミックのクラスのヘッダファイル === */

#include "DxLib.h"
#include "Gimmick.h"


/* --- 針床ギミックのクラス(Gimmickクラスの派生クラス) --- */
class NeedleFloor : public Gimmick
{
public:
	NeedleFloor(int id, int x, int y);	// コンストラクタ

	void Init();	// ギミックの初期化メソッド
	void Update();	// ギミックの更新メソッド
	void Draw();	// ギミックの描画メソッド
};