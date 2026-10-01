#pragma once
/* === ゲームオーバーシーンのクラスのヘッダファイル === */

#include "DxLib.h"
#include "Scene.h"


#define NumberOfGameoverOption 2    // ゲームオーバー画面の選択肢の数(選択肢の最大値)

/* --- ゲームオーバーシーンのクラス(Sceneクラスの派生クラス) --- */
class GameOverScene : public Scene
{
private:
    int gameoverNumber;     // ゲームオーバーになったステージ番号(GameOverSceneクラス固有の変数)
    int selectedIndex;      // ゲームオーバー画面の選択肢用の変数(1:リトライ,2:タイトルに戻る、GameOverSceneクラス固有の変数)

    RECT option1Button;     // 選択肢1
    RECT option2Button;     // 選択肢2

public:
    GameOverScene(int stage);   // コンストラクタ
    ~GameOverScene();           // デストラクタ

    void Init() override;       // ゲームオーバーシーンの初期化メソッド
    void Update() override;     // ゲームオーバーシーンの更新メソッド
    void Draw() override;       // ゲームオーバーシーンの描画メソッド
    void End() override;        // ゲームオーバーシーンの終了メソッド
};