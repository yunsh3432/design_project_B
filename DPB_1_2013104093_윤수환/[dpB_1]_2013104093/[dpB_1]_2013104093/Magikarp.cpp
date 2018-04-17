#include"Magikarp.h"

Magikarp::Magikarp()
{
	
	setName("잉어킹");
	sethealth_point(50);
	setattack_point(0);
	setdefense_point(3);
	setType(1);//1: 지상 2: 비행
	setskill_cnt();
}

Magikarp::~Magikarp()
{

}

int Magikarp::skill(Pokemon* ally,Pokemon* enemy)
{
	if(ally->getskill_cnt() == 0)
	{
		cout << "스킬을 사용할 수 없습니다" << endl;
		return 0;
	}
	else
	{
		cout << "잉어킹의 튀어오르기!!"<< endl;
		cout << "효과는 없었다!!" << endl;
	
		ally->changeskill_cnt();
		cout << "이제 사용가능한 스킬 횟수는 " << ally->getskill_cnt() << "번 입니다." << endl;

	}
	/*스킬이름 "튀어오르기" 무쓸모*/
}