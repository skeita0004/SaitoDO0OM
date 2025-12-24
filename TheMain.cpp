#include <DxLib.h>
#include <string>
#include <filesystem>
#include "Game.h"
#include "DO0OM.h"

namespace fs = std::filesystem;

namespace
{
	const int FPS{ 60 };
}

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

	Game::Start<DO0OM>();

	while (Game::Update())
	{
		ScreenFlip();
		ClearDrawScreen();
		WaitTimer(1000 / FPS);

		if (ProcessMessage() == -1) break;
	}

	Game::End();

	DxLib_End();

	return 0;
}
