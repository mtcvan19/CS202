#pragma once
#include "Header.h"

class CAnimal {
protected:
	int mX, mY;
public:
	//virtual void Move(int, int);
	//virtual void Tell();
	int getX();
	int getY();
	void updatePosAnimal(int, int);

	CAnimal(int, int);

	//For Impact function
	virtual bool isDxAndDyInRange(int, int);
};
