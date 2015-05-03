#pragma once

#include <iostream>

using namespace std;

class Ball
{
private:
	//attributes
	double p_xpoz;
	double p_ypoz;
	double p_xbrz;
	double p_ybrz;

public:
	//constructor
	Ball ()
	{
		p_xpoz=0;
		p_ypoz=0;
		p_xbrz=0;
		p_ybrz=0;
	}
	Ball (Ball& ball)
	{
		p_xpoz = ball.dohvatiXpoz();
		p_ypoz = ball.dohvatiYpoz();
		p_xbrz = ball.dohvatiXbrz();
		p_ybrz = ball.dohvatiYbrz();
	}
	//postaviters
	void postaviXpoz (const double xpoz)
	{
		p_xpoz=xpoz;
	}
	void postaviYpoz (const double ypoz)
	{
		p_ypoz=ypoz;
	}
	void postaviXbrz (const double xbrz)
	{
		p_xbrz=xbrz;
	}
	void postaviYbrz (const double ybrz)
	{
		p_ybrz=ybrz;
	}
	//dohvatiters
	double dohvatiXpoz () const
	{
		return p_xpoz;
	}
	double dohvatiYpoz () const
	{
		return p_ypoz;
	}
	double dohvatiXbrz () const
	{
		return p_xbrz;
	}
	double dohvatiYbrz () const
	{
		return p_ybrz;
	}
	//input protocol
	void inputpoz ();
	void inputbrz ();
};

