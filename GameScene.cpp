#include "GameScene.h"
#include "GameObject.h"

void GameScene::RegisterGameObject(GameObject* _pGameObject)
{
	pGameObjects_.push_back(_pGameObject);
}

void GameScene::UnRegisterGameObject(GameObject* _pGameObject)
{
	for (auto itr = pGameObjects_.begin();
		itr != pGameObjects_.end();)
	{
		if ((*itr) == _pGameObject)
		{
			pGameObjects_.erase(itr);
		}
		else
		{
			itr++;
		}
	}
}
