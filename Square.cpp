#include <iostream>
#include "turtle.h"
#include "Drawable.cpp"

#ifndef SqrRandomSideLengthWid
#define SqrRandomSideLengthWid rand() % (min(win_width, win_height) - 150) + 150
#endif

#ifndef RandomColor
#define RandomColor Scalar(rand() % 155 + 100, rand() % 155 + 100, rand() % 155 + 100)
#endif

using namespace std;

class Square : public Drawable {
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

            for (int i = 0; i < 4; i++) {
                t->moveForward(sideLen, c);
                t->changeDirection((d+=90) % 360);
            }
        }

        void Init() {
            // Get side length, the largest possible being the size of the window
            sideLen = SqrRandomSideLengthWid;
            
            x_pos = rand() % (win_width - sideLen - 1);
            y_pos = rand() % (win_height - sideLen - 1);

            c = RandomColor;
        }
};