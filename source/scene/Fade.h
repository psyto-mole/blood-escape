#pragma once
/* === フェード処理に関するヘッダファイル ===  */

#include "DxLib.h"


#define FadeAlphaMax 255    // フェードの透明度の最大値

/* --- フェードの状態に関する列挙型 --- */
enum class FadeState
{
    None,       // フェードしない
    FadeOut,    // フェードアウト
    FadeIn,     // フェードイン
    FadeTrans   // フェードアウトからフェードインへの切り換わり(このタイミングでシーンが切り換わる)
};

/* --- フェードクラス --- */
class Fade
{
private:
    FadeState fadeState;    // フェードの状態を保持する変数

    int fadeAlpha;  // フェードの透明度を保持する変数(255で透過なし、0で完全に透明)
    int fadeSpeed;  // フェードのスピードを保持する変数(値が大きいほどフェードが早い)

public:
    Fade();     // コンストラクタ

    void FadeInit(int alpha, int speed);    // フェードの初期化するメソッド
    void FadeUpdate();                      // フェードの更新するメソッド
    void FadeDraw();                        // フェードを描画するメソッド

    void SetStateNone();     // フェードの状態を「フェードしない」に設定するメソッド
    void SetStateFadeIn();   // フェードの状態を「フェードイン」に設定するメソッド
    void SetStateFadeOut();  // フェードの状態を「フェードアウト」に設定するメソッド

    FadeState GetFadeState();   // フェードの状態を取得するメソッド

    void SetFadeAlpha(int alpha);    // フェードの透明度を設定
    void SetFadeSpeed(int speed);    // フェードのスピードを設定
};