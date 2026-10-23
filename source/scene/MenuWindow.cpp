/* === メニュー画面関連の処理のソースファイル === */

#include "MenuWindow.h"
#include "GameManager.h"
#include "Key.h"
#include "Mouse.h"
#include "Geometry.h"
#include "Color.h"
#include "Font.h"
#include "Sound.h"
#include "Message.h"
#include "Rectparameter.h"


/* --- コンストラクタ --- */
MenuWindow::MenuWindow()
{
	selectedIndex = 1;	// 選択している選択肢の番号を初期化

	gameEnd = false;	// ゲーム終了フラグをfalseにする

	menuState = MenuState::Close;	// メニュー画面を閉じている状態に設定
}

/* --- デストラクタ --- */
MenuWindow::~MenuWindow()
{

}

/* --- メニュー画面の初期化メソッド --- */
void MenuWindow::Init()
{
	selectedIndex = 1;	// 選択している選択肢の番号を初期化

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

		if (Key_Check_Click(KEY_INPUT_UP))	// 上キーが押されたら
		{
			selectedIndex--;	// 選択している選択肢の番号を1減らす

			if(selectedIndex <= 0)	// 選択している選択肢の番号が0以下になったら
			{
				selectedIndex = NumberOfMenuTopOption;	// 選択している選択肢の番号を最後に設定
			}

			Sound_Play(SE_Select);   // 選択肢の変更のSEを再生
		}
		else if (Key_Check_Click(KEY_INPUT_DOWN))	// 下キーが押されたら
		{
			selectedIndex++;	// 選択している選択肢の番号を1増やす

			if (selectedIndex > NumberOfMenuTopOption)	// 選択している選択肢の番号が最大値を超えたら
			{
				selectedIndex = 1;	// 最初の選択肢の戻す
			}

			Sound_Play(SE_Select);   // 選択肢の変更のSEを再生
		}

		if (Key_Check_Click(KEY_INPUT_RETURN))	// エンターキーが押された
		{
			/* +++ 選択されている選択肢の番号に応じて処理を変える +++ */
			switch (selectedIndex)
			{
			case 1:
				/* +++「 操作方法」が選択されている +++ */

				selectedIndex = 1;	// 選択している選択肢の番号を1に設定

				SetMenuState(MenuState::Operation);		// メニューの状態を操作方法表示に設定

				Sound_Play(SE_Enter);   // エンターキーを押した時のSEを再生
				break;
			case 2:
				/* +++ 「ゲームを終了」が選択されている +++ */

				selectedIndex = 2;	// 選択している選択肢の番号を2(「はい」)に設定

				SetMenuState(MenuState::GameEnd);	// メニューの状態をゲーム終了画面に設定

				Sound_Play(SE_Enter);   // エンターキーを押した時のSEを再生
				break;
			case 3:
				/* +++ 「使用楽曲」が選択されている +++ */

				selectedIndex = 1;	// 選択している選択肢の番号を1に設定

				SetMenuState(MenuState::Credit);	// メニューの状態を使用楽曲の表示に設定

				Sound_Play(SE_Enter);   // エンターキーを押した時のSEを再生
				break;
			case 4:
				/* +++ 「戻る」が選択されている +++ */

				selectedIndex = 1;	// 選択している選択肢の番号を1に設定

				SetMenuState(MenuState::Close);		// メニューを閉じる

				Sound_Play(SE_Cancel);   // 選択肢の取り消しのSEを再生
				break;
			}
		}
		break;
	case MenuState::Operation:
		/* +++ 操作方法の説明画面の場合 +++ */

		if (Key_Check_Click(KEY_INPUT_RETURN))	// エンターキーが押された
		{
			selectedIndex = 1;	// 選択している選択肢の番号を1に設定

			SetMenuState(MenuState::MenuTop);	// メニュー画面トップに戻る

			Sound_Play(SE_Cancel);   // 選択肢の取り消しのSEを再生
		}
		break;
	case MenuState::GameEnd:
		/* +++ ゲーム終了画面の場合 +++ */

		if (Key_Check_Click(KEY_INPUT_LEFT))	// 左キーが押されたら
		{
			selectedIndex--;	// 選択している選択肢の番号を1減らす

			if (selectedIndex <= 0)	// 選択している選択肢の番号が0以下になったら
			{
				selectedIndex = NumberOfGameEndOption;	// 選択している選択肢の番号を最後に設定
			}

			Sound_Play(SE_Select);   // 選択肢の変更のSEを再生
		}
		else if (Key_Check_Click(KEY_INPUT_RIGHT))	// 右キーが押されたら
		{
			selectedIndex++;	// 選択している選択肢の番号を1増やす

			if (selectedIndex > NumberOfGameEndOption)	// 選択している選択肢の番号が最大値を超えたら
			{
				selectedIndex = 1;	// 最初の選択肢の戻す
			}

			Sound_Play(SE_Select);   // 選択肢の変更のSEを再生
		}

		if (Key_Check_Click(KEY_INPUT_RETURN))
		{
			switch (selectedIndex)
			{
			case 1:
				/* +++ 「戻る」が選択されている場合 +++ */

				selectedIndex = 1;	// 選択している選択肢の番号を1に設定

				SetMenuState(MenuState::MenuTop);	// メニュー画面の状態をメニュートップにする

				Sound_Play(SE_Cancel);  // 選択肢を取り消した時のSEを再生
				break;
			case 2:
				/* +++ 「はい」が選択されている場合 +++ */

				SetGameEndTrue();	// ゲーム終了を選択状態にする

				Sound_Play(SE_Enter);   // エンターキーを押した時のSEを再生
				break;
			case 3:
				/* +++ 「いいえ」が選択されている場合 +++ */

				selectedIndex = 1;	// 選択している選択肢の番号を1に設定

				SetMenuState(MenuState::MenuTop);	// メニュー画面の状態をメニュートップにする

				Sound_Play(SE_Cancel);  // 選択肢を取り消した時のSEを再生
				break;
			}
		}
		break;
	case MenuState::Credit:
		/* +++ 使用楽曲の説明画面の場合 +++ */

		if (Key_Check_Click(KEY_INPUT_RETURN))	// エンターキーが押された
		{
			selectedIndex = 1;	// 選択している選択肢の番号を1に設定

			SetMenuState(MenuState::MenuTop);	// メニュー画面トップに戻る

			Sound_Play(SE_Cancel);   // 選択肢の取り消しのSEを再生
		}
		break;
	}

	return;
}

/* --- メニュー画面の描画メソッド --- */
void MenuWindow::Draw()
{
	if (menuState == MenuState::Close)	// メニュー画面が閉じれれている状態なら
	{
		return;		// 何もせずに終了
	}

	if (GameDebug)
	{
		DrawFormatStringToHandleAlign(GameWindowWidth - 200, GameWindowHeight / 2, FAlign_AllCenter,  Color_LightGreen, KHDot_30_1,  "selectedIndex : %d", selectedIndex);
	}

	DrawRect(menuWindowFrame, Color_White, true, 1);	// メニュー画面の外枠を描画
	DrawRect(menuWindowInside, Color_Black, true, 1);	// メニュー画面の内側を描画

	/* +++ メニュー画面の状態に応じて描画する +++ */
	switch (menuState)
	{
	case MenuState::MenuTop:
		/* +++ メニュートップの場合 +++ */

		/* +++ 選択されているボタンを色を変えて描画 +++ */
		switch (selectedIndex)
		{
		case 1:
			/* +++ 「操作方法」が選択されている +++ */

			/* +++ ボタン1を赤枠に白、それ以外を白枠に黒で描画 +++ */
			DrawRect(menuTopButton1Frame, Color_Red, true, 1);
			DrawRect(menuTopButton1Inside, Color_White, true, 1);
			DrawRect(menuTopButton2Frame, Color_White, true, 1);
			DrawRect(menuTopButton2Inside, Color_Black, true, 1);
			DrawRect(menuTopButton3Frame, Color_White, true, 1);
			DrawRect(menuTopButton3Inside, Color_Black, true, 1);
			DrawRect(menuTopButton4Frame, Color_White, true, 1);
			DrawRect(menuTopButton4Inside, Color_Black, true, 1);

			/* +++ ボタン1の文字列を赤で、それ以外を白で描画 +++ */
			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton1CenterY, FAlign_AllCenter, Color_Red, KHDot_50_2, "%s", OptionMenuWindowOperation);
			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton2CenterY, FAlign_AllCenter, Color_White, KHDot_50_2, "%s", OptionMenuWindowEndGame);
			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton3CenterY, FAlign_AllCenter, Color_White, KHDot_50_2, "%s", OptionMenuWindowCredit);
			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton4CenterY, FAlign_AllCenter, Color_White, KHDot_50_2, "%s", OptionMenuWindowBack);
			break;
		case 2:
			/* +++ 「ゲーム終了」が選択されている +++ */

			/* +++ ボタン2を赤枠に白、それ以外を白枠に黒で描画 +++ */
			DrawRect(menuTopButton1Frame, Color_White, true, 1);
			DrawRect(menuTopButton1Inside, Color_Black, true, 1);
			DrawRect(menuTopButton2Frame, Color_Red, true, 1);
			DrawRect(menuTopButton2Inside, Color_White, true, 1);
			DrawRect(menuTopButton3Frame, Color_White, true, 1);
			DrawRect(menuTopButton3Inside, Color_Black, true, 1);
			DrawRect(menuTopButton4Frame, Color_White, true, 1);
			DrawRect(menuTopButton4Inside, Color_Black, true, 1);

			/* +++ ボタン2の文字列を赤で、それ以外を白で描画 +++ */
			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton1CenterY, FAlign_AllCenter, Color_White, KHDot_50_2, "%s", OptionMenuWindowOperation);
			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton2CenterY, FAlign_AllCenter, Color_Red, KHDot_50_2, "%s", OptionMenuWindowEndGame);
			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton3CenterY, FAlign_AllCenter, Color_White, KHDot_50_2, "%s", OptionMenuWindowCredit);
			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton4CenterY, FAlign_AllCenter, Color_White, KHDot_50_2, "%s", OptionMenuWindowBack);
			break;
		case 3:
			/* +++ 「使用楽曲」が選択されている +++ */

			/* +++ ボタン3を赤枠に白、それ以外を白枠に黒で描画 +++ */
			DrawRect(menuTopButton1Frame, Color_White, true, 1);
			DrawRect(menuTopButton1Inside, Color_Black, true, 1);
			DrawRect(menuTopButton2Frame, Color_White, true, 1);
			DrawRect(menuTopButton2Inside, Color_Black, true, 1);
			DrawRect(menuTopButton3Frame, Color_Red, true, 1);
			DrawRect(menuTopButton3Inside, Color_White, true, 1);
			DrawRect(menuTopButton4Frame, Color_White, true, 1);
			DrawRect(menuTopButton4Inside, Color_Black, true, 1);

			/* +++ ボタン3の文字列を赤で、それ以外を白で描画 +++ */
			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton1CenterY, FAlign_AllCenter, Color_White, KHDot_50_2, "%s", OptionMenuWindowOperation);
			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton2CenterY, FAlign_AllCenter, Color_White, KHDot_50_2, "%s", OptionMenuWindowEndGame);
			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton3CenterY, FAlign_AllCenter, Color_Red, KHDot_50_2, "%s", OptionMenuWindowCredit);
			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton4CenterY, FAlign_AllCenter, Color_White, KHDot_50_2, "%s", OptionMenuWindowBack);
			break;
		case 4:
			/* +++ 「戻る」が選択されている +++*/

			/* +++ ボタン4を赤枠に白、それ以外を白枠に黒で描画 +++ */
			DrawRect(menuTopButton1Frame, Color_White, true, 1);
			DrawRect(menuTopButton1Inside, Color_Black, true, 1);
			DrawRect(menuTopButton2Frame, Color_White, true, 1);
			DrawRect(menuTopButton2Inside, Color_Black, true, 1);
			DrawRect(menuTopButton3Frame, Color_White, true, 1);
			DrawRect(menuTopButton3Inside, Color_Black, true, 1);
			DrawRect(menuTopButton4Frame, Color_Red, true, 1);
			DrawRect(menuTopButton4Inside, Color_White, true, 1);

			/* +++ ボタン4の文字列を赤で、それ以外を白で描画 +++ */
			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton1CenterY, FAlign_AllCenter, Color_White, KHDot_50_2, "%s", OptionMenuWindowOperation);
			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton2CenterY, FAlign_AllCenter, Color_White, KHDot_50_2, "%s", OptionMenuWindowEndGame);
			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton3CenterY, FAlign_AllCenter, Color_White, KHDot_50_2, "%s", OptionMenuWindowCredit);
			DrawFormatStringToHandleAlign(MenuTopButtonCenterX, MenuTopButton4CenterY, FAlign_AllCenter, Color_Red, KHDot_50_2, "%s", OptionMenuWindowBack);
			break;
		}
		break;
	case MenuState::Operation:
		/* +++ 操作方法の表示の場合 +++ */

		//Draw
		break;
	case MenuState::GameEnd:
		/* +++ ゲーム終了画面の場合 +++ */

		DrawFormatStringToHandleAlign(MenuWindowCenterX, MenuWindowCenterY - 200, FAlign_AllCenter, Color_White, KHDot_50_2, "%s", QuestionGameEnd);	// 「ゲームを終了しますか」の文字列を白で描画

		/* +++ 選択されているボタンに応じて描画 +++ */
		;		switch (selectedIndex)
		{
		case 2:
			/* +++ 「はい」が選択されている +++ */

			DrawRect(gameEndYesButtonFrame, Color_Red, true, 1);		// 「はい」ボタンの外枠を赤で描画
			DrawRect(gameEndYesButtonInside, Color_White, true, 1);		// 「はい」ボタンの内側を白で描画
			DrawRect(gameEndNoButtonFrame, Color_White, true, 1);		// 「いいえ」ボタンの外枠を白で描画
			DrawRect(gameEndNoButtonInside, Color_Black, true, 1);		// 「いいえ」ボタンの内側を黒で描画

			DrawFormatStringToHandleAlign(GameEndYesButtonCenterX, GameEndButtonCenterY, FAlign_AllCenter, Color_Red, KHDot_50_2, "%s", ResponseYes);		// 「はい」の文字列を赤で描画
			DrawFormatStringToHandleAlign(GameEndNoButtonCenterX, GameEndButtonCenterY, FAlign_AllCenter, Color_White, KHDot_50_2, "%s", ResponseNo);		// 「いいえ」の文字列を白で描画
			break;
		case 3:
			/* +++ 「いいえ」が選択されている +++ */

			DrawRect(gameEndYesButtonFrame, Color_White, true, 1);		// 「はい」ボタンの外枠を白で描画
			DrawRect(gameEndYesButtonInside, Color_Black, true, 1);		// 「はい」ボタンの内側を黒で描画
			DrawRect(gameEndNoButtonFrame, Color_Red, true, 1);			// 「いいえ」ボタンの外枠を赤で描画
			DrawRect(gameEndNoButtonInside, Color_White, true, 1);		// 「いいえ」ボタンの内側を白で描画

			DrawFormatStringToHandleAlign(GameEndYesButtonCenterX, GameEndButtonCenterY, FAlign_AllCenter, Color_White, KHDot_50_2, "%s", ResponseYes);		// 「はい」の文字列を白で描画
			DrawFormatStringToHandleAlign(GameEndNoButtonCenterX, GameEndButtonCenterY, FAlign_AllCenter, Color_Red, KHDot_50_2, "%s", ResponseNo);		// 「いいえ」の文字列を赤で描画
			break;
		default:
			/* +++ どちらも選択されていない +++ */

			DrawRect(gameEndYesButtonFrame, Color_White, true, 1);		// 「はい」ボタンの外枠を白で描画
			DrawRect(gameEndYesButtonInside, Color_Black, true, 1);		// 「はい」ボタンの内側を黒で描画
			DrawRect(gameEndNoButtonFrame, Color_White, true, 1);		// 「いいえ」ボタンの外枠を白で描画
			DrawRect(gameEndNoButtonInside, Color_Black, true, 1);		// 「いいえ」ボタンの内側を黒で描画

			DrawFormatStringToHandleAlign(GameEndYesButtonCenterX, GameEndButtonCenterY, FAlign_AllCenter, Color_White, KHDot_50_2, "%s", ResponseYes);		// 「はい」の文字列を白で描画
			DrawFormatStringToHandleAlign(GameEndNoButtonCenterX, GameEndButtonCenterY, FAlign_AllCenter, Color_White, KHDot_50_2, "%s", ResponseNo);		// 「いいえ」の文字列を白で描画
			break;
		}
		break;
	case MenuState::Credit:
		/* +++ 使用楽曲を表示する画面の場合 +++ */

		DrawFormatStringToHandleAlign(MenuWindowCenterX - 200, MenuWindowCenterY - 200, FAlign_AllCenter, Color_LightBlue, KHDot_50_2, "%s", MusicUsed);	// 「使用楽曲」の文字列を水色で描画
		DrawFormatStringToHandleAlign(MenuWindowCenterX - 200, MenuWindowCenterY - 150, FAlign_AllCenter, Color_White, KHDot_30_1, "%s", MaohDamashi);		// 「魔王魂」の文字列を水色で描画
		DrawFormatStringToHandleAlign(MenuWindowCenterX - 200, MenuWindowCenterY - 100, FAlign_AllCenter, Color_White, KHDot_30_1, "%s", SoundEffectLab);	// 「効果音ラボ」の文字列を水色で描画
		DrawFormatStringToHandleAlign(MenuWindowCenterX - 200, MenuWindowCenterY - 50, FAlign_AllCenter, Color_White, KHDot_30_1, "%s", OtoLogic);			// 「OtoLogic」の文字列を水色で描画
		
		DrawFormatStringToHandleAlign(MenuWindowCenterX + 200, MenuWindowCenterY - 200, FAlign_AllCenter, Color_Purple, KHDot_50_2, "%s", ToolUsed);	// 「使用ツール」の文字列を紫で描画
		DrawFormatStringToHandleAlign(MenuWindowCenterX + 200, MenuWindowCenterY - 150, FAlign_AllCenter, Color_White, KHDot_30_1, "%s", DotArt);		// 「DotArt」の文字列を紫で描画
		break;
	}

	/* +++ メニュー画面トップに戻るボタンの描画 +++ */
	if (menuState != MenuState::MenuTop)	// メニューの状態がメニュー画面トップでないなら
	{
		if (selectedIndex == 1)		// 「メニュートップ」ボタンが選択されているなら
		{
			DrawRect(backTopButtonFrame, Color_White, true, 1);		// ボタンの外枠を白で描画
			DrawRect(backTopButtonInside, Color_Red, true, 1);		// ボタンの内側を赤で描画

			DrawFormatStringToHandleAlign(BackTopButtonCenterX, BackTopButtonCenterY, FAlign_AllCenter, Color_White, KHDot_30_1, "%s", BackButtonText);		// 「メニュートップ」の文字列を白で描画
		}
		else
		{
			DrawRect(backTopButtonFrame, Color_White, true, 1);		// ボタンの外枠を白で描画
			DrawRect(backTopButtonInside, Color_Black, true, 1);	// ボタンの内側を黒で描画

			DrawFormatStringToHandleAlign(BackTopButtonCenterX, BackTopButtonCenterY, FAlign_AllCenter, Color_White, KHDot_30_1, "%s", BackButtonText);		// 「メニュートップ」の文字列を白で描画
		}
	}

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