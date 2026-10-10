/* === 1度きりのギミックのソースファイル === */

#include "OneShotGimmick.h"


/* --- コンストラクタ --- */
OneShotGimmick::OneShotGimmick(int id, int x, int y, int state, int target) : ContactGimmick(id, x, y, state, target)
{

}

/* --- デストラクタ --- */
OneShotGimmick::~OneShotGimmick()
{

}