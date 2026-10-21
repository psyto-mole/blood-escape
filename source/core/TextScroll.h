#pragma once
/* === 文字送り処理のヘッダファイル === */

#include <string>
#include <vector>
#include "DxLib.h"


/* --- 文字送り機能付きで文章を描画するクラス --- */
class TextPrinter
{
private:
	std::vector<std::string> messageMatrix;		// 文章一覧

	size_t currentMessage;		// 現在表示している文章番号
	size_t displayPosition;		// 何バイト目まで表示するか

	int timer;				// 文字送り用タイマー
	int scrollInterval;		// 文字送りの間隔

public:
	TextPrinter();	// コンストラクタ

	void SetMessages(const std::vector<std::string>& messages);		// 文章を設定するメソッド

	void Update();											// 文字送り機能付き文章の更新メソッド
	void Draw(int x, int y, int color, int fontHandle);		// 文字送り機能付き文章の描画メソッド

	void AdvanceText();								// 文章を進めるメソッド(Enterキーが押されたときに実行する)
	void SkipScroll(const std::string& message);	// 文字送りを飛ばすメソッド
	void ChangeText();								// 文章を変えるメソッド


	bool IsCurrentMessageFinished() const;	// 現在の文章が最後まで表示されたか
	bool IsAllMessageFinished() const;		// 全ての文章が最後まで表示されたか

private:
	size_t GetCharacterByte(size_t pos) const;	// 現在位置の文字のバイトを取得
};