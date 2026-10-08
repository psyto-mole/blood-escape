#pragma once
/* === ギミックを管理する処理のヘッダファイル === */

#include "DxLib.h"
#include "Gimmick.h"


#define MaxNumberOfGimmick	100		// ステージ中のギミック数の最大値
#define NumberOfGimmickData	6		// csvファイルから読み込むギミック1つあたりのデータの数
#define GimmickSize			32		// ギミックの大きさ

/* --- ギミックマネージャークラス --- */
class GimmickManager
{
private:
	Gimmick* gimmicks[MaxNumberOfGimmick];	// ギミックオブジェクトのポインタを格納する配列

	int gimmickNumber;	// ステージ中のギミック数

public:
	GimmickManager();	// コンストラクタ
	~GimmickManager();	// デストラクタ


	int Load(const char* csvPath);	// csvファイルからギミックデータを読み込むメソッド

	void Update();		// ギミックの更新を行うメソッド
	void Draw() const;  // ギミックの描画を行うメソッド

	Gimmick* CreateGimmick(const char* type, int id, int x, int y);		// ギミックを生成するメソッド

	Gimmick* GetGimmickWithID(int targertID);		// ギミックをIDで検索
	Gimmick* GetGimmickWithPos(int x, int y);		// 指定した位置のギミックを取得
	Gimmick* GetGimmickWithinRange(RECT range);		// 指定した範囲のギミックのうち、中心に近いものを取得

	int GetGimmickIDWithinRange(RECT range);		// 指定した範囲内のギミックのIDを取得

	GimmickGroup GetGimmickGroup(int targetID);	// ギミックの属性を取得するメソッド

	void ChangeGimmickState(int targetID, int state);	// ギミックの状態を変える
	void AdvanceGimmickState(int targetID);				// ギミックの状態を進める
	int GetGimmickState(int targetID);					// ギミックの状態を取得

	bool IsPassable(POINT position);	// 引数で渡した座標が通行可能かを判定するメソッド
};