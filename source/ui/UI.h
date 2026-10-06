#pragma once
/* === UI関連の処理のヘッダファイル === */

#include "DxLib.h"


class UserInterface
{
public:
	virtual void Init() = 0;	// UIの初期化メソッド
	virtual void Update() = 0;	// UIの更新メソッド
	virtual void Draw() = 0;	// UIの描画メソッド
	virtual void End() = 0;		// UIの終了メソッド
};