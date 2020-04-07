#include "ColorCheck.h"
#include "Game.h"
#include "ScoreBoardManager.h"

ColorCheck::ColorCheck()
{
	TheTextureManager::Instance()->load("../Assets/monk/green.png", "green",
		TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/monk/red.png", "red",
		TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/monk/yellow.png", "yellow",
		TheGame::Instance()->getRenderer());

	auto size = TheTextureManager::Instance()->getTextureSize("green");
	setWidth(size.x);
	setHeight(size.y);
	m_id = "green";
	m_alpha = 0;
	setPosition(320.0f, 75.0f);
}

ColorCheck::~ColorCheck()
{
}

void ColorCheck::draw()
{
	const int xComponent = getPosition().x;
	const int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw(m_id, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, m_alpha, true);
}

void ColorCheck::update()
{
	m_color = ScoreBoardManager::Instance()->getColor();
	if(m_color == RED)
	{
		m_id = "red";
	} else if(m_color == GREEN)
	{
		m_id = "green";
	}else if(m_color == YELLOW)
	{
		m_id = "yellow";
	}
}

void ColorCheck::clean()
{
}

void ColorCheck::setColor(Color color)
{
	m_color = color;
}

void ColorCheck::setAlpha(int alpha)
{
	m_alpha = alpha;
}

Color ColorCheck::getColor()
{
	return m_color;
}
