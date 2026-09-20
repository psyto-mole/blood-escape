/* === サウンド処理のソースファイル === */

#include <string.h>
#include "Sound.h"

/* +++ BGM +++ */
//Sound BGM_Fake;			// 偽のタイトル画面のBGM

/* +++ 操作関連のSE +++ */
//Sound SE_Menu;			// メニューを開くSE


/* --- 読み込み・ハンドル生成(初期化) --- */
int Sound_Init(void)
{
	/* +++ BGM +++ */
	/*BGM_Fake = Sound_Load(PathBGMFake, VolumeQuiet, DX_PLAYTYPE_LOOP);
	if (BGM_Fake.Handle == -1)
	{
		return -1;
	}*/


	/* +++ 操作関連のSE +++ */
	//SE_Menu = Sound_Load(PathSEMenu, VolumeMax, DX_PLAYTYPE_BACK);
	//if (SE_Menu.Handle == -1)
	//{
	//	MessageBox(
	//		GetMainWindowHandle(),		// ウィンドウハンドル
	//		"Sound Menu",				// エラー内容
	//		"Sound Error",				// エラータイトル
	//		MB_OK						// OKボタンのみ表示
	//	);

	//	return -1;
	//}

	return 0;
}

/* --- 後始末 --- */
void Sound_End(void)
{
	/* +++ BGM +++ */
	//Sound_Delete(BGM_Fake);

	/* +++ 操作関連のSE +++ */
	//Sound_Delete(SE_Menu);

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