#include "Game.h"
#include "GameObject.h"

GameScene* Game::pGameScene_{ nullptr };

bool Game::Update()
{
	if (Game::pGameScene_)
	{
		Game::pGameScene_->CallUpdate();
		Game::pGameScene_->CallDraw();
	}

	if (CheckHitKey(KEY_INPUT_ESCAPE))
	{
		return false;  // エスケープキーでゲーム終了
	}

	return true;
}

void Game::End()
{
	if (pGameScene_)
	{
		delete pGameScene_;
		pGameScene_ = nullptr;
	}
}
