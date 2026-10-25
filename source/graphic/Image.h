#pragma once
/* === 画像処理のヘッダファイル === */

#include "DxLib.h"


/* +++ マップのタイルセットの画像パス +++ */
#define PathOfPassableTile		".\\image\\MapTile10_96x96.png"		// 通行可能タイルの画像のパス
#define PathOfImpassableTile	".\\image\\MapTile20_96x96.png"		// 通行不可タイルの画像のパス


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


/* +++ ゲームマスターのアニメーション +++ */
#define GameMasterAnimationPath		".\\image\\GameMaster_96x96.png"
#define GameMasterAnimationDivX		2
#define GameMasterAnimationDivY		2
#define GameMasterAnimationDivNum	4
#define GameMasterAnimationSizeX	48
#define GameMasterAnimationSizeY	48


/* +++ プレイヤーのアニメーション +++ */
#define PlayerAnimationPath		".\\image\\Player_96x96.png"
#define PlayerAnimationDivX		3
#define PlayerAnimationDivY		3
#define PlayerAnimationDivNum	9
#define PlayerAnimationSizeX	32
#define PlayerAnimationSizeY	32


/* === メニューで使用する画像 === */
/* +++ 操作方法 +++ */
#define PathOfImageKeyA		".\\image\\Key_A_32x32.png"
#define PathOfImageKeyS		".\\image\\Key_S_32x32.png"
#define PathOfImageKeyUp	".\\image\\Key_Up_32x32.png"
#define PathOfImageKeyDown	".\\image\\Key_Down_32x32.png"
#define PathOfImageKeyRight	".\\image\\Key_Right_32x32.png"
#define PathOfImageKeyLeft	".\\image\\Key_Left_32x32.png"

extern int imageKeyA;		// Aキーの画像ハンドル
extern int imageKeyS;		// Sキーの画像ハンドル
extern int imageKeyUp;		// 上キーの画像ハンドル
extern int imageKeyDown;	// 下キーの画像ハンドル
extern int imageKeyRight;	// 右キーの画像ハンドル
extern int imageKeyLeft;	// 左キーの画像ハンドル


extern int Image_Init(void);	// 画像の初期化関数
extern void Image_End(void);	// 画像の終了処を行う理関数

extern void DrawGraphOnPoint(POINT center, int width, int height, int imageHandle, int transFlag);			// 画像を中心座標に基づき描画
extern void DrawTurnGraphOnPoint(POINT center, int width, int height, int imageHandle, int transFlag);		// 画像を中心座標に基づき反転して描画
extern void DrawExtendGraphOnPoint(POINT center, int width, int height, int imageHandle, int transFlag);	// 画像を中心座標をもとに拡大・縮小描画する関数
