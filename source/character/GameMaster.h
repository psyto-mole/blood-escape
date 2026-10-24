#pragma once
/* +++ ゲームマスター関連の処理のヘッダファイル +++ */

#include "DxLib.h"
#include "Image.h"


/* --- ゲームマスターのクラス --- */
class GameMaster
{
private:
	int animationHandle[GameMasterAnimationDivNum];		// ゲームマスターのアニメーションの画像ハンドルを格納する配列
	int drawImage;										// 描画する画像の配列における要素番号

	POINT position;		// ゲームマスターを描画する位置
public:
	GameMaster();	// コンストラクタ
	~GameMaster();	// デストラクタ

	int Init();		// ゲームマスターの初期化メソッド
	void Update();	// ゲームマスターの更新メソッド
	void Draw();	// ゲームマスターの描画メソッド
};