#pragma once
#ifndef __SCORE_BOARD_MANAGER__
#define __SCORE_BOARD_MANAGER__

#include "Config.h"
#include "Label.h"
#include "Color.h"

class ScoreBoardManager
{
public:
	// singleton
	static ScoreBoardManager* Instance()
	{
		if(m_pInstance == nullptr)
		{
			m_pInstance = new ScoreBoardManager();
			return m_pInstance;
		}
		return m_pInstance;
	}

	void Start();
	void Draw() const;

	// getters and setters
	int getScore() const;
	void setScore(int new_score);

	int getLives() const;
	void setLives(int new_lives);

	Color getColor() const;	
	void setColor(Color new_color);

	int getBananas() const;
	void setBananas(int new_bananas);

	int getApples() const;
	void setApples(int new_apples);

	int getMelons() const;
	void setMelons(int new_melons);
	
	
private:
	ScoreBoardManager();
	~ScoreBoardManager();

	int m_score{};
	int m_lives{};
	Color m_color{};
	int m_bananas{};
	int m_apples{};
	int m_melons{};
	

	Label* m_pLivesLabel{};
	Label* m_pScoreLabel{};
	Label* m_pFruitsLabel{};
	
	static ScoreBoardManager* m_pInstance;
};
#endif /* defined (__SCORE_BOARD_MANAGER__) */