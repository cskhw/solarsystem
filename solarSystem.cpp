#include<Windows.h>
#include<stdio.h>

#define BALL_SIZE 30 // 불의 크기 상수를 정의
#define MOVE_STEP 5 //불의 이동 간격 상수를 정의

int main(void) {
	int x = 100;
	int y = 100;
	int dx = +5;
	int dy = +5;

	HWND hwnd = GetForegroundWindow();
	HDC hdc = GetWindowDC(hwnd);

	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(255, 255, 255)));
	SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));

	SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(0, 0, 255)));
	SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));

	Rectangle(hdc, 30, 40, 500 + BALL_SIZE + MOVE_STEP, 400 + BALL_SIZE + MOVE_STEP);

	TextOut(hdc, 220, 450, L"BALL Simulation", 15);

	while (1)
	{
		SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(0, 0, 255)));
		SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 00)));

		Ellipse(hdc, x, y, x + BALL_SIZE, y + BALL_SIZE);

		Sleep(40);
	}
}