#pragma once

#include <iostream>

using namespace std;

class GameStatus
{
private:
	//attributes
	bool m_reset;
	bool m_homePlaysOnRight;
	int m_homeGoals;
	int m_awayGoals;
	bool m_homeKicksOff;
	int m_mainCounter;
	int m_homeAttacksOnRight; // +-1  // ***

public:
	//constructor
	GameStatus ()
	{
		m_reset=false;
		m_homePlaysOnRight=false;
		m_homeGoals=0;
		m_awayGoals=0;
		m_homeKicksOff=false;
		m_mainCounter=0;
		m_homeAttacksOnRight = 1; // opposite to m_homePlaysOnRight // ***
	}
	//setters
	void setReset (const bool reset)
	{
		m_reset=reset;
	}
	void setHomePlaysOnRight (const bool homePlaysOnRight)
	{
		m_homePlaysOnRight=homePlaysOnRight;
	}
	void setHomeGoals (const int homeGoals)
	{
		m_homeGoals=homeGoals;
	}
	void setAwayGoals (const int awayGoals)
	{
		m_awayGoals=awayGoals;
	}
	void setHomeKicksOff (const bool homeKicksOff)
	{
		m_homeKicksOff=homeKicksOff;
	}
	void setMainCounter (const bool mainCounter)
	{
		m_mainCounter=mainCounter;
	}
	void setHomeAttacksOnRight (const int homeAttacksOnRight)
	{
		m_homeAttacksOnRight = homeAttacksOnRight;
	}
	//getters
	bool getReset () const
	{
		return m_reset;
	}
	bool getHomePlaysOnRight () const
	{
		return m_homePlaysOnRight;
	}
	int getHomeGoals ()
	{
		return m_homeGoals;
	}
	int getAwayGoals ()
	{
		return m_awayGoals;
	}
	bool getHomeKicksOff ()
	{
		return m_homeKicksOff;
	}
	int getMainCounter ()
	{
		return m_mainCounter;
	}
	int getHomeAttacksOnRight ()
	{
		return m_homeAttacksOnRight;
	}
	//input
	void inputGameStatus ();

};

