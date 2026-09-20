#pragma once
/* === 幾何学処理のヘッダファイル === */

#include <math.h>
#include "DxLib.h"


/* --- 円の構造体 --- */
typedef struct _CIRCLE
{
	POINT point;	// 円の中心座標
	float radius;	// 円の半径
}CIRCLE;

/* --- 直線の構造体 --- */
typedef struct _LINE
{
	POINT startPoint;	// 直線の始点
	POINT endPoint;		// 直線の終点
	int Thickness;		// 直線の太さ
}LINE;


/* === ゲーム画面 === */
extern POINT GameWindowCenter;	// ゲーム画面の中心点


/* === システムメニュー === */
/* +++ メニューボックス +++ */
//extern RECT menuBox;	// メニューボックスの矩形
//extern LINE menuLine1;	// メニューボックスのライン1
//extern LINE menuLine2;	// メニューボックスのライン2
//extern LINE menuLine3;	// メニューボックスのライン3

/* +++ メニューウィンドウ +++ */
//extern RECT menuWindow1;		// メニューウィンドウの外枠
//extern RECT menuWindow2;		// メニューウィンドウの内側
//extern LINE devideMenuWindow;	// メニューウィンドウを分割する直線
//extern RECT menuButton1;		// メニューウィンドウのボタン1
//extern RECT menuButton2;		// メニューウィンドウのボタン2
//extern RECT menuButton3;		// メニューウィンドウのボタン3
//extern RECT menuButton4;		// メニューウィンドウのボタン4
//extern RECT menuButton5;		// メニューウィンドウのボタン5
//extern RECT menuYesButton;		// メニューウィンドウの「はい」ボタン
//extern RECT menuNoButton;		// メニューウィンドウの「いいえ」ボタン


/* +++ 幾何学処理の関数 +++ */
extern void Geometry_Init(void);	// 幾何学処理の初期化関数

/* +++ 点に関する関数 +++ */
extern POINT GetPoint(int x, int y);						// X座標とY座標からPOINT型を取得
extern bool CollisionPointToPoint(POINT a, POINT b);		// 点と点が接触しているか
extern void DrawPoint(POINT point, unsigned int color);		// POINT型から点を描画

/* +++ 線に関する関数 +++ */
extern LINE GetLine(POINT a, POINT b, int Thickness);			// 始点と終点からLINE型を取得
extern void DrawLineWithStruct(LINE line, unsigned int color);	// LINE型から直線を描画

/* +++ 矩形に関する関数 +++ */
extern RECT GetRect(int left, int top, int right, int bottom);																	// RECT型を一時的に取得
extern RECT GetRectOnPoint(int centerX, int centerY, int width, int height);													// 中心座標と幅、高さからRECT型を一時的に取得
extern POINT GetRectCenter(RECT rect);																							// 矩形の中心座標を取得
extern void DrawRect(RECT rect, unsigned int color, bool fill, int lineThickness);												// 矩形を描画
extern void DrawBoxOnPoint(int centerX, int centerY, int width, int height, unsigned int color, bool fill, int lineThickness);	// 矩形を中心点を用いて描画
extern bool CollisionRectToPoint(RECT rect, POINT point);																		// 矩形と点が接触しているか
extern bool CollisionRectToRect(RECT a, RECT b);																				// 矩形と矩形が接触している

/* +++ 円に関する関数 +++ */
extern CIRCLE GetCircle(POINT point, float radius);										// CIRCLE型を取得する関数
extern void DrawCircleWithStruct(CIRCLE circle, int color, bool fill, int thickness);	// CIRCLE型を用いて円を描画する関数
