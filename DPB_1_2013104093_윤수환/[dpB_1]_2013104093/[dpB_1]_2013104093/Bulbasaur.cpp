#include"Bulbasaur.h"

Bulbasaur::Bulbasaur()
{
	
	setName("�̻��ؾ�");
	sethealth_point(150);
	setattack_point(7);
	setdefense_point(4);
	setType(1);//1: ���� 2: ����
	setskill_cnt();
}


Bulbasaur::~Bulbasaur()
{
}

int Bulbasaur:: skill(Pokemon* ally, Pokemon* enemy)
{
	if(ally->getskill_cnt() == 0)
	{
		cout << "��ų�� ����� �� �����ϴ�" << endl;
		return 0;
	}
	else{
		cout << "�̻��ؾ� ���ռ�!!" << endl;
		int attack = ally->getAttack()+1;
		ally->setattack_point(attack);
		ally->changeskill_cnt();
		cout << "���� ��밡���� ��ų Ƚ���� " << ally->getskill_cnt() << "�� �Դϴ�." << endl;

		return 0;/*��ų �̸� "���ռ�" �̹��Ͽ� �������� �ʰ� ��Ʋ�� ������ ���� ���ݷ� 1 ���*/
	}
}