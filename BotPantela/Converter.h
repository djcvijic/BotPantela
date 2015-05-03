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
                  hp1.setYPos(263-hp1.getYPos());
				  hp2.setYPos(263-hp2.getYPos());			  
				  ap1.setYPos(263-ap1.getYPos());
				  ap2.setYPos(263-ap2.getYPos());	
				  b.setYPos(263-b.getYPos()); 
				  b.setYVel(-b.getYVel());

			  if(true == g.getHomePlaysOnRight())
			  {
			  // X koordinate:
				  hp1.setXPos(796-hp1.getXPos());		  
				  hp2.setXPos(796-hp2.getXPos());				  
				  ap1.setXPos(796-ap1.getXPos());				  
				  ap2.setXPos(796-ap2.getXPos());				  
				  b.setXPos(796-b.getXPos());				  
				  b.setXVel(-b.getXVel());			  		  
		      }
		  }



		  void convertOut (Player& hp1, Player& hp2, Player& ap1, Player& ap2, Ball& b, GameStatus& g)
		  {
			      // Y koordinate:
                  hp1.setYPos(263-hp1.getYPos());
				  hp2.setYPos(263-hp2.getYPos());			  
				  ap1.setYPos(263-ap1.getYPos());
				  ap2.setYPos(263-ap2.getYPos());	
				  b.setYPos(263-b.getYPos()); 
				  b.setYVel(-b.getYVel());

				  // i jos Y koordinata:
				  hp1.setDestinationY(263-hp1.getDestinationY());
				  hp2.setDestinationY(263-hp2.getDestinationY());
				  ap1.setDestinationY(263-ap1.getDestinationY());
				  ap2.setDestinationY(263-ap2.getDestinationY());
				  hp1.setKickVectorY(-hp1.getKickVectorY());
				  hp2.setKickVectorY(-hp2.getKickVectorY());
			  

			  if (true == g.getHomePlaysOnRight())
			  {
				  // X koordinate:
				  hp1.setXPos(796-hp1.getXPos());		  
				  hp2.setXPos(796-hp2.getXPos());				  
				  ap1.setXPos(796-ap1.getXPos());				  
				  ap2.setXPos(796-ap2.getXPos());				  
				  b.setXPos(796-b.getXPos());				  
				  b.setXVel(-b.getXVel());

				  // i jos X koordinata:
				  hp1.setDestinationX(796-hp1.getDestinationX());
				  hp2.setDestinationX(796-hp2.getDestinationX());
				  ap1.setDestinationX(796-ap1.getDestinationX());
				  ap2.setDestinationX(796-ap2.getDestinationX());
				  hp1.setKickVectorX(-hp1.getKickVectorX());
				  hp2.setKickVectorX(-hp2.getKickVectorX());

				 
			      
			  }
		  }

			 
	  };


      #endif