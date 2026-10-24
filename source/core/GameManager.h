#pragma once
/* === ゲーム処理のヘッダファイル === */

#include "DxLib.h"

#define GameWindowWidth		1920				// ゲームウィンドウの幅
#define GameWindowHeight	1080				// ゲームウィンドウの高さ
#define GameColor			32					// ゲームに使用するカラー(32bit)
#define GameFPS				60					// ゲームのFPS

// #define AllCharacterNumber	6							// キャラクターの種類(sheppを含む)
// #define CharacterNumber		(AllCharacterNumber - 1)	// キャラクターの種類 - 1(sheppの分を引く)

// #define BattleSceneFPS		150		// バトルシーン中のFPS設定(GameFPS / BattleSceneFPSの値がバトルシーン中のFPSとなる)

#define GameDebug	1		// デバッグモードの設定(0:通常プレイモード, 1:シーン遷移機能のみ有効, 2:グラフィック系の機能も有効, 3:罫線モード)

#define StringLength	256		// 使用できる文字列の長さ
