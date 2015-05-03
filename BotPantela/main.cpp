#include <iostream>
#include <cmath>

#pragma warning( disable: 4700 )
#include "Constants.h"

#include "GameStatus.h"
#include "Player.h"
#include "Ball.h"
#include "Converter.h"

#include "Methods.h"
#include "MethodsGoalkeeper.h"


#include <time.h>



using namespace std;

int main ()
{
	GameStatus gameStatus;
	Converter converter;
	Player homePlayer1;
	Player homePlayer2; 
	Player awayPlayer1;
	Player awayPlayer2; 
	Ball ball;

	srand(time(NULL));
	int pohotnostRand, pozicioniranjeRand, dodavanjeRand, strat;
	bool stratFlipFlop, scoreFlipFlop;
	int successCounter [12];
	int mainMainCounter = 0;



		 double px0,py0,px1,py1,px2,py2,px3,py3;
		 bool presreci01,presreci02,presreci03;   // homePlayer1
		 bool presreci11,presreci12,presreci13;   // homePlayer2
		 bool presreci21,presreci22,presreci23;   // awayPlayer1
		 bool presreci31,presreci32,presreci33;   // awayPlayer2
		 double vremePr0,vremePr1,vremePr2,vremePr3;

		 for (int i=0;i<12;i++) successCounter[i]=0;

	while (true)
	{/*if (LogFajl.is_open() != true) 
	  LogFajl.open("Izlaz.txt",ios::app);*/
	
		
		//start input
		//10 //20 //30 //40
		gameStatus.inputGameStatus();
		//50 //60 //70 //80
		homePlayer1.inputPos();
		homePlayer2.inputPos();
		awayPlayer1.inputPos();
		awayPlayer2.inputPos();
		//90 //100 //110 //120
		ball.inputPos();
		ball.inputVel();
		//130 //140 //150
		homePlayer1.inputHasKicked();
		homePlayer2.inputHasKicked();
		awayPlayer1.inputHasKicked();
		awayPlayer2.inputHasKicked();
		//end input
		//Player nizIgraca[4] = {homePlayer1,homePlayer2,awayPlayer1,awayPlayer2};
		
		

		// IN CONVERSION
		converter.convertIn(homePlayer1,homePlayer2,awayPlayer1,awayPlayer2,ball,gameStatus);

  //      double a1,b1;
		//odrediTackuOdbijanja(1,-398,a1,b1,ball); // !!!!!******!!!!!*******!!!!!!
		//cout << "INTERSECTION POINT: " << a1 << " " << b1 << endl;

		//start calc

		if ((ball.getXPos()>0) && (ball.getXPos()<g_fieldLength)) mainMainCounter++;

		if ((mainMainCounter<6000) && gameStatus.getReset() && stratFlipFlop)
		{
			stratFlipFlop = false;
			strat = rand() % 12;
			if (strat < 12)
			{
				pohotnostRand = strat % 3;
				pozicioniranjeRand = strat % 2;
				dodavanjeRand = strat / 6;
			}
		}

		if (mainMainCounter >= 6000)
		{
			int pohotnostSuccess[3]={0,0,0},pozicioniranjeSuccess[2]={0,0},dodavanjeSuccess[2]={0,0};
			for (int i=0;i<12;i++)
			{
				pohotnostSuccess[i%3] += successCounter[i];
				pozicioniranjeSuccess[i%2] += successCounter[i];
				dodavanjeSuccess[i/6] += successCounter[i];
			}
			int pohotnostMaxI = maximumN(pohotnostSuccess,3),pozicioniranjeMaxI = maximumN(pozicioniranjeSuccess,2),dodavanjeMaxI = maximumN(dodavanjeSuccess,2);
			if (pohotnostMaxI == 0)
			{
				if (pozicioniranjeMaxI == 0) strat = 0 + 6*dodavanjeMaxI;
				else strat = 3 + 6*dodavanjeMaxI;
			}
			if (pohotnostMaxI == 1)
			{
				if (pozicioniranjeMaxI == 0) strat = 4 + 6*dodavanjeMaxI;
				else strat = 1 + 6*dodavanjeMaxI;
			}
			if (pohotnostMaxI == 2)
			{
				if (pozicioniranjeMaxI == 0) strat = 2 + 6*dodavanjeMaxI;
				else strat = 5 + 6*dodavanjeMaxI;
			}
		}

//Vreme::Primerak()->postaviPrviTajmer();


  homePlayer1.setWillMove(true);                    // *** 
  homePlayer1.setWillKick(true);
  homePlayer2.setWillMove(true);
  homePlayer2.setWillKick(true);

  // potrebno da bi se izracunavala brzina igraca:
  homePlayer1.setPastPos();
  homePlayer2.setPastPos();
  awayPlayer1.setPastPos();
  awayPlayer2.setPastPos();





         odrediTackuPresretanja(homePlayer1,ball,px0,py0,vremePr0,presreci01,presreci02,presreci03,3);
		 odrediTackuPresretanja(homePlayer2,ball,px1,py1,vremePr1,presreci11,presreci12,presreci13,0);
		 odrediTackuPresretanja(awayPlayer1,ball,px2,py2,vremePr2,presreci21,presreci22,presreci23,0);
		 odrediTackuPresretanja(awayPlayer2,ball,px3,py3,vremePr3,presreci31,presreci32,presreci33,0);

		 //LogFajl << vremePr0 << " " << vremePr3 << " " << vectorDistance(ball.getXPos(), ball.getYPos(), homePlayer1.getXPos(), homePlayer1.getYPos()) << " " << vectorDistance(ball.getXPos(), ball.getYPos(), awayPlayer2.getXPos(), awayPlayer2.getYPos()) << " " ;

		 double niz[4] = {vremePr0,vremePr1,vremePr2,vremePr3};

		 int koCePrvi = minimum(niz);

		 // if ((0 == koCePrvi) || (1 == koCePrvi))



		 //if ()
 


        // ODBRAMBENI IGRAC (kretanje)

  double destX, destY;

  //if (0 == koCePrvi) {destX = px0; destY = py0;}else
   odrediKretanjeGolmana (homePlayer1,homePlayer2,awayPlayer1,awayPlayer2,koCePrvi,ball,destX,destY,px0,py0,pohotnostRand);

  homePlayer1.setDestinationX(destX);  
  homePlayer1.setDestinationY(destY);  

  //if (sqrt(pow((homePlayer2.getXPos()-ball.getXPos()),2)+pow((homePlayer2.getYPos()-ball.getYPos()),2)) < 40) // ***
  //{
	 // homePlayer1.setDestinationX(500);
	 // homePlayer2.setDestinationY(200);
  //}

 


  // NAPADACKI IGRAC  (kretanje)

	double pX,pY,vremePr;
	//Vreme::Primerak()->postaviPrviTajmer();
	odrediTackuPresretanja(homePlayer2,ball,pX,pY,vremePr,presreci11,presreci12,presreci13,0);
	//Vreme::Primerak()->postaviDrugiTajmer();
	//Vreme::Primerak()->ispisiTrajanjeIzvrsavanjaULog();

	if (true == (presreci11 || presreci12 || presreci13))  // moze i samo true == presreci 13
	{
		homePlayer2.setDestinationX(pX);
		homePlayer2.setDestinationY(pY);
	}
	else
	{
		homePlayer2.setDestinationX(homePlayer2.getXPos());       // ball.getXPos()
		homePlayer2.setDestinationY(homePlayer2.getYPos());       // ball.getYpos()
	}

 Player awayGoalie = ((awayPlayer1.getXPos() > awayPlayer2.getXPos()) ? awayPlayer1 : awayPlayer2);
 int AGIndex = ((awayPlayer1.getXPos() > awayPlayer2.getXPos()) ? 2 : 3);
 //LogFajl << " AGIndex " << AGIndex << "  koCePrvi " << koCePrvi << " " ; 
 
 if ((koCePrvi != 1) && (koCePrvi != AGIndex) && (pozicioniranjeRand == 1))
 {
  //LogFajl << " DA ";
  homePlayer2.setDestinationX((awayPlayer1.getXPos() + awayPlayer2.getXPos()) / 2);
  homePlayer2.setDestinationY((awayPlayer1.getYPos() + awayPlayer2.getYPos()) / 2);
 }

 if (((0 == koCePrvi) && (awayGoalie.getXPos() > g_fieldLength - 150) && (abs(awayGoalie.getYPos()) < 150)) && (pozicioniranjeRand==0))
 {
  //LogFajl << " DA ";
  homePlayer2.setDestinationX(awayGoalie.getXPos() - 30);
  homePlayer2.setDestinationY(-1*awayGoalie.getYPos());
 }
 if(((0 == koCePrvi) && (!((awayGoalie.getXPos() > g_fieldLength - 150) && (abs(awayGoalie.getYPos()) < 150)))) && (pozicioniranjeRand==0))
 {
  homePlayer2.setDestinationX(awayGoalie.getXPos() + 60);
  homePlayer2.setDestinationY(-1*awayGoalie.getYPos());
  //homePlayer2.setDestinationX((awayPlayer1.getXPos() + awayPlayer2.getXPos()) / 2);
  //homePlayer2.setDestinationY((awayPlayer1.getYPos() + awayPlayer2.getYPos()) / 2);
 }
  




	// ========SUTIRANJE======== //

	double xkick,ykick;
	double intenzitet;
	bool mozeSigurno;

	sutUgol(ball,awayPlayer1,awayPlayer2,xkick,ykick,intenzitet,mozeSigurno);

   //LogFajl << koCePrvi << " " << setw(15) ;
   
  if (mozeSigurno)
  {//LogFajl << "Sut Sigurica";
	homePlayer1.setKickVectorX(xkick);  //**********
	homePlayer1.setKickVectorY(ykick);  //**********
	homePlayer1.setKickIntensity(intenzitet); // treba 100 za precisionShotMax

	homePlayer2.setKickVectorX(xkick);
	homePlayer2.setKickVectorY(ykick);
	homePlayer2.setKickIntensity(intenzitet);
  }
  else
  {
	  bool mozeVodjenje; double xkickV,ykickV,intenzitetV;
	  if (sqrt(pow((homePlayer1.getXPos()-ball.getXPos()),2)+pow((homePlayer1.getYPos()-ball.getYPos()),2)) < sqrt(pow((homePlayer2.getXPos()-ball.getXPos()),2)+pow((homePlayer2.getYPos()-ball.getYPos()),2)))
    vodiLoptu(g_fieldLength,0,ball,homePlayer1,awayPlayer1,awayPlayer2,xkickV,ykickV,intenzitetV,mozeVodjenje);
	  else vodiLoptu(g_fieldLength,0,ball,homePlayer2,awayPlayer1,awayPlayer2,xkickV,ykickV,intenzitetV,mozeVodjenje);

	  

	  if (mozeVodjenje)
   {//LogFajl << "Vodi Loptu";
    homePlayer1.setKickVectorX(xkickV);  
    homePlayer1.setKickVectorY(ykickV);  
    homePlayer1.setKickIntensity(intenzitetV); 

    homePlayer2.setKickVectorX(xkickV);
    homePlayer2.setKickVectorY(ykickV);
    homePlayer2.setKickIntensity(intenzitetV);
   }  
	  else
	  {
			
			double AP1DoGolmana = vectorDistance(awayPlayer1.getXPos(),awayPlayer1.getYPos(),homePlayer1.getXPos(),homePlayer1.getYPos()),
				AP2DoGolmana = vectorDistance(awayPlayer2.getXPos(),awayPlayer2.getYPos(),homePlayer1.getXPos(),homePlayer1.getYPos()),
				bliziDoGolmana = (AP1DoGolmana < AP2DoGolmana) ? AP1DoGolmana : AP2DoGolmana;
			
			double dodajX,dodajY,dodajInt;

			bool mozeDodajHP1Spec = dodajSpec(ball,homePlayer1,homePlayer2,awayPlayer1,awayPlayer2,dodajX,dodajY,dodajInt);
			

			if (mozeDodajHP1Spec)
			{
				homePlayer1.setKickVectorX(dodajX);  //**********
				homePlayer1.setKickVectorY(dodajY);  //**********
				homePlayer1.setKickIntensity(dodajInt);
			}
			else
			{
				bool mozeDodajHP1 = dodaj(ball,homePlayer1,homePlayer2,awayPlayer1,awayPlayer2,dodajX,dodajY,dodajInt);
				if (mozeDodajHP1)
				{//LogFajl << "Dodavanje hp1";
					homePlayer1.setKickVectorX(dodajX);  //**********
					homePlayer1.setKickVectorY(dodajY);  //**********
					homePlayer1.setKickIntensity(dodajInt);
				}
				else
				{
					homePlayer1.setKickVectorX(xkick);  //**********
					homePlayer1.setKickVectorY(ykick);  //**********
					homePlayer1.setKickIntensity(intenzitet); // treba 100 za precisionShotMax
				}
			}

			bool mozeDodajHP2 = dodaj(ball,homePlayer2,homePlayer1,awayPlayer1,awayPlayer2,dodajX,dodajY,dodajInt);

			if (mozeDodajHP2 && (homePlayer2.getXPos() > (g_fieldLength / (3 - dodavanjeRand)) - g_playerDiameter)  && (bliziDoGolmana > g_fieldLength / 4))
			{//LogFajl << "Dodavanje hp2";
				homePlayer2.setKickVectorX(dodajX);  //**********
				homePlayer2.setKickVectorY(dodajY);  //**********
				homePlayer2.setKickIntensity(dodajInt);
			}
			else
			{
				homePlayer2.setKickVectorX(xkick);
				homePlayer2.setKickVectorY(ykick);
				homePlayer2.setKickIntensity(intenzitet);
			}
	  }
  }

 


  if (gameStatus.getReset() == false)
	  stratFlipFlop = true;

  if ((ball.getXPos() > g_fieldLength + g_ballDiameter) && scoreFlipFlop)
  {
	  scoreFlipFlop = false;
	  successCounter[strat]++;
  }
  if ((ball.getXPos() < - g_ballDiameter) && scoreFlipFlop)
  {
	  scoreFlipFlop = false;
	  successCounter[strat]--;
  }

  if ((ball.getXPos() > 0) && (ball.getXPos()<g_fieldLength))
  {
	  scoreFlipFlop = true;
  }

		//end calc

  

// ISPIS U FAJL
  
    /*LogFajl.is_open() != true) 
	  LogFajl.open("Izlaz.txt",ios::app);*/

//double bolXvel = ball.getXVel(), bolYvel = ball.getYVel(), homeXpos = homePlayer1.getXPos(), homeYpos = homePlayer1.getYPos();
//double ka = ball.getYVel() / ball.getXVel() ;

	//LogFajl << koCePrvi << " ||| " << px0 << " " << py0 << endl; //<< " ||| " << presreci01 << " ||| " ; //<< homeXpos << " " << homeYpos << " ||| " << bolXvel << " " << bolYvel << endl ;
    //LogFajl << ball.getXVel() << " " << ball.getYVel() << " " << ka << endl;
	/*LogFajl << " " << koCePrvi << " " << ball.getXVel() << " " << ball.getYVel() << "  igractackapreseka:   " << vectorDistance(homePlayer1.getXPos(),homePlayer1.getYPos(),px0,py0) << "   loptatackapreseka  " << vectorDistance(ball.getXPos(),ball.getYPos(),px0,py0) << "   brzinaigraca  " << vectorLength(homePlayer1.getVelX(),homePlayer1.getVelY()) << "  |||| ";
	LogFajl << "  njihovtackapreseka:   " << vectorDistance(awayPlayer2.getXPos(),awayPlayer2.getYPos(),px3,py3) << "   loptatackapresekanjihov  " << vectorDistance(ball.getXPos(),ball.getYPos(),px3,py3) << "   brzinanjihov  " << vectorLength(awayPlayer2.getVelX(),awayPlayer2.getVelY()) << endl;*/

	//LogFajl << "glavni tajmer:   " << mainMainCounter << "   strategija:   " << strat<< endl;

	//LogFajl <<  vremeGore << " " << vremeDole << " " << vremeDirekt << " " << sut << " "  ;
	//LogFajl <<  ball.getXVel() << " " << ball.getYVel() << endl ;
		
		//sqrt(pow(ball.getXVel(),2)+pow(ball.getYVel(),2)) << endl;               // presreci13 << " " ;     
		
		//sqrt(pow(ball.getXVel(),2)+pow(ball.getYVel(),2)) << " ";

  //LogFajl.close(); 



//Vreme::Primerak()->postaviDrugiTajmer();


		// OUT CONVERSION
		converter.convertOut(homePlayer1,homePlayer2,awayPlayer1,awayPlayer2,ball,gameStatus);


		

		//Vreme::Primerak()->ispisiTrajanjeIzvrsavanjaULog();
        

		//start output
		//170 //180 //190 //200 //210 //220 //230 //240
		homePlayer1.outputDecisions();
		homePlayer2.outputDecisions();
  
		//end output

		
		// Vreme::Primerak()->ispisiTrajanjeIzvrsavanjaULog();
	} // while (true)

	

	return 0;
}



