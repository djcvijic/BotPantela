#include "Player.h"



void Player::inputPos () 
{
	double xPos;
	double yPos;
	cin >> xPos;
	cin >> yPos;
	setXPos(xPos);
	setYPos(yPos);
}

void Player::inputHasKicked ()
{
	bool hasKicked;
	cin >> hasKicked;
	setHasKicked(hasKicked);
}

void Player::outputDecisions ()
{
	cout << getWillMove() << endl;
	if (getWillMove())
	{
		cout << getDestinationX() << endl;
		cout << getDestinationY() << endl;
	}
	cout << getWillKick() << endl;
	if (getWillKick())
	{
		cout << getKickVectorX() << endl;
		cout << getKickVectorY() << endl;
		cout << getKickIntensity() << endl;
	}
}