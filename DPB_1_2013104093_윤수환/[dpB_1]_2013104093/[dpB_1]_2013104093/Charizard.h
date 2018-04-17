#pragma once
#include "Pokemon.h"
class Charizard :
	public Pokemon
{
public:
	Charizard();
	~Charizard();

	virtual int skill(Pokemon* ally, Pokemon* enemy);
};

