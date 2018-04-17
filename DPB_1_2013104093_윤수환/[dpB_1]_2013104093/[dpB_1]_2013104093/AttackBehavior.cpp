#include"AttackBehavior.h"

AttackBehavior::AttackBehavior()
{
}

AttackBehavior::~AttackBehavior()
{
}

int AttackBehavior::executeTurn(Pokemon* subject, Pokemon* target)
{
	int attackpoint = subject->getAttack();
	int Enemydefense = target->getdefense();
	int subType = subject->getType();
	int tarType = target->getType();//1: 지상, 2: 공중

	float ratio;
	if(subType > tarType)
		ratio = 2;
	else if(subType < tarType)
		ratio = 0.5;
	else
		ratio = 1;
	
	float demege = 0;
	if(attackpoint < Enemydefense)
		demege = 1*6*ratio;
	else
		demege = (attackpoint - Enemydefense)*6*ratio;

	int Enemyhealth = target->gethealth();
	int health = Enemyhealth - demege;
	target->changehealth_point(health);

	return 0;
}