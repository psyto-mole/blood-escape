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

/* --- キャラクターの描画関数 --- */
//void DrawExtendGraphConditional(int x1, int y1, int x2, int y2, int characterNumber, bool isPlayer)
//{
//	/* +++ キャラクターの種類に応じてキャラクター画像を表示 +++ */
//	switch (characterNumber)
//	{
//	case 1:
//		/* +++ ロボットの場合 +++ */
//
//		DrawExtendGraph(x1, y1, x2, y2, RobotImageHandle, true);		// 画面左側に描画
//		break;
//	case 2:
//		/* +++ 勇者の場合 +++ */
//
//		DrawExtendGraph(x1, y1, x2, y2, HumanImageHandle, true);	// 画面左側に描画
//		break;
//	case 3:
//		/* +++ ドラゴンの場合 +++ */
//
//		DrawExtendGraph(x1, y1, x2, y2, DragonImageHandle, true);	// 画面左側に描画
//		break;
//	case 4:
//		/* +++ ダイトメアの場合 +++ */
//
//		DrawExtendGraph(x1, y1, x2, y2, DightmareImageHandle, true);	// 画面左側に描画
//		break;
//	case 5:
//		/* +++ キューキャラクターの場合 +++ */
//
//		DrawExtendGraph(x1, y1, x2, y2, NonameImageHandle, true);	// 画面左側に描画
//		break;
//	case 99:
//		/* +++ Sheppキャラクターの場合 +++ */
//
//		DrawExtendGraph(x1, y1, x2, y2, SheppImageHandle, true);	// 画面左側に描画
//		break;
//	default:
//		break;
//	}
//
//	return;
//}