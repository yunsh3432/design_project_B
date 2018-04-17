#pragma once
#include "Pokemon.h"
class Bulbasaur :
	public Pokemon
{
public:
	Bulbasaur();
	~Bulbasaur();

	virtual int skill(Pokemon* ally, Pokemon* enemy);
};

