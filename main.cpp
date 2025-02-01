#include <iostream>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y;

void setup() {
    gameOver = false;
}
void draw() {
    system("cls");

    for (int i = 0; i < width; i++) {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";

            cout << " ";

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }
     for(int i=0; i<width; i++) {
       cout << "#";
     }
}
void input() {

}
void logic() {

}
int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
    }
    cout << "Hello world!" << endl;
}