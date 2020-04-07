#pragma once
#ifndef __FRUIT__
#define __FRUIT__
#include "DisplayObject.h"

class Fruit : public DisplayObject
{
public:
	Fruit();
	~Fruit();
	void draw() override;
	void update() override;
	void clean() override;
	void reset();
private:
	std::string m_id;
	void m_move();
	void m_checkBounds();
	
};

#endif
