#pragma once
#include <sstream>

/// <summary>
/// 送信メッセージのインタフェース
/// </summary>
class ISendMessage
{
public:
	ISendMessage() {}
	virtual ~ISendMessage() {}

	/// <summary>
	/// 書き出し処理
	/// </summary>
	/// <param name="_ss">書き出す先</param>
	virtual void WriteOut(std::stringstream& _ss) = 0;
};
