#pragma once
#include "TurnBehavior.h"
class SkillBehavior :
	public TurnBehavior
{
public:
	SkillBehavior();
	~SkillBehavior();

	virtual int executeTurn(Pokemon* subject, Pokemon* target);
};

