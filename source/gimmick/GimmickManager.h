#pragma once
/* === ギミックを管理する処理のヘッダファイル === */

#include "DxLib.h"
#include "Gimmick.h"
#include "NeedleFloor.h"


#define GimmickNumberMax	100		// ステージ中のギミック数の最大値

/* --- ギミックマネージャークラス --- */
class GimmickManager
{
private:
	Gimmick* gimmick[GimmickNumberMax];		// ギミックオブジェクトのポインタを格納する配列

	int gimmickNumber;	// ステージ中のギミック数

public:
	GimmickManager();	// コンストラクタ
	~GimmickManager();	// デストラクタ


	int Load(const char* csvPath);	// csvファイルからギミックデータを読み込むメソッド

	void Update();		// ギミックの更新を行うメソッド
	void Draw() const;  // ギミックの描画を行うメソッド

	Gimmick* GetGimmickWithID(int targertID);	// ギミックをIDで検索
	Gimmick* GetGimmickWithPos(int x, int y);	// 指定した位置のギミックを取得

	void ChangeGimmickState(int targetID, int state);		// ギミックの状態を変える
	int GetGimmickState(int targetID);				// ギミックの状態を取得
};