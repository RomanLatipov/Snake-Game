#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {Stop = 0, Left, Right, Up, Down};
eDirection dir;
int tailX[100], tailY[100];
int tail;

void setup() {
    gameOver = false;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
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
            else if (i == fruitY && j == fruitX)
                cout << "O";
            else {
                bool print = false;
                for (int k = 0; k < tail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        print = true;
                    }

                }
                if (!print)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }
     for(int i=0; i<width+2; i++) {
       cout << "#";
     }
     cout << endl;
     cout << "Score: " << score << endl;
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
    int prevX = tailX[0];
    int prevY = tailY[0];
    tailX[0] = x;
    tailY[0] = y;
    int prev2X, prev2Y;

    for (int i = 1; i < tail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    if (dir == Up)
        y--;
    if (dir == Down)
        y++;
    if (dir == Left)
        x--;
    if (dir == Right)
        x++;

    if (x > width || x < 0 || y > height || y < 0)
        gameOver = true;
    if (x == fruitX && y == fruitY) {
        fruitX = rand() % width;
        fruitY = rand() % height;
        score += 10;
        tail++;
    }
}
int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(50);
    }
}