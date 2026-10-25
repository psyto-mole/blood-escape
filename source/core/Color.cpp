/* === 色定義のソースファイル === */

#include "Color.h"

int Color_White;		// 白
int Color_Black;		// 黒
int Color_Gray;			// 灰色
int Color_Red;			// 赤
int Color_Green;		// 緑
int Color_Blue;			// 青
int Color_Yellow;		// 黄
int Color_Cyan;			// 水色
int Color_Violet;		// バイオレット
int Color_Purple;		// パープル
int Color_SkyBlue;		// 空色

int Color_LightGray;	// 明るい灰色
int Color_LightRed;		// 明るい赤
int Color_LightGreen;	// 明るい緑
int Color_LightBlue;	// 明るい青

int Color_DarkGray;		// 暗い灰色
int Color_DarkRed;		// 暗い赤
int Color_DarkGreen;	// 暗い緑
int Color_DarkBlue;		// 暗い青

int Color_SW_Rainbow;	// 時間経過で色が移り変わる虹色
int Color_SW_Violet;	// 時間経過で点滅する紫色
int Color_SW_Light;		// 時間経過で点滅する白

int SW_Red;		// 時間経過で変化するRGBのRの割合を管理する変数
int SW_Green;	// 時間経過で変化するRGBのGの割合を管理する変数
int SW_Blue;	// 時間経過で変化するRGBのBの割合を管理する変数
int SW_Light;	// 時間経過で変化する明暗の割合を管理する変数

bool lightSwitchingFlag;	// 明暗の増減管理フラグ(trueで増加、falseで減少)

/* --- カラーの初期化関数 --- */
void Color_Init()
{
	Color_White = GetColor(255, 255, 255);		// 白
	Color_Black = GetColor(0, 0, 0);			// 黒
	Color_Gray = GetColor(100, 100, 100);		// 灰色
	Color_Red = GetColor(255, 0, 0);			// 赤
	Color_Green = GetColor(0, 150, 0);			// 緑
	Color_Blue = GetColor(0, 0, 255);			// 青
	Color_Yellow = GetColor(255, 255, 0);		// 黄色
	Color_Cyan = GetColor(0, 255, 255);			// 水色
	Color_Violet = GetColor(150, 0, 200);		// バイオレット
	Color_Purple = GetColor(255, 0, 255);		// パープル
	Color_SkyBlue = GetColor(0, 255, 255);		// 空色

	Color_LightGray = GetColor(150, 150, 150);	// 明るい灰色
	Color_LightRed = GetColor(255, 0, 0);		// 明るい赤
	Color_LightGreen = GetColor(0, 255, 0);		// 明るい緑
	Color_LightBlue = GetColor(100, 100, 255);	// 明るい青

	Color_DarkGray = GetColor(50, 50, 50);		// 暗い灰色
	Color_DarkRed = GetColor(100, 0, 0);		// 暗い赤
	Color_DarkGreen = GetColor(0, 100, 0);		// 暗い緑
	Color_DarkBlue = GetColor(0, 0, 100);		// 暗い青

	SW_Red = 255;		// 時間経過で変化するRGBのRの割合の初期化
	SW_Green = 0;		// 時間経過で変化するRGBのGの割合の初期化
	SW_Blue = 0;		// 時間経過で変化するRGBのBの割合の初期化
	SW_Light = 255;		// 時間経過で変化する明暗の割合の初期化

	Color_SW_Rainbow = GetColor(SW_Red, SW_Green, SW_Blue);		// 時間経過で色が移り変わる虹色の初期化
	Color_SW_Violet = GetColor(SW_Light, 0, SW_Light);			// 時間経過で点滅する紫色の初期化
	Color_SW_Light = GetColor(SW_Light, SW_Light, SW_Light);	// 時間経過で点滅する白の初期化

	lightSwitchingFlag = false;	// 明暗の増減管理フラグの初期化
}

/* --- カラーの処理関数 --- */
void Color_Process()
{
	/* +++ RGBを順番に増減させることで虹色の移り変わりの処理を行う +++ */
	// 常にRGBのいずれかの値は255にしておき、以下のローテーションで各値の増減を行う
	// 1. Rの値を255で固定した状態でGの値を0 -> 255に徐々に増加させる
	// 2. Gの値を255で固定した状態でRの値を255 -> 0に徐々に減少させる
	// 3. Gの値を255で固定した状態でBの値を0 -> 255に徐々に増加させる
	// 4. Bの値を255で固定した状態でGの値を255 -> 0に徐々に減少させる
	// 5. Bの値を255で固定した状態でRの値を0 -> 255に徐々に増加させる
	// 6. Rの値を255で固定した状態でBの値を255 -> 0に徐々に減少させる
	if (SW_Red == 255 && SW_Green < 255)	// Rの値が255でGの値が255未満なら
	{
		if (SW_Blue > 0)	// Bの値が0より大きいなら
		{
			SW_Blue -= ColorSwitchingRate;	// Bの値を設定した割合で減少させる

			if (SW_Blue < 0)	// Bの値が0を下回ったら
			{
				SW_Blue = 0;	// Bの値を0にする
			}
		}
		else
		{
			SW_Green += ColorSwitchingRate;		// Gの値を設定した割合で増加させる

			if (SW_Green > 255)		// Gの値が255を超えたら
			{
				SW_Green = 255;		// Gの値を255にする
			}
		}
	}
	else if (SW_Green == 255 && SW_Blue < 255)	// Gの値が255でBの値が255未満なら
	{
		if (SW_Red > 0)		// Rの値が0より大きいなら
		{
			SW_Red -= ColorSwitchingRate;	// Rの値を設定した割合で減少させる

			if (SW_Red < 0)		// Rの値が0を下回ったら
			{
				SW_Red = 0;		// Rの値を0にする
			}
		}
		else
		{
			SW_Blue += ColorSwitchingRate;	// Bの値を設定した割合で増加させる

			if (SW_Blue > 255)	// Bの値が255を超えたら
			{
				SW_Blue = 255;	// Bの値を255にする
			}
		}
	}
	else if (SW_Blue == 255 && SW_Red < 255)	// Bの値が255でRの値が255未満なら
	{
		if (SW_Green > 0)	// Gの値が0より大きいなら
		{
			SW_Green -= ColorSwitchingRate;		// Gの値を設定した割合で減少させる

			if (SW_Green < 0)	// Gの値が0を下回ったら
			{
				SW_Green = 0;	// Gの値を0にする
			}
		}
		else
		{
			SW_Red += ColorSwitchingRate;	// Rの値を設定した割合で増加させる

			if (SW_Red > 255)	// Rの値が255を超えたら
			{
				SW_Red = 255;	// Rの値を255にする
			}
		}
	}

	if (lightSwitchingFlag)		// 明暗の増減管理フラグがtrue(増加)なら
	{
		SW_Light += ColorSwitchingRate;		// 明暗を設定した割合で増加させる

		if (SW_Light >= 255)	// 明暗の値が255以上なら
		{
			SW_Light = 255;					// 明暗の値を255にする
			lightSwitchingFlag = false;		// 明暗の増減フラグをfalse(減少)にする
		}
	}
	else
	{
		SW_Light -= ColorSwitchingRate;		// 明暗を設定した割合で減少させる

		if (SW_Light <= 0)	// 明暗の値が0以下なら
		{
			SW_Light = 0;				// 明暗の値を0にする
			lightSwitchingFlag = true;	// 明暗の増減フラグをtrue(増加)にする
		}
	}

	Color_SW_Rainbow = GetColor(SW_Red, SW_Green, SW_Blue);		// 時間経過で色が移り変わる虹色の再定義
	Color_SW_Violet = GetColor(SW_Red, 0, SW_Blue);				// 時間経過で色が移り変わる紫色の再定義
	Color_SW_Light = GetColor(SW_Light, SW_Light, SW_Light);	// 時間経過で明るさが移り変わる白の再定義

	return;
}