#include "App.h"
#include<iostream>

using namespace std;

App::App(void)
{
	cf = new CounterFacade();
	mf = new ManagerFacade(cf->getOTM(), cf->getSM(), cf->getSLM());
}


App::~App(void)
{
}

void App::run()
{
	while(1)
	{
		cout << "Ŀ�Ǽ� �Ŵ�����Ʈ ���α׷�" << endl;
		cout << "1.���� �޴�" << endl;
		cout << "2.���� �޴�" << endl;
		cout << "0.����" << endl;
		int selec;
		cin >> selec;
		if(selec == 1)
		{
			cf->menu();
		}
		else if(selec == 2)
		{
			mf->menu();
		}
		else if(selec == 0)
		{
			return ;
		}
		else
		{
			cout << "���� �޴��Դϴ�. �ٽ� �Է��ϼ���" << endl;
		}
	}
}