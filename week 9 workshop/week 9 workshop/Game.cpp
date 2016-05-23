#include "Game.h"

Game :: Game()// constructor
{				
		Tank = new player_Tank[2];
		powerUp = new powerUps[2];

		Tank[0].setPos_x(1.0f);
		Tank[0].setPos_y(0.0f);
		Tank[0].setRotation(180.0f);
		Tank[0].setSpeed(0.00f);
		Tank[0].setAcceleration(0.001f);
		Tank[0].Turret[0].tSetRot(-180.0f);

		Tank[1].setPos_x(-1.0f);
		Tank[1].setPos_y(0.0f);		
		Tank[1].setRotation(0.0f);
		Tank[1].setSpeed(0.00f);
		Tank[1].setAcceleration(0.001f);
		Tank[1].Turret[1].tSetRot(180.0f);

		powerUp[0].setPos_x(1.0f);
		powerUp[0].setPos_y(1.0f);
		powerUp[0].setRotation(0.0f);

		powerUp[1].setPos_x(-1.0f);
		powerUp[1].setPos_y(-1.0f);
		powerUp[1].setRotation(0.0f);

		currentTime = time(NULL);
		oldTime = currentTime - 0.09f;

}
Game::~Game()
{
	delete [] Tank;
	Tank = nullptr;

	delete [] powerUp;
	powerUp = nullptr;
}
void Game::setOldTime(time_t time)
{
	oldTime = time;
}
time_t Game::getOldTime(void)
{
	return oldTime;
}
	
void Game::setCurrentTime(time_t current)
{
	currentTime = current;
}
time_t Game::getCurrent(void)
{
	return currentTime;
}