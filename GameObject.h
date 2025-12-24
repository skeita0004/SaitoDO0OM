#pragma once
#include <DxLib.h>

class GameScene;

class GameObject
{
	friend class Game;
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update() = 0;
	virtual void Draw() = 0;

private:
	static GameScene* pGameScene_;  // ゲームへのポインタ
};
