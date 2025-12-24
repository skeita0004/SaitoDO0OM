#pragma once
#include "GameScene.h"

/// <summary>
/// ゲームそのもののクラス
/// </summary>
class Game
{
private:
	Game() = delete;
	~Game() = delete;

public:
	/// <summary>
	/// ゲームを開始する
	/// </summary>
	/// <param name="_pGame">開始するゲームのポインタ</param>
	template<typename T>
	static void Start();
	
	/// <summary>
	/// ゲームを更新する
	/// </summary>
	/// <returns>更新に成功したか</returns>
	static bool Update();

	/// <summary>
	/// ゲームを終了する
	/// </summary>
	static void End();

private:
	static GameScene* pGameScene_;  // ゲームのポインタ
};

#include "Game.inl"
