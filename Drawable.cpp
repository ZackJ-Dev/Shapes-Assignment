// Technically an extra file? I suppose
// I used inheritance instead of a dynamic enum array
// Why?
// Cause as I was completed the requirements sequentially I did so to complete the prior objective, and I've already spent too long on this to
//     refactor the code, especially into a less standard convention.

#include "turtle.h"

#ifndef DrawableDefined
#define DrawableDefined
class Drawable {
    public:
        virtual void Draw() = 0;
        virtual void SetTurtle(Turtle*) = 0;
        virtual ~Drawable() = default;
};
#endif