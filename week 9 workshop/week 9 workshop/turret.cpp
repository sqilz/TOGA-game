#include "turret.h"

turret::turret()
{
		posX = 0.0f;
		posY = 0.0f;
		rotation = 0.0f;
}
void turret::tSetPosx(float pos_X)					//position X
		{
			posX = pos_X;
		}
float turret::tGetPosx(void)
		{
			return posX;
		}

void turret::tSetPosy(float pos_Y)
		{
			posY = pos_Y;
		}
float turret::tGetPosy(void)
		{
			return posY;
		}
void turret::tSetRot(float rot)
		{
			rotation = rot;
		}
float turret::tGetRot(void)
		{
				return rotation;
		}