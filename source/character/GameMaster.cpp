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
	return;
}

/* --- ゲームマスターの描画メソッド --- */
void GameMaster::Draw()
{
	return;
}