#pragma once

#include <iostream>

using namespace std;

class Player
{
private:
	//attributes
	double m_xPos;
	double m_yPos;
	bool m_hasKicked;
	bool m_willMove;
	double m_destinationX;
	double m_destinationY;
	bool m_willKick;
	double m_kickVectorX;
	double m_kickVectorY;
	double m_kickIntensity;
	double m_pastPointsX[10];
	double m_pastPointsY[10];

public:
	//constructor
	Player ()
	{
		m_xPos=0;
		m_yPos=0;
		m_hasKicked=false;
		m_willMove=false;
		m_destinationX=0;
		m_destinationY=0;
		m_willKick=false;
		m_kickVectorX=0;
		m_kickVectorY=0;
		m_kickIntensity=0;
		for (int i = 0; i<10; m_pastPointsX[i++] = 0); //m_pastPointsX = {0,0,0,0,0};
		for (int i = 0; i<10; m_pastPointsY[i++] = 0); //m_pastPointsY = {0,0,0,0,0};
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
	void setHasKicked (const bool HasKicked)
	{
		m_hasKicked=HasKicked;
	}
	void setWillMove (const bool willMove)
	{
		m_willMove=willMove;
	}
	void setDestinationX (const double destinationX)
	{
		m_destinationX=destinationX;
	}
	void setDestinationY (const double destinationY)
	{

		m_destinationY=destinationY;
	}
	void setWillKick (const bool willKick)
	{
		m_willKick=willKick;
	}
	void setKickVectorX (const double kickVectorX)
	{
		m_kickVectorX=kickVectorX;
	}
	void setKickVectorY (const double kickVectorY)
	{
		m_kickVectorY=kickVectorY;
	}
	void setKickIntensity (const double kickIntensity)
	{
		m_kickIntensity=kickIntensity;
	} 

	void setPastPos ()
	{
		for (int i=0;i<9;i++) 
			{
				m_pastPointsX[i]=m_pastPointsX[i+1];
				m_pastPointsY[i]=m_pastPointsY[i+1];
		    }
		m_pastPointsX[9] = m_xPos;
		m_pastPointsY[9] = m_yPos;
		
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
	bool getHasKicked () const
	{
		return m_hasKicked;
	}
	bool getWillMove () const
	{
		return m_willMove;
	}
	double getDestinationX () const
	{
		return m_destinationX;
	}
	double getDestinationY () const
	{
		return m_destinationY;
	}
	bool getWillKick () const
	{
		return m_willKick;
	}
	double getKickVectorX () const
	{
		return m_kickVectorX;
	}
	double getKickVectorY () const
	{
		return m_kickVectorY;
	}
	double getKickIntensity () const
	{
		return m_kickIntensity;
	}
	//input protocol
	void inputPos ();
	void inputHasKicked ();
	//output protocol
	void outputDecisions ();

	//other methods
	double Player::getVelX ()
	{
		int i=0;
		double velX = m_pastPointsX[9] - m_pastPointsX[8],
			velXPret = m_pastPointsX[8] - m_pastPointsX[7];
		while ((abs(velX - velXPret) > 0.25) && (i<=6) && (abs(velX) > abs(velXPret)))
		{
			velX = velXPret;
			velXPret = m_pastPointsX[9-i-2] - m_pastPointsX[9-i-3];
			i++;
		};
		return velX;
	}

	double Player::getVelY ()
	{
		int i=0;
		double velY = m_pastPointsY[9] - m_pastPointsY[8],
			velYPret = m_pastPointsY[8] - m_pastPointsY[7];
		while ((abs(velY - velYPret) > 0.25) && (i<=6) && (abs(velY) > abs(velYPret)))
		{
			velY = velYPret;
			velYPret = m_pastPointsY[9-i-2] - m_pastPointsY[9-i-3];
			i++;
		}
		return velY;
	}

};