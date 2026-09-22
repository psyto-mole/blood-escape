#include "StageScene.h"

StageScene::StageScene(int stage)
    : stageNumber(stage),
    result(SceneResult::None)
{
}

void StageScene::Init()
{
    result = SceneResult::None;

    // ステージデータを読み込む
    // プレイヤーの初期位置を設定
    // 敵を配置
    // パズルを初期状態にする
}

void StageScene::Update()
{
    // プレイヤーの更新
    // 敵の更新
    // パズルの更新
    // 当たり判定

    // クリア判定
    //if (/* パズルをクリアした */)
    //{
    //    result = SceneResult::Clear;
    //    return;
    //}

    //// ゲームオーバー判定
    //if (/* ゲームオーバー */)
    //{
    //    result = SceneResult::GameOver;
    //    return;
    //}
}

void StageScene::Draw()
{
    // ステージ描画
    // プレイヤー描画
    // 敵描画
    // UI描画
}

void StageScene::End()
{
    // ステージ固有のリソース解放
}

SceneResult StageScene::GetResult() const
{
    return result;
}

int StageScene::GetStageNumber() const
{
    return stageNumber;
}