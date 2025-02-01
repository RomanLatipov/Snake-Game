#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y;
enum eDirection {Stop = 0, Left, Right, Up, Down};
eDirection dir;

void setup() {
    gameOver = false;
    x = width / 2;
    y = height / 2;
}
void draw() {
    system("cls");

    for (int i = 0; i < width+2; i++) {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";

            if (i == y && j == x)
                cout << "0";
            else
                cout << " ";

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }
     for(int i=0; i<width+2; i++) {
       cout << "#";
     }
}
void input() {
    if (_kbhit()) {
        char key = _getch();
        if (key == 'a')
            dir = Left;
        else if (key == 'd')
            dir = Right;
        else if (key == 'w')
            dir = Up;
        else if (key == 's')
            dir = Down;
        else if (key == 'x')
            gameOver = true;
    }
}
void logic() {
    if (dir == Up)
        y--;
    if (dir == Down)
        y++;
    if (dir == Left)
        x--;
    if (dir == Right)
        x++;
}
int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
    }
}