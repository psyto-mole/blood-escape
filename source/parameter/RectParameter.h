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
#define MenuWindowCenterX			(GameWindowWidth / 2)
#define MenuWindowCenterY			(GameWindowHeight / 2)
#define MenuWindowFrameWidth		720
#define MenuWindowFrameHeight		1280
#define MenuWindowInsideWidth		(MenuWindowFrameWidth - 6)
#define MenuWindowInsideHeightr		(MenuWindowFrameHeight - 6)
#define MenuWindowButtonWidth		200
#define MenuWindowButtonHeight		100
#define MenuWindowButtonCenterX		(GameWindowWidth - 150)
#define MenuWindowButton1CenterY	(GameWindowHeight - 300)
#define MenuWindowButton2CenterY	(MenuWindowButton1CenterY + 150)
#define MenuWindowButton3CenterY	(MenuWindowButton2CenterY + 150)
#define MenuWindowButton4CenterY	(MenuWindowButton3CenterY + 150)


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