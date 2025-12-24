#pragma once
#include "ISendMessage.h"
#include "IRecvMessage.h"
#include "TcpClient.h"

/// <summary>
/// サーバー参加するやつ
/// </summary>
class ServerJoiner
{
public:
	ServerJoiner(const NetworkManager& _networkManager);
	~ServerJoiner();

	void Join();

	void Leave();

	void Send(const ISendMessage* _pSendMessage);

	/// <summary>
	/// 受け取ったメッセージを処理する
	/// </summary>
	/// <param name="_callback">
	/// <para>コールバック関数</para>
	/// <para>[] (const IRecvMessage*) -> void {}</para>
	/// </param>
	void GetMassages(std::function<void(const IRecvMessage*)> _callback);

private:
	TcpClient client_;  // tcpClient

	std::queue<IRecvMessage*> recvMessageQueue_;  // 受け取ったメッセージキュー
};
