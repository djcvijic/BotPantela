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
		homePlayer1.inputpoz();
		homePlayer2.inputpoz();
		awayPlayer1.inputpoz();
		awayPlayer2.inputpoz();
		//90 //100 //110 //120
		ball.inputpoz();
		ball.inputbrz();
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

		if ((ball.dohvatiXpoz()>0) && (ball.dohvatiXpoz()<k_fieldLength)) mainMainCounter++;

		if ((mainMainCounter<6000) && gameStatus.dohvatiRepostavi() && stratFlipFlop)
		{
			stratFlipFlop = false;
			strat = rand() % 12;
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

		pohotnostRand = strat % 3;
		pozicioniranjeRand = strat % 2;
		dodavanjeRand = strat / 6;

//Vreme::Primerak()->postaviPrviTajmer();


  homePlayer1.postaviWillMove(true);                    // *** 
  homePlayer1.postaviWillKick(true);
  homePlayer2.postaviWillMove(true);
  homePlayer2.postaviWillKick(true);

  // potrebno da bi se izracunavala brzina igraca:
  homePlayer1.postaviPastpoz();
  homePlayer2.postaviPastpoz();
  awayPlayer1.postaviPastpoz();
  awayPlayer2.postaviPastpoz();





         odrediTackuPresretanja(homePlayer1,ball,px0,py0,vremePr0,presreci01,presreci02,presreci03,0);
		 odrediTackuPresretanja(homePlayer2,ball,px1,py1,vremePr1,presreci11,presreci12,presreci13,0);
		 odrediTackuPresretanja(awayPlayer1,ball,px2,py2,vremePr2,presreci21,presreci22,presreci23,0);
		 odrediTackuPresretanja(awayPlayer2,ball,px3,py3,vremePr3,presreci31,presreci32,presreci33,0);

		 //LogFajl << vremePr0 << " " << vremePr3 << " " << vectorDistance(ball.dohvatiXpoz(), ball.dohvatiYpoz(), homePlayer1.dohvatiXpoz(), homePlayer1.dohvatiYpoz()) << " " << vectorDistance(ball.dohvatiXpoz(), ball.dohvatiYpoz(), awayPlayer2.dohvatiXpoz(), awayPlayer2.dohvatiYpoz()) << " " ;

		 double niz[4] = {vremePr0,vremePr1,vremePr2,vremePr3};

		 int koCePrvi = minimum(niz);

		 // if ((0 == koCePrvi) || (1 == koCePrvi))



		 //if ()
 


        // ODBRAMBENI IGRAC (kretanje)

  double destX, destY;

  //if (0 == koCePrvi) {destX = px0; destY = py0;}else
   odrediKretanjeGolmana (homePlayer1,homePlayer2,awayPlayer1,awayPlayer2,koCePrvi,ball,destX,destY,px0,py0,pohotnostRand);

  homePlayer1.postaviDestinationX(destX);  
  homePlayer1.postaviDestinationY(destY);  

  //if (sqrt(pow((homePlayer2.dohvatiXpoz()-ball.dohvatiXpoz()),2)+pow((homePlayer2.dohvatiYpoz()-ball.dohvatiYpoz()),2)) < 40) // ***
  //{
	 // homePlayer1.postaviDestinationX(500);
	 // homePlayer2.postaviDestinationY(200);
  //}

 


  // NAPADACKI IGRAC  (kretanje)

	double pX,pY,vremePr;
	//Vreme::Primerak()->postaviPrviTajmer();
	odrediTackuPresretanja(homePlayer2,ball,pX,pY,vremePr,presreci11,presreci12,presreci13,0);
	//Vreme::Primerak()->postaviDrugiTajmer();
	//Vreme::Primerak()->ispisiTrajanjeIzvrsavanjaULog();

	if (true == (presreci11 || presreci12 || presreci13))  // moze i samo true == presreci 13
	{
		homePlayer2.postaviDestinationX(pX);
		homePlayer2.postaviDestinationY(pY);
	}
	else
	{
		double kLH, nLH,xLH,yLH;
		odrediKiN(kLH,nLH,ball);
		odrediTackuOdbijanja(kLH,nLH,xLH,yLH,ball);
		homePlayer2.postaviDestinationX(xLH);       // ball.dohvatiXpoz()
		homePlayer2.postaviDestinationY(yLH);       // ball.dohvatiYpoz()
	}

 Player awayGoalie = ((awayPlayer1.dohvatiXpoz() > awayPlayer2.dohvatiXpoz()) ? awayPlayer1 : awayPlayer2);
 int AGIndex = ((awayPlayer1.dohvatiXpoz() > awayPlayer2.dohvatiXpoz()) ? 2 : 3);
 //LogFajl << " AGIndex " << AGIndex << "  koCePrvi " << koCePrvi << " " ; 
 
 if ((koCePrvi != 1) && (koCePrvi != AGIndex) && (pozicioniranjeRand == 1))
 {
  //LogFajl << " DA ";
  homePlayer2.postaviDestinationX((awayPlayer1.dohvatiXpoz() + awayPlayer2.dohvatiXpoz()) / 2);
  homePlayer2.postaviDestinationY((awayPlayer1.dohvatiYpoz() + awayPlayer2.dohvatiYpoz()) / 2);
 }

 if (((0 == koCePrvi) && (awayGoalie.dohvatiXpoz() > k_fieldLength - 150) && (abs(awayGoalie.dohvatiYpoz()) < 150)) && (pozicioniranjeRand==0))
 {
  //LogFajl << " DA ";
  homePlayer2.postaviDestinationX(awayGoalie.dohvatiXpoz() - 30);
  homePlayer2.postaviDestinationY(-1*awayGoalie.dohvatiYpoz());
 }
 if(((0 == koCePrvi) && (!((awayGoalie.dohvatiXpoz() > k_fieldLength - 150) && (abs(awayGoalie.dohvatiYpoz()) < 150)))) && (pozicioniranjeRand==0))
 {
  homePlayer2.postaviDestinationX(awayGoalie.dohvatiXpoz() + 60);
  homePlayer2.postaviDestinationY(-1*awayGoalie.dohvatiYpoz());
  //homePlayer2.postaviDestinationX((awayPlayer1.dohvatiXpoz() + awayPlayer2.dohvatiXpoz()) / 2);
  //homePlayer2.postaviDestinationY((awayPlayer1.dohvatiYpoz() + awayPlayer2.dohvatiYpoz()) / 2);
 }
  




	// ========SUTIRANJE======== //

	double xkick,ykick;
	double intenzitet;
	bool mozeSigurno;

	sutUgol(ball,awayPlayer1,awayPlayer2,xkick,ykick,intenzitet,mozeSigurno);

   //LogFajl << koCePrvi << " " << postaviw(15) ;
   
  if (mozeSigurno)
  {//LogFajl << "Sut Sigurica";
	homePlayer1.postaviKickVectorX(xkick);  //**********
	homePlayer1.postaviKickVectorY(ykick);  //**********
	homePlayer1.postaviKickIntensity(intenzitet); // treba 100 za precisionShotMax

	homePlayer2.postaviKickVectorX(xkick);
	homePlayer2.postaviKickVectorY(ykick);
	homePlayer2.postaviKickIntensity(intenzitet);
  }
  else
  {
	  bool mozeVodjenje; double xkickV,ykickV,intenzitetV;
	  if (sqrt(pow((homePlayer1.dohvatiXpoz()-ball.dohvatiXpoz()),2)+pow((homePlayer1.dohvatiYpoz()-ball.dohvatiYpoz()),2)) < sqrt(pow((homePlayer2.dohvatiXpoz()-ball.dohvatiXpoz()),2)+pow((homePlayer2.dohvatiYpoz()-ball.dohvatiYpoz()),2)))
    vodiLoptu(k_fieldLength,0,ball,homePlayer1,awayPlayer1,awayPlayer2,xkickV,ykickV,intenzitetV,mozeVodjenje);
	  else vodiLoptu(k_fieldLength,0,ball,homePlayer2,awayPlayer1,awayPlayer2,xkickV,ykickV,intenzitetV,mozeVodjenje);

	  

	  if (mozeVodjenje)
   {//LogFajl << "Vodi Loptu";
    homePlayer1.postaviKickVectorX(xkickV);  
    homePlayer1.postaviKickVectorY(ykickV);  
    homePlayer1.postaviKickIntensity(intenzitetV); 

    homePlayer2.postaviKickVectorX(xkickV);
    homePlayer2.postaviKickVectorY(ykickV);
    homePlayer2.postaviKickIntensity(intenzitetV);
   }  
	  else
	  {
			
			double AP1DoGolmana = vectorDistance(awayPlayer1.dohvatiXpoz(),awayPlayer1.dohvatiYpoz(),homePlayer1.dohvatiXpoz(),homePlayer1.dohvatiYpoz()),
				AP2DoGolmana = vectorDistance(awayPlayer2.dohvatiXpoz(),awayPlayer2.dohvatiYpoz(),homePlayer1.dohvatiXpoz(),homePlayer1.dohvatiYpoz()),
				bliziDoGolmana = (AP1DoGolmana < AP2DoGolmana) ? AP1DoGolmana : AP2DoGolmana;
			
			double dodajX,dodajY,dodajInt;

			bool mozeDodajHP1Spec = dodajSpec(ball,homePlayer1,homePlayer2,awayPlayer1,awayPlayer2,dodajX,dodajY,dodajInt);
			

			if (mozeDodajHP1Spec)
			{
				homePlayer1.postaviKickVectorX(dodajX);  //**********
				homePlayer1.postaviKickVectorY(dodajY);  //**********
				homePlayer1.postaviKickIntensity(dodajInt);
			}
			else
			{
				bool mozeDodajHP1 = dodaj(ball,homePlayer1,homePlayer2,awayPlayer1,awayPlayer2,dodajX,dodajY,dodajInt);
				if (mozeDodajHP1)
				{//LogFajl << "Dodavanje hp1";
					homePlayer1.postaviKickVectorX(dodajX);  //**********
					homePlayer1.postaviKickVectorY(dodajY);  //**********
					homePlayer1.postaviKickIntensity(dodajInt);
				}
				else
				{
					homePlayer1.postaviKickVectorX(xkick);  //**********
					homePlayer1.postaviKickVectorY(ykick);  //**********
					homePlayer1.postaviKickIntensity(intenzitet); // treba 100 za precisionShotMax
				}
			}

			bool mozeDodajHP2 = dodaj(ball,homePlayer2,homePlayer1,awayPlayer1,awayPlayer2,dodajX,dodajY,dodajInt);

			if (mozeDodajHP2 && (homePlayer2.dohvatiXpoz() > (k_fieldLength / (3 - dodavanjeRand)) - k_playerDiameter)  && (bliziDoGolmana > k_fieldLength / 4))
			{//LogFajl << "Dodavanje hp2";
				homePlayer2.postaviKickVectorX(dodajX);  //**********
				homePlayer2.postaviKickVectorY(dodajY);  //**********
				homePlayer2.postaviKickIntensity(dodajInt);
			}
			else
			{
				homePlayer2.postaviKickVectorX(xkick);
				homePlayer2.postaviKickVectorY(ykick);
				homePlayer2.postaviKickIntensity(intenzitet);
			}
	  }
  }

 


  if (gameStatus.dohvatiRepostavi() == false)
	  stratFlipFlop = true;

  if ((ball.dohvatiXpoz() > k_fieldLength + k_ballDiameter) && scoreFlipFlop)
  {
	  scoreFlipFlop = false;
	  successCounter[strat]++;
  }
  if ((ball.dohvatiXpoz() < - k_ballDiameter) && scoreFlipFlop)
  {
	  scoreFlipFlop = false;
	  successCounter[strat]--;
  }

  if ((ball.dohvatiXpoz() > 0) && (ball.dohvatiXpoz()<k_fieldLength))
  {
	  scoreFlipFlop = true;
  }

		//end calc

  

// ISPIS U FAJL
  
    /*LogFajl.is_open() != true) 
	  LogFajl.open("Izlaz.txt",ios::app);*/

//double bolXbrz = ball.dohvatiXbrz(), bolYbrz = ball.dohvatiYbrz(), homeXpoz = homePlayer1.dohvatiXpoz(), homeYpoz = homePlayer1.dohvatiYpoz();
//double ka = ball.dohvatiYbrz() / ball.dohvatiXbrz() ;

	//LogFajl << koCePrvi << " ||| " << px0 << " " << py0 << endl; //<< " ||| " << presreci01 << " ||| " ; //<< homeXpoz << " " << homeYpoz << " ||| " << bolXbrz << " " << bolYbrz << endl ;
    //LogFajl << ball.dohvatiXbrz() << " " << ball.dohvatiYbrz() << " " << ka << endl;
	/*LogFajl << " " << koCePrvi << " " << ball.dohvatiXbrz() << " " << ball.dohvatiYbrz() << "  igractackapreseka:   " << vectorDistance(homePlayer1.dohvatiXpoz(),homePlayer1.dohvatiYpoz(),px0,py0) << "   loptatackapreseka  " << vectorDistance(ball.dohvatiXpoz(),ball.dohvatiYpoz(),px0,py0) << "   brzinaigraca  " << vectorLength(homePlayer1.dohvatibrzX(),homePlayer1.dohvatibrzY()) << "  |||| ";
	LogFajl << "  njihovtackapreseka:   " << vectorDistance(awayPlayer2.dohvatiXpoz(),awayPlayer2.dohvatiYpoz(),px3,py3) << "   loptatackapresekanjihov  " << vectorDistance(ball.dohvatiXpoz(),ball.dohvatiYpoz(),px3,py3) << "   brzinanjihov  " << vectorLength(awayPlayer2.dohvatibrzX(),awayPlayer2.dohvatibrzY()) << endl;*/

	//LogFajl << "glavni tajmer:   " << mainMainCounter << "   strategija:   " << strat<< endl;

	//LogFajl <<  vremeGore << " " << vremeDole << " " << vremeDirekt << " " << sut << " "  ;
	//LogFajl <<  ball.dohvatiXbrz() << " " << ball.dohvatiYbrz() << endl ;
		
		//sqrt(pow(ball.dohvatiXbrz(),2)+pow(ball.dohvatiYbrz(),2)) << endl;               // presreci13 << " " ;     
		
		//sqrt(pow(ball.dohvatiXbrz(),2)+pow(ball.dohvatiYbrz(),2)) << " ";

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



