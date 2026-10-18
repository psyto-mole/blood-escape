#pragma once
/* === メニュータブ関連の処理のヘッダファイル === */

#include "DxLib.h"


/* --- メニュータブのクラス --- */
class MenuTab
{
private:
	RECT menuTabFrame;		// メニュータブの外枠
	RECT menuTabInside;		// メニュータブの内側

public:
	MenuTab();		// コンストラクタ
	~MenuTab();		// デストラクタ

	int Init();		// メニュータブの初期化メソッド
	void Update();	// メニュータブの更新メソッド
	void Draw();	// メニュータブの描画メソッド
};