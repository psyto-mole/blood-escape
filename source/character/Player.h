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

	int playerAnimation[9];		// プレイヤーのアニメーションの画像ハンドルの配列

	bool isBleeding;	// 出血状態

public:
	Player();	// コンストラクタ

	void Init() override;		// プレイヤーの初期化メソッド
	void Update(Map* mapManager, GimmickManager* gimmickManager) override;	// プレイヤーの更新メソッド
	void Draw() override;		// プレイヤーの描画メソッド

	void MovePlayer();	// プレイヤーの移動メソッド(現在位置は変更しない)

	void ProcessBleeding();			// 出血の処理メソッド
	void SetBleedingTrue();			// 出血状態にするメソッド
	void SetBleedingFalse();		// 出血状態を解除するメソッド
	void ProcessDamage(int value);	// 被ダメージのメソッド

	void TransfusionBlood();	// 輸血の処理メソッド

private:
	void PlayerAnimation();		// プレイヤーのアニメーションメソッド

};