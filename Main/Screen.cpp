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
	"2018년 12월 25일에 이 채널이 처음 등장했고,",
	"약 1,000개의 영상을 제작하면서 많은 점을 느꼈습니다.",
	"\"언젠가는 제 영상의 수보다 구독자가 더 많아질 날이 오지 않을까?\"",
	"최근에는 학업과 다른 이유로 영상 제작이 현저히 줄었습니다...",
	"그래서 지난 영상부터 AI 버튜버를 개발하고 있는데,",
	"방송을 여러 차례 거쳐 안정적인 구동이 가능하면 방송하려고 합니다!",
	"하지만 아직 유아 AI 모델에는 부족한 점이 많이 있습니다.",
	"목소리가 없어서 글로만 소통할 수 있고, 아직은 혼자 방송하기에 무리가 있어 보입니다.",
	"그럼에도 끝까지 믿고 AI 유아의 발전을 기대해 주세요!",
	"다시 한번 구독자 700명에 감사 인사를 드립니다!!"
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
