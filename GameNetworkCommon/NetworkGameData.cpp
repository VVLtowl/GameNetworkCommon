#include "NetworkGameData.h"

std::vector<std::function<void(MsgContent)>>  NetworkManager::Commands;


void NetworkManager::Init(int count)
{
	for (int i = 0; i < count; i++)
	{
		Commands.push_back([](const MsgContent& msg) {});
	}
}

void NetworkManager::InitServer()
{
	Init((int)BHID_C2S::Max);
}

void NetworkManager::InitClient()
{
	Init((int)BHID_S2C::Max);
}

void NetworkManager::SetCommand(BHID_C2S id, std::function<void(MsgContent)> func)
{
	Commands[(int)id] = func;
}

void NetworkManager::SetCommand(BHID_S2C id, std::function<void(MsgContent)> func)
{
	Commands[(int)id] = func;
}
