#pragma once
#ifndef __COLOR_CHECK__
#define __COLOR_CHECK__
#include "DisplayObject.h"
#include "Color.h"

class ColorCheck : public DisplayObject
{
public:
	ColorCheck();
	~ColorCheck();
	void draw() override;
	void update() override;
	void clean() override;
	void setColor(Color color);
	void setAlpha(int alpha);
	Color getColor();
private:
	Color m_color;
	std::string m_id;
	int m_alpha;
};

#endif

