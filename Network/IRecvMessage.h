#pragma once
#include <sstream>

/// <summary>
/// 送信メッセージのインタフェース
/// </summary>
class IRecvMessage
{
public:
	IRecvMessage() {}
	virtual ~IRecvMessage() {}

	/// <summary>
	/// 読み込み処理処理
	/// </summary>
	/// <param name="_ss">読み込む元</param>
	virtual void ReadIn(const std::stringstream& _ss) = 0;
};
