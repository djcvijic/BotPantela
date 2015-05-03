      #ifndef Converter_h
	  #define Converter_h

      #include <iostream>

	#include "Constants.h"

	#include "GameStatus.h"
	#include "Player.h"
	#include "Ball.h"
	#include <cmath>

    using namespace std;

      class Converter
	  {
	  public:

		  void convertIn (Player& hp1, Player& hp2, Player& ap1, Player& ap2, Ball& b, GameStatus& g)
		  {
				  // Y koordinate:
                  hp1.postaviYpoz(263-hp1.dohvatiYpoz());
				  hp2.postaviYpoz(263-hp2.dohvatiYpoz());			  
				  ap1.postaviYpoz(263-ap1.dohvatiYpoz());
				  ap2.postaviYpoz(263-ap2.dohvatiYpoz());	
				  b.postaviYpoz(263-b.dohvatiYpoz()); 
				  b.postaviYbrz(-b.dohvatiYbrz());

			  if(true == g.dohvatiHomePlaysOnRight())
			  {
			  // X koordinate:
				  hp1.postaviXpoz(796-hp1.dohvatiXpoz());		  
				  hp2.postaviXpoz(796-hp2.dohvatiXpoz());				  
				  ap1.postaviXpoz(796-ap1.dohvatiXpoz());				  
				  ap2.postaviXpoz(796-ap2.dohvatiXpoz());				  
				  b.postaviXpoz(796-b.dohvatiXpoz());				  
				  b.postaviXbrz(-b.dohvatiXbrz());			  		  
		      }
		  }



		  void convertOut (Player& hp1, Player& hp2, Player& ap1, Player& ap2, Ball& b, GameStatus& g)
		  {
			      // Y koordinate:
                  hp1.postaviYpoz(263-hp1.dohvatiYpoz());
				  hp2.postaviYpoz(263-hp2.dohvatiYpoz());			  
				  ap1.postaviYpoz(263-ap1.dohvatiYpoz());
				  ap2.postaviYpoz(263-ap2.dohvatiYpoz());	
				  b.postaviYpoz(263-b.dohvatiYpoz()); 
				  b.postaviYbrz(-b.dohvatiYbrz());

				  // i jos Y koordinata:
				  hp1.postaviDestinationY(263-hp1.dohvatiDestinationY());
				  hp2.postaviDestinationY(263-hp2.dohvatiDestinationY());
				  ap1.postaviDestinationY(263-ap1.dohvatiDestinationY());
				  ap2.postaviDestinationY(263-ap2.dohvatiDestinationY());
				  hp1.postaviKickVectorY(-hp1.dohvatiKickVectorY());
				  hp2.postaviKickVectorY(-hp2.dohvatiKickVectorY());
			  

			  if (true == g.dohvatiHomePlaysOnRight())
			  {
				  // X koordinate:
				  hp1.postaviXpoz(796-hp1.dohvatiXpoz());		  
				  hp2.postaviXpoz(796-hp2.dohvatiXpoz());				  
				  ap1.postaviXpoz(796-ap1.dohvatiXpoz());				  
				  ap2.postaviXpoz(796-ap2.dohvatiXpoz());				  
				  b.postaviXpoz(796-b.dohvatiXpoz());				  
				  b.postaviXbrz(-b.dohvatiXbrz());

				  // i jos X koordinata:
				  hp1.postaviDestinationX(796-hp1.dohvatiDestinationX());
				  hp2.postaviDestinationX(796-hp2.dohvatiDestinationX());
				  ap1.postaviDestinationX(796-ap1.dohvatiDestinationX());
				  ap2.postaviDestinationX(796-ap2.dohvatiDestinationX());
				  hp1.postaviKickVectorX(-hp1.dohvatiKickVectorX());
				  hp2.postaviKickVectorX(-hp2.dohvatiKickVectorX());

				 
			      
			  }
		  }

			 
	  };


      #endif