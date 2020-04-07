#include "Background.h"
#include "Game.h"

Background::Background()
{
	TheTextureManager::Instance()->load("../Assets/monk/background.png", "background",
		TheGame::Instance()->getRenderer());

	auto size = TheTextureManager::Instance()->getTextureSize("background");
	setWidth(size.x);
	setHeight(size.y);
	setType(BACKGROUND);
	setIsColliding(false);
	setPosition(0.0f, 0.0f);
}

Background::~Background() = default;

void Background::draw()
{
	const int xComponent = getPosition().x;
	const int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("background", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), false);
}

void Background::update()
{
	glm::vec2 currentPosition = getPosition();
	glm::vec2 newPosition = currentPosition;
	newPosition.x -= 2.0f;
	//std::cout << "position x: " << currentPosition.x << std::endl;
	setPosition(newPosition);
	if(getPosition().x <= -640)
	{
		setPosition(0.0f, 0.0f);
	}
}

void Background::clean()
{
}
