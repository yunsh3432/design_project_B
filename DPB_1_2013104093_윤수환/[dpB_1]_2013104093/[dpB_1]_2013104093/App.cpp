#include"App.h"
#include<iostream>

using namespace std;

App::App()
{
}

App::~App()
{
}

void App::run()
{
	selectAllyPokemon();
	selectEnemyPokemon();
	printAllPokemon();
	int start;
	while(1)
	{
		cout << "��Ʋ�� �����ϱ� ���� ������ �Է� �ϼ���: ";
		cin >> start;
		if(cin.fail() == 1)
		{
			cin.clear();
			cin.ignore();
			cout << "������ �ƴմϴ� �ٽ� �Է��� �ּ���" << endl;
		}
		else
		{
			break;
		}
	}
	startBattle();

}

void App::selectAllyPokemon()
{
	cout << "�Ʊ� ���ϸ� 3������ ������ �ּ���" << endl;
	
	showPokemonList();
	int i = 0;
	while(i < 3)
	{
		cout << "��ȣ�� �Է��� �ּ���: ";
		int selecAlly;
		cin >> selecAlly;
		if(selecAlly < 7&& selecAlly > 0)
		{
			Pokemon* pokemon;
			pokemon = pf.create_pokemon(selecAlly);
			allyList.push_back(pokemon);
			i++;
		}
		else
		{
			cout << "�ٽ��Է����ּ���" << endl;
		}
	}

}

void App::selectEnemyPokemon()
{
	cout << "���� ���ϸ� 3������ ������ �ּ���" << endl;
	
	
	showPokemonList();
	
	
	int i = 0;
	while(i < 3)
	{
		cout << "��ȣ�� �Է��� �ּ���: ";
		int selecEnemy;
		cin >> selecEnemy;
		if(selecEnemy<7 && selecEnemy > 0)
		{
			Pokemon* pokemon;
			pokemon = pf.create_pokemon(selecEnemy);
			enemyList.push_back(pokemon);
			i++;
		}
		else
		{
			cout << "�ٽ��Է��� �ּ���" << endl;
		}
	}
	
}

void App::printAllPokemon()
{
	cout << "���� ���ϸ� " << endl;
	for(vector<Pokemon*>::size_type i = 0; i < allyList.size(); i++)
	{
		allyList[i]->printStatus();
		cout << endl;
	}

	cout  << "������ ���ϸ� " << endl;
	for(vector<Pokemon*>::size_type i = 0; i < enemyList.size(); i++)
	{
		enemyList[i]->printStatus();
		cout << endl;
	}
	
	/*
	allyList�� enemyList�� �ִ� �͵��� curAlly�� curEnemy�� �̵� ��Ű�鼭 ���� �� �� 
	��ġ�� ó������ ���½�Ű�� ��Ʋ�� �����Ѵ�.
	*/
}

void App::showPokemonList()
{
	for(int i = 0; i < 20; i++)
		cout << '-';
	cout << endl;

	cout << "���ϸ� ����Ʈ" <<endl;
	cout << "1.���ڸ�"<<endl;
	cout << "2.�̻��ؾ�"<<endl;
	cout << "3.�źϿ�"<<endl;
	cout << "4.�ܵ���"<<endl;
	cout << "5.����"<<endl;
	cout << "6.�׾�ŷ"<<endl;

	for(int i = 0; i < 20; i++)
		cout << '-';
	cout << endl;
}
void App::startBattle()
{	
	while(1)
	{
		if(allyList.empty())
		{
			cout << "��Ʋ�� �������ϴ�" << endl;
			cout << "���ڴ� ���Դϴ�." << endl;
			return ;
		}
		else if(enemyList.empty())
		{
		
			cout << "��Ʋ�� �������ϴ�" << endl;
			cout << "���ڴ� ���Դϴ�." << endl;
			return ;
		}
		else
		{
			curAlly = allyList[0];
			curEnemy = enemyList[0];
			selectTurnBehavior();
			//executeTrun();
		}
	}
}

void App::selectTurnBehavior()
{
	isMyTurn = true;
	while(1)
	{
		if(curAlly->gethealth() <= 0)
		{
			vector<Pokemon*>::iterator it = allyList.begin();
			allyList.erase(it);
			curAlly = NULL;
			return;
		}
		else if(curEnemy->gethealth() <= 0)
		{
			vector<Pokemon*>::iterator it = enemyList.begin();
			enemyList.erase(it);
			curAlly = NULL;
			return;
		}

		if(isMyTurn ==true)
		{
			cout << "���� ��" << endl;
			curAlly->printStatus();
			curEnemy->printStatus();
		for( int i = 0; i < 20; i++)
			cout << '-';
		cout << endl;
		
		cout << "�̹� �Ͽ� ������ �Ͻðڽ��ϱ�?" << endl;
		cout <<"1. �Ϲ� ����" << endl;
		cout <<"2. �޽�" << endl;
		cout <<"3. ��ų ����" << endl;
		
		for( int i = 0; i < 20; i++)
			cout << '-';
		cout << endl;
		cout << "��ȣ�� �Է��� �ּ���: ";
		int selec;
		cin >> selec;
		switch(selec){
			
			case 1:
				tb = new AttackBehavior;
				tb->executeTurn(curAlly,curEnemy);
				if(isMyTurn == true)
					isMyTurn = false;
				else
					isMyTurn = true;
				break;
			case 2:
				tb = new RestBehavior;
				tb->executeTurn(curAlly,curEnemy);
				
				if(isMyTurn == true)
					isMyTurn = false;
				else
					isMyTurn = true;
				break;
			case 3:
				tb = new SkillBehavior;
				tb->executeTurn(curAlly,curEnemy);
				if(isMyTurn == true)
					isMyTurn = false;
				else
					isMyTurn = true;
				break;
			default:
				cout << "�ٽ��Է��� �ּ���" << endl;
		}
		}
		else {
			cout << "���� ��" << endl;

		
		curAlly->printStatus();
		curEnemy->printStatus();
		for( int i = 0; i < 20; i++)
			cout << '-';
		cout << endl;
		
		cout << "�̹� �Ͽ� ������ �Ͻðڽ��ϱ�?" << endl;
		cout <<"1. �Ϲ� ����" << endl;
		cout <<"2. �޽�" << endl;
		cout <<"3. ��ų ����" << endl;
		
		for( int i = 0; i < 20; i++)
			cout << '-';
		cout << endl;
		cout << "��ȣ�� �Է��� �ּ���: ";
		int selec;
		cin >> selec;
		switch(selec){
			
			case 1:
				tb = new AttackBehavior;
				tb->executeTurn(curEnemy,curAlly);
		
				if(isMyTurn == true)
					isMyTurn = false;
				else
					isMyTurn = true;
				break;
			case 2:
				tb = new RestBehavior;
				tb->executeTurn(curEnemy,curAlly);
				
				if(isMyTurn == true)
					isMyTurn = false;
				else
					isMyTurn = true;
				break;
			case 3:
				tb = new SkillBehavior;
				tb->executeTurn(curEnemy,curAlly);
				
				if(isMyTurn == true)
					isMyTurn = false;
				else
					isMyTurn = true;
				break;
			default:
				cout << "�ٽ��Է��� �ּ���" << endl;
		}
		}
	}
}