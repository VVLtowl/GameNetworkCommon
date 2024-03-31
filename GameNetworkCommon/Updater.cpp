#include "Updater.h"

void Updater::Update()
{
	DWORD dwCurrentTime = timeGetTime();

	//fixed update
	if ((dwCurrentTime - dwExecLastTime) >= (1000 / FPS))
	{
		dwExecLastTime = dwCurrentTime+1;

		UpdateEvent();
	}
}

void Updater::SetUpdateEvent(std::function<void()> func)
{
	UpdateEvent = func;
}
