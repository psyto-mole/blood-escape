#pragma once
/* === メニュー画面関連の処理のヘッダファイル === */

#include "DxLib.h"


#define NumberOfMenuTopOption	4	// メニュー画面トップの選択肢の数
#define NumberOfGameEndOption	3	// ゲーム終了画面の選択肢の数

/* --- メニュー画面の状態の列挙型 --- */
enum class MenuState
{
	Close,		// メニュー画面を閉じている
	MenuTop,	// メニュー画面トップ
	Operation,	// 操作方法を表示
	GameEnd,	// ゲーム終了画面
	Credit		// 使用楽曲等の表示画面
};

/* --- メニュー画面のクラス --- */
class MenuWindow
{
private:
	int selectedIndex;	// 選択されている選択肢の番号

	bool gameEnd;	// 「ゲーム終了」が選択されているかのフラグ

	MenuState menuState;	// メニュー画面の状態を管理する変数

	RECT menuWindowFrame;	// メニューウィンドウの外枠
	RECT menuWindowInside;	// メニューウィンドウの内側

	RECT menuTopButton1Frame;	// メニュー画面トップのボタン1の外枠
	RECT menuTopButton1Inside;	// メニュー画面トップのボタン1の内側
	RECT menuTopButton2Frame;	// メニュー画面トップのボタン2の外枠
	RECT menuTopButton2Inside;	// メニュー画面トップのボタン2の内側
	RECT menuTopButton3Frame;	// メニュー画面トップのボタン3の外枠
	RECT menuTopButton3Inside;	// メニュー画面トップのボタン3の内側
	RECT menuTopButton4Frame;	// メニュー画面トップのボタン4の外枠
	RECT menuTopButton4Inside;	// メニュー画面トップのボタン4の内側

	RECT backTopButtonFrame;	// メニュートップに戻るボタンの外枠
	RECT backTopButtonInside;	// メニュートップに戻るボタンの内側

	RECT gameEndYesButtonFrame;		// ゲーム終了画面の「はい」のボタンの外枠
	RECT gameEndYesButtonInside;	// ゲーム終了画面の「はい」のボタンの内側
	RECT gameEndNoButtonFrame;		// ゲーム終了画面の「いいえ」のボタンの外枠
	RECT gameEndNoButtonInside;		// ゲーム終了画面の「いいえ」のボタンの内側

public:
	MenuWindow();	// コンストラクタ
	~MenuWindow();	// デストラクタ

	void Init();	// メニュー画面の初期化メソッド
	void Update();	// メニュー画面の更新メソッド
	void Draw();	// メニュー画面の描画メソッド

	bool GetGameEnd();			// ゲーム終了フラグを取得するメソッド
	void SetGameEndTrue();		// ゲーム終了フラグをtrueにするメソッド
	void SetGameEndFalse();		// ゲーム終了フラグをfalseにするメソッド

	MenuState GetMenuState();				// メニュー画面の状態を取得するメソッド
	void SetMenuState(MenuState state);		// メニュー画面の状態を設定するメソッド
};