#include "GameStatus.h"

void GameStatus::inputGameStatus ()
{
	cin >> p_repostavi;  // <--- OVO SE IZVRSAVA CELU VECNOST !!!
	if (p_repostavi)
	{
		p_mainCounter=0;
		cin >> p_homePlaysOnRight;
		cin >> p_homeGoals;
		cin >> p_awayGoals;
		cin >> p_homeKicksOff; // laGenteEstaMuiLoca::WTF()???

		if (0 == p_homePlaysOnRight) postaviHomeAttacksOnRight(1);
		else postaviHomeAttacksOnRight(-1);
	}
	else
	{
		p_mainCounter++;
	}
}