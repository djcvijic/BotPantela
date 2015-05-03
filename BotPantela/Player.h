#pragma once

#include <iostream>

using namespace std;

class Player
{
private:
	//attributes
	double p_xpoz;
	double p_ypoz;
	bool p_hasKicked;
	bool p_willMove;
	double p_destinationX;
	double p_destinationY;
	bool p_willKick;
	double p_kickVectorX;
	double p_kickVectorY;
	double p_kickIntensity;
	double p_pastPointsX[10];
	double p_pastPointsY[10];

public:
	//constructor
	Player ()
	{
		p_xpoz=0;
		p_ypoz=0;
		p_hasKicked=false;
		p_willMove=false;
		p_destinationX=0;
		p_destinationY=0;
		p_willKick=false;
		p_kickVectorX=0;
		p_kickVectorY=0;
		p_kickIntensity=0;
		for (int i = 0; i<10; p_pastPointsX[i++] = 0); //p_pastPointsX = {0,0,0,0,0};
		for (int i = 0; i<10; p_pastPointsY[i++] = 0); //p_pastPointsY = {0,0,0,0,0};
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
	void postaviHasKicked (const bool HasKicked)
	{
		p_hasKicked=HasKicked;
	}
	void postaviWillMove (const bool willMove)
	{
		p_willMove=willMove;
	}
	void postaviDestinationX (const double destinationX)
	{
		p_destinationX=destinationX;
	}
	void postaviDestinationY (const double destinationY)
	{

		p_destinationY=destinationY;
	}
	void postaviWillKick (const bool willKick)
	{
		p_willKick=willKick;
	}
	void postaviKickVectorX (const double kickVectorX)
	{
		p_kickVectorX=kickVectorX;
	}
	void postaviKickVectorY (const double kickVectorY)
	{
		p_kickVectorY=kickVectorY;
	}
	void postaviKickIntensity (const double kickIntensity)
	{
		p_kickIntensity=kickIntensity;
	} 

	void postaviPastpoz ()
	{
		for (int i=0;i<9;i++) 
			{
				p_pastPointsX[i]=p_pastPointsX[i+1];
				p_pastPointsY[i]=p_pastPointsY[i+1];
		    }
		p_pastPointsX[9] = p_xpoz;
		p_pastPointsY[9] = p_ypoz;
		
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
	bool dohvatiHasKicked () const
	{
		return p_hasKicked;
	}
	bool dohvatiWillMove () const
	{
		return p_willMove;
	}
	double dohvatiDestinationX () const
	{
		return p_destinationX;
	}
	double dohvatiDestinationY () const
	{
		return p_destinationY;
	}
	bool dohvatiWillKick () const
	{
		return p_willKick;
	}
	double dohvatiKickVectorX () const
	{
		return p_kickVectorX;
	}
	double dohvatiKickVectorY () const
	{
		return p_kickVectorY;
	}
	double dohvatiKickIntensity () const
	{
		return p_kickIntensity;
	}
	//input protocol
	void inputpoz ();
	void inputHasKicked ();
	//output protocol
	void outputDecisions ();

	//other methods
	double Player::dohvatibrzX ()
	{
		int i=0;
		double brzX = p_pastPointsX[9] - p_pastPointsX[8],
			brzXPret = p_pastPointsX[8] - p_pastPointsX[7];
		while ((abs(brzX - brzXPret) > 0.25) && (i<=6) && (abs(brzX) > abs(brzXPret)))
		{
			brzX = brzXPret;
			brzXPret = p_pastPointsX[9-i-2] - p_pastPointsX[9-i-3];
			i++;
		};
		return brzX;
	}

	double Player::dohvatibrzY ()
	{
		int i=0;
		double brzY = p_pastPointsY[9] - p_pastPointsY[8],
			brzYPret = p_pastPointsY[8] - p_pastPointsY[7];
		while ((abs(brzY - brzYPret) > 0.25) && (i<=6) && (abs(brzY) > abs(brzYPret)))
		{
			brzY = brzYPret;
			brzYPret = p_pastPointsY[9-i-2] - p_pastPointsY[9-i-3];
			i++;
		}
		return brzY;
	}

};