/* === 出血ギミックのソースファイル === */

#include "BloodGimmick.h"


/* --- コンストラクタ-- - */
BloodGimmick::BloodGimmick(int id, int x, int y, int state, int target) : Gimmick(id, x, y, state, target)
{

	gimmickTag = GimmickTag::Blood;		// ギミックのタグを「出血ギミック」に設定
}

/* --- デストラクタ-- - */
BloodGimmick::~BloodGimmick()
{
}