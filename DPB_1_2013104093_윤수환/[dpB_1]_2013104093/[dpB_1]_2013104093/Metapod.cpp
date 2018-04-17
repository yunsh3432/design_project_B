#include"Metapod.h"

Metapod::Metapod()
{
	
	setName("단데기");
	sethealth_point(100);
	setattack_point(0);
	setdefense_point(10);
	setType(1);//1: 지상 2: 비행
	setskill_cnt();
}

Metapod::~Metapod()
{
}

int Metapod::skill(Pokemon* ally,Pokemon* enemy)
{
	if(ally->getskill_cnt() == 0)
	{
		cout << "스킬을 사용할 수 없습니다" << endl;
		return 0;
	}
	else
	{
		cout << "단데기의 단단해지기!!"<< endl;
		ally->setdefense_point(ally->getdefense()+2);
	
		ally->changeskill_cnt();
		cout << "이제 사용가능한 스킬 횟수는 " << ally->getskill_cnt() << "번 입니다." << endl;

	}
	/*스킬명 "단단해지기" 배틀 끝날때 까지 방어력 2상승*/
}