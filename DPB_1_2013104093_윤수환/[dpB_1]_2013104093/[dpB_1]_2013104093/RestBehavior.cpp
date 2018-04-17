#include"RestBehavior.h"

RestBehavior::RestBehavior()
{
}

RestBehavior::~RestBehavior()
{
}

int RestBehavior::executeTurn(Pokemon* subject, Pokemon* target)
{
	int subhealth = subject->gethealth()+10;
	if(subhealth >= subject->getmaxhealth())
	{
		subhealth = subject->getmaxhealth();
		subject->changehealth_point(subhealth);
	}
	else
	{
		subject->changehealth_point(subhealth);
	}

	return 0;
}