#pragma once
#include <windows.h>
#include <functional>

class Updater
{
public:
	//time control
	DWORD dwExecLastTime;
	SHORT FPS;

public:
	void Update();
	void SetUpdateEvent(std::function<void()> func = []() {});

private:
	std::function<void()> UpdateEvent;
};
