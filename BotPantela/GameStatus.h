#pragma once

#include <iostream>

using namespace std;

class GameStatus
{
private:
	//attributes
	bool p_repostavi;
	bool p_homePlaysOnRight;
	int p_homeGoals;
	int p_awayGoals;
	bool p_homeKicksOff;
	int p_mainCounter;
	int p_homeAttacksOnRight; // +-1  // ***

public:
	//constructor
	GameStatus ()
	{
		p_repostavi=false;
		p_homePlaysOnRight=false;
		p_homeGoals=0;
		p_awayGoals=0;
		p_homeKicksOff=false;
		p_mainCounter=0;
		p_homeAttacksOnRight = 1; // oppozite to p_homePlaysOnRight // ***
	}
	//postaviters
	void postaviRepostavi (const bool repostavi)
	{
		p_repostavi=repostavi;
	}
	void postaviHomePlaysOnRight (const bool homePlaysOnRight)
	{
		p_homePlaysOnRight=homePlaysOnRight;
	}
	void postaviHomeGoals (const int homeGoals)
	{
		p_homeGoals=homeGoals;
	}
	void postaviAwayGoals (const int awayGoals)
	{
		p_awayGoals=awayGoals;
	}
	void postaviHomeKicksOff (const bool homeKicksOff)
	{
		p_homeKicksOff=homeKicksOff;
	}
	void postaviMainCounter (const bool mainCounter)
	{
		p_mainCounter=mainCounter;
	}
	void postaviHomeAttacksOnRight (const int homeAttacksOnRight)
	{
		p_homeAttacksOnRight = homeAttacksOnRight;
	}
	//dohvatiters
	bool dohvatiRepostavi () const
	{
		return p_repostavi;
	}
	bool dohvatiHomePlaysOnRight () const
	{
		return p_homePlaysOnRight;
	}
	int dohvatiHomeGoals ()
	{
		return p_homeGoals;
	}
	int dohvatiAwayGoals ()
	{
		return p_awayGoals;
	}
	bool dohvatiHomeKicksOff ()
	{
		return p_homeKicksOff;
	}
	int dohvatiMainCounter ()
	{
		return p_mainCounter;
	}
	int dohvatiHomeAttacksOnRight ()
	{
		return p_homeAttacksOnRight;
	}
	//input
	void inputGameStatus ();

};

