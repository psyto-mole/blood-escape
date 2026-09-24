/* === クリアシーンのクラスのソースファイル === */

#include "ClearScene.h"
#include "GameManager.h"


/* --- クリアシーンの初期化メソッド --- */
void ClearScene::Init()
{
	transition = {};	// 遷移情報をクリア

	sceneElapsedFrame = 0;	// 経過フレームをリセット

	return;
}

/* --- クリアシーンの更新メソッド --- */
void ClearScene::Update()
{
	sceneElapsedFrame += 1;		// 経過フレームを1加算

	if (/* エンターがクリックされた */ && sceneElapsedFrame >= GameFPS)	// シーン切り替えから1秒が経過しエンターがクリックされたら
	{
		transition.transitionType = TransitionType::ChangeScene;	// 遷移情報の遷移の状態を「シーン切り替え」に設定
		transition.sceneType = SceneType::Title;					// 遷移情報のシーンの種類をタイトルシーンに設定
	}

	return;
}

/* --- クリアシーンの描画メソッド --- */
void ClearScene::Draw()
{
	return;
}

/* --- クリアシーンの終了メソッド --- */
void ClearScene::End()
{
	return;
}

/* --- 遷移情報を取得するメソッド --- */
SceneTransition ClearScene::GetTransition() const
{
	return transition;	// 遷移情報を返す
}