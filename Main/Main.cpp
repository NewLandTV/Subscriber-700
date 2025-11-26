#include <iostream>
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
	// TODO ...
}

int Update()
{
	int key = _getch();

	if (key == VK_ESCAPE)
	{
		return -1;
	}

	return 0;
}