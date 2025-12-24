#include "TcpClient.h"
#include <cassert>

namespace
{
	const size_t BUFFER_SIZE{ 1024 };
}

TcpClient::TcpClient() :
	sock_{ INVALID_SOCKET },
	sockaddr_{},
	receiveQueue_{},
	sendQueue_{},
	onRecvCallback_{ [](std::vector<char>&){} }
{
}

TcpClient::~TcpClient()
{

}

bool TcpClient::TryConnect(const SOCKADDR_IN& _remoteSockaddr)
{
	int ret{};

	sock_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock_ == INVALID_SOCKET)
	{
		return false;
	}

	ret = connect(sock_, reinterpret_cast<const SOCKADDR*>(&_remoteSockaddr), sizeof(SOCKADDR_IN));
	if (ret == SOCKET_ERROR)
	{
		return false;
	}

	// ノンブロッキングにする
	u_long arg{ 0x01 };
	ioctlsocket(sock_, FIONBIO, &arg);
}

bool TcpClient::Update()
{
	int ret{};
	char buffer[BUFFER_SIZE]{};

	// 送信処理
	while (!sendQueue_.empty())
	{
		// コピーして
		memcpy(buffer, sendQueue_.front().data(), sendQueue_.front().size());
		// 送信！
		ret = send(sock_, buffer, BUFFER_SIZE, 0);
		if (ret > 0)  // 送信できていたならポップする
		{
			sendQueue_.pop();
		}
	}

	// 受信処理
	while (true)
	{
		ret = recv(sock_, buffer, BUFFER_SIZE, 0);

		if (ret > 0)  // 送信成功
		{
			receiveQueue_.push(std::vector<char>(ret, 0x00));
			memcpy(receiveQueue_.back().data(), buffer, receiveQueue_.back().size());
		}
		else  // 受信失敗
		{
			int errorCode{ WSAGetLastError() };
			if (errorCode == WSAEWOULDBLOCK)
			{  // ノンブロッキング処理のため無視
				break;  // ループ離脱
			}
			else if (errorCode == WSAECONNRESET)
			{
				return false;  // コネクションが切断されたため切断
			}
			else
			{
				assert(false && "知らんエラー");
			}
			//switch (errorCode)
			//{
			//case WSAEWOULDBLOCK:
			//	break;  // ノンブロッキング処理のため無視
			//default:
			//	assert(false && "知らんエラー");
			//	break;
			//}
		}
	}

	// 受信を処理する
	while (!receiveQueue_.empty())
	{
		onRecvCallback_(receiveQueue_.front());
		receiveQueue_.pop();
	}

	return true;
}

void TcpClient::Send(const std::vector<char>& _sendBuffer)
{
	sendQueue_.push(_sendBuffer);
}

void TcpClient::OnReceive(const std::function<void(const std::vector<char>&)>& _callback)
{
	onRecvCallback_ = _callback;
}

void TcpClient::Disconnect()
{
	if (sock_ != INVALID_SOCKET)
	{
		shutdown(sock_, SD_BOTH);
		closesocket(sock_);
		sock_ = INVALID_SOCKET;
	}
}
