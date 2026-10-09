#pragma once
/* === 針床のクラスのヘッダファイル === */

#include "DxLib.h"
#include "ContactGimmick.h"


/* --- 針床のクラス(ContactGimmickクラスの派生クラス) --- */
class NeedleFloor : public ContactGimmick
{
public:
	NeedleFloor(int id, int x, int y);	// コンストラクタ
	~NeedleFloor() override;			// デストラクタ

	void Init() override;		// 針床の初期化メソッド
	void Update() override;		// 針床の更新メソッド
	void Draw() override;		// 針床の描画メソッド
};