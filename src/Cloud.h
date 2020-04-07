#pragma once
#ifndef __CLOUD__
#define __CLOUD__
#include "DisplayObject.h"
#include "Color.h"

class Cloud : public DisplayObject
{
public:
	Cloud();
	~Cloud();
	
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	Color getColor();
private:
	void m_reset();
	void m_move();
	void m_checkBounds();
	Color m_color;
	std::string m_id;
	float m_speed;
};
#endif /* defined (__CLOUD__) */

