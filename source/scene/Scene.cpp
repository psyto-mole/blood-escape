/* === 全シーン共通のインターフェースのソースファイル === */

#include "Scene.h"


/* --- 遷移情報を取得するメソッド-- - */
SceneTransition Scene::GetTransition() const
{
	return transition;
}