#pragma once
/* === メニューの処理のヘッダファイル === */

#include "DxLib.h"


/* --- メニューのクラス --- */
class Menu
{
private:


public:
	Menu();		// コンストラクタ
	~Menu();	// デストラクタ

	int Init();		// メニューの初期化メソッド
	void Update();	// メニューの更新メソッド
	void Draw();	// メニューの描画メソッド
};