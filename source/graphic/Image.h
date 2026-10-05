#pragma once
/* === 画像処理のヘッダファイル === */

#include "DxLib.h"


extern int Image_Init(void);	// 画像の初期化関数
extern void Image_End(void);	// 画像の終了処を行う理関数

extern void DrawGraphOnPoint(POINT center, int width, int height, int imageHandle, int transFlag);			// 画像を中心座標に基づき描画
extern void DrawTurnGraphOnPoint(POINT center, int width, int height, int imageHandle, int transFlag);		// 画像を中心座標に基づき反転して描画
extern void DrawExtendGraphOnPoint(POINT center, int width, int height, int imageHandle, int transFlag);	// 画像を中心座標をもとに拡大・縮小描画する関数
