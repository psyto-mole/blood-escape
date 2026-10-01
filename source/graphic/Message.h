#pragma once
/* === ゲーム中のメッセージ表示を管理するヘッダファイル === */

#include "DxLib.h"


/* --- メッセージの表示パターンの列挙型 --- */
enum MessagePattern
{
	Message1Line,	// メッセージを1行表示
	Message2Line,	// メッセージを2行表示
	Message3Line,	// メッセージを3行表示
	Message4Line	// メッセージを4行表示
};

extern MessagePattern settingMessagePattern;
extern MessagePattern displayMessagePattern;


/* === 汎用 === */
/* +++ 回答文 +++ */
#define ResponseYes	"はい"		// 回答文「はい」
#define ResponseNo	"いいえ"	// 回答文「いいえ」
#define ResponseOK	"OK"		// 回答文「OK」


/* +++ 助詞 +++ */
#define ParticleHA	"は"


/* +++ 「back」ボタン +++ */
#define BackButtonText	"戻る"	// 「戻る」ボタンのテキスト


/* +++ プレイヤー +++ */
#define NamePlayer	"プレイヤー"
#define NameEnemy	"エネミー"



/* === シーンマネージャ === */
#define FlagStatusTrue		"true"		// 「true」の文字列(デバッグ用)
#define FlagStatusFalse		"false"		// 「false」の文字列(デバッグ用)



/* === システムメニュー === */
/* +++ メニュートップ +++ */
#define OptionSystemMenuAchievement		"記録"
#define OptionSystemMenuDelete			"データ消去"
#define OptionSystemMenuEndGame			"ゲーム終了"
#define OptionSystemMenuCredit			"クレジット"
#define OptionSystemMenuBack			"戻る"

#define DetailAchievement	"これまでの討伐記録を確認します"
#define DetailDeleteData	"保存されているデータを消去します"
#define DetailGameEnd		"ゲームを終了します"
#define DetailCredit		"仕様楽曲などを表示します"
#define DetailBackMenu		"メニューを閉じゲームに戻ります"


/* +++ データ消去画面 +++ */
#define QuestionDeleteData1		"ゲームデータを消去しますか?"
#define QuestionDeleteData2		"※消去したデータは戻せません"


/* +++ ゲームの終了 +++ */
#define QuestionGameEnd		"ゲームを終了しますか?"


/* +++ クレジット +++ */
#define MusicUsed		"使用楽曲"
#define MaohDamashi		"魔王魂"
#define SoundEffectLab	"効果音ラボ"
#define OtoLogic		"OtoLogic"

#define ToolUsed	"使用ツール"
#define DotArt		"DotArt"



/* === タイトル画面 === */
#define StringGameTitle		"Blood Escape"	// ゲームのタイトル
#define StringPressEnter	"Press Enter"	// Press Enterの文字列



/* === リザルト画面 === */
#define ResultGratulateMessage	"Congratulation!!"			// お祝いメッセージ



/* === ゲームオーバー画面 === */
#define StringGameOver	"Game Over"			// ゲームオーバー画面のタイトル
#define StringRetry		"リトライ"			// 「リトライ」
#define StringBackTitle	"タイトルに戻る"	// 「タイトルに戻る」



/* +++ 修飾 +++ */
#define Players		"Playerの"
#define Enemys		"Enemyの"