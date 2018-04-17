#pragma once
#include <string>
#include <iostream>
using namespace std;

class Pokemon
{
public:
	Pokemon();
	~Pokemon();

	virtual int skill(Pokemon* ally, Pokemon* enemy) = 0;
	void setName(string _name);
	void sethealth_point(int health);
	void changehealth_point(int health);
	void setattack_point(int attack);
	void setdefense_point(int defense);
	void setType(int _type);
	void setskill_cnt();
	void changeskill_cnt();
	void resetskill_cnt();
	int getskill_cnt();
	int getType();
	int getdefense();
	int getAttack();
	int gethealth();
	int getmaxhealth();
	void printStatus();
public:
	int type1;
	string name;
	int maximum_health_point;
	int health_point;
	int attack_point;
	int defense_point;
	int skill_cnt;
};

