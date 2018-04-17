#pragma once
#include "Pokemon.h"
class Metapod :
	public Pokemon
{
public:
	Metapod();
	~Metapod();

	virtual int skill(Pokemon* ally, Pokemon* enemy);
};

