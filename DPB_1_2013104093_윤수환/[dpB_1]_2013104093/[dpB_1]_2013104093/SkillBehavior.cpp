#include"SkillBehavior.h"

SkillBehavior::SkillBehavior()
{
}

SkillBehavior::~SkillBehavior()
{
}

int SkillBehavior::executeTurn(Pokemon* subject, Pokemon* target)
{
	subject->skill(subject,target);
	return 0;
}