#include "Rock.h"
#include "Game.h"

Rock::Rock()
{
	TheTextureManager::Instance()->load("../Assets/monk/rock_round.png", "rock",
		TheGame::Instance()->getRenderer());
	//Framesize 32x32
	auto size = TheTextureManager::Instance()->getTextureSize("rock");
	setWidth(size.x);
	setHeight(size.y);

	setIsColliding(false);
	setPosition(700.0f, 420.0f);

	m_currentRow = 0;
	m_currentFrame = 0;
	m_frameNumber = 4;
}

Rock::~Rock()
{
}

void Rock::draw()
{
	const int xComponent = getPosition().x;
	const int yComponent = getPosition().y;

	TheTextureManager::Instance()->drawFrame("rock", xComponent,
		yComponent, 32, 32, m_currentRow,
		m_currentFrame, m_frameNumber, 1, 1.0f,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Rock::update()
{
	glm::vec2 currentPosition = getPosition();
	setPosition(currentPosition.x - 4.0f, currentPosition.y);

	if(getPosition().x <= -700.0f)
	{
		reset();
	}
}

void Rock::clean()
{
}

void Rock::reset()
{
	setPosition((rand() % 200) + 640.0f, getPosition().y);
}
