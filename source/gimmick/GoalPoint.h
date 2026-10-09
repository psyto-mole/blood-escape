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

	void Init() override;		// ゴール地点の初期化メソッド
	void Update() override;		// ゴール地点の更新メソッド
	void Draw() override;		// ゴール地点の描画メソッド
};