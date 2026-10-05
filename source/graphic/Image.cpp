/* === 画像処理のソースファイル === */

#include "Image.h"


/* --- 画像の初期化関数 --- */
int Image_Init(void)
{
	//RobotImageHandle = LoadGraph(ROBOTIMAGEPATH);		// ロボット画像の読み込み・ハンドル取得


	//if (RobotImageHandle == -1)
	//{
	//	// エラーメッセージの表示
	//	MessageBox(
	//		GetMainWindowHandle(),
	//		"Character Image",
	//		"Image Error",
	//		MB_OK
	//	);

	//	return -1;	// エラーで終了(-1を返す)
	//}

	return 0;	// 正常終了(0を返す)
}

/* --- 画像の終了処を行う理関数 --- */
void Image_End()
{
	//DeleteGraph(RobotImageHandle);		// ロボット画像の削除(メモリの解放)

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