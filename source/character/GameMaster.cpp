/* +++ ゲームマスター関連の処理のソースファイル +++ */

#include "GameMaster.h"
#include "GameManager.h"
#include "Geometry.h"


/* --- コンストラクタ --- */
GameMaster::GameMaster()
{
	for (int i = 0; i < GameMasterAnimationDivNum; i++)
	{
		animationHandle[0] = -1;	// アニメーションの画像ハンドルを初期化
	}

	drawImage = 0;	// 描画する画像の要素番号を初期化

	position = GetPoint(GameWindowWidth / 2, GameWindowHeight / 2);		// 描画する位置を描画
}

/** --- デストラクタ --- */
GameMaster::~GameMaster()
{

}

/* --- ゲームマスターの初期化メソッド --- */
int GameMaster::Init()
{
	/* +++ アニメーション画像を読み込み +++ */
	if (LoadDivGraph(GameMasterAnimationPath, GameMasterAnimationDivNum, GameMasterAnimationDivX, GameMasterAnimationDivY, GameMasterAnimationSizeX, GameMasterAnimationSizeY, animationHandle) == -1)	// 読み込みに失敗したら
	{
		MessageBox(
			GetMainWindowHandle(),
			"GameMaster.cpp : Init() : Failed to load game master's animation.",
			"Load Error",
			MB_OK
		);

		return -1;	// -1を返す(初期化失敗)
	}

	return 0;
}

/* --- ゲームマスターの更新メソッド --- */
void GameMaster::Update()
{
	drawImage = 0;	// 描画する場像の要素番号をリセット

	if (GetRand(100) <= AnimationSwitchingProbability)	// 画像が切り換わるなら
	{
		drawImage = GetRand(1) + 1;		// 1～2の乱数を生成し、要素番号として格納
	}

	return;
}

/* --- ゲームマスターの描画メソッド --- */
void GameMaster::Draw()
{
	DrawExtendGraphOnPoint(position, GameMasterAnimationSizeX * 20, GameMasterAnimationSizeY * 20, animationHandle[drawImage], TRUE);	// ゲームマスターの画像を描画

	return;
}

/* --- 描画する画像を指定するメソッド --- */
void GameMaster::SetDrawImage(int imageIndexNumber)
{
	drawImage = imageIndexNumber;	// 描画する画像を設定

	return;
}