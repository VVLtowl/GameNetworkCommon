﻿#include "NetworkCommon.h"


#pragma region ========== network unit ==========

void NetworkUnit::Launch()
{
	if (m_IsStart)return;

	//try wsa start up
	int ret = WSAStartup(MAKEWORD(2, 2), &m_WsaData);
	assert(ret == 0, "WSA start error");
	std::cout << "WSA start\n";
	
	//set HostEnt by this pc
	char hostName[256];
	gethostname(hostName, (int)sizeof(hostName));
	HOSTENT* hostEnt = gethostbyname(hostName);

	if (hostEnt == nullptr)
	{
		std::cout << "shit" << std::endl;
		return;
	}

	//set IP by host
	IN_ADDR inaddr;
	memcpy(&inaddr, hostEnt->h_addr_list[0], 4);
	m_IP = std::string(inet_ntoa(inaddr));
	std::cout << "this IP: " << m_IP.c_str() << std::endl;

	m_IsStart = true;
}

void NetworkUnit::ShutDown()
{
	if (!m_IsStart)return;

	//try wsa clean up
	assert(WSACleanup() == 0, "WSA clean error");
	std::cout << "WSA shut down\n";

	m_IsStart = false;
}

int NetworkUnit::Recieve(SOCKET* socket, char* msgBuf)
{
	//recv
	int ret = recv(
		*socket,
		msgBuf,
		LEN_MSG,
		0);

	//check error
	if (ret == SOCKET_ERROR)
	{
		//todo 
		//make error default msgBuf
		//m_Manager->AddRecvMsg(nullptr, msgBuf);
		std::cout << "recv error\n";
		return 0;
	}
	else
	{
		//m_Manager->AddRecvMsg(socket, msgBuf);
		std::cout << "recv\n";
		return 1;
	}
}

void NetworkUnit::Send(SOCKET* socket, char* msgBuf)
{
	//recv
	int ret = send(
		*socket,
		msgBuf,
		LEN_MSG,
		0);

	//check error
	if (ret == SOCKET_ERROR)
	{
		std::cout << "send error\n";
	}
	else
	{
		std::cout << "send\n";
	}
}

int NetworkUnit::RecvFrom(SOCKET* socket,char* msgBuf, SOCKADDR_IN* from)
{
	int fromLen = sizeof(SOCKADDR);

	//recvfrom
	int ret = recvfrom(
		*socket,
		msgBuf,
		LEN_MSG,
		0,
		(SOCKADDR*)from,
		&fromLen);

	//check error
	if (ret == SOCKET_ERROR)
	{
		//todo 
		//make error default msgBuf
		//m_Manager->AddRecvMsg(nullptr, msgBuf, from);
		//std::cout << "recv from error\n";
		return 0;
	}
	else
	{
		//m_Manager->AddRecvMsg(socket, msgBuf, from);
		std::cout << "recv from\n";

		//show from ip and message
		char ipBuffer[LEN_MSG]; // 定义用于存储 IP 地址字符串的缓冲区
		inet_ntop(AF_INET, &(from->sin_addr), ipBuffer, INET_ADDRSTRLEN); // 将二进制 IP 地址转换为字符串形式
		std::cout << "[" << ipBuffer << "]: " << msgBuf << std::endl;

		return 1;
	}
}

void NetworkUnit::SendTo(SOCKET* socket, char* msgBuf, SOCKADDR_IN* dest)
{
	int destLen = sizeof(SOCKADDR);

	//recvfrom
	int ret = sendto(
		*socket,
		msgBuf,
		LEN_MSG,
		0,
		(SOCKADDR*)dest,
		destLen);

	//check error
	if (ret == SOCKET_ERROR)
	{
		std::cout << "send to error\n";
	}
	else
	{
		std::cout << "send to\n";

		//show destination ip send message
		char ipBuffer[LEN_MSG]; // 定义用于存储 IP 地址字符串的缓冲区
		inet_ntop(AF_INET, &(dest->sin_addr), ipBuffer, INET_ADDRSTRLEN); // 将二进制 IP 地址转换为字符串形式
		std::cout << "to [" << ipBuffer << "]: " << msgBuf << std::endl;
	}
}
#pragma endregion
