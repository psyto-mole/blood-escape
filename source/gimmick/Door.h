#pragma once
/* === ドアギミックのヘッダファイル === */

#include "DxLib.h"
#include "Gimmick.h"


/* --- ドアギミッククラス(Gimmickクラスの派生クラス) --- */
class Door : public Gimmick
{
private:


public:
	Door(int id, int x, int y);		// コンストラクタ
	~Door() override;				// デストラクタ

	void Init() override;		// ドアギミックの初期化メソッド
	void Update() override;		// ドアギミックの更新メソッド
	void Draw() override;		// ドアギミックの描画メソッド
};