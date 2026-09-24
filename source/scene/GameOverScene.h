#pragma once
/* === ゲームオーバーシーンのクラスのヘッダファイル === */

#include "DxLib.h"
#include "Scene.h"


/* --- ゲームオーバーシーンのクラス(Sceneクラスの派生クラス) --- */
class GameOverScene : public Scene
{
private:
    SceneTransition transition;     // 遷移情報

    int gameoverNumber;     // ゲームオーバーになったステージ番号(GameOverSceneクラス固有の変数)
    int selectedIndex;      // ゲームオーバー画面の選択肢用の変数(0:リトライ,1:タイトルに戻る、GameOverSceneクラス固有の変数)

    int sceneElapsedFrame;   // シーンの経過フレーム
    
public:
    GameOverScene(int stage);   // コンストラクタ

    void Init() override;       // ゲームオーバーシーンの初期化メソッド
    void Update() override;     // ゲームオーバーシーンの更新メソッド
    void Draw() override;       // ゲームオーバーシーンの描画メソッド
    void End() override;        // ゲームオーバーシーンの終了メソッド

    SceneTransition GetTransition() const override;     // 遷移情報の取得メソッド
};