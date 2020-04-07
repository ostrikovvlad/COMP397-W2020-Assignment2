#pragma once
#ifndef __ROCK__
#define __ROCK__
#include "DisplayObject.h"

class Rock : public DisplayObject
{
public:
	Rock();
	~Rock();
	void draw() override;
	void update() override;
	void clean() override;
	void reset();

private:

	int m_currentRow;
	int m_currentFrame;
	int m_frameNumber;
};

#endif

