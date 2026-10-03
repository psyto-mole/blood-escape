#pragma once
/* === フォント処理のヘッダーファイル === */

#include "DxLib.h"

#define FontAlignStringMax 256	// 文字揃えができる最大長

// 文字揃えの列挙型
enum Font_Align
{
	FAlign_Left,		// 左揃え
	FAlign_Center,		// 中央揃え
	FAlign_Right,		// 右揃え
	FAlign_AllCenter	// 上下左右ともに中央揃え
};

/* +++ DXフォントファイルのパス +++ */
#define PathKHDotS100T9B1	".\\font\\KHDot\\KHDot_Hibiya24_S100_T9_B1.dft"
#define PathKHDotS100T9B4	".\\font\\KHDot\\KHDot_Hibiya24_S100_T9_B4.dft"
#define PathKHDotS30T1B1	".\\font\\KHDot\\KHDot_Kagurazaka12_S30_T1_B1.dft"
#define PathKHDotS30T1B4	".\\font\\KHDot\\KHDot_Kagurazaka12_S30_T1_B4.dft"

/* +++ 横書きフォント +++ */
extern int KHDot_30_1;		// KHドットフォント(サイズ30、太さ1)
extern int KHDot_100_9;		// KHドットフォント(サイズ100、太さ9)

/* +++ 縦書きフォント +++ */
//extern int V_30_1;	// (サイズ30、太さ)

/* --- フォントの初期化関数 --- */
extern int Font_Init(void);

/* --- フォントの終了処理を行う関数 --- */
extern void Font_End(void);

/* --- 文字列を指定フォント・指定の揃えで横書きする関数 --- */
extern void DrawFormatStringToHandleAlign(int x, int y, Font_Align align,
	unsigned int Color, int FontHandle, const char* FormatString, ...);

/* --- 文字列を指定フォント・指定の揃えで縦書きする関数 --- */
extern void DrawFormatVStringToHandleAlign(int x, int y, Font_Align align,
	unsigned int color, int fontHandle, const char* formatString, ...);

