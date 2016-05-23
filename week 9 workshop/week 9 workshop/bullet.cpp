#include "bullet.h"

bullet::bullet()
{
		posX = 100.0f;
		posY = 100.0f;
		speed = 0.0f;
		rotation = 0.0f;
		acceleration = 0.0f;
}
//passing by value
void bullet::bSetPosx(float pos_X)					//position X
		{
			posX = pos_X;
		}
float bullet::bGetPosx(void)
		{
			return posX;
		}
//passing by value
void bullet::bSetPosy(float pos_Y)
		{
			posY = pos_Y;
		}
float bullet::bGetPosy(void)
		{
			return posY;
		}
//passing by value
void bullet::bSetSpeed(float spd)
		{
			speed = spd;
		}
float bullet::bGetSpeed(void)
		{
			return speed;
		}
//passing by value
void bullet::bSetRot(float rot)
		{
			rotation = rot;
		}
float bullet::bGetRot(void)
		{
				return rotation;
		}
//passing by value
void bullet::bSetAcceleration(float accelerate)
		{
			acceleration = accelerate;
		}
float bullet::bGetAcceleration(void)
		{
			return acceleration;
		}