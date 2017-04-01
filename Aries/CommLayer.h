#pragma once
#include <WinSock2.h>
#include <CommCtrl.h>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "comctl32.lib")

typedef int (*fncallback)(void *params);

class CCommLayer
{
public:
	explicit CCommLayer(void);
	virtual ~CCommLayer(void);

public:
	BOOL Init();
	void Clear();
	BOOL UDPMultiCast();
	BOOL CreateServer();
	int Send(SOCKET s, const char *buf , int len);
	int Recv(SOCKET s, char *buf, int len);
	int SendTo(SOCKET s, const char *buf, int len, const SOCKADDR_IN *pTo);
	int RecvFrom(SOCKET s, char *buf, int len, SOCKADDR_IN *pFrom);
	BOOL SendFileTo();
	BOOL RecvFileFrom();

private:

};

