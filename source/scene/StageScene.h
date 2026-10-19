#pragma once
/* === ステージのクラスのヘッダファイル === */

#include "DxLib.h"
#include "Scene.h"
#include "Player.h"
#include "Map.h"
#include "GimmickManager.h"


#define NumberOfStage   4   // ステージ数

/* --- ステージクラス(Sceneクラスの派生クラスで全ステージ共通) --- */
class StageScene : public Scene
{
private:
    int stageNumber;    // ステージ番号(StageSceneクラス固有の変数)

    Player playerObject;            // プレイヤーのオブジェクト
    Map mapManager;                 // マップマネージャー
    GimmickManager gimmickManager;  // ギミックマネージャー

public:
    StageScene(int stage);  // コンストラクタ
    ~StageScene();          // デストラクタ

    int Init() override;       // ステージの初期化メソッド
    void Update() override;     // ステージの更新メソッド
    void Draw() override;       // ステージの描画メソッド
    void End() override;        // ステージの終了メソッド

    int GetStageNumber() const;     // ステージ番号の取得メソッド(Stageクラスの独自のメソッド)
};