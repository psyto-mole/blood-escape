#pragma once
/* === プレイヤークラスのヘッダファイル === */

#include "DxLib.h"
#include "Character.h"


#define PlayerMaxHP	100		// プレイヤーの最大HP
#define PlayerSpeed	5		// プレイヤーの移動速度

/* --- プレイヤークラス(Characterクラスの派生クラス) --- */
class Player : public Character
{
protected:
	int inputVector;	// プレイヤーの入力方向を格納する変数

public:
	Player();	// コンストラクタ

	void Update() override;		// プレイヤーの更新メソッド
	void Draw() override;		// プレイヤーの描画メソッド

	void MovePlayer();	// プレイヤーの移動メソッド
};