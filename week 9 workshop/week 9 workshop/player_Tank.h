#include "bullet.h"
#include "turret.h"

class player_Tank{//this structure is holding data about the player's tank position and rotation
	//coordinates of tank

public:												// prototypes
		player_Tank();				//Constructor
		~player_Tank();

		bullet * Bullet;
		turret * Turret;
		

		void setPos_x(float posX);
		float getPos_x(void);

		void setPos_y(float posY);
		float getPos_y(void);

		void setScale(float scal);
		float getScale(void);

		void setVelocity(float vel);
		float getVelocity(void);
		 
		void setRotation(float rot);
		float getRotation(void);

		void setSpeed(float speed);
		float getSpeed(void);

		void setAcceleration(float accel);
		float getAcceleration(void);

		void setMaxSpeed(float speedMax);
		float getMaxSpeed(void);

		void setMinSpeed(float speedMin);
		float getMinSpeed(void);

		void setUp(bool up);
		bool getUp(void);

		void setDown(bool down);
		bool getDown(void);

		void setLeft(bool left);
		bool getLeft(void);

		void setRight(bool right);
		bool getRight(void);

		void setFire(bool fire);
		bool getFire(void);

		void setTurLeft(bool turretLeft);
		bool getTurLeft(void);

		void setTurRight(bool turretRight);
		bool getTurRight(void);

		void setReloaded(bool reloaded);
		bool getReloaded(void);

		void setInvincible(bool invincible);
		bool getInvincible(void);

private:
	float position_x;
	float position_y;
	float scale;
	float velocity;

	float rotation;
	float speed;
	float acceleration;
	float maxSpeed;
	float minSpeed;
	//variables for checking if the up, down, left, right and fire are DOWN
	bool up;
	bool down;
	bool left;
	bool right;
	bool fire;
	bool turretLeft;
	bool turretRight;
	bool reloaded;
	bool invincible;

	
};