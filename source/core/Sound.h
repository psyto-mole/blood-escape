#pragma once
/* === サウンド処理のヘッダファイル === */

#include "DxLib.h"


#define VolumeMax	250		// 音量「最大」の時の音量
#define BGMVolume	100		// BGMの音量
#define SEVolume	200		// SEの音量

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
#define PathBGMTitle	".\\sound\\bgm\\maou_damashi\\maoh_bgm_8bit26.mp3"	// タイトル画面のBGMのパス
#define PathBGMTutorial	".\\sound\\bgm\\maou_damashi\\maoh_bgm_8bit21.mp3"	// チュートリアル画面のBGMのパス
#define PathBGMStage	".\\sound\\bgm\\maou_damashi\\maoh_bgm_8bit04.mp3"	// ステージのBGMのパス
#define PathBGMGameOver	".\\sound\\bgm\\maou_damashi\\maoh_bgm_8bit03.mp3"	// ゲームオーバー画面のBGMのパス
#define PathBGMClear	".\\sound\\bgm\\maou_damashi\\maoh_bgm_8bit23.mp3"	// クリア画面のBGMのパス

extern Sound BGM_Title;		// タイトル画面のBGM
extern Sound BGM_Tutorial;	// チュートリアル画面のBGM
extern Sound BGM_Stage;		// ステージのBGM
extern Sound BGM_GameOver;	// ゲームオーバー画面のBGM
extern Sound BGM_Clear;		// クリア画面のBGM


/* +++ 操作関連のSE +++ */
#define PathSEMenu		".\\sound\\se\\sound_effect_lab\\open_menu2.mp3"		// メニューを開く時のSEのパス
#define PathSEEnter		".\\sound\\se\\sound_effect_lab\\press_enter15.mp3"		// エンターキーを押した時のSEのパス
#define PathSECancel	".\\sound\\se\\sound_effect_lab\\cancel2.mp3"			// 選択肢をキャンセルした時のSEのパス
#define PathSESelect	".\\sound\\se\\sound_effect_lab\\move_cursor8.mp3"		// 選択肢を変更したと時のSEのパス

extern Sound SE_Menu;		// メニューを開く時のSE
extern Sound SE_Enter;		// エンターキーを押した時のSE
extern Sound SE_Cancel;		// 選択肢をキャンセルした時のSE
extern Sound SE_Select;		// 選択肢を変更した時のSE


/* +++ プレイヤー関連のSE +++ */
#define PathSEInteract	".\\sound\\se\\sound_effect_lab\\press_enter33.mp3"		// ギミック操作のSEのパス
#define PathSESelfHarm	".\\sound\\se\\sound_effect_lab\\wield_whip1.mp3"		// 自傷のSEのパス
#define PathSEBleeding	".\\sound\\se\\sound_effect_lab\\blood_drips1.mp3"		// 出血のSEのパス

extern Sound SE_Interact;	// ギミック操作のSE
extern Sound SE_SelfHarm;	// 自傷のSE
extern Sound SE_Bleeding;	// 出血のSE


/* +++ ギミック関連のSE +++ */
#define PathSEBandage		".\\sound\\se\\sound_effect_lab\\wrap.mp3"	// 包帯のSEのパス
#define PathSEBloodPack		".\\sound\\se\\sound_effect_lab\\blisters2.mp3"	// 輸血パックのSEのパス
#define PathSEDoor			".\\sound\\se\\sound_effect_lab\\close_door3.mp3"	// ドアのSEのパス
#define PathSEGoalPoint		".\\sound\\se\\sound_effect_lab\\trauma.mp3"	// ゴール地点のSEのパス
#define PathSENeedleFloor	".\\sound\\se\\sound_effect_lab\\cut_with_knife.mp3"	// 針床のSEのパス
#define PathSESwitch		".\\sound\\se\\sound_effect_lab\\push_lever.mp3"		// スイッチのSEのパス

extern Sound SE_Bandage;		// 包帯のSE
extern Sound SE_BloodPack;		// 輸血パックのSE
extern Sound SE_Door;			// ドアのSE
extern Sound SE_GoalPoint;		// ゴール地点のSE
extern Sound SE_NeedleFloor;	// 針床のSE
extern Sound SE_Switch;			// スイッチのSE


/* +++ その他のSE +++ */
#define PathSETextScroll	".\\sound\\se\\sound_effect_lab\\display_message1.mp3"	// 文字送りのSEのパス

extern Sound SE_TextScroll;		// 文字送りのSE


extern int Sound_Init(void);	// サウンドの初期化関数
extern void Sound_End(void);	// サウンドの終了処理を行う関数

extern Sound Sound_Load(const char* path, int volume, int playType);	// 読み込み
extern void Sound_Play(Sound sound);									// 再生
extern void Sound_Pause(Sound* sound);									// 一時停止
extern void Sound_Stop(Sound* sound);									// 停止
extern void Sound_Delete(Sound sound);									// 削除

void ChangeSoundVolume(Sound* sound, int volume);	// 音量変更
