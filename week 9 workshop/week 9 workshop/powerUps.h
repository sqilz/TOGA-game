class powerUps{
public:
	

	powerUps();
	~powerUps();

	void setPos_x(float setposx);
	float getPos_x(void);

	void setPos_y(float setposy);
	float getPos_y(void);

	void setRotation(float setrot);
	float getRotation(void);
private:
	float posX;
	float posY;
	float rotation;
};