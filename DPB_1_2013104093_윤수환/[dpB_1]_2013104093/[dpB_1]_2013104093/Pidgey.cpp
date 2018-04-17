#include"Pidgey.h"

Pidgey::Pidgey()
{
	
	setName("구구");
	sethealth_point(50);
	setattack_point(5);
	setdefense_point(3);
	setType(2);//1: 지상 2: 비행
	setskill_cnt();
}

Pidgey::~Pidgey()
{
}

int Pidgey::skill(Pokemon* ally, Pokemon* enemy)
{
	if(ally->getskill_cnt() == 0)
	{
		cout << "스킬을 사용할 수 없습니다" << endl;
		return 0;
	}
	else
	{
		cout << "구구의 모래뿌리기!"<< endl;
		enemy->setattack_point(enemy->getAttack()-1);
	
		ally->changeskill_cnt();
		cout << "이제 사용가능한 스킬 횟수는 " << ally->getskill_cnt() << "번 입니다." << endl;

	}/*스킬 이름 "모래뿌리기" 배틀이 끝날때 까지상대방 공격력 1 감소*/
}