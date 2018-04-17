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
		cout << "커피숍 매니지먼트 프로그램" << endl;
		cout << "1.점원 메뉴" << endl;
		cout << "2.점장 메뉴" << endl;
		cout << "0.종료" << endl;
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
			cout << "없는 메뉴입니다. 다시 입력하세요" << endl;
		}
	}
}