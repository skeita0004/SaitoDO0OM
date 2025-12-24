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
	bool force = true;
	if (::AttachConsole(ATTACH_PARENT_PROCESS) == FALSE)
	{
		if (not(force))
		{
			MessageBox(nullptr, "ERROR! AttachConsole.", "Information", MB_OK);
			return -1;
		}
		if (::AllocConsole() == FALSE)
		{
			MessageBox(nullptr, "ERROR! AllocConsole.", "Information", MB_OK);
			return -1;
		}
	}

	FILE* fpOut = nullptr;
	::freopen_s(&fpOut, "CONOUT$", "w", stdout);

	FILE* fpErr = nullptr;
	::freopen_s(&fpErr, "CONOUT$", "w", stderr);

	FILE* fpIn  = nullptr;
	::freopen_s(&fpIn, "CONOUT$", "w", stdin);

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
