#include "Constants.h"
#include "Player.h"
#include "Ball.h"
#include <cmath>

// mera pozicioniranjei od 0 do 1 (ali vredi podesavati samo od 0.1 do 0.5)

              // stavi upucuvace ako hoces nesto da menjas
 void odrediKretanjeGolmana (Player golman, Player hp2, Player ap1, Player ap2, int koCePrvi, Ball ball, double& destX, double& destY, double px, double py,int pohotaRand) 
 { 

	 double pohotnost;
	 switch (pohotaRand)
	 {
		 case 0: pohotnost = 0.35; break;
		 case 1: pohotnost = 0.25; break;
		 case 2: pohotnost = 0.45; break;
	 }

  double k,n;
  bool odbitakGore = false, odbitakDole = false, uGol = false;

  odrediKiN(k,n,ball);

  if (((n > (k_fieldWidth - k_goalWidth/2))&&(n<(k_fieldWidth + k_goalWidth/2))) || ((n>-(k_fieldWidth + k_goalWidth/2))&&(n<-(k_fieldWidth - k_goalWidth/2))) || ((n<k_goalWidth/2)&&(n>-k_goalWidth/2))) uGol = true; // UCI CE U GOL OD GORNJU M, DONJU M. ILI DIREKTNO
  if ((n > k_fieldWidth/2) && (n < k_fieldWidth * 3/2)) {n = k_fieldWidth - n; odbitakGore = true;} // OVO ZNACI DA CE ODBITI OD GORNJU MARTINELU I UCI U GOL
  if ((n < -k_fieldWidth/2) && (n > -k_fieldWidth * 3/2)) {n = -k_fieldWidth - n;odbitakDole = true;}// OVO ZNACI DA CE ODBITI OD DONJU MARTINELU I UCI U GOL

  double udaljenostLopte = sqrt(pow(ball.dohvatiXpoz(),2) + pow(ball.dohvatiYpoz(),2)),
	  udaljenostAp1 = sqrt(pow(ap1.dohvatiXpoz(),2) + pow(ap1.dohvatiYpoz(),2)),
	  udaljenostAp2 = sqrt(pow(ap2.dohvatiXpoz(),2) + pow(ap2.dohvatiYpoz(),2)),
	  udaljenostGolmana = sqrt(pow(golman.dohvatiXpoz()/*+k_goalWidth*/,2) + pow(golman.dohvatiYpoz(),2)),
	  xHazarda,
	  yHazarda;
  Player bProtivnik = (udaljenostAp1 < udaljenostAp2) ? ap1 : ap2;
  double udaljenostBProtivnika = sqrt(pow(bProtivnik.dohvatiXpoz(),2) + pow(bProtivnik.dohvatiYpoz(),2));

  if (udaljenostBProtivnika < udaljenostLopte)
  {
	  xHazarda = (2 * bProtivnik.dohvatiXpoz() + ball.dohvatiXpoz()) / 3;
	  yHazarda = (2 * bProtivnik.dohvatiYpoz() + ball.dohvatiYpoz()) / 3;
  }
  else
  {
	  xHazarda = ball.dohvatiXpoz();
	  yHazarda = ball.dohvatiYpoz();
  }

  double udaljenostHazarda = sqrt(pow(xHazarda,2) + pow(yHazarda,2));



  if ((uGol && (udaljenostLopte < udaljenostBProtivnika) && (vectorLength(ball.dohvatiXbrz(),ball.dohvatiYbrz() > 2.5))) || (koCePrvi == 0) || (ball.dohvatiXpoz() < golman.dohvatiXpoz())) /*|| (vectorLength(ball.dohvatiXpoz(),ball.dohvatiYpoz() < k_goalWidth - 2*k_ballDiameter))*/
	{
		destX = px;  //destX = k_ballDiameter;
		destY = py;   //destY = n + k * golman.dohvatiXpoz();
	}
  else
  {
	  if (udaljenostHazarda < k_goalWidth)
	  {
		  destX = xHazarda;
		  destY = yHazarda;
	  }
	 
	else
	{
		destY = yHazarda;
		destX = xHazarda;
		double koef = udaljenostHazarda/(k_goalWidth/2 - k_ballDiameter);
		destY /= koef;
		destX /= koef;
		//if (5 * pow((double)k_goalWidth / 2,2) > pow(destY,2))
			//destX = sqrt(5 * pow((double)k_goalWidth / 2,2) - pow(destY,2)) - k_goalWidth;


		if (abs(destY - golman.dohvatiYpoz()) < k_ballDiameter / 2)
		{

			double udaljenostDestinacije = sqrt(pow(destX,2) + pow(destY,2));
			destX = xHazarda * pohotnost; //2.71828;
			destY = yHazarda * pohotnost; //2.71828;
			/*if ( udaljenostDestinacije < (k_goalWidth / 2 - k_ballDiameter) )
			{
				destX = destX * (k_goalWidth / 2 - k_ballDiameter) / udaljenostDestinacije;
				destY = destY * (k_goalWidth / 2 - k_ballDiameter) / udaljenostDestinacije;
			}*/
		}

	  }
  }
  
  /*}
  else
  {
	  if (ball.dohvatiYpoz()>k_goalWidth/2) homePlayer1.postaviDestinationY(103);
      if (ball.dohvatiYpoz()<-k_goalWidth/2) homePlayer1.postaviDestinationY(-103);
	  if ((ball.dohvatiYpoz() <=k_goalWidth/2)&&(ball.dohvatiYpoz() >= -k_goalWidth/2)) homePlayer1.postaviDestinationY(ball.dohvatiYpoz());
  }*/

	}