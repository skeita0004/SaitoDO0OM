#pragma once
#include "Common.h"
#include "TcpClient.h"

class NetworkManager
{
public:
	NetworkManager();
	~NetworkManager();

	/// <summary>
	/// ネットワークを使い始める
	/// </summary>
	void Start();
	/// <summary>
	/// ネットワークを使い終わる
	/// </summary>
	void End();

	/// <summary>
	/// TCPClientを作成する
	/// </summary>
	/// <returns>作成したTcpClient</returns>
	TcpClient* CreateTcpClient();

private:
	WSAData wsaData_;  // WSAのデータいちおう
	bool started_;     // スタートしたか

	std::list<TcpClient*> pTcpClients_;  // 作ったTCPクライアント
};
