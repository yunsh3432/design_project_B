#include"Bulbasaur.h"

Bulbasaur::Bulbasaur()
{
	
	setName("이상해씨");
	sethealth_point(150);
	setattack_point(7);
	setdefense_point(4);
	setType(1);//1: 지상 2: 비행
	setskill_cnt();
}


Bulbasaur::~Bulbasaur()
{
}

int Bulbasaur:: skill(Pokemon* ally, Pokemon* enemy)
{
	if(ally->getskill_cnt() == 0)
	{
		cout << "스킬을 사용할 수 없습니다" << endl;
		return 0;
	}
	else{
		cout << "이상해씨 광합성!!" << endl;
		int attack = ally->getAttack()+1;
		ally->setattack_point(attack);
		ally->changeskill_cnt();
		cout << "이제 사용가능한 스킬 횟수는 " << ally->getskill_cnt() << "번 입니다." << endl;

		return 0;/*스킬 이름 "광합성" 이번턴에 공격하지 않고 배틀이 끝날때 까지 공격력 1 상승*/
	}
}