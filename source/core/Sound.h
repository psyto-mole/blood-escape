#pragma once
/* === サウンド処理のヘッダファイル === */

#include "DxLib.h"


#define VolumeQuiet		100		// 音量「小」の時の音量
#define VolumeMedium	150		// 音量「中」の時の音量
#define VolumeLoud		200		// 音量「大」の時の音量
#define VolumeMax		250		// 音量「最大」の時の音量

#define SoundPathStringMax 256	// サウンドの指定パスの文字列の最大長


/* --- サウンドの設定(構造体) --- */
typedef struct _Sound
{
	int Handle = -1;					// 画像ハンドル
	char Path[SoundPathStringMax];		// パス
	int Volume = -1;					// 音量
	bool PlayBeginning = true;			// 停止後に最初から再生するか
	int Playtype = DX_PLAYTYPE_BACK;	// 再生形式(デフォルトは1回のみ)
}Sound;


/* +++ BGM +++ */
//#define PathBGMFake			".\\Sound\\Maoh_Damashi\\maoh_game_village06.mp3"	// 偽のタイトル画面のBGMのパス

//extern Sound BGM_Fake;			// 偽のタイトル画面のBGM


/* +++ 操作関連のSE +++ */
//#define PathSEMenu			".\\Sound\\Sound_Effect_Lab\\Menu4.mp3"			// メニューを開くSEのパス

//extern Sound SE_Menu;			// メニューを開くSE


extern int Sound_Init(void);	// サウンドの初期化関数
extern void Sound_End(void);	// サウンドの終了処理を行う関数

extern Sound Sound_Load(const char* path, int volume, int playType);	// 読み込み
extern void Sound_Play(Sound sound);									// 再生
extern void Sound_Pause(Sound* sound);									// 一時停止
extern void Sound_Stop(Sound* sound);									// 停止
extern void Sound_Delete(Sound sound);									// 削除

void ChangeSoundVolume(Sound* sound, int volume);	// 音量変更
