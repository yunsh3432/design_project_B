#include"Blastoise.h"

Blastoise::Blastoise()
{
	
	setName("�źϿ�");
	sethealth_point(200);
	setattack_point(6);
	setdefense_point(5);
	setType(1);//1: ���� 2: ����
	setskill_cnt();
}
Blastoise::~Blastoise()
{
}

int Blastoise:: skill(Pokemon* ally, Pokemon* enemy)
{
	if(ally->getskill_cnt() == 0)
	{
		cout << "��ų�� ����� �� �����ϴ�" << endl;
		return 0;
	}
	else
	{
	cout << "�źϿ��� ������!!"<< endl;/* ��ų "������" 1.5�� ����*/
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
	cout << "���� ��밡���� ��ų Ƚ���� " << ally->getskill_cnt() << "�� �Դϴ�." << endl;

	return 0;
	}
}