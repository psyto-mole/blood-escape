#pragma once
/* === プレイヤークラスのヘッダファイル === */

#include "DxLib.h"
#include "Character.h"


#define PlayerMaxHP	100		// プレイヤーの最大HP
#define PlayerSpeed	5		// プレイヤーの移動速度

#define DamageOfSelfHarm	10	// 自傷のダメージ

/* --- プレイヤークラス(Characterクラスの派生クラス) --- */
class Player : public Character
{
protected:
	int inputVector;			// プレイヤーの入力方向を格納する変数
	int pastFacingDirection;	// プレイヤーが前に向いていた向き

	int playerAnimation[9];		// プレイヤーのアニメーションの画像ハンドルの配列

	bool isBleeding;	// 出血状態

	RECT maxHPBar;	// 最大HPバーの矩形
	RECT hpBar;		// HPバーの矩形

	RECT interactCollider;	// インタラクトの判定

public:
	Player();	// コンストラクタ

	void Init() override;		// プレイヤーの初期化メソッド
	void Update(Map* mapManager, GimmickManager* gimmickManager) override;	// プレイヤーの更新メソッド
	void Draw() override;		// プレイヤーの描画メソッド

	void MovePlayer(Map* mapManager, GimmickManager* gimmickManager);	// プレイヤーの移動メソッド(現在位置は変更しない)

	void InteractGimmick(GimmickManager* gimmickManager, int gimmickID);	// インタラクト(通常ギミックを操作する)メソッド
	void SelfHarm(GimmickManager* gimmickManager, int gimmickID);			// 自傷(出血ギミックを操作する)メソッド

	void ProcessBleeding();			// 出血の処理メソッド
	void SetBleedingTrue();			// 出血状態にするメソッド
	void SetBleedingFalse();		// 出血状態を解除するメソッド
	void TakeDamage(int value);		// 被ダメージのメソッド

private:
	void PlayerAnimation();		// プレイヤーのアニメーションメソッド

	RECT GenerateInteractCollision();	// プレイヤーのインタラクト判定の生成メソッド
	void DrawInteractCollision();		// プレイヤーのインタラクト判定の描画メソッド

	void DrawPlayerUI();	// プレイヤーのUIの描画メソッド
};