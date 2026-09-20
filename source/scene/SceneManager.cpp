/* === シーン管理のソースファイル === */

#include "SceneManager.h"
#include "GameManager.h"
#include "Color.h"
#include "Font.h"
#include "Key.h"
#include "Mouse.h"
#include "Geometry.h"
#include "FakeScene.h"
#include "Title.h"
#include "Result.h"
#include "GameOver.h"
#include "Message.h"
#include "Sound.h"
#include "SaveLoad.h"
#include "Menu.h"


GameScene NowGameScene;		// 現在のシーン
GameScene NextGameScene;	// 次のシーン

int SceneChangeFrameCount;	// シーン切換後からのゲームの経過フレーム
int elapseFrameCounter;		// ゲームの経過フレーム


/* --- シーンの初期化関数 --- */
int Scene_Init(GameScene sceneName)
{
	SceneChangeFrameCount = 0;	// シーン切り換え後からの経過フレームをリセット
	elapseFrameCounter = 0;		// 経過フレームをリセット

	/* +++ 指定したシーンの初期化関数を呼び出す +++ */
	switch (sceneName)
	{
	case Title_Scene:
		/* +++ タイトルシーンの場合 +++ */

		if (Title_Init() == -1)	// タイトルシーンの初期化に失敗したら
		{
			return -1;	// シーンの初期化失敗(-1を返す)
		}

		break;
	case Tutorial_Stage:
		/* +++ チュートリアルステージの場合 +++ */

		if (Tutorial_Init() == -1)	// チュートリアルステージの初期化に失敗したら
		{
			return -1;	// シーンの初期化失敗(-1を返す)
		}

		break;
	case Stage1:
		/* +++ ステージ1の場合 +++ */

		if (Stage1_Init() == -1)	// ステージ1の初期化に失敗したら
		{
			return -1;	// シーンの初期化失敗(-1を返す)
		}

		break;
	case Result_Scene:
		/* +++ リザルトシーンの場合 +++ */

		if (Result_Init() == -1)	// リザルトシーンの初期化に失敗したら
		{
			return -1;	// シーンの初期化失敗(-1を返す)
		}
		break;
	case GameOver_Scene:
		/* +++ ゲームオーバーシーンの場合 +++ */

		if (GameOver_Init() == -1)	// ゲームオーバーシーンの初期化に失敗したら
		{
			return -1;	// シーンの初期化失敗(-1を返す)
		}
		break;
	default:
		break;
	}

	return 0;
}

/* --- シーンの処理を管理する関数 --- */
int Scene_Manage()
{
	if (Scene_Process() == -1)
	{
		return -1;
	}

	Scene_Draw();

	return 0;	// シーン処理の管理関数の終了(0を返す)
}

/* --- シーンの処理関数 --- */
int Scene_Process()
{
	SceneChangeFrameCount++;	// シーン切換後からの経過フレームを1増やす
	elapseFrameCounter++;		// 経過フレームを1増やす

	if (menuKind == MenuOFF)
	{
		if (NextGameScene != NowGameScene)	// 現在のシーンと次のシーンが異なる(シーンが切り換わる)
		{
			/* +++ 切り換わり先のシーンに応じて引数を変えてシーン初期化関数を実行 +++ */
			switch (NextGameScene)
			{
			case Title_Scene:
				/* +++ タイトルシーンの場合 +++ */

				/* +++ 前のシーンの終了処理を行う +++ */
				switch (NowGameScene)
				{
				case GameOver_Scene:
					/* +++ 前のシーンがゲームオーバーシーンなら +++ */

					/* +++ ゲームオーバーシーンの終了処理を行う +++ */
					if (GameOver_End() == -1)	// 終了処理が正常に行われなかった場合
					{
						return -1;	// シーンの処理の失敗(-1を返す)
					}
					break;
				case Result_Scene:
					/* +++ 前のシーンがリザルトシーンなら +++ */

					/* +++ リザルトシーンの終了処理を行う +++ */
					if (Result_End() == -1)	// 終了処理が正常に行われなかった場合
					{
						return -1;	// シーンの処理の失敗(-1を返す)
					}
					break;
				default:
					break;
				}

				/* +++ タイトルシーンの初期化を行う +++ */
				if (Scene_Init(Title_Scene) == -1)	// タイトルシーンの初期化に失敗した
				{
					return -1;	// シーンの処理の失敗(-1を返す)
				}
				break;
			case Tutorial_Stage:
				/* +++ チュートリアルステージの場合 +++ */

				/* +++ タイトルシーンの終了処理を行う +++ */
				if (Title_End() == -1)	// 終了処理が正常に行われなかった場合
				{
					return -1;	// シーンの処理の失敗(-1を返す)
				}

				/* +++ チュートリアルステージの初期化を行う +++ */
				if (Scene_Init(Tutorial_Stage) == -1)	// チュートリアルステージの初期化に失敗した
				{
					return -1;	// シーンの処理の失敗(-1を返す)
				}
				break;
			case Stage1:
				/* +++ ステージ1の場合 +++ */

				/* +++ チュートリアルステージの終了処理を行う +++ */
				if (Tutorial_End() == -1)	// 終了処理が正常に行われなかった場合
				{
					return -1;	// シーンの処理の失敗(-1を返す)
				}

				/* +++ ステージ1の初期化を行う +++ */
				if (Scene_Init(Stage1) == -1)	// ステージ1の初期化に失敗した
				{
					return -1;	// シーンの処理の失敗(-1を返す)
				}
				break;
			case Result_Scene:
				/* +++ リザルト画面の場合 +++ */

				/* +++ ステージ1の終了処理 +++ */
				if (Stage1_End() == -1)
				{
					return -1;	// シーンの処理の失敗(-1を返す)
				}

				/* +++ リザルトシーンの初期化を行う +++ */
				if (Scene_Init(Result_Scene) == -1)	// ResultSceneの初期化に失敗した
				{
					return -1;	// シーンの処理の失敗(-1を返す)
				}
				break;
			case GameOver_Scene:
				/* +++ ゲームオーバー画面の場合 +++ */

				if (BattleScene_End() == -1)
				{
					return -1;	// シーン処理の失敗(-1を返す)
				}

				if (Scene_Init(GameOver_Scene) == -1)	// GameOverSceneの初期化に失敗した
				{
					return -1;	// シーンの処理の失敗(-1を返す)
				}
				break;
			default:
				break;
			}

			NowGameScene = NextGameScene;	// 切換先のシーンを現在のシーンに設定
		}
		else
		{
			/* +++ 現在のシーンに応じて引数を変えてシーンの処理関数を実行 +++ */
			switch (NowGameScene)
			{
			case Title_Scene:
				/* +++ タイトル画面の場合 +++ */

				Title_Manage();	// タイトルシーンの処理関数を実行
				break;
			case Tutorial :
				/* +++ チュートリアルステージの場合 +++ */

				Tutorial_Manage();	// チュートリアルステージの処理関数を実行
				break;
			case Stage1:
				/* +++ ステージ1の場合 +++ */

				Stage1_Manage();	// ステージ1の処理関数を実行
				break;
			case Result_Scene:
				/* +++ リザルト画面の場合 +++ */

				Result_Manage();	// リザルトシーンの処理関数を実行
				break;
			case GameOver_Scene:
				/* +++ ゲームオーバー画面の場合 +++ */

				GameOver_Manage();	// ゲームオーバーシーンの処理関数を実行
				break;
			default:
				break;
			}
		}
	}

	/* +++ メニューの処理を行う +++ */
	if (Menu_Process() == -1)	// 処理に失敗した
	{
		return -1;	// シーンの処理の失敗(-1を返す)
	}

	/* +++ デバッグモードの場合、ゲームを途中で強制終了するための処理 +++ */
	if (GameDebug)
	{
		/* +++ 「END」と押されたら +++ */
		if (Key_Check_Press(KEY_INPUT_E) && Key_Check_Press(KEY_INPUT_N)
			&& Key_Check_Press(KEY_INPUT_D))
		{
			return -1;	// ゲームを終了する
		}
	}

	return 0;
}

/* --- シーンの描画関数 --- */
void Scene_Draw()
{
	int i, j;

	Menu_Draw();	// メニューを描画する

	if (GameDebug)
	{

	}

	if (RuledLine)
	{
		Draw_RuledLine();
	}

	return;
}