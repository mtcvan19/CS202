#pragma once
#include "CVehical.h"

class CCar : public CVehicle
{
public:
	CCar(int, int);
	void draw(int, bool);

	// For Impact function
	bool isDxAndDyInRange(int, int);
};
