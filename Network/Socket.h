#pragma once
#include "Common.h"
#include <queue>
#include <vector>
#include <functional>

class ISocket
{
public:
	ISocket() {}
	virtual ~ISocket() {}

	/// <summary>
	/// 試しに接続する
	/// </summary>
	/// <param name="_remoteSockaddr">接続先のSockaddr</param>
	/// <returns>接続成功 true / false</returns>
	virtual bool TryConnect(const SOCKADDR_IN& _remoteSockaddr) = 0;

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <returns>接続できている true / false</returns>
	virtual bool Update() = 0;

	/// <summary>
	/// 送信処理
	/// </summary>
	/// <param name="_sendBuffer">バッファの参照</param>
	virtual void Send(const std::vector<char>& _sendBuffer) = 0;

	/// <summary>
	/// 受信処理
	/// </summary>
	virtual void OnReceive(const std::function<void(const std::vector<char>&)>& _callback) = 0;
};
