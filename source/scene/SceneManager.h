#pragma once
/* === シーン管理のヘッダファイル === */

#include "DxLib.h"


#define SceneChangeInterval 60	// シーン切換のインターバルフレーム


/* --- ゲームシーンの列挙 --- */
enum GameScene
{
	Title_Scene,		// タイトル画面
	Tutorial,			// チュートリアルステージ
	Stage1,				// ステージ1
	Result_Scene,		// リザルト画面
	GameOver_Scene		// ゲームオーバー画面
};

extern GameScene NowGameScene;		// 現在のシーン
extern GameScene NextGameScene;		// 次のシーン

extern int SceneChangeFrameCount;	// 直前のシーン切換からの経過フレーム
extern int elapseFrameCounter;		// 経過フレーム


extern int Scene_Init(GameScene sceneName);		// シーンの初期化関数(引数はシーン名)
extern int Scene_Manage();						// シーンの処理を管理する関数
extern int Scene_Process();						// シーンの処理関数
extern void Scene_Draw();						// シーンの描画関数