/* === 画像処理のソースファイル === */

#include "Image.h"


int imageKeyA;		// Aキーの画像ハンドル
int imageKeyS;		// Sキーの画像ハンドル
int imageKeyUp;		// 上キーの画像ハンドル
int imageKeyDown;	// 下キーの画像ハンドル
int imageKeyRight;	// 右キーの画像ハンドル
int imageKeyLeft;	// 左キーの画像ハンドル

/* --- 画像の初期化関数 --- */
int Image_Init(void)
{
	imageKeyA = LoadGraph(PathOfImageKeyA);				// Aキーの画像の読み込み・ハンドル取得
	imageKeyS = LoadGraph(PathOfImageKeyS);				// Sキーの画像の読み込み・ハンドル取得
	imageKeyUp = LoadGraph(PathOfImageKeyUp);			// 上キーの画像の読み込み・ハンドル取得
	imageKeyDown = LoadGraph(PathOfImageKeyDown);		// 下キーの画像の読み込み・ハンドル取得
	imageKeyRight = LoadGraph(PathOfImageKeyRight);		// 右キーの画像の読み込み・ハンドル取得
	imageKeyLeft = LoadGraph(PathOfImageKeyLeft);		// 左キーの画像の読み込み・ハンドル取得

	if (imageKeyA == -1)	// Aキーの画像の読み込みに失敗したら
	{
		// エラーメッセージの表示
		MessageBox(
			GetMainWindowHandle(),
			"Image.cpp : Init() : Failed load image of key A",
			"Load Error",
			MB_OK
		);

		return -1;	// エラーで終了(-1を返す)
	}

	if (imageKeyS == -1)	// Sキーの画像の読み込みに失敗したら
	{
		// エラーメッセージの表示
		MessageBox(
			GetMainWindowHandle(),
			"Image.cpp : Init() : Failed load image of key S",
			"Load Error",
			MB_OK
		);

		return -1;	// エラーで終了(-1を返す)
	}

	if (imageKeyUp == -1)	// 上キーの画像の読み込みに失敗したら
	{
		// エラーメッセージの表示
		MessageBox(
			GetMainWindowHandle(),
			"Image.cpp : Init() : Failed load image of key Up",
			"Load Error",
			MB_OK
		);

		return -1;	// エラーで終了(-1を返す)
	}

	if (imageKeyDown == -1)	// 下キーの画像の読み込みに失敗したら
	{
		// エラーメッセージの表示
		MessageBox(
			GetMainWindowHandle(),
			"Image.cpp : Init() : Failed load image of key Down",
			"Load Error",
			MB_OK
		);

		return -1;	// エラーで終了(-1を返す)
	}

	if (imageKeyRight == -1)	// 右キーの画像の読み込みに失敗したら
	{
		// エラーメッセージの表示
		MessageBox(
			GetMainWindowHandle(),
			"Image.cpp : Init() : Failed load image of key Right",
			"Load Error",
			MB_OK
		);

		return -1;	// エラーで終了(-1を返す)
	}

	if (imageKeyLeft == -1)	// 左キーの画像の読み込みに失敗したら
	{
		// エラーメッセージの表示
		MessageBox(
			GetMainWindowHandle(),
			"Image.cpp : Init() : Failed load image of key Left",
			"Load Error",
			MB_OK
		);

		return -1;	// エラーで終了(-1を返す)
	}

	return 0;	// 正常終了(0を返す)
}

/* --- 画像の終了処を行う理関数 --- */
void Image_End()
{
	DeleteGraph(imageKeyA);			// Aキー画像の削除(メモリの解放)
	DeleteGraph(imageKeyS);			// Sキー画像の削除(メモリの解放)
	DeleteGraph(imageKeyUp);		// 上キー画像の削除(メモリの解放)
	DeleteGraph(imageKeyDown);		// 下キー画像の削除(メモリの解放)
	DeleteGraph(imageKeyRight);		// 右キー画像の削除(メモリの解放)
	DeleteGraph(imageKeyLeft);		// 左キー画像の削除(メモリの解放)

	return;
}

/* --- 画像を中心座標に基づき描画 --- */
void DrawGraphOnPoint(POINT center, int width, int height, int imageHandle, int transFlag)
{
	int upperLeftX, upperLeftY;		// 画像の左上の座標

	upperLeftX = center.x - (width / 2);	// 画像の左上のX座標を計算
	upperLeftY = center.y - (height / 2);	// 画像の左上のY座標を計算

	DrawGraph(upperLeftX, upperLeftY, imageHandle, transFlag);	// 画像を描画

	return;
}

/* --- 画像を中心座標に基づき反転して描画-- - */
void DrawTurnGraphOnPoint(POINT center, int width, int height, int imageHandle, int transFlag)
{
	int upperLeftX, upperLeftY;		// 画像の左上の座標

	upperLeftX = center.x - (width / 2);	// 画像の左上のX座標を計算
	upperLeftY = center.y - (height / 2);	// 画像の左上のY座標を計算

	DrawTurnGraph(upperLeftX, upperLeftY, imageHandle, transFlag);	// 画像を左右反転して描画

	return;
}

/* --- 画像を中心座標をもとに拡大・縮小描画する関数-- - */
void DrawExtendGraphOnPoint(POINT center, int width, int height, int imageHandle, int transFlag)
{
	int upperLeftX, upperLeftY;		// 画像の左上の座標
	int lowerRightX, lowerRightY;	// 画像の右下の座標

	upperLeftX = center.x - (width / 2);	// 画像の左上のX座標を計算
	upperLeftY = center.y - (height / 2);	// 画像の左上のY座標を計算

	lowerRightX = center.x + (width / 2) + 1;	// 画像の右下のX座標を計算
	lowerRightY = center.y + (height / 2) + 1;	// 画像の右下のY座標を計算

	DrawExtendGraph(upperLeftX, upperLeftY, lowerRightX, lowerRightY, imageHandle, transFlag);	// 画像を描画(拡大縮小に対応)

	return;
}