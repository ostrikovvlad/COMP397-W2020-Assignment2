#include "Fruit.h"
#include "Game.h"

Fruit::Fruit()
{
	// Banana
	TheTextureManager::Instance()->load("../Assets/monk/banana.png", "banana",
		TheGame::Instance()->getRenderer());
	// Apple
	TheTextureManager::Instance()->load("../Assets/monk/apple.png", "apple",
		TheGame::Instance()->getRenderer());
	// Watermelon
	TheTextureManager::Instance()->load("../Assets/monk/watermelon.png", "watermelon",
		TheGame::Instance()->getRenderer());
	m_id = "banana";
	setType(BANANA);
	auto size = TheTextureManager::Instance()->getTextureSize("banana");
	setWidth(size.x);
	setHeight(size.y);
	reset();
	setIsColliding(false);
}

Fruit::~Fruit()
{
}

void Fruit::draw()
{
	const int xComponent = getPosition().x;
	const int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw(m_id, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Fruit::update()
{
	m_checkBounds();
	m_move();
}

void Fruit::clean()
{
}

void Fruit::reset()
{
	setPosition(640.0f + Util::RandomRange(100.0f, 250.0f), 420.0f);
	switch(rand() % 3)
	{
	case 0:
		setType(BANANA);
		m_id = "banana";
		break;
	case 1:
		setType(APPLE);
		m_id = "apple";
		break;
	case 2:
		setType(WATERMELON);
		m_id = "watermelon";
		break;
	}
}

void Fruit::m_move()
{
	setPosition(getPosition().x - 4, getPosition().y);
}

void Fruit::m_checkBounds()
{
	if(getPosition().x < -640.0f - getWidth())
	{
		reset();
	}
}
