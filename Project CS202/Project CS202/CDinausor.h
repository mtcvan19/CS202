#pragma once
#include "CAnimal.h"

class CDinausor: public CAnimal
{
public:
	CDinausor(int, int);
	void draw(int, bool);

	// For Impact function
	bool isDxAndDyInRange(int, int);
};
