#include "NetworkManager.h"
#include <cassert>

NetworkManager::NetworkManager() :
	wsaData_{},
	started_{ false }
{
}

NetworkManager::~NetworkManager()
{
}

void NetworkManager::Start()
{
	int result{ WSAStartup(WINSOCK_VERSION, &wsaData_) };
	assert(result != SOCKET_ERROR);

	started_ = true;
}

void NetworkManager::End()
{
	for (auto pTcpClient : pTcpClients_)
	{
		// クライアントを解放していく
		delete pTcpClient;
	}
	pTcpClients_.clear();

	WSACleanup();

	started_ = false;
}

TcpClient* NetworkManager::CreateTcpClient()
{
	TcpClient* pTcpClient{ new TcpClient{} };

	pTcpClients_.push_back(pTcpClient);

	return pTcpClient;
}
