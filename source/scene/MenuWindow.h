#pragma once
/* === メニュー画面関連の処理のヘッダファイル === */

#include "DxLib.h"


/* --- メニュー画面の状態の列挙型 --- */
enum class MenuState
{
	Close,		// メニュー画面を閉じている
	MenuTop		// メニュー画面トップ
};

/* --- メニュー画面のクラス --- */
class MenuWindow
{
private:
	MenuState menuState;	// メニュー画面の状態を管理する変数

	RECT menuWindowFrame;	// メニューウィンドウの外枠
	RECT menuWindowInside;	// メニューウィンドウの内側

	RECT menuButton1Frame;		// メニュー画面のボタン1の外枠
	RECT menuButton1Inside;		// メニュー画面のボタン1の内側
	RECT menuButton2Frame;		// メニュー画面のボタン2の外枠
	RECT menuButton2Inside;		// メニュー画面のボタン2の内側
	RECT menuButton3Frame;		// メニュー画面のボタン3の外枠
	RECT menuButton3Inside;		// メニュー画面のボタン3の内側
	RECT menuButton4Frame;		// メニュー画面のボタン4の外枠
	RECT menuButton4Inside;		// メニュー画面のボタン4の内側

public:
	MenuWindow();	// コンストラクタ
	~MenuWindow();	// デストラクタ

	int Init();		// メニュー画面の初期化メソッド
	void Update();	// メニュー画面の更新メソッド
	void Draw();	// メニュー画面の描画メソッド

	MenuState GetMenuState();	// メニュー画面の状態を取得するメソッド
};