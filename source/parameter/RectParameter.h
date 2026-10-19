#pragma once
/* === 矩形の幅と高さを管理するヘッダーファイル === */

#include "DxLib.h"
#include "GameManager.h"


/* === メニュー === */
/* +++ メニュータブ +++ */
#define MenuTabCenterX		(GameWindowWidth - 150)
#define MenuTabCenterY		(GameWindowHeight - 100)
#define MenuTabFrameWidth	100
#define MenuTabFrameHeight	50
#define MenuTabInsideWidth	(MenuTabFrameWidth - 4)
#define MenuTabInsideHeight	(MenuTabFrameHeight - 4)

/* +++ メニュー画面 +++ */
#define MenuWindowCenterX		(GameWindowWidth / 2)
#define MenuWindowCenterY		(GameWindowHeight / 2)
#define MenuWindowFrameWidth	720
#define MenuWindowFrameHeight	1280
#define MenuWindowInsideWidth	(MenuWindowFrameWidth - 6)
#define MenuWindowInsideHeight	(MenuWindowFrameHeight - 6)

#define MenuTopButtonFrameWidth		200
#define MenuTopButtonFrameHeight	100
#define MenuTopButtonInsideWidth	(MenuTopButtonFrameWidth - 4)
#define MenuTopButtonInsideHeight	(MenuTopButtonFrameHeight - 4)
#define MenuTopButtonCenterX		(GameWindowWidth - 150)
#define MenuTopButton1CenterY		(GameWindowHeight - 300)
#define MenuTopButton2CenterY		(MenuTopButton1CenterY + 150)
#define MenuTopButton3CenterY		(MenuTopButton2CenterY + 150)
#define MenuTopButton4CenterY		(MenuTopButton3CenterY + 150)

#define BackTopButtonCenterX		(MenuWindowCenterX - MenuWindowFrameWidth / 2 + 50)
#define BackTopButtonCenterY		(MenuWindowCenterY - MenuWindowFrameHeight / 2 + 25)
#define BackTopButtonFrameWidth		100
#define BackTopButtonFrameHeight	50
#define BackTopButtonInsideWidth	(BackTopButtonFrameWidth - 4)
#define BackTopButtonInsideHeight	(BackTopButtonFrameHeight - 4)

#define GameEndYesButtonCenterX		(MenuWindowCenterX - 150)
#define GameEndNoButtonCenterX		(MenuWindowCenterX + 150)
#define GameEndButtonCenterY		(MenuWindowCenterY + 100)
#define GameEndButtonFrameWidth		200
#define GameEndButtonFrameHeight	100
#define GameEndButtonInsideWidth	(GameEndButtonFrameWidth - 6)
#define GameEndButtonInsideHeight	(GameEndButtonFrameHeight - 6)


/* === ステージシーン === */
/* +++ プレイヤー +++ */
#define PlayerInteractRextWidth		32	// プライヤーのインタラクト判定の幅
#define PlayerInteractRextHeight	32	// プライヤーのインタラクト判定の高さ

/* +++ プレイヤーUI +++ */
#define PlayerHPBarCenterY		(GameWindowHeight - 100)							// プレイヤーのHPバーの中心のY座標
#define PlayerHPBarHeight		50													// プレイヤーのHPバーの高さ
#define PlayerHPBarUpperLeftX	(GameWindowWidth - 150)								// プレイヤーのHPバーの左上のX座標
#define PlayerHPBarUpperLeftY	(PlayerHPBarCenterY - PlayerHPBarHeight / 2)		// プレイヤーのHPバーの左上のY座標
#define PlayerHPBarLowerRightY	(PlayerHPBarCenterY + PlayerHPBarHeight / 2 + 1)	// プレイヤーのHPバーの右下Yの座標


/* === ゲームオーバーシーン === */
#define GameOverOptionWidth		500
#define GameOverOptionHeight	100	
#define GameOverOption1CenterX	(GameWindowWidth / 2  - GameOverOptionWidth / 2 - 100)
#define GameOverOption2CenterX	(GameWindowWidth / 2  + GameOverOptionWidth / 2 + 100)
#define GameOverOptionCenterY	(GameWindowHeight / 2 + 300)