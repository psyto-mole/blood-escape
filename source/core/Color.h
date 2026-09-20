#pragma once
/* === カラー定義のヘッダファイル === */

#include "DxLib.h"


#define ColorSwitchingRate 5	// 時間経過で変化する色の変化のの割合(各フレームごとにこの割合で色が変化する)

extern int Color_White;			// 白
extern int Color_Black;			// 黒
extern int Color_Gray;			// 灰色
extern int Color_LightGray;		// 明るい灰色
extern int Color_DarkGray;		// 暗い灰色
extern int Color_Red;			// 赤
extern int Color_Green;			// 緑
extern int Color_Blue;			// 青
extern int Color_Yellow;		// 黄
extern int Color_Cyan;			// 水色
extern int Color_Violet;		// 濃い紫
extern int Color_Purple;		// 薄い紫
extern int Color_LightGreen;	// 明るい緑
extern int Color_DarkGreen;		// 暗い緑
extern int Color_LightBlue;		// 明るい青
extern int Color_DarkBlue;		// 暗い青
extern int Color_SkyBlue;		// 空色

extern int Color_SW_Rainbow;	// 時間経過で色が移り変わる虹色
extern int Color_SW_Violet;		// 時間経過で点滅する紫色
extern int Color_SW_Light;		// 時間経過で点滅する白

extern int SW_Red;		// 時間経過で変化するRGBのRの割合を管理する変数
extern int SW_Green;	// 時間経過で変化するRGBのGの割合を管理する変数
extern int SW_Blue;		// 時間経過で変化するRGBのBの割合を管理する変数
extern int SW_Light;	// 時間経過で変化する明暗の割合を管理する変数

/* --- カラーの初期化関数 --- */
extern void Color_Init();

/* --- カラーの処理関数 --- */
extern void Color_Process();

