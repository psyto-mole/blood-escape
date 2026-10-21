/* === 文字送り処理のソースファイル ==== */

#include "TextScroll.h"
#include "Sound.h"


/* --- コンストラクタ --- */
TextPrinter::TextPrinter()
{
	currentMessage = 0;		// 現在表示している文章番号の初期化
	displayPosition = 0;	// 表示するバイト数の初期化

	timer = 0;				// 文字送り用タイマーの初期化
	scrollInterval = 5;		// 文字送りの間隔の初期化
}

/* --- 文章を設定するメソッド-- - */
void TextPrinter::SetMessages(const std::vector<std::string>& messages)
{
	messageMatrix = messages;	// 文章を設定

	currentMessage = 0;		// 表示する文章を最初に戻す
	displayPosition = 0;	// 表示するバイト数を初期化

	timer = 0;	// タイマーを初期化

	return;
}

/* --- 文字送り機能付き文章の更新メソッド-- - */
void TextPrinter::Update()
{
	if (IsAllMessageFinished())		// 全ての文章が表示されている
	{
		return;		// 何もせずに処理を終了
	}

	if (IsCurrentMessageFinished())		// 現在の文章が最後まで表示されている
	{
		return;		// 何もせずに処理を終了
	}

	timer++;	// タイマーを1加算

	if (timer >= scrollInterval)	// タイマー(経過フレーム)が文字送りの間隔に達したら
	{
		displayPosition += GetCharacterByte(displayPosition);	// 現在表示している文字のバイト数だけ進める
	
		timer = 0;	// タイマーを0に戻す

		Sound_Play(SE_TextScroll);	// 文字送りのSEを再生
	}

	return;
}

/* --- 文字送り機能付き文章の描画メソッド-- - */
void TextPrinter::Draw(int x, int y, int color, int fontHandle)
{
	if (messageMatrix.empty())	// 文章が存在しなければ
	{
		return;		// 何もせずに処理を終了
	}

	if (IsAllMessageFinished())		// 全ての文章が表示されている
	{
		return;		// 何もせずに処理を終了
	}

	const std::string& message = messageMatrix[currentMessage];		// 現在の文章を設定

	std::string displayText = message.substr(0, displayPosition);	// 文章から表示する部分を抜き出す

	DrawFormatStringToHandle(x, y, color, fontHandle, displayText.c_str());		// 文章を表示

	return;
}

/* --- 文章を次に進めるメソッド-- - */
void TextPrinter::AdvanceText()
{
	if (IsAllMessageFinished())		// 全ての文章が表示されているなら
	{
		return;		// 何もせずに処理を終了
	}

	const std::string& message = messageMatrix[currentMessage];		// 現在の文章を取得

	if (IsCurrentMessageFinished())		// 現在の文章が最後まで表示されている(文字送りが終了しているなら)
	{
		ChangeText();	// 次の文章を設定
	}
	else
	{
		SkipScroll(message);	// 文字送りを飛ばす
	}

	return;
}

/* --- 文字送りを飛ばすメソッド-- - */
void TextPrinter::SkipScroll(const std::string& message)
{
	displayPosition = message.size();	// 現在の文章yを最後まで表示する

	return;
}

/* --- 文章を変えるメソッド-- - */
void TextPrinter::ChangeText()
{
	currentMessage++;	// 次の文章にする

	if (IsAllMessageFinished() != true)		// 全ての文章を表示していない(次の文章が存在する)
	{
		displayPosition = 0;	// 表示する位置を最初に戻す

		timer = 0;	// タイマーをリセット
	}

	return;
}

/* --- 現在の文章が最後まで表示されたか-- - */
bool TextPrinter::IsCurrentMessageFinished() const
{
	if (IsAllMessageFinished())
	{
		return true;
	}

	if (displayPosition >= messageMatrix[currentMessage].size())
	{
		return true;
	}

	return false;
}

/* --- 全ての文章が最後まで表示されたか-- - */
bool TextPrinter::IsAllMessageFinished() const
{
	if (messageMatrix.empty() || currentMessage >= messageMatrix.size())
	{
		return true;
	}

	return false;
}

/* --- 現在位置の文字のバイトを取得-- - */
size_t TextPrinter::GetCharacterByte(size_t pos) const
{
	if (IsAllMessageFinished())		// 全ての文章が表示されているなら
	{
		return 0;	// 0を返す
	}

	const std::string& message = messageMatrix[currentMessage];		// 現在の文章を取得

	if (pos >= message.size())	// 文字の位置が文章のサイズ以上(最後の文字)なら
	{
		return 0;	// 0を返す
	}

	unsigned char c = static_cast<unsigned char>(message[pos]);		// 現在表示している最後の文字を取得

	if (c <= 0x7F)	// ASCII文字(記号)なら
	{
		return 1;	// 1を返す
	}

	return 2;	// 2を返す
}