#include"Pokemon.h"

Pokemon::Pokemon()
{
}

Pokemon::~Pokemon()
{
}


void Pokemon::setName(string _name)
{
	name = _name;
}

void Pokemon::sethealth_point(int health)
{
	health_point = health;
	maximum_health_point = health;
}

void Pokemon:: changehealth_point(int health)
{
	health_point = health;
}
void Pokemon::setattack_point(int attack)
{
	attack_point = attack;
}
void Pokemon::setdefense_point(int defense)
{
	defense_point = defense;
}
void Pokemon::setType(int type)
{
	type1 = type;
}

void Pokemon::setskill_cnt()
{
	skill_cnt = 2;
}
void Pokemon::printStatus()
{
	for( int i = 0 ; i < 20; i++)
		cout << '-';
	cout << endl;

	cout << "�̸�: " << name << endl;
	cout << "ü��: " << health_point << endl;
	cout << "���ݷ�: " << attack_point << endl;
	cout << "����: " << defense_point << endl;
	cout << "��ų ��� ���� Ƚ��: " << skill_cnt << endl;

	for( int i = 0 ; i < 20; i++)
		cout << '-';
	cout << endl;
}

int Pokemon::getskill_cnt()
{
	return skill_cnt;
}

int Pokemon::getType()
{
	return type1;
}

int Pokemon::getdefense()
{
	return defense_point;
}

int Pokemon::getAttack()
{
	return attack_point;
}

int Pokemon::getmaxhealth()
{
	return maximum_health_point;
}

void Pokemon::changeskill_cnt()
{
	skill_cnt--;
}

void Pokemon::resetskill_cnt()
{
	skill_cnt = 2;
}

int Pokemon::gethealth()
{
	return health_point;
}