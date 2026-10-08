#pragma once
/* === ゴール地点のヘッダファイル === */

#include "DxLib.h"
#include "ContactGimmick.h"


/* --- ゴール地点ギミックのクラス(ContactGimmickクラスの派生クラス) --- */
class GoalPoint : public ContactGimmick
{
private:

public:
	GoalPoint(int id, int x, int y);	// ゴール地点のコンストラクタ
	~GoalPoint() override;				// ゴール地点のデストラクタ
};