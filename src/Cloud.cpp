#include "Cloud.h"
#include "Game.h"

Cloud::Cloud()
{
	// Red
	TheTextureManager::Instance()->load("../Assets/monk/cloudR.png",
		"cloudR", TheGame::Instance()->getRenderer());
	// Green
	TheTextureManager::Instance()->load("../Assets/monk/cloudG.png",
		"cloudG", TheGame::Instance()->getRenderer());
	// Yellow
	TheTextureManager::Instance()->load("../Assets/monk/cloudY.png",
		"cloudY", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	const auto size = TheTextureManager::Instance()->getTextureSize("cloudY");
	setWidth(size.x);
	setHeight(size.y);
	switch(rand() % 3)
	{
	case 0:
		m_id = "cloudR";
		m_color = RED;
		break;
	case 1:
		m_id = "cloudG";
		m_color = GREEN;
		break;
	case 2:
		m_id = "cloudY";
		m_color = YELLOW;
		break;
	}
	m_reset();
	setIsColliding(false);
	setType(GameObjectType::CLOUD);
	setPosition(640.0f + getWidth(), 350);
	

	TheSoundManager::Instance()->load("../Assets/audio/thunder.ogg", "thunder", SOUND_SFX);
}

Cloud::~Cloud()
= default;

void Cloud::draw()
{
	const int xComponent = getPosition().x;
	const int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw(m_id, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 128, true);
}

void Cloud::update()
{
	m_move();
	m_checkBounds();
}

void Cloud::clean()
{
}

Color Cloud::getColor()
{
	return m_color;
}

void Cloud::m_reset()
{
	setPosition(640.0f + Util::RandomRange(100.0f, 200.0f), getPosition().y);
	m_speed = Util::RandomRange(3.0f, 6.0f);
	switch (rand() % 3)
	{
	case 0:
		m_id = "cloudR";
		m_color = RED;
		break;
	case 1:
		m_id = "cloudG";
		m_color = GREEN;
		break;
	case 2:
		m_id = "cloudY";
		m_color = YELLOW;
		break;
	}
}

void Cloud::m_move()
{
	const int xPos = getPosition().x - m_speed;
	const int yPos = getPosition().y;
	setPosition(glm::vec2(xPos, yPos));
}

void Cloud::m_checkBounds()
{
	if (getPosition().x < -(Config::SCREEN_WIDTH + getWidth()))
	{
		m_reset();
	}
}
