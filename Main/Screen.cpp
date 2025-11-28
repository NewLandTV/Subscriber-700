#include <iostream>
#include <cstring>
#include <Windows.h>
#include "Screen.h"

int Screen::width = 0;
int Screen::height = 0;
int Screen::currentPage = 0;
const char* Screen::stories[STORY_COUNT] =
{
	"안녕하세요.",
	"반갑습니다.",
	"이번에 구독자 700명을 달성해서 진심으로 감사합니다!",
	"앞으로도 다양한 영상을 제작하겠습니다!!!",
	"...",
	"저번에 올린 AI 버튜버 만드는 영상의 반응이 생각보다 나쁘지 않아서,",
	"조만간 AI 유아와 실시간 방송을 진행하려고 합니다.",
	"......"
};

void Screen::Setup(const char* title)
{
	// 콘솔창 제목 바꾸기
	char buffer[MAX_BUFFER_SIZE];

	sprintf_s(buffer, "title %s", title);
	system(buffer);

	// 콘솔창 커서 숨기기
	CONSOLE_CURSOR_INFO consoleCursorInfo;

	consoleCursorInfo.dwSize = 1;
	consoleCursorInfo.bVisible = 0;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);
}

void Screen::SetSize(int width, int height)
{
	Screen::width = width;
	Screen::height = height;

	char buffer[MAX_BUFFER_SIZE];

	sprintf_s(buffer, "mode con cols=%d lines=%d", width, height);
	system(buffer);
}

void Screen::Gotoxy(int x, int y)
{
	COORD position = { x, y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void Screen::RenderNext()
{
	system("cls");

	int index = Screen::currentPage;

	if (index >= STORY_COUNT)
	{
		return;
	}

	int len = strlen(Screen::stories[index]);
	int x = (Screen::width >> 1) - (len >> 1);
	int y = (Screen::height >> 1);

	Gotoxy(x, y);

	std::cout << Screen::stories[index];

	Screen::currentPage++;
}
