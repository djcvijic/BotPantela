#include "GameStatus.h"
#include "Vreme.h"

void GameStatus::inputGameStatus ()
{
	cin >> m_reset;  // <--- OVO SE IZVRSAVA CELU VECNOST !!!
	if (m_reset)
	{
		m_mainCounter=0;
		cin >> m_homePlaysOnRight;
		cin >> m_homeGoals;
		cin >> m_awayGoals;
		cin >> m_homeKicksOff; // laGenteEstaMuiLoca::WTF()???

		if (0 == m_homePlaysOnRight) setHomeAttacksOnRight(1);
		else setHomeAttacksOnRight(-1);
	}
	else
	{
		m_mainCounter++;
	}
}