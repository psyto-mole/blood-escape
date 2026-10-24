#pragma once
/* === ゲーム処理のヘッダファイル === */

#include "DxLib.h"

#define GameWindowWidth		1920				// ゲームウィンドウの幅
#define GameWindowHeight	1080				// ゲームウィンドウの高さ
#define GameColor			32					// ゲームに使用するカラー(32bit)
#define GameFPS				60					// ゲームのFPS

#define GameDebug	2		// デバッグモードの設定(0:通常プレイモード, 1:シーン遷移機能のみ有効, 2:当たり判定やパラメータの可視化まで有効, 3:マップデータの可視化まで有効, 4:罫線モード(未実装))

#define StringLength	256		// 使用できる文字列の長さ
