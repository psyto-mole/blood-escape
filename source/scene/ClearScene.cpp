/* === クリアシーンのクラスのソースファイル === */

#include "ClearScene.h"
#include "GameManager.h"
#include "Key.h"
#include "Color.h"
#include "Font.h"
#include "Message.h"
#include "Sound.h"


/* --- クリアシーンの初期化メソッド --- */
int ClearScene::Init()
{
	transition = {};	// 遷移情報をクリア

	sceneElapsedFrame = 0;	// 経過フレームをリセット

	Sound_Play(BGM_Clear);	// クリア画面のBGMを再生

	return 0;
}

/* --- クリアシーンの更新メソッド --- */
void ClearScene::Update()
{
	if (Key_Check_Click(KEY_INPUT_RETURN) && sceneElapsedFrame >= GameFPS)	// シーン切り替えから1秒が経過しエンターがクリックされたら
	{
		transition.transitionType = TransitionType::ChangeScene;	// 遷移情報の遷移の状態を「シーン切り替え」に設定
		transition.sceneType = SceneType::Title;					// 遷移情報のシーンの種類をタイトルシーンに設定

		Sound_Play(SE_Enter);   // エンターキーを押した時のSEを再生
	}

	sceneElapsedFrame += 1;		// 経過フレームを1加算

	return;
}

/* --- クリアシーンの描画メソッド --- */
void ClearScene::Draw()
{
	DrawFormatStringToHandleAlign(GameWindowWidth / 2, 300, FAlign_AllCenter, Color_White, KHDot_100_9, "%s", StringResultMessage);	// お祝いメッセージを描画

	return;
}

/* --- クリアシーンの終了メソッド --- */
void ClearScene::End()
{
	Sound_Stop(&BGM_Clear);		// クリア画面のBGMの再生を停止

	return;
}