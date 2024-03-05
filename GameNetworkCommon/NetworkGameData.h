#pragma once
#include "SerializedTool.h"
#include <functional>
#include <vector>


enum class BHID_C2S
{
	User_TryJoin,
	User_StartGame,
	Player_InputMove,
	Player_InputHit,
	User_Quit,
	Max,
};

enum class BHID_S2C
{
	SetID,
	AddExistPlayers,
	AddPlayer,
	RemovePlayer,
	SyncObjectPosition,
	ApproveQuit,
	Max,
};



struct V3
{
	float x = 0;
	float y = 0;
	float z = 0;
};

struct Data_Bool
{
	bool value;
};

struct Data_UserID
{
	unsigned int id;
};

struct Data_Pos
{
	float x=0;
	float y=0;
	float z=0;
};

struct Data_C2S_PlayerMove
{
	unsigned int id;
	short upDown;//-1:down, 0:none, 1:up
	short leftRight;//-1:left, 0:none, 1:right
};

struct Data_S2C_ObjectPos2
{
	short max = 11;
	V3 pos[11];
};

struct Data_S2C_AddPlayer
{
	int playerID;
};

//give up
struct Data_S2C_ObjectPos
{
	float player1X;
	float player1Y;
	float player1Z;

	float player2X;
	float player2Y;
	float player2Z;

	float shuttleX;
	float shuttleY;
	float shuttleZ;
};

class NetworkGameData
{

};

class NetworkManager
{
public:
	//network commands
	static std::vector<std::function<void(MsgContent)>> Commands;

private:
	static void Init(int count);

public:
	static void InitServer();
	static void InitClient();
	static void ResetCommands();
	static void SetCommand(BHID_C2S id, std::function<void(MsgContent)> func = nullptr);
	static void SetCommand(BHID_S2C id, std::function<void(MsgContent)> func = nullptr);
};



