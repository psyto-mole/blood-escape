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
	menuState = MenuState::Close;	// メニューの状態を「閉じている」に設定

	menuTab.Init();		// メニュータブを初期化

	menuWindow.Init();	// メニュー画面の初期化

	return 0;
}

/* --- メニューの更新メソッド --- */
void Menu::Update()
{
	return;
}

/* --- メニューの描画メソッド --- */
void Menu::Draw()
{
	return;
}

/* --- メニュー画面を開いているかを取得するメソッド --- */
bool Menu::IsMenuOpen()
{
	if (menuState == MenuState::Close)	// メニューが閉じているなら
	{
		return false;	// falseを返す
	}

	return true;	// trueを返す
}