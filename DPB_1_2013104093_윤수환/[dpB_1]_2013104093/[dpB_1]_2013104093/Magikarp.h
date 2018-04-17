#pragma once
#include "Pokemon.h"
class Magikarp :
	public Pokemon
{
public:
	Magikarp();
	~Magikarp();

	virtual int skill(Pokemon* ally, Pokemon* enemy);
};

