#include"Blastoise.h"

Blastoise::Blastoise()
{
	
	setName("거북왕");
	sethealth_point(200);
	setattack_point(6);
	setdefense_point(5);
	setType(1);//1: 지상 2: 비행
	setskill_cnt();
}
Blastoise::~Blastoise()
{
}

int Blastoise:: skill(Pokemon* ally, Pokemon* enemy)
{
	if(ally->getskill_cnt() == 0)
	{
		cout << "스킬을 사용할 수 없습니다" << endl;
		return 0;
	}
	else
	{
	cout << "거북왕의 물대포!!"<< endl;/* 스킬 "물대포" 1.5배 증뎀*/
	float Allyattack = ally->getAttack()*1.5;
	int allytype = ally->getType();
	int enemytype = enemy->getType();
	int enemydefense = enemy->getdefense();

	float ratio;
	if(allytype > enemytype)
	{
		ratio = 2;
	}
	else if(allytype == enemytype)
	{
		ratio = 1;
	}
	else
	{
		ratio = 0.5;
	}

	float demege = 0;
	if(Allyattack < enemydefense)
		demege = 1*6*ratio;
	else
		demege = (Allyattack - enemydefense)*6*ratio;

	int Enemyhealth = enemy->gethealth();
	int health = Enemyhealth - demege;
	enemy->changehealth_point(health);

	ally->changeskill_cnt();
	cout << "이제 사용가능한 스킬 횟수는 " << ally->getskill_cnt() << "번 입니다." << endl;

	return 0;
	}
}