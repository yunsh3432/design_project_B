#include"Metapod.h"

Metapod::Metapod()
{
	
	setName("�ܵ���");
	sethealth_point(100);
	setattack_point(0);
	setdefense_point(10);
	setType(1);//1: ���� 2: ����
	setskill_cnt();
}

Metapod::~Metapod()
{
}

int Metapod::skill(Pokemon* ally,Pokemon* enemy)
{
	if(ally->getskill_cnt() == 0)
	{
		cout << "��ų�� ����� �� �����ϴ�" << endl;
		return 0;
	}
	else
	{
		cout << "�ܵ����� �ܴ�������!!"<< endl;
		ally->setdefense_point(ally->getdefense()+2);
	
		ally->changeskill_cnt();
		cout << "���� ��밡���� ��ų Ƚ���� " << ally->getskill_cnt() << "�� �Դϴ�." << endl;

	}
	/*��ų�� "�ܴ�������" ��Ʋ ������ ���� ���� 2���*/
}