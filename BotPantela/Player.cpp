#include "Player.h"



void Player::inputpoz () 
{
	double xpoz;
	double ypoz;
	cin >> xpoz;
	cin >> ypoz;
	postaviXpoz(xpoz);
	postaviYpoz(ypoz);
}

void Player::inputHasKicked ()
{
	bool hasKicked;
	cin >> hasKicked;
	postaviHasKicked(hasKicked);
}

void Player::outputDecisions ()
{
	cout << dohvatiWillMove() << endl;
	if (dohvatiWillMove())
	{
		cout << dohvatiDestinationX() << endl;
		cout << dohvatiDestinationY() << endl;
	}
	cout << dohvatiWillKick() << endl;
	if (dohvatiWillKick())
	{
		cout << dohvatiKickVectorX() << endl;
		cout << dohvatiKickVectorY() << endl;
		cout << dohvatiKickIntensity() << endl;
	}
}