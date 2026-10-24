/* === フォント処理のソースファイル === */

#include "Font.h"


/* +++ 横書きフォント +++ */
int KHDot_20_1;		// KHドットフォント(サイズ20、太さ1)
int KHDot_30_1;		// KHドットフォント(サイズ30、太さ1)
int KHDot_40_2;		// KHドットフォント(サイズ40、太さ2)
int KHDot_50_2;		// KHドットフォント(サイズ50、太さ2)
int KHDot_100_9;	// KHドットフォント(サイズ100、太さ9)
int KHDot_200_9;	// KHドットフォント(サイズ200、太さ9)

/* +++ 縦書きフォント +++ */
//int V_30_1;	// (サイズ30、太さ)

/* --- フォントの初期化関数 --- */
int Font_Init()
{
	/* === フォントデータの作成 === */
	/* +++ 横書きフォント +++ */
	KHDot_20_1	= LoadFontDataToHandle(PathKHDotS20T1B1, 0);	// KHドットフォント(サイズ20、太さ1)
	KHDot_30_1	= LoadFontDataToHandle(PathKHDotS30T1B1, 0);	// KHドットフォント(サイズ30、太さ1)
	KHDot_40_2	= LoadFontDataToHandle(PathKHDotS40T2B1, 0);	// KHドットフォント(サイズ40、太さ2)
	KHDot_50_2	= LoadFontDataToHandle(PathKHDotS50T2B1, 0);	// KHドットフォント(サイズ50、太さ2)
	KHDot_100_9 = LoadFontDataToHandle(PathKHDotS100T9B1, 0);	// KHドットフォント(サイズ100、太さ9)
	KHDot_200_9 = LoadFontDataToHandle(PathKHDotS200T9B1, 0);	// KHドットフォント(サイズ200、太さ9)

	/* +++ 縦書きフォント +++ */
	//V_30_1 = CreateFontToHandle("@MS 明朝", 30, 1, DX_FONTTYPE_ANTIALIASING);	// (サイズ30、太さ1)


	if (KHDot_200_9 == -1)	// フォントデータが作成できていなかったら
	{
		/* +++ エラーメッセージを出力 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"Font.cpp : Init() : Cannot load KHDot_200_9",
			"Load Error",
			MB_OK
		);

		return -1;	// 初期化失敗(-1を返す)
	}

	if (KHDot_100_9 == -1)	// フォントデータが作成できていなかったら
	{
		/* +++ エラーメッセージを出力 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"Font.cpp : Init() : Cannot load KHDot_100_9",
			"Load Error",
			MB_OK
		);

		return -1;	// 初期化失敗(-1を返す)
	}

	if (KHDot_50_2 == -1)	// フォントデータが作成できていなかったら
	{
		/* +++ エラーメッセージを出力 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"Font.cpp : Init() : Cannot load KHDot_50_2",
			"Load Error",
			MB_OK
		);

		return -1;	// 初期化失敗(-1を返す)
	}

	if (KHDot_40_2 == -1)	// フォントデータが作成できていなかったら
	{
		/* +++ エラーメッセージを出力 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"Font.cpp : Init() : Cannot load KHDot_40_2",
			"Load Error",
			MB_OK
		);

		return -1;	// 初期化失敗(-1を返す)
	}

	if (KHDot_30_1 == -1)	// フォントデータが作成できていなかったら
	{
		/* +++ エラーメッセージを出力 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"Font.cpp : Init() : Cannot load KHDot_30_1",
			"Load Error",
			MB_OK
		);

		return -1;	// 初期化失敗(-1を返す)
	}

	if (KHDot_20_1 == -1)	// フォントデータが作成できていなかったら
	{
		/* +++ エラーメッセージを出力 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"Font.cpp : Init() : Cannot load KHDot_20_1",
			"Load Error",
			MB_OK
		);

		return -1;	// 初期化失敗(-1を返す)
	}

	return 0;	// 初期化成功(0を返す)
}

/* --- フォントの終了処理を行う関数 --- */
void Font_End()
{
	/* === フォントデータをメモリから削除 === */
	/* +++ 横書きフォント +++ */
	DeleteFontToHandle(KHDot_20_1);		// KHドットフォント(サイズ20、太さ1)
	DeleteFontToHandle(KHDot_30_1);		// KHドットフォント(サイズ30、太さ1)
	DeleteFontToHandle(KHDot_40_2);		// KHドットフォント(サイズ40、太さ2)
	DeleteFontToHandle(KHDot_50_2);		// KHドットフォント(サイズ50、太さ2)
	DeleteFontToHandle(KHDot_100_9);	// KHドットフォント(サイズ100、太さ9)
	DeleteFontToHandle(KHDot_200_9);	// KHドットフォント(サイズ200、太さ9)

	/* +++ 縦書きフォント +++ */
	//DeleteFontToHandle(V_30_1);		// (サイズ30、太さ1)
}

/* --- 文字列を指定フォント・指定の揃えで描画する関数 --- */
void DrawFormatStringToHandleAlign(int x, int y, Font_Align align,
	unsigned int Color, int FontHandle, const char* FormatString, ...)
{
	int align_x, align_y;			// 揃え後の文字列の書き始め位置
	int StringWidth, StringHeight;	// 文字列の幅と高さ

	char DrawString[FontAlignStringMax];	// 描画する時の文字列

	va_list args;		// 可変引数(...)をうけとる変数

	/* +++ 各変数の初期化(左揃えで初期化) +++ */
	align_x = x;
	align_y = y;
	StringWidth = 0;
	StringHeight = 0;

	va_start(args, FormatString);	// 直前の引数のアドレスからデータの位置を求め変数に格納

	// 文字列を可変引数から生成
	vsnprintf(DrawString, sizeof(DrawString), FormatString, args);

	// 文字列の幅を計算
	StringWidth = GetDrawStringWidthToHandle(DrawString, strlen(DrawString), FontHandle);

	// 文字列の高さを取得
	StringHeight = GetFontSizeToHandle(FontHandle);

	// 揃える位置ごとに位置を計算
	switch (align)
	{
	case FAlign_Left:
		// そのままなので何もしない
		break;

	case FAlign_Center:
		// 中央位置を計算

		// x座標だけ中央に寄せる
		align_x = x - StringWidth / 2;
		break;

	case FAlign_Right:
		// 右揃え

		// x座標のみ右に寄せる
		align_x = x - StringWidth;
		break;

	case FAlign_AllCenter:
		// 上下左右ともに中央揃え

		// x座標を中央に寄せる
		align_x = x - StringWidth / 2;

		// y座標を中央に寄せる
		align_y = y - StringHeight / 2;
		break;

	default:
		break;
	}

	// 揃え後の書き出し位置を基に文字列を描画
	DrawFormatStringToHandle(align_x, align_y, Color, FontHandle, "%s", DrawString);

	va_end(args);	// 可変引数をもらうのを終える

	return;
}

/* --- 文字列を指定フォント・指定の揃えで縦書きする関数 --- */
void DrawFormatVStringToHandleAlign(int x, int y, Font_Align align, unsigned int color, int fontHandle, const char* formatString, ...)
{
	int align_x, align_y;			// 揃え後の文字列の書き始め位置
	int StringWidth, StringHeight;	// 文字列の幅と高さ

	char DrawString[FontAlignStringMax];	// 描画する時の文字列

	va_list args;		// 可変引数(...)をうけとる変数

	/* +++ 各変数の初期化(左揃えで初期化) +++ */
	align_x = x;
	align_y = y;
	StringWidth = 0;
	StringHeight = 0;

	va_start(args, formatString);	// 直前の引数のアドレスからデータの位置を求め変数に格納

	// 文字列を可変引数から生成
	vsnprintf(DrawString, sizeof(DrawString), formatString, args);

	// 文字列の幅を計算
	StringHeight = GetDrawStringWidthToHandle(DrawString, strlen(DrawString), fontHandle);

	// 文字列の高さを取得
	StringWidth = GetFontSizeToHandle(fontHandle);

	// 揃える位置ごとに位置を計算
	switch (align)
	{
	case FAlign_Left:
		// そのままなので何もしない
		break;

	case FAlign_Center:
		// 中央位置を計算

		// x座標だけ中央に寄せる
		align_x = x - StringWidth / 2;
		break;

	case FAlign_Right:
		// 右揃え

		// x座標のみ右に寄せる
		align_x = x - StringWidth;
		break;

	case FAlign_AllCenter:
		// 上下左右ともに中央揃え

		// x座標を中央に寄せる
		align_x = x - StringWidth / 2;

		// y座標を中央に寄せる
		align_y = y - StringHeight / 2;
		break;

	default:
		break;
	}

	// 揃え後の書き出し位置を基に文字列を描画
	DrawFormatVStringToHandle(align_x, align_y, color, fontHandle, "%s", DrawString);

	va_end(args);	// 可変引数をもらうのを終える

	return;
}