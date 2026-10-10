/* === 接触ギミックのソースファイル === */

#include "ContactGimmick.h"


/* --- コンストラクタ-- - */
ContactGimmick::ContactGimmick(int id, int x, int y, int state, int target) : Gimmick(id, x, y, state, target)
{
	gimmickTag = GimmickTag::Contact;	// ギミックのタグを「接触ギミック」に設定

	isPassable = true;		// ギミックを「通行可」に設定

	isContact = false;	// 「プレイヤーと接触していない」に設定
}

/* --- デストラクタ-- - */
ContactGimmick::~ContactGimmick()
{
}