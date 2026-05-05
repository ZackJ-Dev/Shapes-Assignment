#ifndef turt_defined
#define turt_defined

#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <math.h>

using namespace cv;
using namespace std;

#define M_PI   3.14159265358979323846264338327950288
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define win_width 1000
#define win_height 1000

#define WHITE Scalar(255, 255, 255)
#define BLACK Scalar(0, 0, 0)

class Turtle
{
public:
    Turtle(int windowWidth=500, int windowHeight=500);
    ~Turtle();
    int _delay = 1;
    
    // 
    // Must be called in main() before any other drawing function
    //
    void init(); 

    //
    // point in the direction given in degrees
    // 0   ==> point right
    // 90  ==> point down
    // 180 ==> point left
    // 270 ==> point up
    //
    void changeDirection(int direction);

    //
    // Moves the pen forward the given number of pixels
    // Note leaves a mark creating a line from the previous point
    // to the new point
    //
    void moveForward(int nPixels, Scalar color=WHITE);

    void goTo(int x, int y);
    
private:
    Mat image;    
    Point _currentPosition;
    string wndname = "TurtleWindow";
    int _direction = 0; // degrees
};

#endif