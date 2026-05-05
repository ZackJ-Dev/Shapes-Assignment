#include <iostream>
#include "turtle.h"
#include "math.h"
#include "Drawable.cpp"

#ifndef RandomColor
#define RandomColor Scalar(rand() % 155 + 100, rand() % 155 + 100, rand() % 155 + 100)
#endif

#define Debug false

using namespace std;

class Line : public Drawable {
    private:
        Turtle* t;
        int x_pos;
        int y_pos;
        int x_pos2;
        int y_pos2;
        int len = 0;
        Scalar c;
    public:
        void Draw() override {
            if(len == 0) Init();

            t->goTo(x_pos, y_pos);
            t->changeDirection(atan2(y_pos2 - y_pos, x_pos2 - x_pos) * 180 / M_PI);

            t->moveForward(len, c);
        }

        void Init() {
            x_pos = rand() % (win_width - 10) + 5;
            y_pos = rand() % (win_height - 10) + 5;

            x_pos2 = rand() % (win_width - 10) + 5;
            y_pos2 = rand() % (win_height - 10) + 5;

            len = sqrt((x_pos2 - x_pos) * (x_pos2 - x_pos) + (y_pos2 - y_pos) * (y_pos2 - y_pos));
            if (len < 150) Init();

            c = RandomColor;
        }

        void SetTurtle(Turtle* tIn) override {
            t = tIn;
        }
};