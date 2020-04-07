#include "Game.h"
#include "Monk.h"
#include "ScoreBoardManager.h"

Monk::Monk()
{
	TheTextureManager::Instance()->load("../Assets/monk/monk.png",
		"monk", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/monk/jump.png",
		"jump", TheGame::Instance()->getRenderer());
	// Yellow
	TheTextureManager::Instance()->load("../Assets/monk/monkY.png",
		"monkY", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/monk/jumpY.png",
		"jumpY", TheGame::Instance()->getRenderer());
	// Green
	TheTextureManager::Instance()->load("../Assets/monk/monkG.png",
		"monkG", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/monk/jumpG.png",
		"jumpG", TheGame::Instance()->getRenderer());
	// Red
	TheTextureManager::Instance()->load("../Assets/monk/monkR.png",
		"monkR", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/monk/jumpR.png",
		"jumpR", TheGame::Instance()->getRenderer());
	// Framesize 64x64

	auto size = TheTextureManager::Instance()->getTextureSize("monk");
	setWidth(size.x);
	setHeight(size.y);

	setIsColliding(false);
	setType(MONK);
	setPosition(200.0f, 400.0f);
	
	m_id = "monk";
	m_frameNumber = 8;
	m_currentRow = 0;
	m_currentFrame = 0;
	m_isJumping = false;
	m_isGrounded = true;
}

Monk::~Monk()
= default;

void Monk::draw()
{
	const int xComponent = getPosition().x;
	const int yComponent = getPosition().y;

	if(m_isGrounded)
	{
			TheTextureManager::Instance()->drawFrame(m_id, xComponent,
		yComponent, 64, 64, m_currentRow,
		m_currentFrame, m_frameNumber, 1, 1.0f,
		TheGame::Instance()->getRenderer(), 0, 255, true);
	}else
	{
		TheTextureManager::Instance()->draw(m_id, xComponent, yComponent,
			TheGame::Instance()->getRenderer(), true);
	}

}

void Monk::update()
{
	m_color = ScoreBoardManager::Instance()->getColor();

	
	if(m_isGrounded)
	{
		if (m_color == RED)
		{
			m_id = "monkR";
		}
		else if (m_color == GREEN)
		{
			m_id = "monkG";
		}
		else if (m_color == YELLOW)
		{
			m_id = "monkY";
		}
		auto size = TheTextureManager::Instance()->getTextureSize("monk");
		setWidth(size.x);
		setHeight(size.y);
		m_frameNumber = 8;
	}
	else if (m_isJumping)
	{
		if (m_color == RED)
		{
			m_id = "jumpR";
		}
		else if (m_color == GREEN)
		{
			m_id = "jumpG";
		}
		else if (m_color == YELLOW)
		{
			m_id = "jumpY";
		}
		auto size = TheTextureManager::Instance()->getTextureSize("jump");
		setWidth(size.x);
		setHeight(size.y);
		//m_frameNumber = 1;
	}
	if(m_isJumping && getPosition().y != 300.0f)
	{
		m_isGrounded = false;
		setPosition(getPosition().x, getPosition().y - 2.0f);
	}
	else if(getPosition().y <= 400.0f)
	{
		m_isJumping = false;
		setPosition(getPosition().x, getPosition().y + 2.0f);
	}
	if(getPosition().y >= 400.0f && !m_isJumping)
	{
		m_isGrounded = true;
		if (m_color == NO_COLOR)
		{
			m_id = "monk";
		}
		else if (m_color == RED)
		{
			m_id = "monkR";
		}
		else if (m_color == YELLOW)
		{
			m_id = "monkY";
		}
		else if (m_color == GREEN)
		{
			m_id = "monkG";
		}
		
	}
}

void Monk::clean()
{
}

void Monk::changeColor(std::string color)
{
}

void Monk::takeDamage()
{
}

Color Monk::getColor()
{
	return m_color;
}

void Monk::setColor(Color color)
{
	m_color = color;
}

void Monk::jump()
{
	if(!m_isJumping && m_isGrounded)
	{
		if(m_color == NO_COLOR)
		{
			m_id = "jump";
		}else if(m_color == RED)
		{
			m_id = "jumpR";
		}else if(m_color == YELLOW)
		{
			m_id = "jumpY";
		}else if(m_color == GREEN)
		{
			m_id = "jumpG";
		}
		
		
	    m_isJumping = true;
	}

}
