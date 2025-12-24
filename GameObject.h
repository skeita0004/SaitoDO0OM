#pragma once
#include <DxLib.h>

class GameObject
{
	friend class Game;
	friend class GameScene;
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update() = 0;
	virtual void Draw() = 0;

private:
	static GameScene* pGameScene_;  // ゲームへのポインタ
};
