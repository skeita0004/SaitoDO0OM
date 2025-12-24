#include "GameObject.h"

template<typename T>
inline void Game::Start()
{
	pGameScene_ = new T{};
}
