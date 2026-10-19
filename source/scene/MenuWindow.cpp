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
void MenuWindow::Init()
{
	gameEnd = false;	// ゲーム終了フラグをfalseにする

	menuState = MenuState::Close;	// メニュー画面を閉じている状態に設定

	menuWindowFrame = GetRectOnPoint(MenuWindowCenterX, MenuWindowCenterY, MenuWindowFrameWidth, MenuWindowFrameHeight);	// メニューウィンドウの外枠の矩形を取得
	menuWindowInside = GetRectOnPoint(MenuWindowCenterX, MenuWindowCenterY, MenuWindowInsideWidth, MenuWindowInsideHeight);	// メニューウィンドウの内側の矩形を取得
	
	menuTopButton1Frame = GetRectOnPoint(MenuTopButtonCenterX, MenuTopButton1CenterY, MenuTopButtonFrameWidth, MenuTopButtonFrameHeight);		// メニュー画面のボタン1の外枠の矩形を取得
	menuTopButton1Inside = GetRectOnPoint(MenuTopButtonCenterX, MenuTopButton1CenterY, MenuTopButtonInsideWidth, MenuTopButtonInsideHeight);	// メニュー画面のボタン1の内側の矩形を取得
	menuTopButton2Frame = GetRectOnPoint(MenuTopButtonCenterX, MenuTopButton2CenterY, MenuTopButtonFrameWidth, MenuTopButtonFrameHeight);		// メニュー画面のボタン2の外枠の矩形を取得
	menuTopButton2Inside = GetRectOnPoint(MenuTopButtonCenterX, MenuTopButton2CenterY, MenuTopButtonInsideWidth, MenuTopButtonInsideHeight);	// メニュー画面のボタン2の内側の矩形を取得
	menuTopButton3Frame = GetRectOnPoint(MenuTopButtonCenterX, MenuTopButton3CenterY, MenuTopButtonFrameWidth, MenuTopButtonFrameHeight);		// メニュー画面のボタン3の外枠の矩形を取得
	menuTopButton3Inside = GetRectOnPoint(MenuTopButtonCenterX, MenuTopButton3CenterY, MenuTopButtonInsideWidth, MenuTopButtonInsideHeight);	// メニュー画面のボタン3の内側の矩形を取得
	menuTopButton4Frame = GetRectOnPoint(MenuTopButtonCenterX, MenuTopButton4CenterY, MenuTopButtonFrameWidth, MenuTopButtonFrameHeight);		// メニュー画面のボタン4の外枠の矩形を取得
	menuTopButton4Inside = GetRectOnPoint(MenuTopButtonCenterX, MenuTopButton4CenterY, MenuTopButtonInsideWidth, MenuTopButtonInsideHeight);	// メニュー画面のボタン4の内側の矩形を取得

	backTopButtonFrame = GetRectOnPoint(BackTopButtonCenterX, BackTopButtonCenterY, BackTopButtonFrameWidth, BackTopButtonFrameHeight);		// メニュートップに戻るボタンの外枠の矩形を取得
	backTopButtonInside = GetRectOnPoint(BackTopButtonCenterX, BackTopButtonCenterY, BackTopButtonInsideWidth, BackTopButtonInsideHeight);	// メニュートップに戻るボタンの内側の矩形を取得

	gameEndYesButtonFrame = GetRectOnPoint(GameEndYesButtonCenterX, GameEndButtonCenterY, GameEndButtonFrameWidth, GameEndButtonFrameHeight);		// ゲーム終了画面の「はい」のボタンの外枠の矩形の取得
	gameEndYesButtonInside = GetRectOnPoint(GameEndYesButtonCenterX, GameEndButtonCenterY, GameEndButtonInsideWidth, GameEndButtonInsideHeight);	// ゲーム終了画面の「はい」のボタンの内側の矩形の取得
	gameEndNoButtonFrame = GetRectOnPoint(GameEndNoButtonCenterX, GameEndButtonCenterY, GameEndButtonFrameWidth, GameEndButtonFrameHeight);			// ゲーム終了画面の「いいえ」のボタンの外枠の矩形の取得
	gameEndNoButtonInside = GetRectOnPoint(GameEndNoButtonCenterX, GameEndButtonCenterY, GameEndButtonInsideWidth, GameEndButtonInsideHeight);		// ゲーム終了画面の「いいえ」のボタンの内側の矩形の取得

	return;
}

/* --- メニュー画面の更新メソッド --- */
void MenuWindow::Update()
{
	/* +++ メニュー画面の状態に応じて処理を変える +++ */
	switch (menuState)
	{
	case MenuState::MenuTop:
		/* +++ メニュートップの場合 +++ */

		if (CollisionRectToPoint(menuTopButton1Frame, nowMousePoint) && Mouse_Check_Click(MOUSE_INPUT_LEFT))	// ボタン1がクリックされたら
		{
			SetMenuState(MenuState::Operation);		// メニューの状態を操作方法表示に設定
		}
		else if (CollisionRectToPoint(menuTopButton2Frame, nowMousePoint) && Mouse_Check_Click(MOUSE_INPUT_LEFT))	// ボタン2がクリックされたら
		{
			SetMenuState(MenuState::GameEnd);	// メニュー画面の状態をゲーム終了画面にする
		}
		else if (CollisionRectToPoint(menuTopButton3Frame, nowMousePoint) && Mouse_Check_Click(MOUSE_INPUT_LEFT))	// ボタン3がクリックされたら
		{
			SetMenuState(MenuState::Credit);	// メニュー画面の状態を使用楽曲表示にする
		}
		else if (CollisionRectToPoint(menuTopButton4Frame, nowMousePoint) && Mouse_Check_Click(MOUSE_INPUT_LEFT))	// ボタン4がクリックされたら
		{
			SetMenuState(MenuState::Close);	// メニュー画面を閉じる
		}
		break;
	case MenuState::GameEnd:
		/* +++ ゲーム終了画面の場合 +++ */

		if (CollisionRectToPoint(gameEndYesButtonFrame, nowMousePoint) && Mouse_Check_Click(MOUSE_INPUT_LEFT))		// 「はい」ボタンがクリックされた
		{
			SetGameEndTrue();	// ゲーム終了を選択状態にする
		}
		else if (CollisionRectToPoint(gameEndNoButtonFrame, nowMousePoint) && Mouse_Check_Click(MOUSE_INPUT_LEFT))		// 「いいえ」ボタンがクリックされた
		{
			SetMenuState(MenuState::MenuTop);	// メニュー画面の状態をメニュートップにする
		}
		break;
	}

	if (menuState != MenuState::MenuTop)	// メニュー画面の状態が画面トップでないなら
	{
		if (CollisionRectToPoint(backTopButtonFrame, nowMousePoint) && Mouse_Check_Click(MOUSE_INPUT_LEFT))		// 「戻る」ボタンがクリックされたら
		{
			SetMenuState(MenuState::MenuTop);	// メニュー画面の状態を画面トップに設定
		}
	}

	return;
}

/* --- メニュー画面の描画メソッド --- */
void MenuWindow::Draw()
{
//	if (menuState == MenuState::Close)	// メニュー画面が閉じれれている状態なら
//	{
//		return;		// 何もせずに終了
//	}
//
//	DrawRect(menuWindowFrame, Color_White, true, 1);	// メニュー画面の外枠を描画
//	DrawRect(menuWindowInside, Color_Black, true, 1);	// メニュー画面の内側を描画
//
//	/* +++ メニュー画面の状態に応じて描画する +++ */
//	switch (menuState)
//	{
//	case MenuState::MenuTop:
//		/* +++ メニュートップの場合 +++ */
//
//		/* +++ カーソルが接触しているボタンを色を変えて描画 +++ */
//		if (CollisionRectToPoint(menuTopButton1Frame, nowMousePoint))	// ボタン1と接触している場合
//		{
//			/* +++ ボタン1を赤枠に白、それ以外を白枠に黒で描画 +++ */
//			DrawRect(menuTopButton1Frame, Color_Red, true, 1);
//			DrawRect(menuTopButton1Inside, Color_White, true, 1);
//			DrawRect(menuTopButton2Frame, Color_White, true, 1);
//			DrawRect(menuTopButton2Inside, Color_Black, true, 1);
//			DrawRect(menuTopButton3Frame, Color_White, true, 1);
//			DrawRect(menuTopButton3Inside, Color_Black, true, 1);
//			DrawRect(menuTopButton4Frame, Color_White, true, 1);
//			DrawRect(menuTopButton4Inside, Color_Black, true, 1);
//
//			/* +++ ボタン1の文字列を赤で、それ以外を白で描画 +++ */
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton1CenterY, FAlign_AllCenter, Color_Red, , "%s", OptionMenuWindowEndGame);
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton2CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowCredit);
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton3CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowBack);
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton4CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindow);
//		}
//		else if (CollisionRectToPoint(menuTopButton2Frame, nowMousePoint))	// ボタン2と接触している場合
//		{
//			/* +++ ボタン2を赤枠に白、それ以外を白枠に黒で描画 +++ */
//			DrawRect(menuTopButton1Frame, Color_Red, true, 1);
//			DrawRect(menuTopButton1Inside, Color_White, true, 1);
//			DrawRect(menuTopButton2Frame, Color_White, true, 1);
//			DrawRect(menuTopButton2Inside, Color_Black, true, 1);
//			DrawRect(menuTopButton3Frame, Color_White, true, 1);
//			DrawRect(menuTopButton3Inside, Color_Black, true, 1);
//			DrawRect(menuTopButton4Frame, Color_White, true, 1);
//			DrawRect(menuTopButton4Inside, Color_Black, true, 1);
//
//			/* +++ ボタン2の文字列を赤で、それ以外を白で描画 +++ */
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton1CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowEndGame);
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton2CenterY, FAlign_AllCenter, Color_Red, , "%s", OptionMenuWindowCredit);
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton3CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowBack);
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton4CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindow);
//		}
//		else if (CollisionRectToPoint(menuTopButton3Frame, nowMousePoint))	// ボタン3と接触している場合
//		{
//			/* +++ ボタン3を赤枠に白、それ以外を白枠に黒で描画 +++ */
//			DrawRect(menuTopButton1Frame, Color_White, true, 1);
//			DrawRect(menuTopButton1Inside, Color_Black, true, 1);
//			DrawRect(menuTopButton2Frame, Color_White, true, 1);
//			DrawRect(menuTopButton2Inside, Color_Black, true, 1);
//			DrawRect(menuTopButton3Frame, Color_Red, true, 1);
//			DrawRect(menuTopButton3Inside, Color_White, true, 1);
//			DrawRect(menuTopButton4Frame, Color_White, true, 1);
//			DrawRect(menuTopButton4Inside, Color_Black, true, 1);
//
//			/* +++ ボタン3の文字列を赤で、それ以外を白で描画 +++ */
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton1CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowEndGame);
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton2CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowCredit);
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton3CenterY, FAlign_AllCenter, Color_Red, , "%s", OptionMenuWindowBack);
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton4CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindow);
//		}
//		else if (CollisionRectToPoint(menuTopButton4Frame, nowMousePoint))	// ボタン4と接触している場合
//		{
//			/* +++ ボタン4を赤枠に白、それ以外を白枠に黒で描画 +++ */
//			DrawRect(menuTopButton1Frame, Color_White, true, 1);
//			DrawRect(menuTopButton1Inside, Color_Black, true, 1);
//			DrawRect(menuTopButton2Frame, Color_White, true, 1);
//			DrawRect(menuTopButton2Inside, Color_Black, true, 1);
//			DrawRect(menuTopButton3Frame, Color_White, true, 1);
//			DrawRect(menuTopButton3Inside, Color_Black, true, 1);
//			DrawRect(menuTopButton4Frame, Color_Red, true, 1);
//			DrawRect(menuTopButton4Inside, Color_White, true, 1);
//
//			/* +++ ボタン4の文字列を赤で、それ以外を白で描画 +++ */
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton1CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowEndGame);
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton2CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowCredit);
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton3CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowBack);
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton4CenterY, FAlign_AllCenter, Color_Red, , "%s", OptionMenuWindow);
//		}
//		else
//		{
//			/* +++ ボタンを白枠に黒で描画 +++ */
//			DrawRect(menuTopButton1Frame, Color_White, true, 1);
//			DrawRect(menuTopButton1Inside, Color_Black, true, 1);
//			DrawRect(menuTopButton2Frame, Color_White, true, 1);
//			DrawRect(menuTopButton2Inside, Color_Black, true, 1);
//			DrawRect(menuTopButton3Frame, Color_White, true, 1);
//			DrawRect(menuTopButton3Inside, Color_Black, true, 1);
//			DrawRect(menuTopButton4Frame, Color_White, true, 1);
//			DrawRect(menuTopButton4Inside, Color_Black, true, 1);
//
//			/* +++ ボタンの文字列をを白で描画 +++ */
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton1CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowEndGame);
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton2CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowCredit);
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton3CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindowBack);
//			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton4CenterY, FAlign_AllCenter, Color_White, , "%s", OptionMenuWindow);
//		}
//		break;
//	case MenuState::Operation:
//		/* +++ 操作方法の表示の場合 +++ */
//
//		Draw
//		break;
//	case MenuState::GameEnd:
//		/* +++ ゲーム終了画面の場合 +++ */
//
//		DrawFormatStringToHandleAlign(MenuWindowCenterX, MenuWindowCenterY - 200, FAlign_AllCenter, Color_White, , "%s", QuestionGameEnd);	// 「ゲームを終了しますか」の文字列を白で描画
//
//		/* +++ カーソルが接触しているボタンに応じて描画 +++ */
//;		if (CollisionRectToPoint(gameEndYesButtonFrame, nowMousePoint))		// カーソルが「はい」のボタンに接触しているなら
//		{
//			DrawRect(gameEndYesButtonFrame, Color_Red, true, 1);		// 「はい」ボタンの外枠を赤で描画
//			DrawRect(gameEndYesButtonInside, Color_White, true, 1);		// 「はい」ボタンの内側を白で描画
//			DrawRect(gameEndNoButtonFrame, Color_White, true, 1);		// 「いいえ」ボタンの外枠を白で描画
//			DrawRect(gameEndNoButtonInside, Color_Black, true, 1);		// 「いいえ」ボタンの内側を黒で描画
//
//			DrawFormatStringToHandleAlign(GameEndYesButtonCenterX, GameEndButtonCenterY, FAlign_AllCenter, Color_Red, , "%s", ResponseYes);		// 「はい」の文字列を赤で描画
//			DrawFormatStringToHandleAlign(GameEndNoButtonCenterX, GameEndButtonCenterY, FAlign_AllCenter, Color_White, , "%s", ResponseNo);		// 「いいえ」の文字列を白で描画
//		}
//		else if (CollisionRectToPoint(gameEndNoButtonFrame, nowMousePoint))		// カーソルが「いいえ」のボタンに接触しているなら
//		{
//			DrawRect(gameEndYesButtonFrame, Color_White, true, 1);		// 「はい」ボタンの外枠を白で描画
//			DrawRect(gameEndYesButtonInside, Color_Black, true, 1);		// 「はい」ボタンの内側を黒で描画
//			DrawRect(gameEndNoButtonFrame, Color_Red, true, 1);		// 「いいえ」ボタンの外枠を赤で描画
//			DrawRect(gameEndNoButtonInside, Color_White, true, 1);		// 「いいえ」ボタンの内側を白で描画
//
//			DrawFormatStringToHandleAlign(GameEndYesButtonCenterX, GameEndButtonCenterY, FAlign_AllCenter, Color_White, , "%s", ResponseYes);		// 「はい」の文字列を白で描画
//			DrawFormatStringToHandleAlign(GameEndNoButtonCenterX, GameEndButtonCenterY, FAlign_AllCenter, Color_Red, , "%s", ResponseNo);		// 「いいえ」の文字列を赤で描画
//		}
//		else
//		{
//			DrawRect(gameEndYesButtonFrame, Color_White, true, 1);		// 「はい」ボタンの外枠を白で描画
//			DrawRect(gameEndYesButtonInside, Color_Black, true, 1);		// 「はい」ボタンの内側を黒で描画
//			DrawRect(gameEndNoButtonFrame, Color_White, true, 1);		// 「いいえ」ボタンの外枠を白で描画
//			DrawRect(gameEndNoButtonInside, Color_Black, true, 1);		// 「いいえ」ボタンの内側を黒で描画
//
//			DrawFormatStringToHandleAlign(GameEndYesButtonCenterX, GameEndButtonCenterY, FAlign_AllCenter, Color_White, , "%s", ResponseYes);		// 「はい」の文字列を白で描画
//			DrawFormatStringToHandleAlign(GameEndNoButtonCenterX, GameEndButtonCenterY, FAlign_AllCenter, Color_White, , "%s", ResponseNo);		// 「いいえ」の文字列を白で描画
//		}
//		break;
//	case MenuState::Credit:
//		/* +++ 使用楽曲を表示する画面の場合 +++ */
//
//		DrawFormatStringToHandleAlign(MenuWindowCenterX - 200, MenuWindowCenterY - 200, FAlign_AllCenter, Color_LightBlue, , "%s", MusicUsed);			// 「使用楽曲」の文字列を水色で描画
//		DrawFormatStringToHandleAlign(MenuWindowCenterX - 200, MenuWindowCenterY - 50, FAlign_AllCenter, Color_White, , "%s", MaohDamashi);			// 「魔王魂」の文字列を水色で描画
//		DrawFormatStringToHandleAlign(MenuWindowCenterX - 200, MenuWindowCenterY + 150, FAlign_AllCenter, Color_White, , "%s", SoundEffectLab);		// 「効果音ラボ」の文字列を水色で描画
//		DrawFormatStringToHandleAlign(MenuWindowCenterX - 200, MenuWindowCenterY + 300, FAlign_AllCenter, Color_White, , "%s", OtoLogic);			// 「OtoLogic」の文字列を水色で描画
//		
//		DrawFormatStringToHandleAlign(MenuWindowCenterX + 200, MenuWindowCenterY - 200, FAlign_AllCenter, Color_Purple, , "%s", ToolUsed);	// 「使用ツール」の文字列を紫で描画
//		DrawFormatStringToHandleAlign(MenuWindowCenterX + 200, MenuWindowCenterY - 50, FAlign_AllCenter, Color_White, , "%s", DotArt);	// 「DotArt」の文字列を紫で描画
//		break;
//	}

	return;
}

/* --- ゲーム終了フラグを取得するメソッド --- */
bool MenuWindow::GetGameEnd()
{
	return gameEnd;		// ゲーム終了が選択されているかのフラグを返す
}

/* --- ゲーム終了フラグをtrueにするメソッド --- */
void MenuWindow::SetGameEndTrue()
{
	gameEnd = true;		// ゲーム終了が選択されているかをtrueにする

	return;
}

/* --- ゲーム終了フラグをfalseにするメソッド --- */
void MenuWindow::SetGameEndFalse()
{
	gameEnd = false;	// ゲーム終了が選択されているかのフラグをfalseにする

	return;
}

/* --- メニュー画面の状態を取得するメソッド --- */
MenuState MenuWindow::GetMenuState()
{
	return menuState;
}

/* --- メニュー画面の状態を設定するメソッド --- */
void MenuWindow::SetMenuState(MenuState state)
{
	menuState = state;	// メニュー画面の状態を設定

	return;
}