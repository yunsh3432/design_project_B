#include"Charizard.h"

Charizard::Charizard()
{
	
	setName("리자몽");
	sethealth_point(150);
	setattack_point(7);
	setdefense_point(3);
	setType(2);//1: 지상 2: 비행
	setskill_cnt();
}

Charizard::~Charizard()
{

}

int Charizard::skill(Pokemon* ally,Pokemon* enemy)
{
	if(ally->getskill_cnt() == 0)
	{
		cout << "스킬을 사용할 수 없습니다" << endl;
		return 0;
	}
	else
	{
		cout << "리자몽의 불대문자!!"<< endl;
		int Enemyhealth = enemy->gethealth();
		int health = Enemyhealth - 25;
		enemy->changehealth_point(health);

		ally->changeskill_cnt();
		cout << "이제 사용가능한 스킬 횟수는 " << ally->getskill_cnt() << "번 입니다." << endl;

		return 0;
	}
	 /*리자몽 스킬 불대문자 방무뎀25*/
}