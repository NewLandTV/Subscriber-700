#ifndef __SCREEN_H__
#define __SCREEN_H__

#define MAX_BUFFER_SIZE 200
#define STORY_COUNT 14

class Screen
{
private:
	static int width;	// 콘솔창 가로 길이
	static int height;	// 콘솔차 세로 길이
	static int currentPage;	// 현재 이야기 순서
	static const char* stories[STORY_COUNT];	// 이야기 정보

public:
	static void Setup(const char* title);	// 콘솔창 기본 정보를 설정합니다.
	static void SetSize(int width, int height);	// 콘솔창 크기를 바꿉니다.
	static void Gotoxy(int x, int y);	// (x, y)로 커서 위치를 옮깁니다.
	static void RenderNext();	// 다음 이야기를 화면에 보여줍니다.
};

#endif