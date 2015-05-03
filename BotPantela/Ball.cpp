#include "Ball.h"

using namespace std;

void Ball::inputPos ()
{
	double xPos;
	double yPos;
	cin >> xPos;
	cin >> yPos;
	setXPos(xPos);
	setYPos(yPos);
}

void Ball::inputVel ()
{
	double xVel;
	double yVel;
	cin >> xVel;
	cin >> yVel;
	setXVel(xVel);
	setYVel(yVel);
}