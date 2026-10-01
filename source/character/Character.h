#pragma once
/* === キャラクタークラスのヘッダファイル === */

#include "DxLib.h"


/* --- キャラクタークラス --- */
class Character
{
protected:
	int positionX;	// キャラクターの現在位置のX座標
	int positionY;	// キャラクターの現在位置のY座標

	int characterImage;		// キャラクターの画像ハンドル

	int hp;		// キャラクターのHP
	int speed;	// キャラクターの移動速度

public:
	Character();	// コンストラクタ
	~Character();	// デストラクタ

	virtual void Init() = 0;	// キャラクターの初期化メソッド
	virtual void Update() = 0;	// キャラクターの更新メソッド
	virtual void Draw() = 0;	// キャラクターの描画メソッド

	void SetCharacterPosition(int x, int y);	// キャラクターの位置を設定するメソッド
	void MoveCharacter(int x, int y);			// 引数で渡した値だけキャラクターを動かすメソッド
};