#pragma once
/* === キャラクタークラスのヘッダファイル === */

#include "DxLib.h"
#include "Map.h"
#include "GimmickManager.h"


/* --- キャラクタークラス --- */
class Character
{
protected:
	POINT nowPosition;		// キャラクターの現在位置
	POINT nextPosition;		// キャラクターの移動後の位置

	int hp;		// キャラクターのHP
	int speed;	// キャラクターの移動速度

	int maxHP;	// 最大HP

public:
	Character();	// コンストラクタ
	~Character();	// デストラクタ

	virtual void Init() = 0;	// キャラクターの初期化メソッド
	virtual void Update(Map* mapManager, GimmickManager* gimmickManager) = 0;	// キャラクターの更新メソッド
	virtual void Draw() = 0;	// キャラクターの描画メソッド

	POINT GetCharacterNowPosition();				// キャラクターの現在位置を取得するメソッド
	POINT GetCharacterNextPosition();				// キャラクターの移動後の位置を取得するメソッド
	void SetCharacterNowPosition(int x, int y);		// キャラクターの現在位置を設定するメソッド
	void SetCharacterNowPosition(POINT position);	// キャラクターの現在位置を設定するメソッド(引数がPOINT型)
	void SetCharacterNextPosition(int x, int y);	// キャラクターの移動後の位置を設定するメソッド
	void SetCharacterNextPosition(POINT position);	// キャラクターの移動後の位置を設定するメソッド(引数がPOINT型)
	void MoveCharacter(int x, int y);				// 引数で渡した値だけキャラクターを動かすメソッド
	void MoveCharacter(POINT position);				// 引数で渡した値だけキャラクターを動かすメソッド(引数がPOINT型)

	void Calc_HP(int value, int isDamage);		// HPを増減させるメソッド

	int Get_HP();	// HPを取得するメソッド
};