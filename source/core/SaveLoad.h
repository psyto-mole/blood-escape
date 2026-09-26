#pragma once
/* === ゲームデータのセーブ・ロードを管理するヘッダファイル === */

#include "DxLib.h"
#include "GameManager.h"


#define PathDataFile	".\\game-data\\save\\gamedata.dat"	// セーブデータを保存するファイルのパス


extern errno_t errorCode;									// ファイルの読み出し・書き込みの際のエラーコードを格納する変数
extern bool alreadySaved;									// セーブ済みかどうかを判定するフラグ
extern bool initialized;									// 初期化済みかどうかを判定するフラグ


extern void Data_Init();										// ゲームデータの初期化関数
extern void Data_Save();										// ゲームデータをセーブする関数
extern void Data_Load();										// ゲームデータをロードする関数
extern void Data_Update(int playerNumber, int enemyNumber);		// ゲームデータを更新する関数
extern void Data_Delete();										// ゲームデータを消去する関数