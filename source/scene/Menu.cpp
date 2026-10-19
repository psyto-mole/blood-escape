/* === メニュー処理のソースファイル === */

#include "Menu.h"


/* --- コンストラクタ --- */
Menu::Menu()
{

}

/* --- デストラクタ --- */
Menu::~Menu()
{

}

/* --- メニューの初期化メソッド --- */
void Menu::Init()
{
	menuTab.Init();		// メニュータブを初期化

	menuWindow.Init();	// メニュー画面の初期化

	return;
}

/* --- メニューの更新メソッド --- */
void Menu::Update()
{
	if (menuWindow.GetMenuState() == MenuState::Close)	// メニュー画面が閉じているなら
	{
		/* +++ メニュータブの更新メソッドを実行 +++ */
		if (menuTab.Update() == -1)	// メニュー画面が開かれたら
		{
			menuWindow.SetMenuState(MenuState::MenuTop);	// メニュー画面の状態をメニュートップに設定
		}

		return;
	}

	menuWindow.Update();	// メニュー画面の更新メソッドを実行

	return;
}

/* --- メニューの描画メソッド --- */
void Menu::Draw()
{
	if (menuWindow.GetMenuState() == MenuState::Close)	// メニュー画面が閉じているなら
	{
		menuTab.Draw();		// メニュータブを描画

		return;
	}

	menuWindow.Draw();	// メニュー画面を描画

	return;
}

/* --- メニュー画面を開いているかを取得するメソッド --- */
bool Menu::IsMenuOpen()
{
	if (menuWindow.GetMenuState() == MenuState::Close)	// メニューが閉じているなら
	{
		return false;	// falseを返す
	}

	return true;	// trueを返す
}

/* --- ゲーム終了が選択されているかを取得するメソッド --- */
bool Menu::IsGameEnd()
{
	if (menuWindow.GetGameEnd())	// ゲーム終了が選択されているなら
	{
		return true;	// trueを返す
	}

	return false;	// falseを返す
}