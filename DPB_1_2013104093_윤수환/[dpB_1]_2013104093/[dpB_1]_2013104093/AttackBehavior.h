#pragma once
#include "TurnBehavior.h"
class AttackBehavior :
	public TurnBehavior
{
public:
	AttackBehavior();
	~AttackBehavior();

	virtual int executeTurn(Pokemon* subjet, Pokemon* target);
};

