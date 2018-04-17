#pragma once
#include "Pokemon.h"
class Blastoise :
	public Pokemon
{
public:
	Blastoise();
	~Blastoise();

	virtual int skill(Pokemon* ally, Pokemon* enemy);
};

