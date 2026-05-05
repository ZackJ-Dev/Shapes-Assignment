#include <iostream>
#include "turtle.h"
#include "math.h"
#include "Drawable.cpp"

#ifndef FromFirstLineToBottom
#define FromFirstLineToBottom sin(degToRad(144)) * sideLen
#define FromBottomToTop sin(degToRad(72)) * sideLen
#endif

#ifndef StarRandomSideLength
#define StarRandomSideLength rand() % (min(win_width, win_height) - 151) + 150
#endif

#ifndef RandomColor
#define RandomColor Scalar(rand() % 155 + 100, rand() % 155 + 100, rand() % 155 + 100)
#endif

#define Debug false

using namespace std;

class Star : public Drawable {
    private:
        Turtle* t;
        int x_pos;
        int y_pos;
        int sideLen = 0;
        Scalar c;
    public:
        void Draw() override {
            if(sideLen == 0) Init();

            t->goTo(x_pos, y_pos);
            t->changeDirection(0);
            int d = 0;

            for (int i = 0; i < 5; i++) {
                t->moveForward(sideLen, c);
                t->changeDirection((d+=144) % 360);
            }
        }

        void Init() {
            sideLen = StarRandomSideLength; // Gets the length of a side, the largest possible being the size of the window
            
            // Get a random VALID upper-left corner of the star (bounding box)
            int basex_pos = rand() % (win_width - sideLen);
            int basey_pos = (rand() % static_cast<int>((win_height - (FromBottomToTop))));

            if (Debug) {
                ShowBoundingBox(basex_pos, basey_pos, sideLen);
                ShowPossibleSpawns(sideLen);
            }

            // From the upper-left of bounding box, adjust points to arrive at the location for the first line
            x_pos = basex_pos;
            y_pos = basey_pos + static_cast<int>((FromBottomToTop) - (FromFirstLineToBottom));

            c = RandomColor;
        }

        void ShowBoundingBox(int x, int y, int sideLen) {
            t->goTo(x, y);

            t->changeDirection(0);
            int d = 0;

            for (int o = 0; o < 4; o++) {
                if (o % 2 == 0) {
                    t->moveForward(sideLen);
                } else {
                    t->moveForward(FromBottomToTop);
                }
                t->changeDirection((d+=90) % 360);
            }
        }

        void ShowPossibleSpawns(int sideLen) {
            t->goTo(0, 0);

            t->changeDirection(0);
            int d = 0;

            for (int o = 0; o < 4; o++) {
                if (o % 2 == 0) {
                    t->moveForward(win_width - sideLen, (255, 255, 255));
                } else {
                    t->moveForward(static_cast<int>((win_height - (FromBottomToTop))), (255, 255, 255));
                }
                // t->moveForward(sideLen);
                t->changeDirection((d+=90) % 360);
            }
        }

        void SetTurtle(Turtle* tIn) override {
            t = tIn;
        }
};