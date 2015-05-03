#pragma once

#include <iostream>

using namespace std;

class Ball
{
private:
	//attributes
	double m_xPos;
	double m_yPos;
	double m_xVel;
	double m_yVel;

public:
	//constructor
	Ball ()
	{
		m_xPos=0;
		m_yPos=0;
		m_xVel=0;
		m_yVel=0;
	}
	Ball (Ball& ball)
	{
		m_xPos = ball.getXPos();
		m_yPos = ball.getYPos();
		m_xVel = ball.getXVel();
		m_yVel = ball.getYVel();
	}
	//setters
	void setXPos (const double xPos)
	{
		m_xPos=xPos;
	}
	void setYPos (const double yPos)
	{
		m_yPos=yPos;
	}
	void setXVel (const double xVel)
	{
		m_xVel=xVel;
	}
	void setYVel (const double yVel)
	{
		m_yVel=yVel;
	}
	//getters
	double getXPos () const
	{
		return m_xPos;
	}
	double getYPos () const
	{
		return m_yPos;
	}
	double getXVel () const
	{
		return m_xVel;
	}
	double getYVel () const
	{
		return m_yVel;
	}
	//input protocol
	void inputPos ();
	void inputVel ();
};

