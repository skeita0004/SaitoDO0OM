#include "GameObject.h"
#include "GameScene.h"

GameScene* GameObject::pGameScene_{ nullptr };

GameObject::GameObject()
{
	pGameScene_->RegisterGameObject(this);
}

GameObject::~GameObject()
{
	pGameScene_->UnRegisterGameObject(this);
}
