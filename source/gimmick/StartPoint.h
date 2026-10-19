#pragma once
/* === スタート地点のヘッダファイル === */

#include "DxLib.h"
#include "Gimmick.h"
#include "Player.h"


#define StartPointStateMax	1	// スタート地点の状態の種類

/* --- スタート地点ギミックのクラス(Gimmickクラスの派生クラス) --- */
class StartPoint : public Gimmick
{
public:
	StartPoint(int id, int x, int y, int state, int target);	// スタート地点のコンストラクタ
	~StartPoint() override;										// スタート地点のデストラクタ

	int Init() override;					// スタート地点の初期化メソッド
	void Update(Player* player) override;	// スタート地点の更新メソッド
	void Draw() override;					// スタート地点の描画メソッド
};