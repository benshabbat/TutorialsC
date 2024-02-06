#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y)
{

    COORD coord;
    coord.X = x;
    coord.Y = y;
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(consoleHandle, coord);
}

int main()
{
    gotoxy(10, 10);
    printf("Checking");
    return 0;
}