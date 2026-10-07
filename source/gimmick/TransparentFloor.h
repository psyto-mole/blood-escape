#pragma once
/* === 透明床ギミックのヘッダファイル === */

#include "DxLib.h"
#include "BloodGimmick.h"


class TransparentFloor : public BloodGimmick
{
public:
	TransparentFloor(int id, int x, int y);		// コンストラクタ
	~TransparentFloor() override;				// デストラクタ
};