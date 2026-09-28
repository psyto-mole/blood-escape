/* === ギミッククラスのソースファイル === */

#include "Gimmick.h"


/* --- デストラクタ --- */
Gimmick::~Gimmick()
{
	if (gimmickImage != -1)
	{
		DeleteGraph(gimmickImage);
	}
}