/* === サウンド処理のソースファイル === */

#include <string.h>
#include "Sound.h"

/* +++ BGM +++ */
Sound BGM_Title;		// タイトル画面のBGM
Sound BGM_Tutorial;		// チュートリアル画面のBGM
Sound BGM_Stage;		// ステージのBGM
Sound BGM_GameOver;		// ゲームオーバー画面のBGM
Sound BGM_Clear;		// クリア画面のBGM

/* +++ 操作関連のSE +++ */
Sound SE_Menu;		// メニューを開く時のSE
Sound SE_Enter;		// エンターキーを押した時のSE
Sound SE_Cancel;		// 選択肢をキャンセルした時のSE
Sound SE_Select;		// 選択肢を変更した時のSE

/* +++ プレイヤー関連のSE +++ */
Sound SE_Interact;	// ギミック操作のSE
Sound SE_SelfHarm;	// 自傷のSE
Sound SE_Bleeding;	// 出血のSE

/* +++ ギミック関連のSE +++ */
Sound SE_Bandage;		// 包帯のSE
Sound SE_BloodPack;		// 輸血パックのSE
Sound SE_Door;			// ドアのSE
Sound SE_GoalPoint;		// ゴール地点のSE
Sound SE_NeedleFloor;	// 針床のSE
Sound SE_Switch;			// スイッチのSE

/* +++ その他のSE +++ */
Sound SE_TextScroll;		// 文字送りのSE


/* --- 読み込み・ハンドル生成(初期化) --- */
int Sound_Init(void)
{
	/* +++ BGM +++ */
	BGM_Title = Sound_Load(PathBGMTitle, BGMVolume, DX_PLAYTYPE_LOOP);	// タイトル画面のBGMを読み込み
	if (BGM_Title.Handle == -1)		// タイトル画面のBGMの読み込みに失敗したら
	{
		/* +++ エラーメッセージを表示 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"Sound.cpp : Sound_Init() : Failed to load title BGM.",
			"Load Error",
			MB_OK
		);

		return -1;	// -1を返す(初期化失敗)
	}

	BGM_Tutorial = Sound_Load(PathBGMTutorial, BGMVolume, DX_PLAYTYPE_LOOP);	// チュートリアル画面のBGMを読み込み
	if (BGM_Tutorial.Handle == -1)		// チュートリアル画面のBGMの読み込みに失敗したら
	{
		/* +++ エラーメッセージを表示 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"Sound.cpp : Sound_Init() : Failed to load tutorial BGM.",
			"Load Error",
			MB_OK
		);

		return -1;	// -1を返す(初期化失敗)
	}

	BGM_Stage = Sound_Load(PathBGMStage, BGMVolume, DX_PLAYTYPE_LOOP);	// ステージのBGMを読み込み
	if (BGM_Stage.Handle == -1)		// ステージのBGMの読み込みに失敗したら
	{
		/* +++ エラーメッセージを表示 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"Sound.cpp : Sound_Init() : Failed to load stage BGM.",
			"Load Error",
			MB_OK
		);

		return -1;	// -1を返す(初期化失敗)
	}

	BGM_GameOver = Sound_Load(PathBGMGameOver, BGMVolume, DX_PLAYTYPE_LOOP);	// ゲームオーバー画面のBGMを読み込み
	if (BGM_GameOver.Handle == -1)		// ゲームオーバー画面のBGMの読み込みに失敗したら
	{
		/* +++ エラーメッセージを表示 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"Sound.cpp : Sound_Init() : Failed to load game over BGM.",
			"Load Error",
			MB_OK
		);

		return -1;	// -1を返す(初期化失敗)
	}

	BGM_Clear = Sound_Load(PathBGMClear, BGMVolume, DX_PLAYTYPE_LOOP);	// クリア画面のBGMを読み込み
	if (BGM_Clear.Handle == -1)		// クリア画面のBGMの読み込みに失敗したら
	{
		/* +++ エラーメッセージを表示 +++ */
		MessageBox(
			GetMainWindowHandle(),
			"Sound.cpp : Sound_Init() : Failed to load clear BGM.",
			"Load Error",
			MB_OK
		);

		return -1;	// -1を返す(初期化失敗)
	}


	/* +++ 操作関連のSE +++ */
	SE_Menu = Sound_Load(PathSEMenu, SEVolume, DX_PLAYTYPE_BACK);	// メニューを開くときのSEを読み込み
	if (SE_Menu.Handle == -1)	// 読み込みに失敗したら
	{
		MessageBox(
			GetMainWindowHandle(),								// ウィンドウハンドル
			"Sound.cpp : Init() : Failed to load menu SE.",		// エラー内容
			"Load Error",										// エラータイトル
			MB_OK												// OKボタンのみ表示
		);

		return -1;	// -1を返す(初期化失敗)
	}

	SE_Enter = Sound_Load(PathSEEnter, SEVolume, DX_PLAYTYPE_BACK);		// エンターキーを押した時のSEを読み込み
	if (SE_Enter.Handle == -1)	// 読み込みに失敗したら
	{
		MessageBox(
			GetMainWindowHandle(),									// ウィンドウハンドル
			"Sound.cpp : Init() : Failed to load enter key SE.",	// エラー内容
			"Load Error",											// エラータイトル
			MB_OK													// OKボタンのみ表示
		);

		return -1;	// -1を返す(初期化失敗)
	}

	SE_Cancel = Sound_Load(PathSECancel, SEVolume, DX_PLAYTYPE_BACK);	// 選択肢の取り消し時のSEの読み込み
	if (SE_Cancel.Handle == -1)	// 読み込みに失敗したら
	{
		MessageBox(
			GetMainWindowHandle(),								// ウィンドウハンドル
			"Sound.cpp : Init() : Failed to load cancel SE.",		// エラー内容
			"Load Error",										// エラータイトル
			MB_OK												// OKボタンのみ表示
		);

		return -1;	// -1を返す(初期化失敗)
	}

	SE_Select = Sound_Load(PathSESelect, SEVolume, DX_PLAYTYPE_BACK);	// 選択肢を変更した時のSEの読み込み
	if (SE_Select.Handle == -1)	// 読み込みに失敗したら
	{
		MessageBox(
			GetMainWindowHandle(),								// ウィンドウハンドル
			"Sound.cpp : Init() : Failed to load select SE.",		// エラー内容
			"Load Error",										// エラータイトル
			MB_OK												// OKボタンのみ表示
		);

		return -1;	// -1を返す(初期化失敗)
	}

	/* +++ プレイヤー関連のSE +++ */
	SE_Interact = Sound_Load(PathSEInteract, SEVolume, DX_PLAYTYPE_BACK);	// ギミック操作時のSEの読み込み
	if (SE_Interact.Handle == -1)	// 読み込みに失敗したら
	{
		MessageBox(
			GetMainWindowHandle(),								// ウィンドウハンドル
			"Sound.cpp : Init() : Failed to load interact SE.",		// エラー内容
			"Load Error",										// エラータイトル
			MB_OK												// OKボタンのみ表示
		);

		return -1;	// -1を返す(初期化失敗)
	}

	SE_SelfHarm = Sound_Load(PathSESelfHarm, SEVolume, DX_PLAYTYPE_BACK);	// 自傷のSEの読み込み
	if (SE_SelfHarm.Handle == -1)	// 読み込みに失敗したら
	{
		MessageBox(
			GetMainWindowHandle(),								// ウィンドウハンドル
			"Sound.cpp : Init() : Failed to load self-harm SE.",		// エラー内容
			"Load Error",										// エラータイトル
			MB_OK												// OKボタンのみ表示
		);

		return -1;	// -1を返す(初期化失敗)
	}

	SE_Bleeding = Sound_Load(PathSEBleeding, SEVolume, DX_PLAYTYPE_BACK);	// 出血のSEの読み込み
	if (SE_Bleeding.Handle == -1)	// 読み込みに失敗したら
	{
		MessageBox(
			GetMainWindowHandle(),								// ウィンドウハンドル
			"Sound.cpp : Init() : Failed to load bleeding SE.",		// エラー内容
			"Load Error",										// エラータイトル
			MB_OK												// OKボタンのみ表示
		);

		return -1;	// -1を返す(初期化失敗)
	}

	/* +++ ギミック関連のSE +++ */
	SE_Bandage = Sound_Load(PathSEBandage, SEVolume, DX_PLAYTYPE_BACK);	// 包帯取得時のSEの読み込み
	if (SE_Bandage.Handle == -1)	// 読み込みに失敗したら
	{
		MessageBox(
			GetMainWindowHandle(),								// ウィンドウハンドル
			"Sound.cpp : Init() : Failed to load bandage SE.",		// エラー内容
			"Load Error",										// エラータイトル
			MB_OK												// OKボタンのみ表示
		);

		return -1;	// -1を返す(初期化失敗)
	}

	SE_BloodPack = Sound_Load(PathSEBloodPack, SEVolume, DX_PLAYTYPE_BACK);	// 輸血パック取得時のSEの読み込み
	if (SE_BloodPack.Handle == -1)	// 読み込みに失敗したら
	{
		MessageBox(
			GetMainWindowHandle(),								// ウィンドウハンドル
			"Sound.cpp : Init() : Failed to load blood pack SE.",		// エラー内容
			"Load Error",										// エラータイトル
			MB_OK												// OKボタンのみ表示
		);

		return -1;	// -1を返す(初期化失敗)
	}

	SE_Door = Sound_Load(PathSEDoor, SEVolume, DX_PLAYTYPE_BACK);	// ドアのSEの読み込み
	if (SE_Door.Handle == -1)	// 読み込みに失敗したら
	{
		MessageBox(
			GetMainWindowHandle(),								// ウィンドウハンドル
			"Sound.cpp : Init() : Failed to load door SE.",		// エラー内容
			"Load Error",										// エラータイトル
			MB_OK												// OKボタンのみ表示
		);

		return -1;	// -1を返す(初期化失敗)
	}

	SE_GoalPoint = Sound_Load(PathSEGoalPoint, SEVolume, DX_PLAYTYPE_BACK);	// ゴール地点のSEの読み込み
	if (SE_GoalPoint.Handle == -1)	// 読み込みに失敗したら
	{
		MessageBox(
			GetMainWindowHandle(),								// ウィンドウハンドル
			"Sound.cpp : Init() : Failed to load goal point SE.",		// エラー内容
			"Load Error",										// エラータイトル
			MB_OK												// OKボタンのみ表示
		);

		return -1;	// -1を返す(初期化失敗)
	}

	SE_NeedleFloor = Sound_Load(PathSENeedleFloor, SEVolume, DX_PLAYTYPE_BACK);	// 針床のSEの読み込み
	if (SE_NeedleFloor.Handle == -1)	// 読み込みに失敗したら
	{
		MessageBox(
			GetMainWindowHandle(),								// ウィンドウハンドル
			"Sound.cpp : Init() : Failed to load needle floor SE.",		// エラー内容
			"Load Error",										// エラータイトル
			MB_OK												// OKボタンのみ表示
		);

		return -1;	// -1を返す(初期化失敗)
	}

	SE_Switch = Sound_Load(PathSESwitch, SEVolume, DX_PLAYTYPE_BACK);	// スイッチのSEの読み込み
	if (SE_Switch.Handle == -1)	// 読み込みに失敗したら
	{
		MessageBox(
			GetMainWindowHandle(),								// ウィンドウハンドル
			"Sound.cpp : Init() : Failed to load switch SE.",		// エラー内容
			"Load Error",										// エラータイトル
			MB_OK												// OKボタンのみ表示
		);

		return -1;	// -1を返す(初期化失敗)
	}

	SE_TextScroll = Sound_Load(PathSETextScroll, SEVolume, DX_PLAYTYPE_BACK);	// 文字送りのSEの読み込み
	if (SE_TextScroll.Handle == -1)	// 読み込みに失敗したら
	{
		MessageBox(
			GetMainWindowHandle(),								// ウィンドウハンドル
			"Sound.cpp : Init() : Failed to load text scroll SE.",		// エラー内容
			"Load Error",										// エラータイトル
			MB_OK												// OKボタンのみ表示
		);

		return -1;	// -1を返す(初期化失敗)
	}
	

	return 0;
}

/* --- 後始末 --- */
void Sound_End(void)
{
	/* +++ BGM +++ */
	Sound_Delete(BGM_Title);		// タイトル画面のBGMを削除
	Sound_Delete(BGM_Tutorial);		// チュートリアル画面のBGMを削除
	Sound_Delete(BGM_Stage);		// ステージのBGMを削除
	Sound_Delete(BGM_GameOver);		// ゲームオーバー画面のBGMを削除
	Sound_Delete(BGM_Clear);		// クリア画面のBGMを削除

	/* +++ 操作関連のSE +++ */
	Sound_Delete(SE_Menu);		// メニューを開いた時のSEを削除
	Sound_Delete(SE_Enter);		// エンターキーを押した時のSEを削除
	Sound_Delete(SE_Cancel);	// 選択を取り消した時のSEを削除
	Sound_Delete(SE_Select);	// 選択肢を変えた時のSEを削除

	/* +++ プレイヤー関連のSE +++ */
	Sound_Delete(SE_Interact);	// ギミック操作時のSEを削除
	Sound_Delete(SE_SelfHarm);	// 自傷のSEを削除
	Sound_Delete(SE_Bleeding);	// 出血のSEを削除

	/* +++ ギミック関連のSE +++ */
	Sound_Delete(SE_Bandage);		// 包帯取得時のSEを削除
	Sound_Delete(SE_BloodPack);		// 輸血パック取得時のSEを削除
	Sound_Delete(SE_Door);			// ドアのSEを削除
	Sound_Delete(SE_GoalPoint);		// ゴール地点のSEを削除
	Sound_Delete(SE_NeedleFloor);	// 針床のSEを削除
	Sound_Delete(SE_Switch);		// スイッチのSEを削除
	
	/* +++ その他のSE +++ */
	Sound_Delete(SE_TextScroll);	// 文字送りのSEを削除

	return;
}

/* --- 読み込み --- */
Sound Sound_Load(const char* path, int volume, int playType)
{
	Sound sound;

	// ファイルの場所をコピー
	sprintf_s(sound.Path, sizeof(sound.Path), "%s", path);

	// 音楽をメモリに読み込み
	sound.Handle = LoadSoundMem(sound.Path);

	/* === 読み込みが成功したかの確認 === */
	if (sound.Handle != -1)
	{
		/* === 正常に読み込みができたらパラメータ設定 === */
		sound.Volume = volume;						// 音量を設定
		ChangeSoundVolume(&sound, sound.Volume);	// 再生音量を設定
		sound.Playtype = playType;					// 再生形式の設定
		sound.PlayBeginning = true;					// 停止後は最初から再生する
	}

	return sound;
}

/* --- 再生 --- */
void Sound_Play(Sound sound)
{
	switch (sound.Playtype)
	{
	case DX_PLAYTYPE_BACK:
		// 1回のみ再生(通常再生)

		// 再生
		PlaySoundMem(sound.Handle, DX_PLAYTYPE_BACK, sound.PlayBeginning);
		break;

	case DX_PLAYTYPE_LOOP:
		// ループ再生

		if (CheckSoundMem(sound.Handle) == 0)	// 再生されていないとき
		{
			// ループ再生する
			PlaySoundMem(sound.Handle, DX_PLAYTYPE_LOOP, sound.PlayBeginning);
		}

		break;

	default:
		break;
	}

	return;
}

/* --- 一時停止 --- */
void Sound_Pause(Sound* sound)
{
	// 停止後の再生位置を今の位置にする
	sound->PlayBeginning = false;

	// 再生されているなら
	if (CheckSoundMem(sound->Handle) == 1)
	{
		// 音楽停止
		StopSoundMem(sound->Handle);

		// マスタ音量に戻す
		ChangeVolumeSoundMem(sound->Volume, sound->Handle);
	}

	return;
}

/* --- 停止 --- */
void Sound_Stop(Sound* sound)
{
	// 停止後の再生位置は最初からにする
	sound->PlayBeginning = true;

	if (CheckSoundMem(sound->Handle) == 1)
	{
		// 音楽停止
		StopSoundMem(sound->Handle);

		// マスタ音量に戻す
		ChangeVolumeSoundMem(sound->Volume, sound->Handle);
	}

	return;
}

/* --- 削除 --- */
/* === ハンドルを渡すので引数は値渡し === */
void Sound_Delete(Sound sound)
{
	if (sound.Handle != -1)		// 正常に読み込みができていれば
	{
		DeleteSoundMem(sound.Handle);	// メモリから削除(メモリを解放)
	}

	return;
}

/* --- 音量変更 --- */
void ChangeSoundVolume(Sound* sound, int volume)
{
	/* === マスタ音量は変えず、再生されている音量を変更 === */
	/* ※構造体のボリュームは最大音量(マスタ音量)なので変更しない */
	if (volume <= sound->Volume)
	{
		ChangeVolumeSoundMem(volume, sound->Handle);
	}


	return;
}