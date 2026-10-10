#pragma once
/* === ギミックを管理する処理のヘッダファイル === */

#include "DxLib.h"
#include "Gimmick.h"
#include "Player.h"


#define MaxNumberOfGimmick	100		// ステージ中のギミック数の最大値
#define NumberOfGimmickData	6		// csvファイルから読み込むギミック1つあたりのデータの数

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

	void Update(Player* player);	// ギミックの更新を行うメソッド
	void Draw() const;				// ギミックの描画を行うメソッド

	Gimmick* CreateGimmick(const char* type, int id, int x, int y, int state, int target);	// ギミックを生成するメソッド

	Gimmick* GetGimmickWithID(int targertID);				// ギミックをIDで検索
	Gimmick* GetGimmickWithPos(int x, int y);				// 指定した位置のギミックを取得
	Gimmick* GetGimmickWithinRange(RECT range);				// 指定した範囲のギミックのうち、中心に近いものを取得
	Gimmick* GetGimmickWithType(GimmickType gimmickType);	// ギミックを種類で検索

	int GetGimmickIDWithinRange(RECT range);		// 指定した範囲内のギミックのIDを取得

	GimmickTag GetGimmickTag(int targetID);		// ギミックのタグを取得するメソッド

	void ChangeGimmickState(int targetID, int state);	// ギミックの状態を変える
	void AdvanceGimmickState(int targetID);				// ギミックの状態を進める
	int GetGimmickState(int targetID);					// ギミックの状態を取得

	void ActivateGimmick(int itargetID);	// IDで指定したギミックを起動する

	bool IsPassable(POINT playerPosition);					// 引数で渡した座標が通行可能かを判定するメソッド

	bool CheckStageClear();		// ステージクリアを確認するメソッド
};