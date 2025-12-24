#include "DO0OM.h"
#include "Stage.h"
#include "Network/NetworkManager.h"
#include "Network/TcpClient.h"
#include "Network/IPEndPoint.h"
#include "IncludeJson.h"
#include <fstream>

DO0OM::DO0OM() :
	networkManager_{}
{
	new Stage{};

	networkManager_.Start();
	pTcpClient_ = networkManager_.CreateTcpClient();

	std::ifstream ifs{ "serverInfo.json" };

	assert(ifs && "ServerInfo.jsonが見つからない");

	json j{};
	j << ifs;
	ifs.close();

	assert(j.contains("ipaddr") && "ipaddr プロパティが見つからない");
	std::string ipAddr{ j.at("ipaddr").get<std::string>() };

	assert(j.contains("port") && "port プロパティが見つからない");
	uint16_t port{ j.at("port").get<uint16_t>() };

	IPEndPoint ipEndPoint{ ipAddr.c_str(), port };

	SOCKADDR_IN sockaddrIn{};
	ipEndPoint.GetSockAddrIn(&sockaddrIn);
	bool succeed{ pTcpClient_->TryConnect(sockaddrIn) };
	assert(succeed && "サーバーへの接続失敗");
}

void DO0OM::Update()
{
	pTcpClient_->Update();

	pTcpClient_->OnReceive
}

void DO0OM::Draw()
{
}

DO0OM::~DO0OM()
{
	networkManager_.End();
}
