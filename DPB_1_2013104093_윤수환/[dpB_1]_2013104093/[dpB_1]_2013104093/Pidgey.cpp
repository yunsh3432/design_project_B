#include"Pidgey.h"

Pidgey::Pidgey()
{
	
	setName("����");
	sethealth_point(50);
	setattack_point(5);
	setdefense_point(3);
	setType(2);//1: ���� 2: ����
	setskill_cnt();
}

Pidgey::~Pidgey()
{
}

int Pidgey::skill(Pokemon* ally, Pokemon* enemy)
{
	if(ally->getskill_cnt() == 0)
	{
		cout << "��ų�� ����� �� �����ϴ�" << endl;
		return 0;
	}
	else
	{
		cout << "������ �𷡻Ѹ���!"<< endl;
		enemy->setattack_point(enemy->getAttack()-1);
	
		ally->changeskill_cnt();
		cout << "���� ��밡���� ��ų Ƚ���� " << ally->getskill_cnt() << "�� �Դϴ�." << endl;

	}/*��ų �̸� "�𷡻Ѹ���" ��Ʋ�� ������ �������� ���ݷ� 1 ����*/
}