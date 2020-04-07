#include "ScoreBoardManager.h"
#include "Game.h"

ScoreBoardManager* ScoreBoardManager::m_pInstance = nullptr;

void ScoreBoardManager::Start()
{
	const SDL_Color black = { 0, 0, 0, 255 };
	m_pLivesLabel = new Label("Lives: 5", "Consolas", 24, black,
		glm::vec2(10.0f, 10.0f), TTF_STYLE_NORMAL, false);

	m_pScoreLabel = new Label("Fullness: 0", "Consolas", 24, black,
		glm::vec2(470.0f, 10.0f), TTF_STYLE_NORMAL, false);

	m_pFruitsLabel = new Label("B: 3 - A: 3 - W: 3", "Consolas", 24, black,
		glm::vec2(175.0f, 10.0f), TTF_STYLE_NORMAL, false);
}

void ScoreBoardManager::Draw() const
{
	m_pLivesLabel->draw();

	m_pScoreLabel->draw();

	m_pFruitsLabel->draw();
}

int ScoreBoardManager::getScore() const
{
	return m_score;
}

void ScoreBoardManager::setScore(const int new_score)
{
	m_score = new_score;
	
	m_pScoreLabel->setText("Score: " + std::to_string(m_score));
}

int ScoreBoardManager::getLives() const
{
	return m_lives;
}

void ScoreBoardManager::setLives(const int new_lives)
{
	m_lives = new_lives;
	if(m_lives < 1)
	{
		Game::Instance()->changeSceneState(END_SCENE);
	}
	m_pLivesLabel->setText("Lives: " + std::to_string(m_lives));
}

Color ScoreBoardManager::getColor() const
{
	return m_color;
}

void ScoreBoardManager::setColor(Color new_color)
{
	m_color = new_color;
}

int ScoreBoardManager::getBananas() const
{
	return m_bananas;
}

void ScoreBoardManager::setBananas(int new_bananas)
{
	m_bananas = new_bananas;
	m_pFruitsLabel->setText("B: " + std::to_string(getBananas())
		+ " - A: " + std::to_string(getApples()) + " - W: " + std::to_string(getMelons()));
}

int ScoreBoardManager::getApples() const
{
	return m_apples;
	
}

void ScoreBoardManager::setApples(int new_apples)
{
	m_apples = new_apples;
	m_pFruitsLabel->setText("B: " + std::to_string(getBananas())
		+ " - A: " + std::to_string(getApples()) + " - W: " + std::to_string(getMelons()));
}

int ScoreBoardManager::getMelons() const
{
	return m_melons;
}

void ScoreBoardManager::setMelons(int new_melons)
{
	m_melons = new_melons;
	m_pFruitsLabel->setText("B: " + std::to_string(getBananas())
		+ " - A: " + std::to_string(getApples()) + " - W: " + std::to_string(getMelons()));
}

ScoreBoardManager::ScoreBoardManager()
{
	Start();
	setScore(Config::SCORE);
	setLives(Config::LIVES);
	setApples(3);
	setBananas(3);
	setMelons(3);
}

ScoreBoardManager::~ScoreBoardManager()
= default;
