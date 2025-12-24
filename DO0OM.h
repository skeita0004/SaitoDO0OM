#pragma once
#include "GameScene.h"

class DO0OM : public GameScene
{
public:
	DO0OM();

	void Update() override;
	void Draw() override;

	~DO0OM();

private:
	NetworkManager networkManager_;  // ネットワーク使うやつ

	TcpClient* pTcpClient_;  // 通信するやつ
};
