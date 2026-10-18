#pragma once
/* === メニューの処理のヘッダファイル === */

#include "DxLib.h"
#include "MenuTab.h"
#include "MenuWindow.h"


/* --- メニューのクラス --- */
class Menu
{
private:
	MenuTab menuTab;	// メニュータブ(ゲーム画面から眼メニュー画面を開くのに用いる)

	MenuWindow menuWindow;	// メニューウィンドウ

public:
	Menu();		// コンストラクタ
	~Menu();	// デストラクタ

	int Init();		// メニューの初期化メソッド
	void Update();	// メニューの更新メソッド
	void Draw();	// メニューの描画メソッド

	bool IsMenuOpen();	// メニュー画面を開いているかを取得するメソッド
};