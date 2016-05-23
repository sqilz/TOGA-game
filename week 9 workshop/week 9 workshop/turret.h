class turret{

public:
	turret();

	void tSetPosx(float pos_X);
	float tGetPosx(void);

	void tSetPosy(float pos_Y);
	float tGetPosy(void);

	void tSetRot(float rot);
	float tGetRot(void);


private:
	float posX;
	float posY;
	float rotation;
	
};