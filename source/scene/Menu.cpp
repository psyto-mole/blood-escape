/* === メニュー処理のソースファイル === */

#include "Menu.h"
#include "Geometry.h"
#include "Color.h"
#include "RectParameter.h"


/* --- コンストラクタ --- */
Menu::Menu()
{

}

/* --- デストラクタ --- */
Menu::~Menu()
{

}

/* --- メニューの初期化メソッド --- */
int Menu::Init()
{
	menuTab.Init();		// メニュータブを初期化

	menuWindow.Init();	// メニュー画面の初期化

	return 0;
}

/* --- メニューの更新メソッド --- */
void Menu::Update()
{
	if (menuWindow.GetMenuState() == MenuState::Close)	// メニュー画面が閉じているなら
	{
		menuTab.Update();	// メニュータブの更新メソッドを実行

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