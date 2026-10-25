/* === メニュータブ関連の処理のソースファイル === */

#include "MenuTab.h"
#include "Key.h"
#include "Mouse.h"
#include "Geometry.h"
#include "Color.h"
#include "Font.h"
#include "Sound.h"
#include "Message.h"
#include "RectParameter.h"


/* --- コンストラクタ --- */
MenuTab::~MenuTab()
{

}

/* --- デストラクタ --- */
MenuTab::MenuTab()
{

}

/* --- メニュータブの初期化メソッド --- */
void MenuTab::Init()
{
	menuTabFrame = GetRectOnPoint(MenuTabCenterX, MenuTabCenterY, MenuTabFrameWidth, MenuTabFrameHeight);		// メニュータブの外枠の矩形を取得
	menuTabInside = GetRectOnPoint(MenuTabCenterX, MenuTabCenterY, MenuTabInsideWidth, MenuTabInsideHeight);	// メニュータブの内側の矩形を取得

	return;
}

/* --- メニュータブの更新メソッド --- */
int MenuTab::Update()
{
	if (Key_Check_Click(KEY_INPUT_M))	// Mキーがクリックされたら
	{
		Sound_Play(SE_Menu);

		return -1;	// -1を返す(メニュー画面起動)
	}

	return 0;
}

/* --- メニュータブの描画メソッド --- */
void MenuTab::Draw()
{
	
	DrawRect(menuTabFrame, Color_Blue, true, 1);	// メニュータブの外枠を青で描画
	DrawRect(menuTabInside, Color_White, true, 1);	// メニュータブの内側を白で描画
	DrawFormatStringToHandleAlign(MenuTabCenterX, MenuTabCenterY, FAlign_AllCenter, Color_Blue, KHDot_30_1,"%s", MenuTabText);	// メニュータブの文字列を青で描画

	return;
}