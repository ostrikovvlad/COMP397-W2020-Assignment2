#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "Plane.h"
#include "Island.h"
#include "Ocean.h"
#include "Cloud.h"
#include "Config.h"
#include "Background.h"
#include "Monk.h"
#include "Rock.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;
	Cloud* clouds[2];

	// getters
	glm::vec2 getMousePosition();

private:
	// game objects
	//Plane* m_pPlane;
	//Island* m_pIsland;
	//Ocean* m_pOcean;

	//int m_cloudNum = Config::CLOUD_NUM;
	//std::vector<Cloud*> m_pClouds;
	//void m_buildClouds();

	Background* m_pBackground;
	Monk* m_pMonk;
	Rock* m_pRock;
	
	// private data member
	glm::vec2 m_mousePosition;
	
	
};

#endif /* defined (__LEVEL_1_SCENE__) */
