#include "powerUps.h"

powerUps::powerUps()
{
	
	posX = 0.0f;
	posY = 0.0f;
	rotation = 0.0f;

}
powerUps::~powerUps()
{
	
}
void powerUps::setPos_x(float pos_x)
	{
		posX = pos_x;
	}
float powerUps::getPos_x(void)
	{
		return posX;
	}

void powerUps::setPos_y(float pos_y)
	{
		posY = pos_y;
	}
float powerUps::getPos_y(void)
	{
		return posY;
	}
void powerUps::setRotation(float rot)
	{
		rotation = rot;
	}
float powerUps::getRotation(void)
	{
		return rotation;
	}

