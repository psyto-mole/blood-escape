#pragma once
/* === クリアシーンのクラスのヘッダファイル === */

#include "DxLib.h"
#include "Scene.h"
#include "TextScroll.h"
#include "GameMaster.h"


/* --- クリアシーンのクラス(Sceneクラスの派生クラス) --- */
class ClearScene : public Scene
{
private:
    TextPrinter textPrinter;    // 文字送り機能付きのテキスト描画を行うオブジェクト

    GameMaster gameMasterObject;    // ゲームマスターのオブジェクト

public:
    int Init() override;    // クリアシーンの初期化メソッド
    void Update() override;  // クリアシーンの更新メソッド
    void Draw() override;    // クリアシーンの描画メソッド
    void End() override;     // クリアシーンの終了メソッド
};