#ifndef Methods_h
#define Methods_h

#include "Constants.h"
#include "Ball.h"
#include "Player.h"
#include "GameStatus.h"
#include <cmath>

     void odrediTackuOdbijanja(const double k, const double n, double& a1,double& b1,Ball& ball)
	 {
		 if( (ball.dohvatiXbrz() <= 0) && (ball.dohvatiYbrz() <= 0) )
		 {
			 if (n< (-0.5*k_fieldWidth)) 
			 { a1 = (-0.5*k_fieldWidth-n)/k; b1=-0.5*k_fieldWidth;}
			 else {a1 = 0; b1 = n;}
		 }

		 if ( (ball.dohvatiXbrz() <= 0) && (ball.dohvatiYbrz() > 0) )
		 {
			 if (n > 0.5*k_fieldWidth)
			 {a1 = (0.5*k_fieldWidth-n)/k; b1 = 0.5*k_fieldWidth;}
			 else {a1 = 0; b1 = n;}
		 }

		 if ( (ball.dohvatiXbrz() > 0) && (ball.dohvatiYbrz() > 0) )
		 {
			 if (k*k_fieldLength+n<0.5*k_fieldWidth)
			 {a1 = k_fieldLength; b1 = k*k_fieldLength + n;}
			 else {b1 = 0.5*k_fieldWidth; a1 = (0.5*k_fieldWidth-n)/k;}
		 }

		 if ( (ball.dohvatiXbrz()>0) && (ball.dohvatiYbrz()<=0) )
		 {
			 if (k*k_fieldLength+n>-0.5*k_fieldWidth)
			 {a1 = k_fieldLength; b1 = k*k_fieldLength+n;}
			 else {b1 = -0.5*k_fieldWidth; a1 = (-0.5*k_fieldWidth-n)/k;}
		 }

		 /*if (abs(-0.5*k_fieldWidth - b1) < 5) 
		 {
			 b1 += k_ballDiameter/2;
			 a1 = ((0 == k) ? 10000 : ((b1-n)/k));
		 }
		 else
		 {
			 if (abs(0.5*k_fieldWidth - b1) < 5)
			 {
				 b1 -= k_ballDiameter/2;
				 a1 = ((0 == k) ? 10000 : ((b1-n)/k)); 
			 }
			 else
			 {
				 if (abs(k_fieldLength - a1) < 5)
				 {
					 a1 -= k_ballDiameter/2;
					 b1 = k*a1+n;
				 }
				 else
				 {
					 if (abs(a1) < 5)
					 {
						 a1 += k_ballDiameter/2;
						 b1 = k*a1+n;
					 }
				 }
			 }
		 }*/
	 }


	 void odrediTackuOdbijanja2(const double k, const double n, double& a1,double& b1,double Xbrz, double Ybrz)
	 {
		 if( (Xbrz <= 0) && (Ybrz <= 0) )
		 {
			 if (n< (-0.5*k_fieldWidth)) 
			 { a1 = (-0.5*k_fieldWidth-n)/k; b1=-0.5*k_fieldWidth;}
			 else {a1 = 0; b1 = n;}
		 }

		 if ( (Xbrz <= 0) && (Ybrz > 0) )
		 {
			 if (n > 0.5*k_fieldWidth)
			 {a1 = (0.5*k_fieldWidth-n)/k; b1 = 0.5*k_fieldWidth;}
			 else {a1 = 0; b1 = n;}
		 }

		 if ( (Xbrz > 0) && (Ybrz > 0) )
		 {
			 if (k*k_fieldLength+n<0.5*k_fieldWidth)
			 {a1 = k_fieldLength; b1 = k*k_fieldLength + n;}
			 else {b1 = 0.5*k_fieldWidth; a1 = (0.5*k_fieldWidth-n)/k;}
		 }

		 if ( (Xbrz>0) && (Ybrz<=0) )
		 {
			 if (k*k_fieldLength+n>-0.5*k_fieldWidth)
			 {a1 = k_fieldLength; b1 = k*k_fieldLength+n;}
			 else {b1 = -0.5*k_fieldWidth; a1 = (-0.5*k_fieldWidth-n)/k;}
		 }



		  /*if (abs(-0.5*k_fieldWidth - b1) < 5) 
		 {
			 b1 += k_ballDiameter/2;
			 a1 = ((0 == k) ? 10000 : ((b1-n)/k));
		 }
		 else
		 {
			 if (abs(0.5*k_fieldWidth - b1) < 5)
			 {
				 b1 -= k_ballDiameter/2;
				 a1 = ((0 == k) ? 10000 : ((b1-n)/k));
			 }
			 else
			 {
				 if (abs(k_fieldLength - a1) < 5)
				 {
					 a1 -= k_ballDiameter/2;
					 b1 = k*a1+n;
				 }
				 else
				 {
					 if (abs(a1) < 5)
					 {
						 a1 += k_ballDiameter/2;
						 b1 = k*a1+n;
					 }
				 }
			 }
		 }*/

	 }




	 void odrediKiN (double& k, double& n, Ball& ball)
	 {
		 // odredjivanje vrednosti 'k' i 'n', ovo za 'k' je ovako zajebano da bi se izbeglo deljenje nulom
  if (0 != ball.dohvatiXbrz()) k = ball.dohvatiYbrz()/ball.dohvatiXbrz();
  else 
  {
	  if (0 != ball.dohvatiYbrz()) k = 10000;  // 10000 menja beskonacno
	  else 
		  if (0 != ball.dohvatiXpoz()) k = ball.dohvatiYpoz()/ball.dohvatiXpoz();
		  else k = 1;// mozda ispitati slucaj 0 == ball.dohvatiXpoz()
  }

  n = ball.dohvatiYpoz() - k* ball.dohvatiXpoz();

	 }



     int ideLiPrema (Player& pl,const double x, const double y)
	 {
		 double d1 = sqrt(pow((pl.dohvatiXpoz()-x),2)+pow((pl.dohvatiYpoz()-y),2));

		 double xPlImag = pl.dohvatiXpoz() + 2* pl.dohvatibrzX();
		 double yPlImag = pl.dohvatiYpoz() + 2* pl.dohvatibrzY();

		 double d2 = sqrt (pow((xPlImag-x),2)+pow((yPlImag-y),2));

		 double zadovoljan = 2.6;

		 if (d1 - d2 > zadovoljan) return 1;
		 else
		 {
			 if ((d1 - d2 <= zadovoljan) && (d1 - d2 > -1*zadovoljan) ) return 0;
			 else return -1;
		 }
	 }


	 double brzinaPremaTacki (Player pl, const double xTek, const double yTek)
	 {
		 double d1 = sqrt(pow((pl.dohvatiXpoz()-xTek),2)+pow((pl.dohvatiYpoz()-yTek),2));

		 double xPlImag = pl.dohvatiXpoz() + 2* pl.dohvatibrzX();
		 double yPlImag = pl.dohvatiYpoz() + 2* pl.dohvatibrzY();

		 double d2 = sqrt (pow((xPlImag-xTek),2)+pow((yPlImag-yTek),2));

		 return (d1 - d2)/2;
	 }



      
	 void odrediTackuPresretanja (Player& pl, Ball& ball, double& a1, double& b1, double& vreme, bool& moze1, bool moze2, bool moze3,  double gratis = 0)
	 {
		 moze1 = moze2 = moze3 = false;
		 double distance = 10000;
		 double vremeLopteMin = 10000;

		 double vremeLopteDoUdara;
		 double vnovo;
		 double XodbStaro,YodbStaro;

   // 'odbX', 'odbY' su koordinate tacke na martineli gde ce sledece udariti lopta; 
   // 'Xin','Yin' su potencijalne koordinate tacke gde igrac uzima loptu
         double Xodb, Yodb, Xin = -500, Yin = -500, vr = -500;  

   // koeficijenti prave po kojoj se krece lopta
 		 double k,n;

		 odrediKiN(k,n,ball);
		 odrediTackuOdbijanja(k,n,Xodb,Yodb,ball);

		 double Xtek,Ytek,S,vnula; // S je rastojanje od lopte do potencijalne intersect tacke
		 double vremeLopte,vremeIgraca;
		 int br = 100;

		 vnula = sqrt(pow(ball.dohvatiXbrz(),2)+pow(ball.dohvatiYbrz(),2));
		 double t1 = -249.5*log(vnula/7.5);
		 double t2;

		 Xtek = Xodb ; 
         for (int i = 0; i<=br; Xtek += (ball.dohvatiXpoz()-Xodb)/br)   //Xtek = Xodb + (i/br)*(ball.dohvatiXpoz()-Xodb
		 {
			 Ytek = k*Xtek+n;

			 //vnula = sqrt(pow(ball.dohvatiXbrz(),2)+pow(ball.dohvatiYbrz(),2));
			 
			 //double t1 = -249.5*log(vnula/7.5);
			 S = sqrt (pow((Xtek-ball.dohvatiXpoz()),2)+pow((Ytek-ball.dohvatiYpoz()),2));
             
			 //double t2;
			 if (249.5*7.5*exp(-t1/249.5)-S > 0) t2 = -249.5*log((249.5*7.5*exp(-t1/249.5)-S)/(249.5*7.5));
			 else t2 = 10000;

			 vremeLopte = abs(t2 - t1);

			 //if (F.is_open() != true) 
	 // F.open("Izlaz.txt",ios::app);

			double Si = sqrt(pow((Xtek-pl.dohvatiXpoz()),2)+pow((Ytek-pl.dohvatiYpoz()),2)) - k_minimalShootingDist + gratis;
			double tejedan,tedva;

			double Sdec,tdec;

			double vpoc = brzinaPremaTacki(pl,Xtek,Ytek);

			

			if ( vpoc < 0 )
			{
				tdec = abs(vpoc/0.21);
				Sdec = abs(vpoc*tdec/2);

				//if (Si + Sdec < 0) Si = -1.0 * Sdec;

				tejedan = 0;

				if (Si + Sdec < 0) tedva = 0;
				else tedva = sqrt( (Si+Sdec) / 0.015 + pow(tejedan,2));

				if (tedva > k_playerAccTime)
					tedva = ( (Si+Sdec) - ((k_playerMaxSpeed + vpoc) * (k_playerAccTime - tejedan) / 2) + k_playerAccTime * k_playerMaxSpeed) / k_playerMaxSpeed;
			

			}
			else
			{
				if (Si < 0) Si = 0;

				tejedan = vpoc / 0.03;
				tedva = sqrt(Si / 0.015 + pow(tejedan,2));
				if (tedva > k_playerAccTime)
					tedva = (Si - ((k_playerMaxSpeed + vpoc) * (k_playerAccTime - tejedan) / 2) + k_playerAccTime * k_playerMaxSpeed) / k_playerMaxSpeed;
			}

			if (Si < 0) vremeIgraca = 0;
			else vremeIgraca = tedva - tejedan;

	   //       double Si = sqrt(pow((Xtek-pl.dohvatiXpoz()),2)+pow((Ytek-pl.dohvatiYpoz()),2));
    //         
			 ////F << "k,n,vnula,S,t1,t2,vrl " << k << " " << n << " " << vnula << " " << S << " " << t1 << " " <<t2 << " " << vremeLopte << endl;
			 //if (Si - k_minimalShootingDist + gratis < k_playerAccDistance)
			 //{
				//  if (0 == ideLiPrema(pl,Xtek,Ytek)) // ako igrac jos nije poztigao k_playerMaxSpeed
				//      vremeIgraca = 31.1138*sqrt(0.0643*(Si-k_minimalShootingDist + gratis) + 0.051397)-1.77753; //+ gratis; // 10 je gratis XD // ********** stavi 10
				//  else
				//  {
				//	  if (1 == ideLiPrema(pl,Xtek,Ytek)) 
				//		  vremeIgraca = (Si-k_minimalShootingDist + gratis)/k_playerMaxSpeed ;
				//	  else 
				//		  if (Si + 23.6 - k_minimalShootingDist+ gratis < k_playerAccDistance)
				//			  vremeIgraca = 20 + 31.1138*sqrt(0.0643*((Si+23.6)-k_minimalShootingDist+ gratis) + 0.051397)-1.77753 ;
				//		  else vremeIgraca = ( (Si+23.6) - k_minimalShootingDist + 10) / k_playerMaxSpeed + 0.5*k_playerAccTime;
				//  }
			 //}
			 //else
			 //{
			 //    if (0 == ideLiPrema(pl,Xtek,Ytek)) // ako igrac jos nije poztigao k_playerMaxSpeed
				//      vremeIgraca = (Si-k_minimalShootingDist+ gratis )/k_playerMaxSpeed + 0.5*k_playerAccTime; 
			 //    else 
		  //  	 {
				//     if (1 == ideLiPrema(pl,Xtek,Ytek)) vremeIgraca = (Si-k_minimalShootingDist+ gratis )/k_playerMaxSpeed;
			 //   	 else vremeIgraca = (Si-k_minimalShootingDist+ gratis )/k_playerMaxSpeed + k_playerAccTime; // 69 = 2* 34.5
			 //    }
			 //}

			 if ((vremeLopte-vremeIgraca >= -0.01) &&  (vremeLopte <= vremeLopteMin))   // Kriterijum najmanjeg rastojanja bio bi (sqrt(pow((Xtek-pl.dohvatiXpoz()),2)+pow((Ytek-pl.dohvatiYpoz()),2)) < distance
			 {
				 distance = sqrt(pow((Xtek-pl.dohvatiXpoz()),2)+pow((Ytek-pl.dohvatiYpoz()),2)) ;
				 vremeLopteMin = vremeLopte;
				 Xin = Xtek; Yin = Ytek;
				 vr = vremeIgraca;
			 }

			 //F << "vremeIgraca " << vremeIgraca << endl << endl; F.close();

			 i++;
		 } // for

		 if (Xin != -500)
		 {		 
       a1 = Xin; b1 = Yin; vreme = vr; moze1 = moze2 = moze3 = true;			
		 }
		 else moze1 = false;


		 if (sqrt(pow(ball.dohvatiXbrz(),2)+pow(ball.dohvatiYbrz(),2)) < 1)
			 {
				 a1 = ball.dohvatiXpoz(); b1 = ball.dohvatiYpoz(); 
				 vreme = sqrt(pow((pl.dohvatiXpoz()-ball.dohvatiXpoz()),2)+pow((pl.dohvatiYpoz()-ball.dohvatiYpoz()),2))/k_playerMaxSpeed;
				 moze1 = moze2 = moze3 = true;
				 return;
			 }



		 if (false == moze1)
		 {
			 k = -1*k;
			 n = Yodb - k*Xodb;
			 S = sqrt (pow((Xodb-ball.dohvatiXpoz()),2)+pow((Yodb-ball.dohvatiYpoz()),2)); // rastojanje od lopte do tacke gde udara u martinelu
             
			 t1 = -249.5*log(vnula/7.5);
			 //double t2;
			 if (249.5*7.5*exp(-t1/249.5)-S > 0) t2 = -249.5*log((249.5*7.5*exp(-t1/249.5)-S)/(249.5*7.5));
			 else t2 = 10000;

			 vremeLopteDoUdara = t2 - t1; // vreme koje ce lopti trebati da udari od martinelu

			 vnovo = 7.5*exp(-1*t2/249.5);
			 vnovo = 0.5976*vnovo;   // gubi se 40 i nest' pozto pri udaru

			 double alpha = atan(k);
			 if ((abs(k_fieldLength - Xodb) < 2) || (abs(0.5*k_fieldWidth - Yodb)<2 && k>0) || (abs(-0.5*k_fieldWidth  - Yodb)<2 && k<0) )
				 alpha += 3.14;

			 double vnovox = vnovo * cos(alpha);
			 double vnovoy = vnovo * sin(alpha);

			 XodbStaro = Xodb; YodbStaro = Yodb;

			 odrediTackuOdbijanja2(k,n,Xodb,Yodb,vnovox,vnovoy);

			 double Xtek,Ytek,S;
			 double vremeIgraca;
		     int br = 100;


			 double distance = 10000;
		     vremeLopteMin = 10000;

   // 'odbX', 'odbY' su koordinate tacke na martineli gde ce sledece udariti lopta; 
   // 'Xin','Yin' su potencijalne koordinate tacke gde igrac uzima loptu
             Xin = -500, Yin = -500, vr = -500; 

             int i = 0;

			 for (Xtek = Xodb ; i<=br; Xtek += (XodbStaro-Xodb)/br )
		 {
			 Ytek = k*Xtek+n;

			 vnula = sqrt(pow(vnovox,2)+pow(vnovoy,2)); // = vnovo
			 
			 double t1 = -249.5*log(vnula/7.5);
			 S = sqrt (pow((Xtek-XodbStaro),2)+pow((Ytek-YodbStaro),2));
             
			 double t2;
			 if (249.5*7.5*exp(-t1/249.5)-S > 0) t2 = -249.5*log((249.5*7.5*exp(-t1/249.5)-S)/(249.5*7.5));
			 else t2 = 10000;

			 vremeLopte = vremeLopteDoUdara + (t2 - t1);

			 //if (F.is_open() != true) 
	 // F.open("Izlaz.txt",ios::app);

	
	
             
			 //double Si = sqrt(pow((Xtek-pl.dohvatiXpoz()),2)+pow((Ytek-pl.dohvatiYpoz()),2));
             
			 //F << "k,n,vnula,S,t1,t2,vrl " << k << " " << n << " " << vnula << " " << S << " " << t1 << " " <<t2 << " " << vremeLopte << endl;
			 double Si = sqrt(pow((Xtek-pl.dohvatiXpoz()),2)+pow((Ytek-pl.dohvatiYpoz()),2)) - k_minimalShootingDist +gratis ;
			double tejedan,tedva;

			double Sdec,tdec;

			double vpoc = brzinaPremaTacki(pl,Xtek,Ytek);

						if ( vpoc < 0 )
			{
				tdec = abs(vpoc/0.21);
				Sdec = abs(vpoc*tdec/2);

				//if (Si + Sdec < 0) Si = -1.0 * Sdec;

				tejedan = 0;

				if (Si + Sdec < 0) tedva = 0;
				else tedva = sqrt( (Si+Sdec) / 0.015 + pow(tejedan,2));

				if (tedva > k_playerAccTime)
					tedva = ( (Si+Sdec) - ((k_playerMaxSpeed + vpoc) * (k_playerAccTime - tejedan) / 2) + k_playerAccTime * k_playerMaxSpeed) / k_playerMaxSpeed;
			

			}
			else
			{
				if (Si < 0) Si = 0;

				tejedan = vpoc / 0.03;
				tedva = sqrt(Si / 0.015 + pow(tejedan,2));
				if (tedva > k_playerAccTime)
					tedva = (Si - ((k_playerMaxSpeed + vpoc) * (k_playerAccTime - tejedan) / 2) + k_playerAccTime * k_playerMaxSpeed) / k_playerMaxSpeed;
			}

			if (Si < 0) vremeIgraca = 0;
			else vremeIgraca = tedva - tejedan;


			 if ((vremeLopte-vremeIgraca > 0) &&  (vremeLopte < vremeLopteMin))   // Kriterijum najmanjeg rastojanja bio bi (sqrt(pow((Xtek-pl.dohvatiXpoz()),2)+pow((Ytek-pl.dohvatiYpoz()),2)) < distance
			 {
				 distance = sqrt(pow((Xtek-pl.dohvatiXpoz()),2)+pow((Ytek-pl.dohvatiYpoz()),2)) ;
				 vremeLopteMin = vremeLopte;
				 Xin = Xtek; Yin = Ytek;
				 vr = vremeIgraca;
			 }

			 //F << "vremeIgraca " << vremeIgraca << endl << endl; F.close();

			 i++;
		 } // for


			 if (Xin != -500)
		 {		 
       a1 = Xin; b1 = Yin; vreme = vr; moze2 = moze3 = true;
	  // if (F.is_open() != true) 
	  //F.open("Izlaz.txt",ios::app);
      
		 }
		 else moze2 = false;


		 } // if ( false == moze )


		 if (false == moze2) // Situacija od drugog odbijanja pa nadalje
		 {
			 k = -1*k;
			 n = Yodb - k*Xodb;
			 S = sqrt (pow((Xodb-XodbStaro),2)+pow((Yodb-YodbStaro),2)); // rastojanje od prvog do drugog mesta udara u martinelu
             
			 t1 = -249.5*log(vnovo/7.5);
			 //double t2;
			 if (249.5*7.5*exp(-t1/249.5)-S > 0) t2 = -249.5*log((249.5*7.5*exp(-t1/249.5)-S)/(249.5*7.5));
			 else t2 = 10000;

			 double vremeLopteDoUdara = t2 - t1; // vreme koje ce lopti trebati da udari od martinelu

			 vnovo = 7.5*exp(-0.004*t2);
			 vnovo = 0.5976*vnovo;   // gubi se 40 i nesto pozto pri udaru

			 double alpha = atan(k);
			 if ((abs(k_fieldLength - Xodb) < 2) || (abs(0.5*k_fieldWidth - Yodb)<2 && k>0) || (abs(-0.5*k_fieldWidth - Yodb)<2 && k<0) )
				 alpha += 3.14;

			 double vnovox = vnovo * cos(alpha);
			 double vnovoy = vnovo * sin(alpha);

			 XodbStaro = Xodb; YodbStaro = Yodb;

			 odrediTackuOdbijanja2(k,n,Xodb,Yodb,vnovox,vnovoy);

			 Xtek,Ytek,S;
			 vremeIgraca;
		     br = 100;


			 double distance = 10000;
		     vremeLopteMin = 10000;

   // 'odbX', 'odbY' su koordinate tacke na martineli gde ce sledece udariti lopta; 
   // 'Xin','Yin' su potencijalne koordinate tacke gde igrac uzima loptu
             Xin = -500, Yin = -500, vr = -500; 

             int i = 0;

			 for (Xtek = Xodb ; i<=br; Xtek += (XodbStaro-Xodb)/br )
		 {
			 Ytek = k*Xtek+n;

			 vnula = sqrt(pow(vnovox,2)+pow(vnovoy,2)); // = vnovo
			 
			 double t1 = -249.5*log(vnula/7.5);
			 S = sqrt (pow((Xtek-XodbStaro),2)+pow((Ytek-YodbStaro),2));
             
			 double t2;
			 if (249.5*7.5*exp(-t1/249.5)-S > 0) t2 = -249.5*log((249.5*7.5*exp(-t1/249.5)-S)/(249.5*7.5));
			 else t2 = 10000;

			 vremeLopte = vremeLopteDoUdara + (t2 - t1);

			 //if (F.is_open() != true) 
	 // F.open("Izlaz.txt",ios::app);

	
	
             
			double Si = sqrt(pow((Xtek-pl.dohvatiXpoz()),2)+pow((Ytek-pl.dohvatiYpoz()),2)) - k_minimalShootingDist + gratis;
			double tejedan,tedva;

			double Sdec,tdec;

			double vpoc = brzinaPremaTacki(pl,Xtek,Ytek);

						if ( vpoc < 0 )
			{
				tdec = abs(vpoc/0.21);
				Sdec = abs(vpoc*tdec/2);

				//if (Si + Sdec < 0) Si = -1.0 * Sdec;

				tejedan = 0;

				if (Si + Sdec < 0) tedva = 0;
				else tedva = sqrt( (Si+Sdec) / 0.015 + pow(tejedan,2));

				if (tedva > k_playerAccTime)
					tedva = ( (Si+Sdec) - ((k_playerMaxSpeed + vpoc) * (k_playerAccTime - tejedan) / 2) + k_playerAccTime * k_playerMaxSpeed) / k_playerMaxSpeed;
			

			}
			else
			{
				if (Si < 0) Si = 0;

				tejedan = vpoc / 0.03;
				tedva = sqrt(Si / 0.015 + pow(tejedan,2));
				if (tedva > k_playerAccTime)
					tedva = (Si - ((k_playerMaxSpeed + vpoc) * (k_playerAccTime - tejedan) / 2) + k_playerAccTime * k_playerMaxSpeed) / k_playerMaxSpeed;
			}

			if (Si < 0) vremeIgraca = 0;
			else vremeIgraca = tedva - tejedan;
			/*if ( vpoc < 0 )
			{
				tdec = abs(vpoc/0.21);
				Sdec = abs(vpoc*tdec/2);

				tejedan = 0;
				tedva = sqrt( (Si+Sdec) / 0.015 + pow(tejedan,2));
				if (tedva > k_playerAccTime)
					tedva = ( (Si+Sdec) - ((k_playerMaxSpeed + vpoc) * (k_playerAccTime - tejedan) / 2) + k_playerAccTime * k_playerMaxSpeed) / k_playerMaxSpeed;
			

			}
			else
			{
				tejedan = vpoc / 0.03;
				tedva = sqrt(Si / 0.015 + pow(tejedan,2));
				if (tedva > k_playerAccTime)
					tedva = (Si - ((k_playerMaxSpeed + vpoc) * (k_playerAccTime - tejedan) / 2) + k_playerAccTime * k_playerMaxSpeed) / k_playerMaxSpeed;
			}

			vremeIgraca = tedva - tejedan;*/
			 //if (Si < k_playerAccDistance)
			 //{
				//  if (0 == ideLiPrema(pl,Xtek,Ytek)) // ako igrac jos nije poztigao k_playerMaxSpeed
				//      vremeIgraca = 31.1138*sqrt(0.0643*(Si-k_minimalShootingDist) + 0.051397)-1.77753 + gratis; // 10 je gratis XD // ********** stavi 10
				//  else
				//  {
				//	  if (1 == ideLiPrema(pl,Xtek,Ytek)) 
				//		  vremeIgraca = (Si-k_minimalShootingDist)/k_playerMaxSpeed + gratis;
				//	  else vremeIgraca = k_playerAccTime + 31.1138*sqrt(0.0643*(Si-k_minimalShootingDist) + 0.051397)-1.77753 + gratis;
				//  }
			 //}
			 //else
			 //{
			 //    if (0 == ideLiPrema(pl,Xtek,Ytek)) // ako igrac jos nije poztigao k_playerMaxSpeed
				//      vremeIgraca = (Si-k_minimalShootingDist+10)/k_playerMaxSpeed + 0.5*k_playerAccTime; 
			 //    else 
		  //  	 {
				//     if (1 == ideLiPrema(pl,Xtek,Ytek)) vremeIgraca = (Si-k_minimalShootingDist+10)/k_playerMaxSpeed;
			 //   	 else vremeIgraca = (Si-k_minimalShootingDist+10)/k_playerMaxSpeed + k_playerAccTime; // 69 = 2* 34.5
			 //    }
			 //}


			 if ((vremeLopte-vremeIgraca > 0) &&  (vremeLopte < vremeLopteMin))   // Kriterijum najmanjeg rastojanja bio bi (sqrt(pow((Xtek-pl.dohvatiXpoz()),2)+pow((Ytek-pl.dohvatiYpoz()),2)) < distance
			 {
				 distance = sqrt(pow((Xtek-pl.dohvatiXpoz()),2)+pow((Ytek-pl.dohvatiYpoz()),2)) ;
				 vremeLopteMin = vremeLopte;
				 Xin = Xtek; Yin = Ytek;
				 vr = vremeIgraca;
			 }

			 //F << "vremeIgraca " << vremeIgraca << endl << endl; F.close();

			 i++;
		 } // for


			 if (Xin != -500)
		 {		 
       a1 = Xin; b1 = Yin; vreme = vr; moze3 = true;
	  // if (F.is_open() != true) 
	  //F.open("Izlaz.txt",ios::app);
      
		 }
		 else moze3 = false;


		 } // if ( false == moze )
		 

		 
         
	 } // KRAJ METODE ZA INTERSECT (hvala bogu XD)







	 //void precisionShot (Ball& ball, const double xdest, const double ydest, const double brzina, double& xkick, double& ykick, double& intensity, bool& moze);


	 //void precisionShotMax (Ball& ball, const double xdest, const double ydest, double& xkick, double& ykick, double& intensity, bool& moze)
	 //{
		// double kr = (ydest - ball.dohvatiYpoz())/(xdest - ball.dohvatiXpoz());
		// double kickbrz = 7.5;
		// double yv = ball.dohvatiYbrz();
		// double xv = ball.dohvatiXbrz();

		// xkick = (kr*yv - pow(kr,2)*xv + sqrt(pow(kickbrz,2)*(pow(kr,2) + 1) - pow((kr*xv - yv),2))) / (pow(kr,2) + 1);
  //       ykick = (kr*xv - yv + kr*sqrt(pow(kickbrz,2)*(pow(kr,2) + 1) - pow((kr*xv-yv),2))) / (pow(kr,2) + 1);

		// if ( (pow(kickbrz,2)*pow(kr,2) + 1 >= 0 ) && ( pow(kickbrz,2)*(pow(kr,2) + 1) - pow((kr*xv-yv),2) >= 0 ) && ( sqrt(pow((xv + xkick),2)+pow((yv + ykick),2)) > 7.49)) //( sqrt(pow((xv + xkick),2)+pow((yv + ykick),2)) > 7.5)
		// {
		// //xkick = (kr*yv - pow(kr,2)*xv + sqrt(pow(kickbrz,2)*(pow(kr,2) + 1) - pow((kr*xv - yv),2))) / (pow(kr,2) + 1);
  //       //ykick = (kr*xv - yv + kr*sqrt(pow(kickbrz,2)*(pow(kr,2) + 1) - pow((kr*xv-yv),2))) / (pow(kr,2) + 1);
		// moze = true;
		// intensity = 100;
		// }
		// else 
		// {   // zaustavljanje lopte
		//	 if (sqrt(pow(ball.dohvatiXbrz(),2)+pow(ball.dohvatiYbrz(),2)) > 7.49)
		//	 {
		//	 xkick = -1*ball.dohvatiXbrz();
		//	 ykick = -1*ball.dohvatiYbrz();
		//	 intensity = 100;
		//	 }
		//	 else
		//	 {
		//		 precisionShot(ball,ball.dohvatiXpoz(),ball.dohvatiYpoz(),0,xkick,ykick,intensity,moze);
		//	 }	
		//	 moze = false;
		// }

	 //}


	 void precisionShot (Ball& ball, const double xdest, const double ydest, const double brzina, double& xkick, double& ykick, double& intensity, bool& moze)
  {
   double xrez,yrez;

   xrez = xdest - ball.dohvatiXpoz();
   yrez = ydest - ball.dohvatiYpoz();
   double koef;

   if (0 != brzina)
   {
   koef = sqrt(pow(xrez,2)+pow(yrez,2))/brzina;
   xrez /= koef;
   yrez /= koef;
   }   
   else 
   {
    koef = 10000;   // ne mora al ajd
    xrez = 0;
    yrez = 0;
   }

   xkick = xrez - ball.dohvatiXbrz();
   ykick = yrez - ball.dohvatiYbrz();
   intensity = sqrt(pow(xkick,2)+pow(ykick,2));

   if (intensity > 9.99)  // ZAUSTAVLJANJE LOPTE
   {     
    //precisionShotMax(ball,xdest,ydest,xkick,ykick,intensity,moze);
    //intensity = 100;
    xkick = -1*ball.dohvatiXbrz();
    ykick = -1*ball.dohvatiYbrz();
    intensity = sqrt(pow(xkick,2)+pow(ykick,2))*10;
    moze = false;
   }
   else
   {
    intensity *= 10;
    moze = true;
    /*if (intensity > 7.5)
    {
     intensity = 100;
    }
    else
    {
     intensity = (intensity - 0.042)/0.09817;
    }
    moze = true;*/
   }
  }


	 int minimum(double niz[])
   {
	   int index = 0;
	   for (int i = 1;i<4;i++)
	   {
		   if (niz[i] < niz[index])  index = i;
	   }
	   return index;
   }

	 int maximum3(double niz[])
   {
	   int index = 0;
	   for (int i = 1;i<3;i++)
	   {
		   if (niz[i] > niz[index])  index = i;
	   }
	   return index;
   }

	 int maximum5(double niz[])
   {
	   int index = 0;
	   for (int i = 1;i<5;i++)
	   {
		   if (niz[i] > niz[index])  index = i;
	   }
	   return index;
   }

	  int minimum3(double niz[])
   {
	   int index = 0;
	   for (int i = 1;i<3;i++)
	   {
		   if (niz[i] < niz[index])  index = i;
	   }
	   return index;
   }

	



	 void sutOpstiDirekt(Ball& ball, Player ap1, Player ap2, Player hp, bool& mozeBezZaustavljanja, bool& mozeSaZaustavljanjem,double& vremeDoKontakta, double xdest, double ydest, double brzina = 7.5)
	 {
		 double xkick,ykick,intenzitet;
		 bool mozeLiSut;
		 precisionShot(ball,xdest,ydest,brzina,xkick,ykick,intenzitet,mozeLiSut);

		 //if (true == mozeLiSut)
		 
			 double xrez,yrez;

		 xrez = xdest -1*ball.dohvatiXpoz();
		 yrez = ydest -1*ball.dohvatiYpoz();
		 double koef;

		 koef = sqrt(pow(xrez,2)+pow(yrez,2))/brzina;
		 xrez /= koef;
		 yrez /= koef;

		 Ball fakeBall(ball);

		 fakeBall.postaviXbrz(xrez);
		 fakeBall.postaviYbrz(yrez);

		 double xAw1,yAw1,vremeAw1;
		 bool mozeAw11,mozeAw12,mozeAw13; 
		 
		 odrediTackuPresretanja(ap1,fakeBall,xAw1,yAw1,vremeAw1,mozeAw11,mozeAw12,mozeAw13,0);

		 double xAw2,yAw2,vremeAw2;
		 bool mozeAw21,mozeAw22,mozeAw23;
		 odrediTackuPresretanja(ap2,fakeBall,xAw2,yAw2,vremeAw2,mozeAw21,mozeAw22,mozeAw23,0);

		 double xH,yH,vremeH;
		 bool mozeH1,mozeH2,mozeH3;
		 odrediTackuPresretanja(hp,fakeBall,xH,yH,vremeH,mozeH1,mozeH2,mozeH3,0);

		 double niz[3] = {vremeAw1,vremeAw2,vremeH};

		 int indeks = minimum3(niz);

		 vremeDoKontakta = niz[indeks];

		 if ( (2 == indeks) && mozeLiSut)
		 {
			 mozeBezZaustavljanja = true;
			 mozeSaZaustavljanjem = true;
		 }
		 else
		 {
			 if ( ( 2 == indeks ) && (!mozeLiSut))
			 {
				mozeBezZaustavljanja = false;
			    mozeSaZaustavljanjem = true;
			 }
			 else
			 {
				mozeBezZaustavljanja = false;
			    mozeSaZaustavljanjem = false;
			 }
		 }	 
	 }


	 void sutOpstiDirektJa(Ball& ball, Player ap1, Player ap2, Player hp, bool& mozeBezZaustavljanja, bool& mozeSaZaustavljanjem,double& vremeDoKontakta, double xdest, double ydest, double brzina = 7.5)
	 {
		 double xkick,ykick,intenzitet;
		 bool mozeLiSut;
		 precisionShot(ball,xdest,ydest,brzina,xkick,ykick,intenzitet,mozeLiSut);

		 //if (true == mozeLiSut)
		 
			 double xrez,yrez;

		 xrez = xdest - ball.dohvatiXpoz();
		 yrez = ydest -1*ball.dohvatiYpoz();
		 double koef;

		 koef = sqrt(pow(xrez,2)+pow(yrez,2))/brzina;
		 xrez /= koef;
		 yrez /= koef;

		 Ball fakeBall(ball);

		 fakeBall.postaviXbrz(0.90*xrez);
		 fakeBall.postaviYbrz(0.90*yrez);

		 fakeBall.postaviXpoz(fakeBall.dohvatiXpoz()+xrez*15);
		 fakeBall.postaviYpoz(fakeBall.dohvatiYpoz()+yrez*15);

		 double xAw1,yAw1,vremeAw1;
		 bool mozeAw11,mozeAw12,mozeAw13; 
		
		 odrediTackuPresretanja(ap1,fakeBall,xAw1,yAw1,vremeAw1,mozeAw11,mozeAw12,mozeAw13,0);

		 double xAw2,yAw2,vremeAw2;
		 bool mozeAw21,mozeAw22,mozeAw23;
		 odrediTackuPresretanja(ap2,fakeBall,xAw2,yAw2,vremeAw2,mozeAw21,mozeAw22,mozeAw23,0);

		 double xH,yH,vremeH;
		 bool mozeH1,mozeH2,mozeH3;
		 odrediTackuPresretanja(hp,fakeBall,xH,yH,vremeH,mozeH1,mozeH2,mozeH3,0);

		 double niz[3] = {vremeAw1,vremeAw2,vremeH + 5}; // !!!!!!!!!!!!!!

		 int indeks = minimum3(niz);

		 vremeDoKontakta = niz[indeks];

		 if ( (2 == indeks) && mozeLiSut)
		 {
			 mozeBezZaustavljanja = true;
			 mozeSaZaustavljanjem = true;
		 }
		 else
		 {
			 if ( ( 2 == indeks ) && (!mozeLiSut))
			 {
				mozeBezZaustavljanja = false;
			    mozeSaZaustavljanjem = true;
			 }
			 else
			 {
				mozeBezZaustavljanja = false;
			    mozeSaZaustavljanjem = false;
			 }
		 }	 
	 }


	 void sutOpstiGore(Ball& ball, Player ap1, Player ap2, Player hp, bool& mozeBezZaustavljanja, bool& mozeSaZaustavljanjem,double& vremeDoKontakta, double xdest, double ydest)
	 {
		 double xkick,ykick,intenzitet;
		 bool mozeLiSut;
		 precisionShot(ball,k_fieldLength,0,7.5,xkick,ykick,intenzitet,mozeLiSut);

		 //if (true == mozeLiSut)
		 
			 double xrez,yrez;

		 xrez = xdest - ball.dohvatiXpoz();
		 yrez = (k_fieldWidth/2 + k_fieldWidth/2 - ydest) -1*ball.dohvatiYpoz();
		 double koef;

		 koef = sqrt(pow(xrez,2)+pow(yrez,2))/7.5;
		 xrez /= koef;
		 yrez /= koef;

		 Ball fakeBall(ball);

		 fakeBall.postaviXbrz(xrez);
		 fakeBall.postaviYbrz(yrez);

		 double xAw1,yAw1,vremeAw1;
		 bool mozeAw11,mozeAw12,mozeAw13; 
		 
		 odrediTackuPresretanja(ap1,fakeBall,xAw1,yAw1,vremeAw1,mozeAw11,mozeAw12,mozeAw13,0);

		 double xAw2,yAw2,vremeAw2;
		 bool mozeAw21,mozeAw22,mozeAw23;
		 odrediTackuPresretanja(ap2,fakeBall,xAw2,yAw2,vremeAw2,mozeAw21,mozeAw22,mozeAw23,0);

		 double xH,yH,vremeH;
		 bool mozeH1,mozeH2,mozeH3;
		 odrediTackuPresretanja(hp,fakeBall,xH,yH,vremeH,mozeH1,mozeH2,mozeH3,0);

		 double niz[3] = {vremeAw1,vremeAw2,vremeH};

		 int indeks = minimum3(niz);

		 vremeDoKontakta = niz[indeks];

		 if ( (2 == indeks) && mozeLiSut)
		 {
			 mozeBezZaustavljanja = true;
			 mozeSaZaustavljanjem = true;
		 }
		 else
		 {
			 if ( ( 2 == indeks ) && (!mozeLiSut))
			 {
				mozeBezZaustavljanja = false;
			    mozeSaZaustavljanjem = true;
			 }
			 else
			 {
				mozeBezZaustavljanja = false;
			    mozeSaZaustavljanjem = false;
			 }
		 }
	 }



	 void sutOpstiDole(Ball& ball, Player ap1, Player ap2, Player hp, bool& mozeBezZaustavljanja, bool& mozeSaZaustavljanjem,double& vremeDoKontakta, double xdest, double ydest)
	 {
		 double xkick,ykick,intenzitet;
		 bool mozeLiSut;
		 precisionShot(ball,k_fieldLength,0,7.5,xkick,ykick,intenzitet,mozeLiSut);

		 //if (true == mozeLiSut)
		 
			 double xrez,yrez;

		 xrez = xdest - ball.dohvatiXpoz();
		 yrez = (-1*k_fieldWidth/2 - (k_fieldWidth/2 + ydest)) -1*ball.dohvatiYpoz();
		 double koef;

		 koef = sqrt(pow(xrez,2)+pow(yrez,2))/7.5;
		 xrez /= koef;
		 yrez /= koef;

		 Ball fakeBall(ball);

		 fakeBall.postaviXbrz(xrez);
		 fakeBall.postaviYbrz(yrez);

		 double xAw1,yAw1,vremeAw1;
		 bool mozeAw11,mozeAw12,mozeAw13; 
		
		 odrediTackuPresretanja(ap1,fakeBall,xAw1,yAw1,vremeAw1,mozeAw11,mozeAw12,mozeAw13,0);

		 double xAw2,yAw2,vremeAw2;
		 bool mozeAw21,mozeAw22,mozeAw23;
		 odrediTackuPresretanja(ap2,fakeBall,xAw2,yAw2,vremeAw2,mozeAw21,mozeAw22,mozeAw23,0);

		 double xH,yH,vremeH;
		 bool mozeH1,mozeH2,mozeH3;
		 odrediTackuPresretanja(hp,fakeBall,xH,yH,vremeH,mozeH1,mozeH2,mozeH3,0);

		 double niz[3] = {vremeAw1,vremeAw2,vremeH};

		 int indeks = minimum3(niz);

		 vremeDoKontakta = niz[indeks];

		 if ( (2 == indeks) && mozeLiSut)
		 {
			 mozeBezZaustavljanja = true;
			 mozeSaZaustavljanjem = true;
		 }
		 else
		 {
			 if ( ( 2 == indeks ) && (!mozeLiSut))
			 {
				mozeBezZaustavljanja = false;
			    mozeSaZaustavljanjem = true;
			 }
			 else
			 {
				mozeBezZaustavljanja = false;
			    mozeSaZaustavljanjem = false;
			 }
		 }		 
	 }

       

	// void sutUgol(Ball ball,Player awayPlayer1, Player awayPlayer2, double& xkick, double& ykick, double& intenzitet, bool& mozeSigurno)
	// {
	//	  bool moze;
 //  
 //                      //precisionShotMax(ball,k_fieldLength,0,xkick,ykick,intenzitet,moze);

 //  bool mozeLiGoreOdma,mozeLiGoreSaZaust;
 //  bool mozeLiDoleOdma,mozeLiDoleSaZaust;
 //  bool mozeLiDirektOdma,mozeLiDirektSaZaust;
 //  bool mozeLiDirektGSOdma,mozeLiDirektGSSaZaust;
 //  bool mozeLiDirektDSOdma,mozeLiDirektDSSaZaust;

 //  double vremeGore,vremeDole,vremeDirekt,vremeDirektGS,vremeDirektDS;

 //  sutGore(ball,awayPlayer1,awayPlayer2,mozeLiGoreOdma,mozeLiGoreSaZaust,vremeGore);
 //  sutDole(ball,awayPlayer1,awayPlayer2,mozeLiDoleOdma,mozeLiDoleSaZaust,vremeDole);
 //  sutDirekt(ball,awayPlayer1,awayPlayer2,mozeLiDirektOdma,mozeLiDirektSaZaust,vremeDirekt);
 //  sutDirektGS(ball,awayPlayer1,awayPlayer2,mozeLiDirektGSOdma,mozeLiDirektGSSaZaust,vremeDirektGS);
 //  sutDirektDS(ball,awayPlayer1,awayPlayer2,mozeLiDirektDSOdma,mozeLiDirektDSSaZaust,vremeDirektDS);

 //  double nizBlokada[5] = {vremeGore,vremeDole,vremeDirekt,vremeDirektGS,vremeDirektDS};

 //  int sut = maximum5(nizBlokada);

 // 
 //  mozeSigurno = true;

 //  if (mozeLiDirektOdma || mozeLiDirektSaZaust)
 //  {precisionShot(ball,k_fieldLength,0,7.5,xkick,ykick,intenzitet,moze);}// DIREKT

 //  else
 //  {
 //  
 //if (mozeLiDirektGSOdma || mozeLiDirektGSSaZaust)
 //{precisionShot(ball,k_fieldLength,k_goalWidth/4+35,7.5,xkick,ykick,intenzitet,moze); }// DIREKT GS

 //else
 // {
 //   if (mozeLiDirektDSOdma || mozeLiDirektDSSaZaust)
 //   {precisionShot(ball,k_fieldLength,-1*k_goalWidth/4-35,7.5,xkick,ykick,intenzitet,moze); }// DIREKT DS
	//   else
	//   {
	//	   if (mozeLiDoleOdma || mozeLiDoleSaZaust)
	//	   {
	//		   precisionShot(ball,k_fieldLength,-1*k_fieldWidth,7.5,xkick,ykick,intenzitet,moze);
	//	   }
	//	   else
	//		   if (mozeLiGoreOdma || mozeLiGoreSaZaust)
	//		   {
	//			   precisionShot(ball,k_fieldLength,k_fieldWidth,7.5,xkick,ykick,intenzitet,moze);
	//		   }
	//		   else
	//		   {
	//	   mozeSigurno = false;
	//	   if (0 == sut) {precisionShot(ball,k_fieldLength,k_fieldWidth,7.5,xkick,ykick,intenzitet,moze); /*LogFajl << "GORE" << endl;*/} // GORE
	//	   if (1 == sut) {precisionShot(ball,k_fieldLength,-1*k_fieldWidth,7.5,xkick,ykick,intenzitet,moze);/* LogFajl << "DOLE" << endl;*/}// DOLE
	//	   if (2 == sut) {precisionShot(ball,k_fieldLength,0,7.5,xkick,ykick,intenzitet,moze); /*LogFajl << "DIREKT" << endl;*/}// DIREKT
	//	   if (3 == sut) {precisionShot(ball,k_fieldLength,k_goalWidth/4+20,7.5,xkick,ykick,intenzitet,moze); }// DIREKT GS
	//	   if (4 == sut) {precisionShot(ball,k_fieldLength,-1*k_goalWidth/4-20,7.5,xkick,ykick,intenzitet,moze); }// DIREKT DS
	//		   }
	//   }
	//}
	// 
 //  }
	// }// sutUgol

	 
	 
	 void sutGore(Ball& ball, Player ap1, Player ap2, bool& mozeBezZaustavljanja, bool& mozeSaZaustavljanjem,double& vremeDoBloka, double& xBloka)
  {
   double xkick,ykick,intenzitet;
   bool mozeLiSut;
   precisionShot(ball,k_fieldLength,k_fieldWidth,7.5,xkick,ykick,intenzitet,mozeLiSut);

   //if (true == mozeLiSut)
   
    double xrez,yrez;

   xrez = k_fieldLength - ball.dohvatiXpoz();
   yrez = k_fieldWidth - ball.dohvatiYpoz();
   double koef;

   koef = sqrt(pow(xrez,2)+pow(yrez,2))/7.5;
   xrez /= koef;
   yrez /= koef;

   Ball fakeBall(ball);

   fakeBall.postaviXbrz(xrez);
   fakeBall.postaviYbrz(yrez);

   double x,y,vreme;
   bool moze1,moze2,moze3; 
   
   odrediTackuPresretanja(ap1,fakeBall,x,y,vreme,moze1,moze2,moze3,-3);

   double x2,y2,vreme2;
   bool moze12,moze22,moze32;
   odrediTackuPresretanja(ap2,fakeBall,x2,y2,vreme2,moze12,moze22,moze32,-3);

   if (mozeLiSut && (!moze2) && (!moze22)) 
   {
    mozeBezZaustavljanja = true;
    mozeSaZaustavljanjem = true;
   }
   else
   {
    if ((!mozeLiSut) && (!moze2) && (!moze22))
     {
    mozeBezZaustavljanja = false;
    mozeSaZaustavljanjem = true;
     }
    else 
     {
       mozeBezZaustavljanja = false;
       mozeSaZaustavljanjem = false;
     }
   }

   if (vreme < vreme2) {vremeDoBloka = vreme; xBloka = x;}
   else {vremeDoBloka = vreme2; xBloka = x2;}



     
    
	 }





void sutDole(Ball& ball, Player ap1, Player ap2, bool& mozeBezZaustavljanja, bool& mozeSaZaustavljanjem,double& vremeDoBloka, double& xBloka)
  {
   double xkick,ykick,intenzitet;
   bool mozeLiSut;
   precisionShot(ball,k_fieldLength,-1*k_fieldWidth,7.5,xkick,ykick,intenzitet,mozeLiSut);

   //if (true == mozeLiSut)
   
    double xrez,yrez;

   xrez = k_fieldLength - ball.dohvatiXpoz();
   yrez = -1*k_fieldWidth - ball.dohvatiYpoz();
   double koef;

   koef = sqrt(pow(xrez,2)+pow(yrez,2))/7.5;
   xrez /= koef;
   yrez /= koef;

   Ball fakeBall(ball);

   fakeBall.postaviXbrz(xrez);
   fakeBall.postaviYbrz(yrez);

   double x,y,vreme;
   bool moze1,moze2,moze3; 
   
   odrediTackuPresretanja(ap1,fakeBall,x,y,vreme,moze1,moze2,moze3,-3);

   double x2,y2,vreme2;
   bool moze12,moze22,moze32;
   odrediTackuPresretanja(ap2,fakeBall,x2,y2,vreme2,moze12,moze22,moze32,-3);

   if (mozeLiSut && (!moze2) && (!moze22)) 
   {
    mozeBezZaustavljanja = true;
    mozeSaZaustavljanjem = true;
   }
   else
   {
    if ((!mozeLiSut) && (!moze2) && (!moze22))
     {
    mozeBezZaustavljanja = false;
    mozeSaZaustavljanjem = true;
     }
    else 
     {
       mozeBezZaustavljanja = false;
       mozeSaZaustavljanjem = false;
     }
   }

   if (vreme < vreme2) {vremeDoBloka = vreme; xBloka = x;}
   else {vremeDoBloka = vreme2; xBloka = x2;}




 
     
    

  }
void sutDirekt(Ball& ball, Player ap1, Player ap2, bool& mozeBezZaustavljanja, bool& mozeSaZaustavljanjem,double& vremeDoBloka, double& xBloka)
  {
   double xkick,ykick,intenzitet;
   bool mozeLiSut;
   precisionShot(ball,k_fieldLength,0,7.5,xkick,ykick,intenzitet,mozeLiSut);

   //if (true == mozeLiSut)
   
    double xrez,yrez;

   xrez = k_fieldLength - ball.dohvatiXpoz();
   yrez =  -1*ball.dohvatiYpoz();
   double koef;

   koef = sqrt(pow(xrez,2)+pow(yrez,2))/7.5;
   xrez /= koef;
   yrez /= koef;

   Ball fakeBall(ball);

   fakeBall.postaviXbrz(xrez);
   fakeBall.postaviYbrz(yrez);

   double x,y,vreme;
   bool moze1,moze2,moze3; 
  
   odrediTackuPresretanja(ap1,fakeBall,x,y,vreme,moze1,moze2,moze3,-3);

   double x2,y2,vreme2;
   bool moze12,moze22,moze32;
   odrediTackuPresretanja(ap2,fakeBall,x2,y2,vreme2,moze12,moze22,moze32,-3);

   if (mozeLiSut && (!moze1) && (!moze12)) 
   {
    mozeBezZaustavljanja = true;
    mozeSaZaustavljanjem = true;
   }
   else
   {
    if ((!mozeLiSut) && (!moze1) && (!moze12))
     {
    mozeBezZaustavljanja = false;
    mozeSaZaustavljanjem = true;
     }
    else 
     {
       mozeBezZaustavljanja = false;
       mozeSaZaustavljanjem = false;
     }
   }

   if (vreme < vreme2) {vremeDoBloka = vreme; xBloka = x;}
   else {vremeDoBloka = vreme2; xBloka = x2;}
     
  }

void sutDirektGS(Ball& ball, Player ap1, Player ap2, bool& mozeBezZaustavljanja, bool& mozeSaZaustavljanjem,double& vremeDoBloka, double& xBloka)
  {
   double xkick,ykick,intenzitet;
   bool mozeLiSut;
   precisionShot(ball,k_fieldLength,0,7.5,xkick,ykick,intenzitet,mozeLiSut);

   //if (true == mozeLiSut)
   
    double xrez,yrez;

   xrez = k_fieldLength - ball.dohvatiXpoz();
   yrez = k_goalWidth/4 + 35 -1*ball.dohvatiYpoz();
   double koef;

   koef = sqrt(pow(xrez,2)+pow(yrez,2))/7.5;
   xrez /= koef;
   yrez /= koef;

   Ball fakeBall(ball);

   fakeBall.postaviXbrz(xrez);
   fakeBall.postaviYbrz(yrez);

   double x,y,vreme;
   bool moze1,moze2,moze3; 
   
   odrediTackuPresretanja(ap1,fakeBall,x,y,vreme,moze1,moze2,moze3,-3);

   double x2,y2,vreme2;
   bool moze12,moze22,moze32;
   odrediTackuPresretanja(ap2,fakeBall,x2,y2,vreme2,moze12,moze22,moze32,-3);

   if (mozeLiSut && (!moze1) && (!moze12)) 
   {
    mozeBezZaustavljanja = true;
    mozeSaZaustavljanjem = true;
   }
   else
   {
    if ((!mozeLiSut) && (!moze1) && (!moze12))
     {
    mozeBezZaustavljanja = false;
    mozeSaZaustavljanjem = true;
     }
    else 
     {
       mozeBezZaustavljanja = false;
       mozeSaZaustavljanjem = false;
     }
   }

  if (vreme < vreme2) {vremeDoBloka = vreme; xBloka = x;}
   else {vremeDoBloka = vreme2; xBloka = x2;}
     
  }



 void sutDirektDS(Ball& ball, Player ap1, Player ap2, bool& mozeBezZaustavljanja, bool& mozeSaZaustavljanjem,double& vremeDoBloka, double& xBloka)
  {
   double xkick,ykick,intenzitet;
   bool mozeLiSut;
   precisionShot(ball,k_fieldLength,0,7.5,xkick,ykick,intenzitet,mozeLiSut);

   //if (true == mozeLiSut)
   
    double xrez,yrez;

   xrez = k_fieldLength - ball.dohvatiXpoz();
   yrez = -1*k_goalWidth/4 - 35 -1*ball.dohvatiYpoz();
   double koef;

   koef = sqrt(pow(xrez,2)+pow(yrez,2))/7.5;
   xrez /= koef;
   yrez /= koef;

   Ball fakeBall(ball);

   fakeBall.postaviXbrz(xrez);
   fakeBall.postaviYbrz(yrez);

   double x,y,vreme;
   bool moze1,moze2,moze3; 
  
   odrediTackuPresretanja(ap1,fakeBall,x,y,vreme,moze1,moze2,moze3,-3);

   double x2,y2,vreme2;
   bool moze12,moze22,moze32;
   odrediTackuPresretanja(ap2,fakeBall,x2,y2,vreme2,moze12,moze22,moze32,-3);

   if (mozeLiSut && (!moze1) && (!moze12)) 
   {
    mozeBezZaustavljanja = true;
    mozeSaZaustavljanjem = true;
   }
   else
   {
    if ((!mozeLiSut) && (!moze1) && (!moze12))
     {
    mozeBezZaustavljanja = false;
    mozeSaZaustavljanjem = true;
     }
    else 
     {
       mozeBezZaustavljanja = false;
       mozeSaZaustavljanjem = false;
     }
   }

   if (vreme < vreme2) {vremeDoBloka = vreme; xBloka = x;}
   else {vremeDoBloka = vreme2; xBloka = x2;}
     
  }


	 double vectorLength(double x, double y) { return sqrt(pow(x,2) + pow(y,2)); }

	 double vectorDistance(double x1, double y1, double x2, double y2) { return vectorLength(x1-x2,y1-y2); }


	void vodiLoptu(const double xdest, const double ydest, Ball ball, Player onajStoVodi, Player ap1, Player ap2, double& xkick, double& ykick, double& intensity, bool& moze)
  {
   bool mozeBezZaust, mozeSaZaust;
   double vreme;
   sutOpstiDirektJa(ball,ap1,ap2,onajStoVodi,mozeBezZaust,mozeSaZaust,vreme,xdest,ydest,2);
   if (mozeBezZaust || mozeSaZaust) moze = true;
   else moze = false;

   double udaljenostAP1 = vectorLength(ball.dohvatiXpoz() - ap1.dohvatiXpoz() , ball.dohvatiYpoz() - ap1.dohvatiYpoz()) ;
         double udaljenostAP2 = vectorLength(ball.dohvatiXpoz() - ap2.dohvatiXpoz() , ball.dohvatiYpoz() - ap2.dohvatiYpoz()) ;
         double udaljenostBAP = (udaljenostAP1 < udaljenostAP2) ? udaljenostAP1 : udaljenostAP2;
      Player BAP = (udaljenostAP1 < udaljenostAP2) ? ap1 : ap2;
      if ((BAP.dohvatiXpoz() > ball.dohvatiXpoz()) && (udaljenostBAP < 2 * k_playerDiameter))
          moze = false;

   if (sqrt(pow(onajStoVodi.dohvatibrzX() - ball.dohvatiXbrz(),2)+pow(onajStoVodi.dohvatibrzY() - ball.dohvatiYbrz(),2)) > 1)
    precisionShot(ball,onajStoVodi.dohvatiXpoz()+5*onajStoVodi.dohvatibrzX(),onajStoVodi.dohvatiYpoz()+5*onajStoVodi.dohvatibrzY(),0.4,xkick,ykick,intensity,mozeBezZaust);
   else  precisionShot(ball,xdest,ydest,2,xkick,ykick,intensity,mozeBezZaust);
  }

	 bool dodaj(Ball lopta,Player dodavalac,Player dodavani,Player ap1,Player ap2,double& xKick,double& yKick,double& intenzitet)
	 {
		 bool mozeDodaj, mozeSut, mozeZSut, precisionMoze;
		 double vremeKontakt,
			 xDest = dodavani.dohvatiXpoz(),
			 yDest = dodavani.dohvatiYpoz();

		 sutOpstiDirekt(lopta,ap1,ap2,dodavani,mozeSut,mozeZSut,vremeKontakt,xDest,yDest);
		 if (mozeSut || mozeZSut)
		 {
			 mozeDodaj = true;
			 precisionShot(lopta,xDest,yDest,7.5,xKick,yKick,intenzitet,precisionMoze);
		 }
		 else
		 {
			 sutOpstiGore(lopta,ap1,ap2,dodavani,mozeSut,mozeZSut,vremeKontakt,xDest,yDest);
			 if (mozeSut || mozeZSut)
			 {
				 mozeDodaj = true;
				 precisionShot(lopta,xDest,k_fieldWidth - yDest,7.5,xKick,yKick,intenzitet,precisionMoze);
			 }
			 else
			 {
				 sutOpstiDole(lopta,ap1,ap2,dodavani,mozeSut,mozeZSut,vremeKontakt,xDest,yDest);
				 if (mozeSut || mozeZSut)
				 {
					 mozeDodaj = true;
					 precisionShot(lopta,xDest,-k_fieldWidth - yDest,7.5,xKick,yKick,intenzitet,precisionMoze);
				 }
				 else mozeDodaj = false;
			 }
		 }

		 return mozeDodaj;
	 }

	 //bool dodajSpec(Ball lopta,Player dodavalac,Player dodavani,Player ap1,Player ap2,double& xKick,double& yKick,double& intenzitet)
	 //{
		// Player njihovGornji = (ap1.dohvatiYpoz() > ap2.dohvatiYpoz()) ? ap1 : ap2;
		// Player njihovDonji = (ap1.dohvatiYpoz() <= ap2.dohvatiYpoz()) ? ap1 : ap2;

		// bool mozeDodaj, mozeSut, mozeZSut, precisionMoze;
		// double vremeKontakt;
		//	 //xDest = dodavani.dohvatiXpoz(),
		//	 //yDest = dodavani.dohvatiYpoz();

		// sutOpstiDirekt(lopta,ap1,ap2,dodavani,mozeSut,mozeZSut,vremeKontakt,(ap1.dohvatiXpoz() + ap2.dohvatiXpoz())/2,(ap1.dohvatiYpoz() + ap2.dohvatiYpoz())/2);
		// if (mozeSut || mozeZSut)
		// {
		//	 mozeDodaj = true;
		//	 precisionShot(lopta,(ap1.dohvatiXpoz() + ap2.dohvatiXpoz())/2,(ap1.dohvatiYpoz() + ap2.dohvatiYpoz())/2,7.5,xKick,yKick,intenzitet,precisionMoze);
		// }
		// else
		// {
		//	 sutOpstiGore(lopta,ap1,ap2,dodavani,mozeSut,mozeZSut,vremeKontakt,njihovGornji.dohvatiXpoz(),0.5*njihovGornji.dohvatiYpoz()+0.25*k_fieldWidth);
		//	 if (mozeSut || mozeZSut)
		//	 {
		//		 mozeDodaj = true;
		//		 precisionShot(lopta,njihovGornji.dohvatiXpoz(),0.5*njihovGornji.dohvatiYpoz()+0.25*k_fieldWidth,7.5,xKick,yKick,intenzitet,precisionMoze);
		//	 }
		//	 else
		//	 {
		//		 sutOpstiDole(lopta,ap1,ap2,dodavani,mozeSut,mozeZSut,vremeKontakt,njihovDonji.dohvatiXpoz(),0.5*njihovGornji.dohvatiYpoz()-0.25*k_fieldWidth);
		//		 if (mozeSut || mozeZSut)
		//		 {
		//			 mozeDodaj = true;
		//			 precisionShot(lopta,njihovDonji.dohvatiXpoz(),0.5*njihovGornji.dohvatiYpoz()-0.25*k_fieldWidth,7.5,xKick,yKick,intenzitet,precisionMoze);
		//		 }
		//		 else mozeDodaj = false;
		//	 }
		// }

		// return mozeDodaj;
	 //}


	 void sutUgol(Ball ball,Player awayPlayer1, Player awayPlayer2, double& xkick, double& ykick, double& intenzitet, bool& mozeSigurno)
  {
    bool moze;
   
                       //precisionShotMax(ball,k_fieldLength,0,xkick,ykick,intenzitet,moze);

   bool mozeLiGoreOdma,mozeLiGoreSaZaust;
   bool mozeLiDoleOdma,mozeLiDoleSaZaust;
   bool mozeLiDirektOdma,mozeLiDirektSaZaust;
   bool mozeLiDirektGSOdma,mozeLiDirektGSSaZaust;
   bool mozeLiDirektDSOdma,mozeLiDirektDSSaZaust;

   double vremeGore,vremeDole,vremeDirekt,vremeDirektGS,vremeDirektDS;
   double xBlokaGore,xBlokaDole,xBlokaDirekt,xBlokaDirektGS,xBlokaDirektDS;

   sutGore(ball,awayPlayer1,awayPlayer2,mozeLiGoreOdma,mozeLiGoreSaZaust,vremeGore,xBlokaGore);
   sutDole(ball,awayPlayer1,awayPlayer2,mozeLiDoleOdma,mozeLiDoleSaZaust,vremeDole,xBlokaDole);
   sutDirekt(ball,awayPlayer1,awayPlayer2,mozeLiDirektOdma,mozeLiDirektSaZaust,vremeDirekt,xBlokaDirekt);
   sutDirektGS(ball,awayPlayer1,awayPlayer2,mozeLiDirektGSOdma,mozeLiDirektGSSaZaust,vremeDirektGS,xBlokaDirektGS);
   sutDirektDS(ball,awayPlayer1,awayPlayer2,mozeLiDirektDSOdma,mozeLiDirektDSSaZaust,vremeDirektDS,xBlokaDirektDS);

   double nizBlokada[5] = {vremeGore,vremeDole,vremeDirekt,vremeDirektGS,vremeDirektDS};
   double nizXBlokova[5] = {xBlokaGore,xBlokaDole,xBlokaDirekt,xBlokaDirektGS,xBlokaDirektDS};

   int sut = maximum5(nizBlokada);
   int xBlokaMax = maximum5(nizXBlokova);

  
   mozeSigurno = true;

   if (mozeLiDirektOdma || mozeLiDirektSaZaust)
   {precisionShot(ball,k_fieldLength,0,7.5,xkick,ykick,intenzitet,moze);}// DIREKT

   else
   {
   
 if (mozeLiDirektGSOdma || mozeLiDirektGSSaZaust)
 {precisionShot(ball,k_fieldLength,k_goalWidth/4+35,7.5,xkick,ykick,intenzitet,moze); }// DIREKT GS

 else
  {
    if (mozeLiDirektDSOdma || mozeLiDirektDSSaZaust)
    {precisionShot(ball,k_fieldLength,-1*k_goalWidth/4-35,7.5,xkick,ykick,intenzitet,moze); }// DIREKT DS
    else
    {
     if (mozeLiDoleOdma || mozeLiDoleSaZaust)
     {
      precisionShot(ball,k_fieldLength,-1*k_fieldWidth,7.5,xkick,ykick,intenzitet,moze);
     }
     else
      if (mozeLiGoreOdma || mozeLiGoreSaZaust)
      {
       precisionShot(ball,k_fieldLength,k_fieldWidth,7.5,xkick,ykick,intenzitet,moze);
      }
      else
      {
     mozeSigurno = false;
     if (0 == xBlokaMax) {precisionShot(ball,k_fieldLength,k_fieldWidth,7.5,xkick,ykick,intenzitet,moze); /*LogFajl << "GORE" << endl;*/} // GORE
     if (1 == xBlokaMax) {precisionShot(ball,k_fieldLength,-1*k_fieldWidth,7.5,xkick,ykick,intenzitet,moze);/* LogFajl << "DOLE" << endl;*/}// DOLE
     if (2 == xBlokaMax) {precisionShot(ball,k_fieldLength,0,7.5,xkick,ykick,intenzitet,moze); /*LogFajl << "DIREKT" << endl;*/}// DIREKT
     if (3 == xBlokaMax) {precisionShot(ball,k_fieldLength,k_goalWidth/4+20,7.5,xkick,ykick,intenzitet,moze); }// DIREKT GS
     if (4 == xBlokaMax) {precisionShot(ball,k_fieldLength,-1*k_goalWidth/4-20,7.5,xkick,ykick,intenzitet,moze); }// DIREKT DS
      }
    }
 }
  
   }
  }// sutUgol

	 bool dodajSpec(Ball lopta,Player dodavalac,Player dodavani,Player ap1,Player ap2,double& xKick,double& yKick,double& intenzitet)
  {
   Player njihovGornji = (ap1.dohvatiYpoz() > ap2.dohvatiYpoz()) ? ap1 : ap2;
   Player njihovDonji = (ap1.dohvatiYpoz() <= ap2.dohvatiYpoz()) ? ap1 : ap2;

   bool mozeDodaj, mozeSut, mozeZSut, precisionMoze;
   double vremeKontakt;
    //xDest = dodavani.dohvatiXpoz(),
    //yDest = dodavani.dohvatiYpoz();

   double trecinax = dodavani.dohvatiXpoz()+(k_fieldLength - dodavani.dohvatiXpoz())/3 , trecinay = dodavani.dohvatiYpoz()/3;

   sutOpstiDirekt(lopta,ap1,ap2,dodavani,mozeSut,mozeZSut,vremeKontakt,trecinax,trecinay);
         if (mozeSut || mozeZSut)
   {
    mozeDodaj = true;
    precisionShot(lopta,trecinax,trecinay,7.5,xKick,yKick,intenzitet,precisionMoze);
   }
   else
   {
     sutOpstiGore(lopta,ap1,ap2,dodavani,mozeSut,mozeZSut,vremeKontakt,trecinax,trecinay);
     if(mozeSut || mozeZSut)
     {
      mozeDodaj = true;
      precisionShot(lopta,trecinax,k_fieldWidth - trecinay,7.5,xKick,yKick,intenzitet,precisionMoze);
     }
     else
    {
     sutOpstiDole(lopta,ap1,ap2,dodavani,mozeSut,mozeZSut,vremeKontakt,trecinax,trecinay);
     if (mozeSut || mozeZSut)
     {
      mozeDodaj = true;
      precisionShot(lopta,trecinax,-k_fieldWidth - trecinay,7.5,xKick,yKick,intenzitet,precisionMoze);
     }
     else
     {
       sutOpstiDirekt(lopta,ap1,ap2,dodavani,mozeSut,mozeZSut,vremeKontakt,(ap1.dohvatiXpoz() + ap2.dohvatiXpoz())/2,(ap1.dohvatiYpoz() + ap2.dohvatiYpoz())/2);
       if (mozeSut || mozeZSut)
       {
        mozeDodaj = true;
        precisionShot(lopta,(ap1.dohvatiXpoz() + ap2.dohvatiXpoz())/2,(ap1.dohvatiYpoz() + ap2.dohvatiYpoz())/2,7.5,xKick,yKick,intenzitet,precisionMoze);
       }
       else
       {
        sutOpstiDirekt(lopta,ap1,ap2,dodavani,mozeSut,mozeZSut,vremeKontakt,njihovGornji.dohvatiXpoz(),0.5*njihovGornji.dohvatiYpoz()+0.25*k_fieldWidth);
        if (mozeSut || mozeZSut)
        {
         mozeDodaj = true;
         precisionShot(lopta,njihovGornji.dohvatiXpoz(),0.5*njihovGornji.dohvatiYpoz()+0.25*k_fieldWidth,7.5,xKick,yKick,intenzitet,precisionMoze);
        }
        else
        {
         sutOpstiDirekt(lopta,ap1,ap2,dodavani,mozeSut,mozeZSut,vremeKontakt,njihovDonji.dohvatiXpoz(),0.5*njihovGornji.dohvatiYpoz()-0.25*k_fieldWidth);
         if (mozeSut || mozeZSut)
         {
          mozeDodaj = true;
          precisionShot(lopta,njihovDonji.dohvatiXpoz(),0.5*njihovGornji.dohvatiYpoz()-0.25*k_fieldWidth,7.5,xKick,yKick,intenzitet,precisionMoze);
         }
         else mozeDodaj = false;
        }
       }
     }
     }
   }
   return mozeDodaj;
  }

	 int maximumN(int niz[], int n)
	 {
		 int index = 0;
		 for (int i=1; i<n;i ++)
			 if (niz[i] > niz[index]) index = i;
		 return index;
	 }

#endif