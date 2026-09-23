#pragma once
/* === ステージのクラスのヘッダファイル === */

#include "DxLib.h"
#include "Scene.h"


/* --- ステージクラス(Sceneクラスの派生クラスで全ステージ共通) --- */
class StageScene : public Scene
{
private:
    SceneTransition transition;     // 遷移情報

    int stageNumber;    // ステージ番号

public:
    StageScene(int stage);  // コンストラクタ

    void Init() override;       // ステージの初期化メソッド
    void Update() override;     // ステージの更新メソッド
    void Draw() override;       // ステージの描画メソッド
    void End() override;        // ステージの終了メソッド

    SceneTransition GetTransition() const override;     // 遷移情報の取得メソッド

    int GetStageNumber() const;     // ステージ番号の取得メソッド(Stageクラスの独自のメソッド)
};