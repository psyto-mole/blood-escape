#pragma once
/* === チュートリアルシーンのクラスのヘッダファイル === */

#include "DxLib.h"
#include "Scene.h"
#include "TextScroll.h"


/* --- チュートリアルシーンのクラス(Sceneクラスの派生クラス) --- */
class TutorialScene : public Scene
{
private:
    TextPrinter textPrinter;    // 文字送り機能付きの文章描画オブジェクト

public:
    ~TutorialScene();   // デストラクタ

    int Init() override;        // チュートリアルシーンの初期化メソッド
    void Update() override;     // チュートリアルシーンの更新メソッド
    void Draw() override;       // チュートリアルシーンの描画メソッド
    void End() override;        // チュートリアルシーンの終了メソッド
};