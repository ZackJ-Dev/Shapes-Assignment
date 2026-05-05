#include "turtle.h"

Turtle::Turtle(int windowWidth, int windowHeight) 
{
    _currentPosition.x = windowWidth / 2;
    _currentPosition.y = windowHeight / 2;
}

Turtle::~Turtle() 
{
    destroyWindow(wndname.c_str());
}

void Turtle::init()
{
    image = Mat::zeros(win_width, win_height, CV_8UC3);
    imshow(wndname.c_str(), image);
	resizeWindow(wndname, win_width, win_height);
	waitKey(_delay);
}

void Turtle::changeDirection(int direction) 
{
    _direction = direction;
}

void Turtle::moveForward(int nPixels, Scalar color)
{
	int x = static_cast<int>(round(nPixels * ::cos(degToRad(_direction))));
	int y = static_cast<int>(round(nPixels * ::sin(degToRad(_direction))));

	Point newPoint = Point(x + _currentPosition.x, y + _currentPosition.y);
	line(image, _currentPosition, newPoint, color);
	_currentPosition = newPoint;
	// cout << "moved to " << newPoint.x << "," << newPoint.y << " dir:" << _direction << endl;
	imshow(wndname, image);
	resizeWindow(wndname, win_width, win_height);
	waitKey(_delay);
}

void Turtle::goTo(int newX, int newY) {
	_currentPosition.x = newX;
	_currentPosition.y = newY;
}
