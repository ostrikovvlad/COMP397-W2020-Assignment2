#include "StartScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
{
}

void StartScene::draw()
{
	//m_pOcean->draw();
	//m_pBackground->draw();
	m_pStartLabel->draw();
	m_pStartLabel2->draw();
	m_pStartLabel3->draw();
	m_pStartLabel4->draw();
	m_pStartLabel5->draw();
	m_pStartButton->draw();
	
}

void StartScene::update()
{
	//m_pOcean->update();
	//m_pBackground->update();
	m_pStartButton->setMousePosition(m_mousePosition);
	m_pStartButton->ButtonClick();
}

void StartScene::clean()
{
	//delete m_pStartLabel;
	
	removeAllChildren();
}

void StartScene::handleEvents()
{
	int wheel = 0;
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;





			
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			}
			break;

		default:
			break;
		}
	}
}

// this function is used for initialization
void StartScene::start()
{
	//m_pOcean = new Ocean();
	//addChild(m_pOcean);
	//
	//m_pBackground = new Background();
	//addChild(m_pBackground);

	
	SDL_Color black = { 0, 0, 0, 255 };
	m_pStartLabel = new Label("Dodge rocks by jumping. To dodge clouds - eat fruit of the same color.", "Consolas", 14, black, 
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, 30.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	m_pStartLabel2 = new Label("Press 1 or B to eat a banana - dodge of yellow clouds.", "Consolas", 14, black,
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, 50.0f));
	m_pStartLabel2->setParent(this);
	addChild(m_pStartLabel2);

	m_pStartLabel3 = new Label("Press 2 or A to eat an apple - dodge of red clouds.", "Consolas", 14, black,
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, 70.0f));
	m_pStartLabel3->setParent(this);
	addChild(m_pStartLabel3);

	m_pStartLabel4 = new Label("Press 3 or W to eat a watermelon - dodge of green clouds.", "Consolas", 14, black,
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, 90.0f));
	m_pStartLabel4->setParent(this);
	addChild(m_pStartLabel4);

	m_pStartLabel5 = new Label("Press SPACE for a jump.", "Consolas", 14, black,
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, 110.0f));
	m_pStartLabel5->setParent(this);
	addChild(m_pStartLabel5);

	m_pStartButton = new StartButton();
	m_pStartButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));
	addChild(m_pStartButton);
}

glm::vec2 StartScene::getMousePosition()
{
	return m_mousePosition;
}
