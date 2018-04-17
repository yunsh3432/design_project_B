#pragma once
#include "Pokemon.h"
class Pidgey :
	public Pokemon
{
public:
	Pidgey();
	~Pidgey();

	virtual int skill(Pokemon* ally, Pokemon* enemy);
};

