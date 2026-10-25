#pragma once
/* === フォント処理のヘッダーファイル === */

#include "DxLib.h"


#define FontAlignStringMax 256	// 文字揃えができる最大長

// 文字揃えの列挙型
enum Font_Align
{
	FAlign_Left,		// 左揃え
	FAlign_LeftCenter,	// 左揃え(高さは中央ぞろえ)
	FAlign_Center,		// 中央揃え
	FAlign_Right,		// 右揃え
	FAlign_AllCenter	// 上下左右ともに中央揃え
};

/* +++ DXフォントファイルのパス +++ */
#define PathKHDotS200T9B1	".\\font\\KHDot\\KHDot_Hibiya24_S200_T9_B1.dft"
#define PathKHDotS100T9B1	".\\font\\KHDot\\KHDot_Hibiya24_S100_T9_B1.dft"
#define PathKHDotS50T2B1	".\\font\\KHDot\\KHDot_Kagurazaka12_S50_T2_B1.dft"
#define PathKHDotS40T2B1	".\\font\\KHDot\\KHDot_Kagurazaka12_S40_T2_B1.dft"
#define PathKHDotS30T1B1	".\\font\\KHDot\\KHDot_Kagurazaka12_S30_T1_B1.dft"
#define PathKHDotS20T1B1	".\\font\\KHDot\\KHDot_Kagurazaka12_S20_T1_B1.dft"

/* +++ 横書きフォント +++ */
extern int KHDot_20_1;		// KHドットフォント(サイズ20、太さ1)
extern int KHDot_30_1;		// KHドットフォント(サイズ30、太さ1)
extern int KHDot_40_2;		// KHドットフォント(サイズ40、太さ2)
extern int KHDot_50_2;		// KHドットフォント(サイズ50、太さ2)
extern int KHDot_100_9;		// KHドットフォント(サイズ100、太さ9)
extern int KHDot_200_9;		// KHドットフォント(サイズ200、太さ9)

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

