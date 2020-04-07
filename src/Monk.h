#pragma once
#ifndef __MONK__
#define __MONK__
#include "DisplayObject.h"
#include "Color.h"

class Monk : public DisplayObject
{
public:
	Monk();
	~Monk();
	void draw() override;
	void update() override;
	void clean() override;
	void changeColor(std::string color);
	void takeDamage();
	Color getColor();
	void setColor(Color color);
	void jump();

private:
	Color m_color;
	std::string m_id;
	int m_frameNumber;
	int m_currentRow;
	int m_currentFrame;
	bool m_isJumping;
	bool m_isGrounded;
};

#endif 
