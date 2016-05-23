#include "player_Tank.h"

player_Tank::player_Tank()
{										// constructor
		
		Bullet = new bullet[2];
		Turret = new turret[2];
		

		position_x = 0.0f;
		position_y = 0.0f;
		scale = 0.0f;
		velocity = 0.0f;
		rotation = 0.0f;
		speed = 0.0f;
		acceleration = 0.0f;
		maxSpeed = 0.03f;
		minSpeed = -0.03f;
		
		up = false;
		down = false;
		left = false;
		right = false;
		fire = false;
		turretLeft = false;
		turretRight = false;
		reloaded = true;
		invincible = false;
}
player_Tank::~player_Tank()
{
	delete [] Bullet;
	Bullet = nullptr;

	delete [] Turret;
	Turret = nullptr;


}
		void player_Tank::setPos_x(float posX)					//position X
		{
			position_x = posX;
		}
		float player_Tank::getPos_x(void)
		{
			return position_x;
		}

		void player_Tank::setPos_y(float posY)				//position Y
		{
			position_y = posY;
		}												
		float player_Tank::getPos_y(void)
		{
			return position_y;
		}

		void player_Tank  :: setScale(float scal)				//scale
		{
			scale = scal;
		}
		float player_Tank :: getScale(void)
		{
			return scale;
		}

		void player_Tank  :: setVelocity(float vel)				//velocity
		{	
			velocity = vel;
		}
		float player_Tank :: getVelocity(void)
		{
			return velocity;
		}
		 
		void player_Tank  :: setRotation(float rot)				//rotation
		{
			rotation = rot;
		}
		float player_Tank :: getRotation(void)
		{
			return rotation;
		}

		void player_Tank  :: setSpeed(float setSpeed)			//speed
		{
			speed = setSpeed;
		}
		float player_Tank :: getSpeed(void)
		{
			return speed;
		}

		void player_Tank  :: setAcceleration(float accel)		//acceleration
		{
			acceleration = accel;
		}
		float player_Tank :: getAcceleration(void)
		{
			return acceleration;
		}

		void player_Tank  :: setMaxSpeed(float speedMax)		//maxSpeed
		{
			maxSpeed = speedMax;
		}
		float player_Tank :: getMaxSpeed(void)
		{
			return maxSpeed;
		}

		void player_Tank  :: setMinSpeed(float speedMin)		//minspeed
		{
			minSpeed = speedMin;
		}
		float player_Tank :: getMinSpeed(void)
		{
			return minSpeed;
		}

		void player_Tank :: setUp(bool setUp)					//Key Up
		{
			up = setUp;
		}
		bool player_Tank::getUp(void)
		{
			return up;
		}

		void player_Tank :: setDown(bool setDown)				//Key Down
		{
			down = setDown;
		}
		bool player_Tank :: getDown(void)
		{
			return down;
		}

		void player_Tank :: setLeft(bool setLeft)				//Key Left
		{
			left = setLeft;
		}
		bool player_Tank :: getLeft(void)
		{
			return left;
		}

		void player_Tank :: setRight(bool setRight)				//Key Right
		{
			right = setRight;
		}
		bool player_Tank :: getRight(void)
		{
			return right;
		}

		void player_Tank :: setFire(bool setFire)				//Fire Key
		{
			fire = setFire;
		}
		bool player_Tank :: getFire(void)
		{
			return fire;
		}

		void player_Tank :: setTurLeft(bool setTurLeft)
		{
			turretLeft = setTurLeft;
		}
		bool player_Tank :: getTurLeft(void)
		{
			return turretLeft;
		}
		void player_Tank :: setTurRight(bool setTurRight)
		{
			turretRight = setTurRight;
		}
		bool player_Tank :: getTurRight(void)
		{
			return turretRight;
		}
		void player_Tank :: setReloaded(bool setReloaded)
		{	
			reloaded = setReloaded;
		}
		bool player_Tank :: getReloaded(void)
		{
			return reloaded;
		}
		void player_Tank :: setInvincible(bool setInv)
		{
			invincible = setInv;
		}
		bool player_Tank :: getInvincible(void)
		{
			return invincible;
		}