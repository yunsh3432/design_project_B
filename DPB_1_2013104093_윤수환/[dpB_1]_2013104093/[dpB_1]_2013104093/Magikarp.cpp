#include"Magikarp.h"

Magikarp::Magikarp()
{
	
	setName("�׾�ŷ");
	sethealth_point(50);
	setattack_point(0);
	setdefense_point(3);
	setType(1);//1: ���� 2: ����
	setskill_cnt();
}

Magikarp::~Magikarp()
{

}

int Magikarp::skill(Pokemon* ally,Pokemon* enemy)
{
	if(ally->getskill_cnt() == 0)
	{
		cout << "��ų�� ����� �� �����ϴ�" << endl;
		return 0;
	}
	else
	{
		cout << "�׾�ŷ�� Ƣ�������!!"<< endl;
		cout << "ȿ���� ������!!" << endl;
	
		ally->changeskill_cnt();
		cout << "���� ��밡���� ��ų Ƚ���� " << ally->getskill_cnt() << "�� �Դϴ�." << endl;

	}
	/*��ų�̸� "Ƣ�������" ������*/
}