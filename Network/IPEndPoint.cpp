#include "IPEndPoint.h"
#include <cassert>
#include <stdexcept>

namespace
{
	const size_t IP_ADDRESS_STRING_SIZE{ 20 };
}

IPEndPoint::IPEndPoint(
	const std::string_view _ipAddress,
	const uint16_t _port) :
	sockaddrIn_{}
{
	sockaddrIn_.sin_family = AF_INET;
	sockaddrIn_.sin_port = _port;

	if (_ipAddress.empty())
	{
		sockaddrIn_.sin_addr.s_addr = htonl(INADDR_ANY);
	}
	else
	{
		int result{ inet_pton(AF_INET, _ipAddress.data(), &sockaddrIn_.sin_addr.s_addr) };
		switch (result)
		{
		case 1:  // ïœä∑ê¨å˜
			break;
		default:
			throw std::exception{ "ïœä∑Ç…é∏îs" };
		}
	}
}

IPEndPoint::IPEndPoint(const SOCKADDR_IN& _sockaddrIn) :
	sockaddrIn_{ _sockaddrIn }
{
}

void IPEndPoint::GetSockAddrIn(SOCKADDR_IN* _pDest) const
{
	*_pDest = sockaddrIn_;
}

std::tuple<IPAddress, PortNumber> IPEndPoint::GetIPAddressAndPort() const
{
	char buffer[IP_ADDRESS_STRING_SIZE]{};
	const char* ret{ inet_ntop(AF_INET, &sockaddrIn_.sin_addr.s_addr, buffer, IP_ADDRESS_STRING_SIZE) };

	if (ret == nullptr)
	{
		// ""
	}
	return { ret, ntohs(sockaddrIn_.sin_port) };
}
