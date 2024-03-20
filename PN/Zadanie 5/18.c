#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>

void move(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void movement(int *xcur, int *ycur) {
    int key = getch();

    if(key == 224) {
        int a = getch();
        switch(a) {
            case 72: // UP
                if(*ycur > 5) {
                    move(*xcur, *ycur);
                    printf(" ");
                    *ycur -= 1;
                    move(*xcur, *ycur);
                    printf("*");
                }
                break;
            case 80: // DOWN
                if(*ycur < 15) {
                    move(*xcur, *ycur);
                    printf(" ");
                    *ycur += 1;
                    move(*xcur, *ycur);
                    printf("*");
                }
                break;
            case 77: // RIGHT
                if(*xcur < 40) {
                    move(*xcur, *ycur);
                    printf(" ");
                    *xcur += 1;
                    move(*xcur, *ycur);
                    printf("*");
                }
                break;
            case 75: // LEFT
                if(*xcur > 0) {
                    move(*xcur, *ycur);
                    printf(" ");
                    *xcur -= 1;
                    move(*xcur, *ycur);
                    printf("*");
                }
                break;
            default:
                break;
        }
    }
}

void init() {
    system("cls");
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

int main() {
    srand(time(NULL));
    int X = (10+ (rand() % 31)), Y = (5+ (rand() % 11));
    int xcur = 10, ycur = 5;
    bool isOnPlace = false;
    init();
    move(X,Y);
    printf("*");
    move(xcur,ycur);
    printf("*");
    while(!isOnPlace) {
        movement(&xcur, &ycur);
        if((xcur == X) && (ycur == Y)) {
            isOnPlace = true;
        }
    }
    return 0;
}