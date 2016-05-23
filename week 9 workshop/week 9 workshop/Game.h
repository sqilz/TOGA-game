#include "player_Tank.h"
#include "powerUps.h"
#include <time.h>

class Game{
public:
	player_Tank * Tank;
	powerUps * powerUp;

	Game();
	~Game();
	
	void setOldTime(time_t time);
	time_t getOldTime(void);
	
	void setCurrentTime(time_t current);
	time_t getCurrent(void);
private:
	time_t oldTime;
	time_t currentTime;


};
