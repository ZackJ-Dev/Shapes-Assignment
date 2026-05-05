#include <iostream>
#include "turtle.h"
#include "Drawable.cpp"

#ifndef RectRandomSideLengthWid
#define RectRandomSideLengthWid rand() % (win_width - 150) + 150
#define RectRandomSideLengthHeight rand() % (win_height - 150) + 150
#endif

#ifndef RandomColor
#define RandomColor Scalar(rand() % 155 + 100, rand() % 155 + 100, rand() % 155 + 100)
#endif

using namespace std;

class Rectangle : public Drawable {
    private:
        Turtle* t;
        int width = 0;
        int height;
        int x_pos;
        int y_pos;
        Scalar c;
    public:
        void SetTurtle(Turtle* tIn) override {
            t = tIn;
        }

        void Draw() override {
            if(width == 0) Init();

            t->goTo(x_pos, y_pos);
            int d = 0;
            t->changeDirection(0);

            for (int i = 0; i < 4; i++) {
                if (i % 2 == 0) {
                    t->moveForward(width, c);
                } else {
                    t->moveForward(height, c);
                }
                t->changeDirection((d+=90) % 360);
            }
        }

        void Init() {
            // Get 2 side lengths, the largest possible being the size of the window
            width = RectRandomSideLengthWid;
            height = RectRandomSideLengthHeight;
            
            x_pos = rand() % (win_width - width - 1);
            y_pos = rand() % (win_height - height - 1);

            c = RandomColor;
        }
};