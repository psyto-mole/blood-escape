/* === クリアシーンのクラスのソースファイル === */

#include "ClearScene.h"
#include "GameManager.h"
#include "Geometry.h"
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

	if (gameMasterObject.Init() == -1)
	{
		return -1;	// -1を返す(初期化失敗)
	}

	textPrinter.SetMessages(
		{
			"おめでとうございます",
			"あなたはこのゲームにしょうりしました",
			"みずからのいのちをけずることもいとわぬしせい...たいへんかんぷくいたしました",
			"このゲーム...あなたにもたのしんでいただけたのならなによりです",
			"それでは...またあらたなゲームでおあいしましょう"
		});

	return 0;
}

/* --- クリアシーンの更新メソッド --- */
void ClearScene::Update()
{
	textPrinter.Update();	// 文字送りを更新

	if (Key_Check_Click(KEY_INPUT_RETURN))  // Enterキーがクリックされたら
	{
		textPrinter.AdvanceText();  // 文章を進める
	}

	gameMasterObject.Update();	// ゲームマスターの更新メソッドを実行

	if (textPrinter.IsAllMessageFinished() && sceneElapsedFrame >= GameFPS)		// シーン切り替えから1秒が経過しメッセージが全て表示されているされたら
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
	DrawRect(GetRect(0, 0, GameWindowWidth, GameWindowHeight), Color_White, true, FALSE);	// ウィンドウの背景を白にする

	gameMasterObject.Draw();	// ゲームマスターを描画

	textPrinter.Draw(GameWindowWidth / 2, 900, FAlign_AllCenter, Color_Black, KHDot_40_2);	// メッセージを描画

	return;
}

/* --- クリアシーンの終了メソッド --- */
void ClearScene::End()
{
	Sound_Stop(&BGM_Clear);		// クリア画面のBGMの再生を停止

	return;
}