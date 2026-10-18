#pragma once
/* === メニュータブ関連の処理のヘッダファイル === */

#include "DxLib.h"


/* --- メニュータブのクラス --- */
class MenuTab
{
private:


public:
	MenuTab();		// コンストラクタ
	~MenuTab();		// デストラクタ

	int Init();		// メニュータブの初期化メソッド
	void Update();	// メニュータブの更新メソッド
	void Draw();	// メニュータブの描画メソッド
};