#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <ctype.h>

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
    int min_y = 0;
    int max_y = 25;

    int symbol_racket = 178;
    int size_racket = 8;
    char symbol_ball = 'O';
    char symbol_ball2 = ' ';

    int ball_velocity_x = 1;
    int ball_velocity_y = 1;

    int ball_coord_x = max_x / 2;
    int ball_coord_y = size_racket / 2;

    while (true)
    {

        for (int y = 0; y < size_racket; y++)
        {
            gotoxy(min_x, y);
            printf("%c", symbol_racket);
        }
        for (int y = 0; y < size_racket; y++)
        {
            gotoxy(max_x, y);
            printf("%c", symbol_racket);
        }

        gotoxy(ball_coord_x, ball_coord_y);
        printf("%c", symbol_ball);

        Sleep(100);



        gotoxy(ball_coord_x, ball_coord_y);
        printf("%c", symbol_ball2);

        if (ball_coord_x == min_x)
        {
            ball_velocity_x*=-1;
        }
        else if (ball_coord_x == max_x)
        {
           ball_velocity_x*=-1;
        }
        else if (ball_coord_y == max_y)
        {
            ball_velocity_y*=-1;
        }
        else if (ball_coord_y == min_y)
        {
            ball_velocity_y*=-1;
        }


        ball_coord_x += ball_velocity_x;
        ball_coord_y += ball_velocity_y;
    }

    return 0;
}