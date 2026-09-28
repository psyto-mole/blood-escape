#pragma once
/* === ギミッククラスのヘッダファイル === */

#include "DxLib.h"


class Gimmick
{
private:
	int positionX;	// ギミックのX座標
	int positionY;	// ギミックのY座標

	int gimmickImage;	// ギミックの画像ハンドル

public:
	~Gimmick();		// デストラクタ

	virtual void Init() = 0;		// ギミックの初期化メソッド
	virtual void Update() = 0;	// ギミックの更新メソッド
	virtual void Draw() = 0;		// ギミックの描画メソッド
};