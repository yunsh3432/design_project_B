#include"Charizard.h"

Charizard::Charizard()
{
	
	setName("���ڸ�");
	sethealth_point(150);
	setattack_point(7);
	setdefense_point(3);
	setType(2);//1: ���� 2: ����
	setskill_cnt();
}

Charizard::~Charizard()
{

}

int Charizard::skill(Pokemon* ally,Pokemon* enemy)
{
	if(ally->getskill_cnt() == 0)
	{
		cout << "��ų�� ����� �� �����ϴ�" << endl;
		return 0;
	}
	else
	{
		cout << "���ڸ��� �Ҵ빮��!!"<< endl;
		int Enemyhealth = enemy->gethealth();
		int health = Enemyhealth - 25;
		enemy->changehealth_point(health);

		ally->changeskill_cnt();
		cout << "���� ��밡���� ��ų Ƚ���� " << ally->getskill_cnt() << "�� �Դϴ�." << endl;

		return 0;
	}
	 /*���ڸ� ��ų �Ҵ빮�� �湫��25*/
}