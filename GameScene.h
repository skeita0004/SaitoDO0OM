#pragma once
#include <list>

class GameObject;

class GameScene
{
	friend class GameObject;
	friend class Game;
public:
	GameScene() {}
	virtual ~GameScene() {}

protected:
	virtual void Update() = 0;
	virtual void Draw() = 0;

private:
	void CallUpdate() { Update(); }
	void CallDraw() { Draw(); }

	void RegisterGameObject(GameObject* _pGameObject);
	void UnRegisterGameObject(GameObject* _pGameObject);

private:
	std::list<GameObject*> pGameObjects_;
};
