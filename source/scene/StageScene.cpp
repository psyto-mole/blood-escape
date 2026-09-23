#include "StageScene.h"

StageScene::StageScene(int stage)
    : stageNumber(stage)
{
}

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
}

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
        transition.transitionType = TransitionType::ChangeScene;

        transition.sceneType = SceneType::Stage;

        transition.stageNum = stageNumber + 1;

        return;
    }

    // --------------------------
    // ゲームオーバー判定
    // --------------------------

    if (/* ゲームオーバー */)
    {
        transition.transitionType = TransitionType::ChangeScene;

        transition.sceneType = SceneType::GameOver;

        transition.stageNum = stageNumber;

        return;
    }
}

void StageScene::Draw()
{
    // ステージ描画
    // プレイヤー描画
    // 敵描画
    // パズル描画
    // UI描画
}

void StageScene::End()
{
    // ステージ固有のリソース解放
}

SceneTransition StageScene::GetTransition() const
{
    return transition;
}

int StageScene::GetStageNumber() const
{
    return stageNumber;
}