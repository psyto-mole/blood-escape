/* +++ 起動ギミックのソースファイル +++ */

#include "BootGimmick.h"
#include "Player.h"


/* --- コンストラクタ --- */
BootGimmick::BootGimmick(int id, int x, int y, int state, int target) : Gimmick(id, x, y, state, target)
{
	gimmickTag = GimmickTag::Boot;	// ギミックのタグを「起動ギミック」に設定
}

/* --- デストラクタ --- */
BootGimmick::~BootGimmick()
{

}