#pragma once
/* === 矩形の幅と高さを管理するヘッダーファイル === */

#include "DxLib.h"
#include "GameManager.h"


/* === メニュー === */
/* +++ メニュータブ +++ */
#define MenuTabCenterX		(GameWindowWidth - 150)
#define MenuTabCenterY		(GameWindowHeight - 100)
#define MenuTabFrameWidth	200
#define MenuTabFrameHeight	50
#define MenuTabInsideWidth	(MenuTabFrameWidth - 4)
#define MenuTabInsideHeight	(MenuTabFrameHeight - 4)

/* +++ メニュー画面 +++ */
#define MenuWindowCenterX		(GameWindowWidth / 2)			// メニュー画面のウィンドウの中心のX座標
#define MenuWindowCenterY		(GameWindowHeight / 2)			// メニュー画面のウィンドウの中心のY座標
#define MenuWindowFrameWidth	1200							// メニュー画面のウィンドウの外枠の幅
#define MenuWindowFrameHeight	1000							// メニュー画面のウィンドウの外枠の高さ
#define MenuWindowInsideWidth	(MenuWindowFrameWidth - 6)		// メニュー画面のウィンドウの内側の幅
#define MenuWindowInsideHeight	(MenuWindowFrameHeight - 6)		// メニュー画面のウィンドウの内側の高さ

#define MenuTopButtonFrameWidth		400								// メニュー画面トップの選択肢のボタンの外枠の幅
#define MenuTopButtonFrameHeight	100								// メニュー画面トップの選択肢のボタンの外枠の高さ
#define MenuTopButtonInsideWidth	(MenuTopButtonFrameWidth - 4)	// メニュー画面トップの選択肢のボタンの内側の幅
#define MenuTopButtonInsideHeight	(MenuTopButtonFrameHeight - 4)	// メニュー画面トップの選択肢のボタンの内側の高さ
#define MenuTopButtonCenterX		MenuWindowCenterX				// メニュー画面トップの選択肢のボタンの中心のX座標
#define MenuTopButton1CenterY		(MenuWindowCenterY - 300)		// メニュー画面トップの選択肢のボタン1の中心のY座標
#define MenuTopButton2CenterY		(MenuTopButton1CenterY + 150)	// メニュー画面トップの選択肢のボタン2の中心のY座標
#define MenuTopButton3CenterY		(MenuTopButton2CenterY + 150)	// メニュー画面トップの選択肢のボタン3の中心のY座標
#define MenuTopButton4CenterY		(MenuTopButton3CenterY + 150)	// メニュー画面トップの選択肢のボタン4の中心のY座標

#define BackTopButtonFrameWidth		250																				// メニュー画面トップに戻るボタンの外枠の幅
#define BackTopButtonFrameHeight	50																				// メニュー画面トップに戻るボタンの外枠の高さ
#define BackTopButtonCenterX		(MenuWindowCenterX - MenuWindowFrameWidth / 2 + BackTopButtonFrameWidth / 2)	// メニュー画面トップに戻るボタンの中心のX座標
#define BackTopButtonCenterY		(MenuWindowCenterY - MenuWindowFrameHeight / 2 + BackTopButtonFrameHeight / 2)	// メニュー画面トップに戻るボタンの中心のY座標
#define BackTopButtonInsideWidth	(BackTopButtonFrameWidth - 4)													// メニュー画面トップに戻るボタンの内側の幅
#define BackTopButtonInsideHeight	(BackTopButtonFrameHeight - 4)													// メニュー画面トップに戻るボタンの内側の高さ

#define GameEndYesButtonCenterX		(MenuWindowCenterX - 150)		// ゲーム終了画面の「はい」ボタンの中心のY座標
#define GameEndNoButtonCenterX		(MenuWindowCenterX + 150)		// ゲーム終了画面の「いいえ」ボタンの中心のX座標
#define GameEndButtonCenterY		(MenuWindowCenterY + 100)		// ゲーム終了画面のボタンの選択肢ボタンの中心のY座標
#define GameEndButtonFrameWidth		200								// ゲーム終了画面のボタンの外枠の選択肢ボタンの幅
#define GameEndButtonFrameHeight	100								// ゲーム終了画面のボタンの外枠の選択肢ボタンの高さ
#define GameEndButtonInsideWidth	(GameEndButtonFrameWidth - 6)	// ゲーム終了画面のボタンの内側の選択肢ボタンの幅
#define GameEndButtonInsideHeight	(GameEndButtonFrameHeight - 6)	// ゲーム終了画面のボタンの内側の選択肢ボタンの高さ


/* === ステージシーン === */
/* +++ プレイヤー +++ */
#define PlayerInteractRextWidth		32	// プライヤーのインタラクト判定の幅
#define PlayerInteractRextHeight	32	// プライヤーのインタラクト判定の高さ

/* +++ プレイヤーUI +++ */
#define PlayerHPBarCenterY		(GameWindowHeight - 100)							// プレイヤーのHPバーの中心のY座標
#define PlayerHPBarHeight		50													// プレイヤーのHPバーの高さ
#define PlayerHPBarUpperLeftX	(GameWindowWidth / 2)								// プレイヤーのHPバーの左上のX座標
#define PlayerHPBarUpperLeftY	(PlayerHPBarCenterY - PlayerHPBarHeight / 2)		// プレイヤーのHPバーの左上のY座標
#define PlayerHPBarLowerRightY	(PlayerHPBarCenterY + PlayerHPBarHeight / 2 + 1)	// プレイヤーのHPバーの右下Yの座標


/* === ゲームオーバーシーン === */
#define GameOverOptionWidth		500
#define GameOverOptionHeight	100	
#define GameOverOption1CenterX	(GameWindowWidth / 2  - GameOverOptionWidth / 2 - 100)
#define GameOverOption2CenterX	(GameWindowWidth / 2  + GameOverOptionWidth / 2 + 100)
#define GameOverOptionCenterY	(GameWindowHeight / 2 + 300)