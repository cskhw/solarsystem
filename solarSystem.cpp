#include<Windows.h>
#include<stdio.h>
#include<math.h>

// 상수 정의 요구사항 #8
// 각 행성의 크기 정의
// 실제 행성의 각 크기 비율: 109, 0.4, 0.9 1 0.5, 11.2, 9.4, 4.0, 3.9
// 실제 행성의 비율을 보기 좋게 변경 요구사항 #2

#define SUN 10
#define MER 5
#define VEN 7
#define EAR 8
#define MAR 4
#define JUP 12
#define SAT 11
#define URA 9
#define NEP 8
#define PLU 4

// 태양계의 실제 비율 : 0.58, 1.08, 1.5, 2.28, 4.14, 7.78, 14.3, 28.7, 45
// 각 수치 간격을 설정함으로써 보기 좋게 바꿈. 요구사항 #5

#define MERMOVE 20
#define VENMOVE 40
#define EARMOVE 60
#define MARMOVE 80
#define JUPMOVE 100
#define SATMOVE 125
#define URAMOVE 150
#define NEPMOVE 170
#define PLUMOVE 190

#define PI 3.141592654 // 파이 요구사항 #8
#define MOVE_STEP 5 // 불의 이동 값


int main(void) {
    int x[10] = { 0, };
    int y[10] = { 0, };
    // 각도의 증가율 -> 공전 주기
    // 각 행성마다 각도를 다르게 증가시킴
    // 각 행성의 각도 초기값
    float angle1 = 1;
    float angle2 = 1;
    float angle3 = 1;
    float angle4 = 1;
    float angle5 = 1;
    float angle6 = 1;
    float angle7 = 1;
    float angle8 = 1;
    float angle9 = 1;
  
    // 고정된 위치에서 시작 요구사항 #4
    // 태양계의 중앙 좌표

    int dx = 270;
    int dy = 240;

    HWND hwnd = GetForegroundWindow(); //핸들 구하기
    HDC hdc = GetWindowDC(hwnd); // 윈도우의 디바이스 컨테스트 헨들을 구하여 윈도우에 접근

    // 배경 설정 흰색
    SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(255, 255, 255)));
    SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));
    Rectangle(hdc, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));

    // 펜의 테두리 색 파란색, 채우는 색은 흰색
    SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(0, 0, 255)));
    SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));

    // 파란색 테두리를 갖는 사각형, 바탕 흰색
    Rectangle(hdc, 30, 40, 500 + SUN + MOVE_STEP, 400 + SUN + MOVE_STEP);

    TextOut(hdc, 220, 450, L"BALL Simulation", 15);

    while (1)
    {
        
        // 펜의 테두리 색 파란색, 채우는 색은 흰색
        SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(0, 0, 255)));
        SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));
        Sleep(0.1);
        // 파란색 테두리를 갖는 사각형, 바탕 흰색
        Rectangle(hdc, 30, 40, 500 + SUN + MOVE_STEP, 430 + SUN + MOVE_STEP);
        // 그리는 펜의 테두리 색은 파란색, 채우는 색은 빨간색으로 설정
        // 태양 요구사항 #1
        SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(0, 0, 255)));
        SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));
        Ellipse(hdc, dx-SUN, dy-SUN, dx+ SUN, dy + SUN);
        // 수성
        SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 255)));
        SelectObject(hdc, CreateSolidBrush(RGB(204, 204, 204)));
        Ellipse(hdc, dx - MER + MERMOVE * sin(angle1 * (PI/180)), dy - MER + MERMOVE * cos(angle1 * (PI/180)), dx + MER + MERMOVE * sin(angle1 * (PI / 180)),  dy + MER + MERMOVE * cos(angle1 * (PI / 180)));
        // 금성
        SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 255)));
        SelectObject(hdc, CreateSolidBrush(RGB(255, 153, 000)));
        Ellipse(hdc, dx - VEN + VENMOVE * sin(angle2 * (PI / 180)), dy - VEN + VENMOVE * cos(angle2 * (PI / 180)), dx + VEN + VENMOVE * sin(angle2 * (PI / 180)), dy + VEN + VENMOVE * cos(angle2 * (PI / 180)));
        // 지구
        SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 255)));
        SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 255)));
        Ellipse(hdc, dx - EAR + EARMOVE * sin(angle3 * (PI / 180)), dy - EAR + EARMOVE * cos(angle3* (PI / 180)), dx + EAR + EARMOVE * sin(angle3 * (PI / 180)), dy + EAR + EARMOVE * cos(angle3 * (PI / 180)));
        // 화성
        SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 255)));
        SelectObject(hdc, CreateSolidBrush(RGB(255, 102, 000)));
        Ellipse(hdc, dx - MAR + MARMOVE * sin(angle4 * (PI / 180)), dy - MAR + MARMOVE * cos(angle4 * (PI / 180)), dx + MAR + MARMOVE * sin(angle4 * (PI / 180)), dy + MAR + MARMOVE * cos(angle4 * (PI / 180)));
        // 목성
        SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 255)));
        SelectObject(hdc, CreateSolidBrush(RGB(204, 102, 00)));
        Ellipse(hdc, dx - JUP + JUPMOVE * sin(angle5* (PI / 180)), dy - JUP + JUPMOVE * cos(angle5 * (PI / 180)), dx + JUP + JUPMOVE * sin(angle5 * (PI / 180)), dy + JUP + JUPMOVE * cos(angle5 * (PI / 180)));
        // 토성
        SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 255)));
        SelectObject(hdc, CreateSolidBrush(RGB(204, 102, 051)));
        Ellipse(hdc, dx - SAT + SATMOVE * sin(angle6 * (PI / 180)), dy - SAT + SATMOVE * cos(angle6 * (PI / 180)), dx + SAT + SATMOVE * sin(angle6 * (PI / 180)), dy + SAT + SATMOVE * cos(angle6 * (PI / 180)));
        // 천왕성
        SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 255)));
        SelectObject(hdc, CreateSolidBrush(RGB(000, 051, 051)));
        Ellipse(hdc, dx - URA + URAMOVE * sin(angle7 * (PI / 180)), dy - URA + URAMOVE * cos(angle7* (PI / 180)), dx + URA + URAMOVE * sin(angle7 * (PI / 180)), dy + URA + URAMOVE * cos(angle7 * (PI / 180)));
        // 혜왕성
        SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 255)));
        SelectObject(hdc, CreateSolidBrush(RGB(102, 153, 255)));
        Ellipse(hdc, dx - NEP + NEPMOVE * sin(angle8 * (PI / 180)), dy - NEP + NEPMOVE * cos(angle8* (PI / 180)), dx + NEP + NEPMOVE * sin(angle8 * (PI / 180)), dy + NEP + NEPMOVE * cos(angle8 * (PI / 180)));
        // 명왕성
        SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 255)));
        SelectObject(hdc, CreateSolidBrush(RGB(102, 153, 153)));
        Ellipse(hdc, dx - PLU + PLUMOVE * sin(angle9 * (PI / 180)), dy - PLU + PLUMOVE * cos(angle9* (PI / 180)), dx + PLU + PLUMOVE * sin(angle9 * (PI / 180)), dy + MER + PLUMOVE * cos(angle9 * (PI / 180)));
        Sleep(40);


        // 각을 1~360범위로 증가, 0일경우 1로 변환
        // 지구의 공전 주기를 1로 설정하여 이를 기준으로 각 1/행성의 공전일수로 증가율을 설정함
        // if문 4회 이상 사용 요구사항 #8
        angle1 = angle1 + 4.1;
        if (angle1 > 360)
            angle1 = 1;
        angle2 = angle2 + 1.6;
        if (angle2 > 360)
            angle2 = 1;
        angle3 = angle3 + 1;
        if (angle3 > 360)
            angle3 = 1;
        angle4 = angle4 + 0.5;
        if (angle4 > 360)
            angle4 = 1;
        angle5 = angle5 + 0.09;
        if (angle5 > 360)
            angle5 = 1;
        angle6 = angle6 + 0.04;
        if (angle6 > 360)
            angle6 = 1;
        angle7 = angle7 + 0.01;
        if (angle7 > 360)
            angle7 = 1;
        angle8 = angle8 + 0.006;
        if (angle8 > 360)
            angle8 = 1;
        angle9 = angle9 + 0.004;
        if (angle9 > 360)
            angle9 = 1;
    }
}
// 전체 주석으로 설명 완료 요구사항 #7
