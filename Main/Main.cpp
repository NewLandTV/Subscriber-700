#include <conio.h>
#include <Windows.h>
#include "Screen.h"

void Init();
int Update();

int main()
{
	Init();

	while (!Update())
	{
		Sleep(10);
	}

	return 0;
}

void Init()
{
	Screen::Setup("구독자 700명 감사합니다!");
	Screen::SetSize(100, 30);
}

int Update()
{
	int key = _getch();

	switch (key)
	{
	case VK_ESCAPE:
		return -1;
	case VK_SPACE:
		Screen::RenderNext();

		break;
	}

	return 0;
}