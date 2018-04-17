#pragma once
#include "TurnBehavior.h"
class RestBehavior :
	public TurnBehavior
{
public:
	RestBehavior();
	~RestBehavior();

	virtual int executeTurn(Pokemon* subject, Pokemon* target);
};

