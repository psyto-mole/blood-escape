#pragma once
/* === 矩形の幅と高さを管理するヘッダーファイル === */

#include "DxLib.h"


/* === メニュー === */
/* +++ メニューボックス +++ */
//#define MenuBoxCenterX	(GameWindowWidth - 20)	// ゲーム終了ボックスの中心のX座標
//#define MenuBoxCenterY	20						// ゲーム終了ボックスの中心のY座標
//#define MenuBoxWidth	30						// ゲーム終了ボックスの幅
//#define MenuBoxHeight	30						// ゲーム終了ボックスの高さ
//
///* +++ メニューウィンドウ +++ */
//#define MenuWindowCenterX	(GameWindowWidth / 2)			// メニューウィンドウの中心のX座標
//#define MenuWindowCenterY	(GameWindowHeight / 2 + 50)		// メニューウィンドウの中心のY座標
//#define MenuWindowWidth1	1000							// メニューウィンドウの外枠の幅
//#define MenuWindowHeight1	900								// メニューウィンドウの外枠の高さ
//#define MenuWindowWidth2	994								// メニューウィンドウの内側の矩形の幅
//#define MenuWindowHeight2	894								// メニューウィンドウの内側の矩形の高さ

/* +++ メニューボタン +++ */
//#define MenuButtonCenterX	(GameWindowWidth / 2 - 350)		// メニューボタンの中心のX座標
//#define MenuButton1LineY	(GameWindowHeight / 2 - 350)	// 1行目のメニューボタンの中心のY座標
//#define MenuButton2LineY	(GameWindowHeight / 2 - 250)	// 2行目のメニューボタンの中心のY座標
//#define MenuButton3LineY	(GameWindowHeight / 2 - 150)	// 3行目のメニューボタンの中心のY座標
//#define MenuButton4LineY	(GameWindowHeight / 2 - 50)		// 4行目のメニューボタンの中心のY座標
//#define MenuButton5LineY	(GameWindowHeight / 2 + 50)		// 5行目のメニューボタンの中心のY座標
//#define MenuButtonWidth		270								// メニューボタンの幅
//#define MenuButtonHeight	70								// メニューボタンの高さ

/* +++ 「はい」・「いいえ」ボタン +++ */
#define MenuYesButtonCenterX	(GameWindowWidth / 2)			// メニューウィンドウの「はい」ボタンの中心のX座標
#define MenuNoButtonCenterX		(GameWindowWidth / 2 + 300)		// メニューウィンドウの「いいえ」ボタンの中心のX座標
#define MenuYesNoButtonCenterY	(GameWindowHeight / 2)			// メニューウィンドウの「はい」・「いいえ」ボタンの中心のY座標
#define MenuYesNoButtonWidth	100								// メニューウィンドウの「はい」・「いいえ」ボタンの幅
#define MenuYesNoButtonHeight	50								// メニューウィンドウの「はい」・「いいえ」ボタンの高さ


/* === ゲームオーバーシーン === */
#define GameOverOptionWidth		500
#define GameOverOptionHeight	100	
#define GameOverOption1CenterX	(GameWindowWidth / 2  - GameOverOptionWidth / 2 - 100)
#define GameOverOption2CenterX	(GameWindowWidth / 2  + GameOverOptionWidth / 2 + 100)
#define GameOverOptionCenterY	(GameWindowHeight / 2 + 300)