#pragma once
#include "Common.h"
#include <cstdint>
#include <string>
#include <string_view>

using PortNumber = uint16_t;
using IPAddress = std::string;

class IPEndPoint
{
public:
	IPEndPoint(const std::string_view _ipAddress, const uint16_t _port);
	IPEndPoint(const SOCKADDR_IN& _sockaddrIn);


	void GetSockAddrIn(SOCKADDR_IN* _pDest) const;
	std::tuple<IPAddress, PortNumber> GetIPAddressAndPort() const;

private:
	SOCKADDR_IN sockaddrIn_;
};
