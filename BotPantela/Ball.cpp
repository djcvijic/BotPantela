#include "Ball.h"

using namespace std;

void Ball::inputpoz ()
{
	double xpoz;
	double ypoz;
	cin >> xpoz;
	cin >> ypoz;
	postaviXpoz(xpoz);
	postaviYpoz(ypoz);
}

void Ball::inputbrz ()
{
	double xbrz;
	double ybrz;
	cin >> xbrz;
	cin >> ybrz;
	postaviXbrz(xbrz);
	postaviYbrz(ybrz);
}