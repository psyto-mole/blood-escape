/* === ステージのクラスのソースファイル === */

#include "StageScene.h"


/* --- Stageクラスのコンストラクタ --- */
StageScene::StageScene(int stage)
    : stageNumber(stage)    // ステージ番号に引数で渡された値を代入
{
}

/* --- ステージの初期化メソッド --- */
void StageScene::Init()
{
    transition = {};    // 遷移情報をリセット

    // ---------------------------
    // ステージ初期化
    // ---------------------------

    // ステージデータを読み込む
    // プレイヤーの初期位置を設定
    // 敵を配置
    // パズルを初期状態にする

    return;
}

/* --- ステージの更新メソッド --- */
void StageScene::Update()
{
    // --------------------
    // ゲーム更新
    // --------------------

    // プレイヤーの更新
    // 敵の更新
    // パズルの更新
    // 当たり判定

    // -----------------
    // クリア判定
    // -----------------

    if (/* パズルをクリアした */)
    {
        transition.transitionType = TransitionType::ChangeScene;    // 遷移の状態をシーン切り替えにする

        transition.sceneType = SceneType::Stage;    // 遷移情報のシーンの種類をステージにする

        transition.stageNum = stageNumber + 1;  //  遷移情報のステージ番号に自身の番号 + 1を代入

        return;
    }

    // --------------------------
    // ゲームオーバー判定
    // --------------------------

    if (/* ゲームオーバー */)
    {
        transition.transitionType = TransitionType::ChangeScene;    // 遷移の状態をシーン切り替えにする

        transition.sceneType = SceneType::GameOver;     // 遷移情報のシーンの種類をゲームオーバーシーンにする

        transition.stageNum = stageNumber;  // 遷移情報のステージ番号に自身の番号を代入する

        return;
    }
}

/* --- ステージの描画メソッド --- */
void StageScene::Draw()
{
    // ステージ描画
    // プレイヤー描画
    // 敵描画
    // パズル描画
    // UI描画

    return;
}

/* --- ステージの終了メソッド --- */
void StageScene::End()
{
    // ステージ固有のリソース解放
}

/* --- 遷移情報の取得メソッド --- */
SceneTransition StageScene::GetTransition() const
{
    return transition;  // 自身の遷移情報を返す
}

/* --- ステージ番号の取得メソッド --- */
int StageScene::GetStageNumber() const
{
    return stageNumber;     // 自身のステージ番号を返す
}