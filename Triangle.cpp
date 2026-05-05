#include <iostream>
#include "turtle.h"
#include "Drawable.cpp"

#ifndef TriRandomSideLength
#define TriRandomSideLength rand() % (min(win_width, win_height) - 150) + 150
#endif

#ifndef RandomColor
#define RandomColor Scalar(rand() % 155 + 100, rand() % 155 + 100, rand() % 155 + 100)
#endif

using namespace std;

class Triangle : public Drawable {
    private:
        Turtle* t;
        int sideLen = 0;
        int x_pos;
        int y_pos;
        Scalar c;
    public:
        void SetTurtle(Turtle* tIn) override {
            t = tIn;
        }

        void Draw() override {
            if(sideLen == 0) Init();

            t->goTo(x_pos, y_pos);
            int d = 0;
            t->changeDirection(0);
            
            for (int i = 0; i < 3; i++) {
                t->moveForward(sideLen, c);
                t->changeDirection((d+=120) % 360);
            }
        }

        void Init() {
            sideLen = TriRandomSideLength;
            x_pos = rand() % static_cast<int>(win_width - sideLen - 1);
            y_pos = rand() % static_cast<int>(win_height - (sin(degToRad(120)) * sideLen) - 1);
            c = RandomColor;
        }
};