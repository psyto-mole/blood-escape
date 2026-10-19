#pragma once
/* === 画像処理のヘッダファイル === */

#include "DxLib.h"


/* === ギミックの画像パス === */
/* +++ 祭壇の画像パス +++ */
#define PathOfAltarImage1	".\\image\\Altar1_32x32.png"
#define PathOfAltarImage2	".\\image\\Altar2_32x32.png"

/* +++ 包帯の画像パス +++ */
#define PathOfBandageImage	".\\image\\Bandage_32x32.png"

/* +++ 輸血パックの画像パス +++ */
#define PathOfBloodPackImage	".\\image\\BloodPack_32x32.png"

/* +++ ドアの画像パス +++ */
#define PathOfDoorImage1	".\\image\\Door1_32x32.png"
#define PathOfDoorImage2	".\\image\\Door2_32x32.png"

/* +++ 針床の画像パス +++ */
#define PathOfNeedleFloorImage1	".\\image\\NeedleFloor1_32x32.png"
#define PathOfNeedleFloorImage2	".\\image\\NeedleFloor2_32x32.png"

/* +++ スイッチの画像パス +++ */
#define PathOfSwitchImage1	".\\image\\Switch1_32x32.png"
#define PathOfSwitchImage2	".\\image\\Switch2_32x32.png"

/* +++ 透明床の画像パス +++ */
#define PathOfTransparentFloorImage1	".\\image\\TransparentFloor1_32x32.png"
#define PathOfTransparentFloorImage2	".\\image\\TransparentFloor2_32x32.png"


extern int Image_Init(void);	// 画像の初期化関数
extern void Image_End(void);	// 画像の終了処を行う理関数

extern void DrawGraphOnPoint(POINT center, int width, int height, int imageHandle, int transFlag);			// 画像を中心座標に基づき描画
extern void DrawTurnGraphOnPoint(POINT center, int width, int height, int imageHandle, int transFlag);		// 画像を中心座標に基づき反転して描画
extern void DrawExtendGraphOnPoint(POINT center, int width, int height, int imageHandle, int transFlag);	// 画像を中心座標をもとに拡大・縮小描画する関数
