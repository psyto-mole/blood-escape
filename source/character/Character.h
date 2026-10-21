#pragma once
/* === キャラクタークラスのヘッダファイル === */

#include "DxLib.h"
#include "Map.h"
#include "GimmickManager.h"


/* --- キャラクタークラス --- */
class Character
{
protected:
	POINT characterPosition;	// キャラクターの現在位置

	int hp;		// キャラクターのHP
	int speed;	// キャラクターの移動速度

	int width;		// キャラクターの幅
	int height;		// キャラクターの高さ

	int maxHP;	// 最大HP

public:
	Character();	// コンストラクタ
	~Character();	// デストラクタ

	virtual void Init(POINT startPosition) = 0;
	virtual void Update(Map* mapManager, GimmickManager* gimmickManager) = 0;	// キャラクターの更新メソッド
	virtual void Draw() = 0;	// キャラクターの描画メソッド

	POINT GetCharacterPosition();																// キャラクターの現在位置を取得するメソッド
	void SetCharacterPosition(int x, int y);													// キャラクターの現在位置を設定するメソッド
	void SetCharacterPosition(POINT position);													// キャラクターの現在位置を設定するメソッド(引数がPOINT型)
	void MoveCharacter(Map* mapManager, GimmickManager* gimmickManagerint, int x, int y);		// 引数で渡した値だけキャラクターを動かすメソッド
	void MoveCharacter(Map* mapManager, GimmickManager* gimmickManagerint, POINT position);		// 引数で渡した値だけキャラクターを動かすメソッド(引数がPOINT型)

	void Set_HP(int value);					// HPを指定した値に設定する
	void Calc_HP(int value, int isDamage);	// HPを増減させるメソッド
	int Get_HP();							// HPを取得するメソッド

	int Get_MaxHP();	// 最大HPを取得するメソッド
};