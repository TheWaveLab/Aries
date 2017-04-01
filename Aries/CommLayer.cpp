#include "StdAfx.h"
#include "CommLayer.h"


CCommLayer::CCommLayer(void)
{
}


CCommLayer::~CCommLayer(void)
{
}

BOOL CCommLayer::Init()
{
	WSADATA wsaData = {};
	if ( WSAStartup( MAKEWORD(2, 2), &wsaData ) )
		return FALSE;

	TRACE("WSA Init.\n");
	return TRUE;
}

int CCommLayer::Send(SOCKET s, const char *buf , int len)
{
	__try
	{
		return send(s, buf, len, 0);
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		return -1;
	}
}

int CCommLayer::SendTo(SOCKET s, const char *buf, int len, const SOCKADDR_IN *pTo)
{
	__try
	{
		return sendto(s, buf, len, 0, (const SOCKADDR *)pTo, sizeof(SOCKADDR_IN));
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		return -1;
	}
}

int CCommLayer::Recv(SOCKET s, char *buf, int len)
{
	__try
	{
		return recv(s, buf, len, 0);
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		return -1;
	}
}

int CCommLayer::RecvFrom(SOCKET s, char *buf, int len, SOCKADDR_IN *pFrom)
{
	__try
	{
		int nFromLen = sizeof(SOCKADDR_IN);
		return recvfrom(s, buf, len, 0, (SOCKADDR*)pFrom, &nFromLen);
	}
	__except( EXCEPTION_EXECUTE_HANDLER )
	{
		return -1;
	}
}

void CCommLayer::Clear()
{
	__try
	{
		WSACleanup();
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
	}
}