#pragma once
#include "Pokemon.h"

class TurnBehavior
{
public:
	TurnBehavior();
	~TurnBehavior();

	virtual int executeTurn(Pokemon* subject, Pokemon* target) = 0;
};

