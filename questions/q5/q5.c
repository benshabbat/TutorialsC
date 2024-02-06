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
    int min_x = 0;
    int max_x = 79;
    int symbol_racket = 178;
    int size_racket = 8;
    char symbol_ball = 'O';
    for (int y = 0; y < size_racket; y++)
    {
        gotoxy(min_x, y);
        printf("%c",symbol_racket);
    }
    for (int y = 0; y < size_racket; y++)
    {
        gotoxy(max_x, y);
        printf("%c",symbol_racket);
    }

        gotoxy(max_x/2, size_racket/2);
        printf("%c",symbol_ball);

    return 0;
}