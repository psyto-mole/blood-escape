#pragma once
/* === 全シーン共通のインターフェースのヘッダファイル === */

#include "DxLib.h"


/* --- シーンの種類の列挙型 --- */
enum class SceneType
{
    Title,      // タイトル画面
    Tutorial,   // チュートリアル画面
    Stage,      // ステージ(全ステージ共通)
    GameOver,   // ゲームオーバー画面
    Clear       // クリア画面
};

/* --- 画面遷移の状態の列挙型(画面遷移を行う際にChanmgeSceneにする) --- */
enum class TransitionType
{
    None,           // 遷移しない
    ChangeScene     // シーン切り替え
};

/* --- シーンの遷移に関わる情報をまとめた構造体 --- */
struct SceneTransition
{
    SceneType sceneType = SceneType::Title;                 // シーンの種類(デフォルトは「タイトル画面」)
    TransitionType transitionType = TransitionType::None;   // 遷移状態(デフォルトは「遷移しない」)

    int stageNum = 0;                                       // ステージ番号
};

/* --- シーンクラス(全てのシーンの基底クラス) --- */
class Scene
{
protected:
    SceneTransition transition;     // シーンの遷移情報

    int sceneElapsedFrame;   // シーンの経過フレーム

public:
    Scene();                        // コンストラクタ
    virtual ~Scene() = default;     // デストラクタ

    virtual void Init() = 0;    // このシーンの初期化メソッド
    virtual void Update() = 0;  // このシーンの更新メソッド
    virtual void Draw() = 0;    // このシーンの描画メソッド
    virtual void End() = 0;     // このシーンの終了メソッド

    SceneTransition GetTransition() const;  // 遷移情報を取得するメソッド(読み取り専用なのでconst)
};