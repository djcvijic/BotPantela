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

  if (((n > (g_fieldWidth - g_goalWidth/2))&&(n<(g_fieldWidth + g_goalWidth/2))) || ((n>-(g_fieldWidth + g_goalWidth/2))&&(n<-(g_fieldWidth - g_goalWidth/2))) || ((n<g_goalWidth/2)&&(n>-g_goalWidth/2))) uGol = true; // UCI CE U GOL OD GORNJU M, DONJU M. ILI DIREKTNO
  if ((n > g_fieldWidth/2) && (n < g_fieldWidth * 3/2)) {n = g_fieldWidth - n; odbitakGore = true;} // OVO ZNACI DA CE ODBITI OD GORNJU MARTINELU I UCI U GOL
  if ((n < -g_fieldWidth/2) && (n > -g_fieldWidth * 3/2)) {n = -g_fieldWidth - n;odbitakDole = true;}// OVO ZNACI DA CE ODBITI OD DONJU MARTINELU I UCI U GOL

  double udaljenostLopte = sqrt(pow(ball.getXPos(),2) + pow(ball.getYPos(),2)),
	  udaljenostAp1 = sqrt(pow(ap1.getXPos(),2) + pow(ap1.getYPos(),2)),
	  udaljenostAp2 = sqrt(pow(ap2.getXPos(),2) + pow(ap2.getYPos(),2)),
	  udaljenostGolmana = sqrt(pow(golman.getXPos()/*+g_goalWidth*/,2) + pow(golman.getYPos(),2)),
	  xHazarda,
	  yHazarda;
  Player bProtivnik = (udaljenostAp1 < udaljenostAp2) ? ap1 : ap2;
  double udaljenostBProtivnika = sqrt(pow(bProtivnik.getXPos(),2) + pow(bProtivnik.getYPos(),2));

  if (udaljenostBProtivnika < udaljenostLopte)
  {
	  xHazarda = (2 * bProtivnik.getXPos() + ball.getXPos()) / 3;
	  yHazarda = (2 * bProtivnik.getYPos() + ball.getYPos()) / 3;
  }
  else
  {
	  xHazarda = ball.getXPos();
	  yHazarda = ball.getYPos();
  }

  double udaljenostHazarda = sqrt(pow(xHazarda,2) + pow(yHazarda,2));



  if ((uGol && (udaljenostLopte < udaljenostBProtivnika) && (vectorLength(ball.getXVel(),ball.getYVel() > 2.5))) || (koCePrvi == 0) || (ball.getXPos() < golman.getXPos())) /*|| (vectorLength(ball.getXPos(),ball.getYPos() < g_goalWidth - 2*g_ballDiameter))*/
	{
		destX = px;  //destX = g_ballDiameter;
		destY = py;   //destY = n + k * golman.getXPos();
	}
  else
  {
	  if (udaljenostHazarda < g_goalWidth)
	  {
		  destX = xHazarda;
		  destY = yHazarda;
	  }
	 
	else
	{
		destY = yHazarda;
		destX = xHazarda;
		double koef = udaljenostHazarda/(g_goalWidth/2 - g_ballDiameter);
		destY /= koef;
		destX /= koef;
		//if (5 * pow((double)g_goalWidth / 2,2) > pow(destY,2))
			//destX = sqrt(5 * pow((double)g_goalWidth / 2,2) - pow(destY,2)) - g_goalWidth;


		if (abs(destY - golman.getYPos()) < g_ballDiameter / 2)
		{

			double udaljenostDestinacije = sqrt(pow(destX,2) + pow(destY,2));
			destX = xHazarda * pohotnost; //2.71828;
			destY = yHazarda * pohotnost; //2.71828;
			/*if ( udaljenostDestinacije < (g_goalWidth / 2 - g_ballDiameter) )
			{
				destX = destX * (g_goalWidth / 2 - g_ballDiameter) / udaljenostDestinacije;
				destY = destY * (g_goalWidth / 2 - g_ballDiameter) / udaljenostDestinacije;
			}*/
		}

	  }
  }
  
  /*}
  else
  {
	  if (ball.getYPos()>g_goalWidth/2) homePlayer1.setDestinationY(103);
      if (ball.getYPos()<-g_goalWidth/2) homePlayer1.setDestinationY(-103);
	  if ((ball.getYPos() <=g_goalWidth/2)&&(ball.getYPos() >= -g_goalWidth/2)) homePlayer1.setDestinationY(ball.getYPos());
  }*/

	}