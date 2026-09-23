/* === フェード処理に関するソースファイル === */

#include "Fade.h"
#include "GameManager.h"
#include "Color.h"


/* --- コンストラクタ --- */
Fade::Fade()
    : fadeState(FadeState::None),
    fadeAlpha(0),
    fadeSpeed(10)
{
}

/* --- フェードの初期化 --- */
void Fade::FadeInit(int alpha, int speed)
{
    fadeAlpha = alpha;  // フェードの透明度を引数で受け取った値に設定
    fadeSpeed = speed;  // フェードの早さを引数で受け取った値に設定

    return;
}

/* --- フェードの更新 --- */
void Fade::FadeUpdate()
{
    /* +++ フェードアウトの処理 +++ */
    if (fadeState == FadeState::FadeOut)    // フェードの状態が「フェードアウト」なら
    {
        fadeAlpha += fadeSpeed;     // フェードの早さの値を透明度に足す


        if (fadeAlpha >= FadeAlphaMax)   // フェードの透明度が最大値以上なら
        {
            fadeAlpha = FadeAlphaMax;    // フェードの透明度を最大値に設定

            fadeState = FadeState::FadeTrans;   // フェードの状態を「アウトからインへの切り換わり」に設定する
        }

        return;
    }

    /* +++ フェードの切り換わりの処理 +++ */
    if (fadeState == FadeState::FadeTrans)  // フェードの状態が「アウトからインへの切り換わり」なら
    {
        fadeState = FadeState::FadeIn;  // フェードの状態を「フェードイン」に設定

        return;
    }

    /* +++ フェードインの処理 +++ */
    if (fadeState == FadeState::FadeIn)     // フェードの状態が「フェードイン」なら
    {
        fadeAlpha -= fadeSpeed;     // フェードの透明度をフェードの早さの値だけ減らす

        if (fadeAlpha <= 0)     // 透明度が0以下となったら
        {
            fadeAlpha = 0;  // 透明度を0にする

            fadeState = FadeState::None;    // フェードの状態を「フェードしない」に設定する
        }

        return;
    }

    return;
}

/* --- フェードを描画 --- */
void Fade::FadeDraw()
{
    if (fadeAlpha <= 0)     // フェードの透明度が0以下なら
    {
        return;     // 何もせず終了
    }

    SetDrawBlendMode(DX_BLENDMODE_ALPHA, fadeAlpha);    // 既に描画されている画像とアルファブレンディング 

    DrawBox(0, 0, GameWindowWidth + 1, GameWindowHeight + 1, Color_Black, TRUE);    // 黒の四角形を全画面で描画

    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // ブレンドモードをデフォルトに戻す

    return;
}

/* --- フェードの状態を「フェードしない」に設定する --- */
void Fade::SetStateNone()
{
    fadeState = FadeState::None;    // フェードの状態を「フェードしない」に設定

    return;
}

/* --- フェードの状態を「フェードイン」に設定する --- */
void Fade::SetStateFadeIn()
{
    fadeState = FadeState::FadeIn;  // フェードの状態を「フェードイン」に設定

    return;
}

/* --- フェードの状態を「フェードアウト」に設定する --- */
void Fade::SetStateFadeOut()
{
    fadeState = FadeState::FadeOut;     // フェードの状態を「フェードアウト」に設定

    return;
}

/* --- フェードの状態を取得するメソッド --- */
FadeState Fade::GetFadeState()
{
    return fadeState;   // フェードの状態を返す
}

// フェードの透明度を設定
void Fade::SetFadeAlpha(int alpha)
{
    fadeAlpha = alpha;  // フェードの透明度を引数で受け取った値に設定

    return;
}

// フェードのスピードを設定
void Fade::SetFadeSpeed(int speed)
{
    fadeSpeed = speed;  // フェードの早さを引数で受け取った値に設定

    return;
}