class bullet{

public:
	bullet();

	void bSetPosx(float pos_X);
	float bGetPosx(void);

	void bSetPosy(float pos_Y);
	float bGetPosy(void);

	void bSetRot(float rot);
	float bGetRot(void);

	void bSetSpeed(float spd);
	float bGetSpeed(void);

	void bSetAcceleration(float acc);
	float bGetAcceleration(void);

private:
	float posX;
	float posY;
	float rotation;
	float speed;
	float acceleration;
};