/* === ゲームのメインのソースファイル === */

/* +++ ライブラリのインクルード +++ */
#include <string>
#include "DxLib.h"
#include "GameManager.h"
#include "Image.h"
#include "Font.h"
#include "Color.h"
#include "Key.h"
#include "Mouse.h"
#include "Sound.h"
#include "SceneManager.h"
#include "Geometry.h"
#include "Message.h"
#include "SaveLoad.h"
//#include "Menu.h"


/* +++ プロトタイプ宣言 +++ */
int Game_Init(SceneManager* );		// ゲームの初期化を行う関数
int Game_Update(SceneManager* );	// ゲームの処理の更新を行う関数
void Game_End(SceneManager* );		// ゲームの終了処理を行う関数


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);						// Log.txtの出力の拒否
	ChangeWindowMode(true);										// ウィンドウモードに設定
	SetGraphMode(GameWindowWidth, GameWindowHeight, GameColor);	// 解像度の設定
	SetWindowSize(GameWindowWidth, GameWindowHeight);			// ウィンドウサイズの設定
	SetMainWindowText(StringGameTitle);								// ウィンドウのタイトル
	SetBackgroundColor(0, 0, 0);								// ウィンドウの背景色
	SetWaitVSyncFlag(true);										// 垂直同期の設定
	SetAlwaysRunFlag(true);										// 非アクティブでもゲーム実行


	SceneManager sceneManager;

	/* +++ ゲームの初期化 +++ */
	if (Game_Init(&sceneManager) == -1)	// 初期化に失敗したなら
	{
		return -1;	// ソフトを終了する
	}

	SetDrawScreen(DX_SCREEN_BACK);	// 裏画面に描画(ダブルバッファリング)

	
	/* +++ ゲームループ(無限ループ) +++ */
	while (true)
	{
		/* +++ メッセージを処理し続ける(マウスやキーの入力を受け付け続ける) +++ */
		if (ProcessMessage() != 0)	// エラー発生やウィンドウが閉じられた
		{
			break;	// ループを終了
		}


		/* +++ 画面を書き換える(画面を消去する) +++ */
		if (ClearDrawScreen() != 0)		// エラー発生
		{
			break;	// ループを終了
		}

		/* +++ ゲームの処理を更新できなかったらループを終了する +++ */
		if (Game_Update(&sceneManager) != 0)		// ゲームの処理を更新できなかった
		{
			break;	// ループを終了
		}

		/* +++ 裏画面を表画面に描画 +++ */
		if (ScreenFlip() != 0)		// エラー発生
		{
			break;	// ループを終了
		}
	}

	Game_End(&sceneManager);	// ゲームの終了

	return 0;	// ソフト終了
}


/* +++ ゲームの初期化処理(ここに諸々の初期化処理を集める) +++ */
int Game_Init(SceneManager* sceneManager)
{
	/* +++ Dxライブラリ初期化処理 +++ */
	if (DxLib_Init() == -1)		// 初期化に失敗したなら
	{
		return -1;	// -1を返す(初期化関数を初期化失敗で終わらせる)
	}

	/* +++ 画像処理の初期化 +++ */
	if (Image_Init() == -1)		// 初期化に失敗した
	{
		return -1;	// -1を返す(初期化関数を初期化失敗で終わらせる)
	}

	/* +++ フォント処理の初期化 +++ */
	if (Font_Init() == -1)	// 初期化失敗
	{
		return -1;	// -1を返す(初期化関数を初期化失敗で終わらせる)
	}

	Color_Init();	// 色管理の初期化

	Key_Init();		// キー入力処理の初期化

	Mouse_Init();	// マウス処理の初期化

	if (sceneManager == NULL)	// シーン管理オブジェクトのポインタが取得できない
	{
		/* +++ エラーメッセージを表示 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"Cannot get scene manager pointer to initialize.",
			"Main Error",
			MB_OK
		);

		return -1;	// -1を返す(初期化失敗)
	}

	sceneManager->Init();	// シーンの初期化

	Data_Init();

	/* +++ サウンド処理の初期化 +++ */
	if (Sound_Init() == -1)		// 初期化失敗
	{
		MessageBox(
			GetMainWindowHandle(),							// ウィンドウハンドル
			"An Error occurred while initializing Sound",	// エラー内容
			"Sound Error",									// エラータイトル
			MB_OK											// OKボタンのみ表示
		);

		return -1;	// -1を返す(初期化関数を初期化失敗で終わらせる)
	}

	//Menu_Init();

	Geometry_Init();

	return 0;	// 諸々の初期化関数の終了(正常終了)
}

/* --- ゲームの処理の更新を行う関数 --- */
int Game_Update(SceneManager* sceneManager)
{
	/* +++ キー入力の取得 +++ */
	if (Key_Update() != 0)	// エラー発生
	{
		return -1;	// 更新不可(-1)を返す
	}

	/* +++ マウス入力の取得 +++ */
	Mouse_Update();

	/* +++ カラー処理 +++ */
	Color_Process();

	if (sceneManager == NULL)	// シーン管理オブジェクトのポインタが取得できない
	{
		/* +++ エラーメッセージを表示 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"Cannot get scene manager pointer to update.",
			"Main Error",
			MB_OK
		);

		return -1;	// -1を返す(初期化失敗)
	}

	sceneManager->Update();	// シーンの更新

	return 0;
}

/* --- ゲームの終了処理(ここに諸々の終了処理を集める) --- */
void Game_End(SceneManager* sceneManager)
{
	Image_End();	// 画像処理の終了

	Font_End();		// フォント処理の終了

	Sound_End();	// サウンド処理の終了

	if (sceneManager == NULL)	// シーン管理オブジェクトのポインタが取得できない
	{
		/* +++ エラーメッセージを表示 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"Cannot get scene manager pointer for end processing.",
			"Main Error",
			MB_OK
		);
	}
	else
	{
		sceneManager->End();	// シーンの終了
	}

	DxLib_End();	// DxLibの終了

	return;
}