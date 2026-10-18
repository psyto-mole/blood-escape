/* === メニュー画面関連の処理のソースファイル === */

#include "MenuWindow.h"
#include "Mouse.h"
#include "Geometry.h"
#include "Color.h"
#include "Font.h"
#include "Message.h"
#include "Rectparameter.h"


/* --- コンストラクタ --- */
MenuWindow::MenuWindow()
{

}

/* --- デストラクタ --- */
MenuWindow::~MenuWindow()
{

}

/* --- メニュー画面の初期化メソッド --- */
int MenuWindow::Init()
{
	menuState = MenuState::Close;	// メニュー画面を閉じている状態に設定

	menuWindowFrame = GetRectOnPoint(MenuWindowCenterX, MenuWindowCenterY, MenuWindowFrameWidth, MenuWindowFrameHeight);	// メニューウィンドウの外枠の矩形を取得
	menuWindowInside = GetRectOnPoint(MenuWindowCenterX, MenuWindowCenterY, MenuWindowInsideWidth, MenuWindowInsideHeight);	// メニューウィンドウの内側の矩形を取得
	
	menuButton1Frame = GetRectOnPoint(MenuButtonCenterX, MenuButton1CenterY, MenuButtonFrameWidth, MenuButtonFrameHeight);		// メニュー画面のボタン1の外枠の矩形を取得
	menuButton1Inside = GetRectOnPoint(MenuButtonCenterX, MenuButton1CenterY, MenuButtonInsideWidth, MenuButtonInsideHeight);	// メニュー画面のボタン1の内側の矩形を取得
	menuButton1Frame = GetRectOnPoint(MenuButtonCenterX, MenuButton2CenterY, MenuButtonFrameWidth, MenuButtonFrameHeight);		// メニュー画面のボタン2の外枠の矩形を取得
	menuButton1Inside = GetRectOnPoint(MenuButtonCenterX, MenuButton2CenterY, MenuButtonInsideWidth, MenuButtonInsideHeight);	// メニュー画面のボタン2の内側の矩形を取得
	menuButton1Frame = GetRectOnPoint(MenuButtonCenterX, MenuButton3CenterY, MenuButtonFrameWidth, MenuButtonFrameHeight);		// メニュー画面のボタン3の外枠の矩形を取得
	menuButton1Inside = GetRectOnPoint(MenuButtonCenterX, MenuButton3CenterY, MenuButtonInsideWidth, MenuButtonInsideHeight);	// メニュー画面のボタン3の内側の矩形を取得
	menuButton1Frame = GetRectOnPoint(MenuButtonCenterX, MenuButton4CenterY, MenuButtonFrameWidth, MenuButtonFrameHeight);		// メニュー画面のボタン4の外枠の矩形を取得
	menuButton1Inside = GetRectOnPoint(MenuButtonCenterX, MenuButton4CenterY, MenuButtonInsideWidth, MenuButtonInsideHeight);	// メニュー画面のボタン4の内側の矩形を取得

	return 0;
}

/* --- メニュー画面の更新メソッド --- */
void MenuWindow::Update()
{
	return;
}

/* --- メニュー画面の描画メソッド --- */
void MenuWindow::Draw()
{
	if (CollisionRectToPoint(menuButton1Frame, nowMousePoint))
	{
		DrawRect(menuButton1Frame, Color_Red, true, 1);
		DrawRect(menuButton1Inside, Color_White, true, 1);
		DrawRect(menuButton2Frame, Color_White, true, 1);
		DrawRect(menuButton2Inside, Color_Black, true, 1);
		DrawRect(menuButton3Frame, Color_White, true, 1);
		DrawRect(menuButton3Inside, Color_Black, true, 1);
		DrawRect(menuButton4Frame, Color_White, true, 1);
		DrawRect(menuButton4Inside, Color_Black, true, 1);

		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton1CenterY, FAlign_AllCenter, Color_Red, , "%s", OptionMenuWindowEndGame);
		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton2CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowCredit);
		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton3CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowBack);
		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton4CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindow);
	}
	else if (CollisionRectToPoint(menuButton2Frame, nowMousePoint))
	{
		DrawRect(menuButton1Frame, Color_Red, true, 1);
		DrawRect(menuButton1Inside, Color_White, true, 1);
		DrawRect(menuButton2Frame, Color_White, true, 1);
		DrawRect(menuButton2Inside, Color_Black, true, 1);
		DrawRect(menuButton3Frame, Color_White, true, 1);
		DrawRect(menuButton3Inside, Color_Black, true, 1);
		DrawRect(menuButton4Frame, Color_White, true, 1);
		DrawRect(menuButton4Inside, Color_Black, true, 1);

		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton1CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowEndGame);
		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton2CenterY, FAlign_AllCenter, Color_Red, , "%s", OptionMenuWindowCredit);
		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton3CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowBack);
		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton4CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindow);
	}
	else if (CollisionRectToPoint(menuButton3Frame, nowMousePoint))
	{
		DrawRect(menuButton1Frame, Color_White, true, 1);
		DrawRect(menuButton1Inside, Color_Black, true, 1);
		DrawRect(menuButton2Frame, Color_White, true, 1);
		DrawRect(menuButton2Inside, Color_Black, true, 1);
		DrawRect(menuButton3Frame, Color_Red, true, 1);
		DrawRect(menuButton3Inside, Color_White, true, 1);
		DrawRect(menuButton4Frame, Color_White, true, 1);
		DrawRect(menuButton4Inside, Color_Black, true, 1);

		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton1CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowEndGame);
		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton2CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowCredit);
		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton3CenterY, FAlign_AllCenter, Color_Red, , "%s", OptionMenuWindowBack);
		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton4CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindow);
	}
	else if (CollisionRectToPoint(menuButton4Frame, nowMousePoint))
	{
		DrawRect(menuButton1Frame, Color_White, true, 1);
		DrawRect(menuButton1Inside, Color_Black, true, 1);
		DrawRect(menuButton2Frame, Color_White, true, 1);
		DrawRect(menuButton2Inside, Color_Black, true, 1);
		DrawRect(menuButton3Frame, Color_White, true, 1);
		DrawRect(menuButton3Inside, Color_Black, true, 1);
		DrawRect(menuButton4Frame, Color_Red, true, 1);
		DrawRect(menuButton4Inside, Color_White, true, 1);

		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton1CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowEndGame);
		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton2CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowCredit);
		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton3CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowBack);
		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton4CenterY, FAlign_AllCenter, Color_Red, , "%s", OptionMenuWindow);
	}
	else
	{
		DrawRect(menuButton1Frame, Color_White, true, 1);
		DrawRect(menuButton1Inside, Color_Black, true, 1);
		DrawRect(menuButton2Frame, Color_White, true, 1);
		DrawRect(menuButton2Inside, Color_Black, true, 1);
		DrawRect(menuButton3Frame, Color_White, true, 1);
		DrawRect(menuButton3Inside, Color_Black, true, 1);
		DrawRect(menuButton4Frame, Color_White, true, 1);
		DrawRect(menuButton4Inside, Color_Black, true, 1);

		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton1CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowEndGame);
		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton2CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowCredit);
		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton3CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowBack);
		DrawFormatStringToHandleAlign(MenuButtonCenterX, MenuButton4CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindow);
	}

	return;
}

/* --- メニュー画面の状態を取得するメソッド --- */
MenuState MenuWindow::GetMenuState()
{
	return menuState;
}