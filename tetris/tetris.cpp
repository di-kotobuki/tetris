// tetris.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <Windows.h>

#define COLOR_BLACK      0x00
#define COLOR_BLUE       0x09
#define COLOR_GREEN      0x0a
#define COLOR_CYAN       0x0b
#define COLOR_RED        0x0c
#define COLOR_VIOLET     0x0d
#define COLOR_YELLOW     0x0e
#define COLOR_WHITE      0x0f
#define COLOR_INTENSITY  0x08
#define COLOR_RED_MASK   0x04
#define COLOR_GREEN_MASK 0x02
#define COLOR_BLUE_MASK  0x01

using namespace std;

void setCursorPosition(int x, int y)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD p;
    p.X = x;
    p.Y = y;
    SetConsoleCursorPosition(h, p);
}

void setColor(int color)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD a = 0;
    if (color & COLOR_INTENSITY)
        a |= BACKGROUND_INTENSITY;
    if (color & COLOR_RED_MASK)
        a |= BACKGROUND_RED;
    if (color & COLOR_GREEN_MASK)
        a |= BACKGROUND_GREEN;
    if (color & COLOR_BLUE_MASK)
        a |= BACKGROUND_BLUE;
    SetConsoleTextAttribute(h, a);
}

void moveMino()
{
    int x = 50;
    int y = 0;

    while (y < 20)
    {
        setColor(COLOR_CYAN);
        setCursorPosition(x, y);
        cout << "  ";
        Sleep(1000);

        int _x = x;
        int _y = y;
        x = x;
        y++;
        setColor(COLOR_BLACK);
        setCursorPosition(_x, _y);
        cout << "  ";
    }

    setColor(COLOR_WHITE);
}

int main()
{
    moveMino();

    return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
