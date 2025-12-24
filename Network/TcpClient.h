#pragma once
#include "Common.h"
#include <queue>
#include <vector>
#include <functional>

/// <summary>
/// TCPクライアント
/// </summary>
class TcpClient
{
	friend class NetworkManager;
public:
	~TcpClient();

	/// <summary>
	/// 試しに接続する
	/// </summary>
	/// <param name="_remoteSockaddr">接続先のSockaddr</param>
	/// <returns>接続成功 true / false</returns>
	bool TryConnect(const SOCKADDR_IN& _remoteSockaddr) override;

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <returns>接続できている true / false</returns>
	bool Update() override;

	/// <summary>
	/// 送信処理
	/// </summary>
	/// <param name="_sendBuffer">バッファの参照</param>
	void Send(const std::vector<char>& _sendBuffer) override;

	/// <summary>
	/// 受信処理
	/// </summary>
	void OnReceive(const std::function<void(const std::vector<char>&)>& _callback) override;

	/// <summary>
	/// 切断する
	/// </summary>
	void Disconnect();

private:
	TcpClient();

private:
	SOCKET sock_;
	SOCKADDR_IN sockaddr_;

	std::queue<std::vector<char>> receiveQueue_;  // 受信予定のバッファ
	std::queue<std::vector<char>> sendQueue_;     // 送信予定のバッファ

	std::function<void(std::vector<char>&)> onRecvCallback_;  // 受診時のコールバック処理
};
