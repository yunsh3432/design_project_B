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
		cout << "배틀을 시작하기 위해 정수를 입력 하세요: ";
		cin >> start;
		if(cin.fail() == 1)
		{
			cin.clear();
			cin.ignore();
			cout << "정수가 아닙니다 다시 입력해 주세요" << endl;
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
	cout << "아군 포켓몬 3마리를 선택해 주세요" << endl;
	
	showPokemonList();
	int i = 0;
	while(i < 3)
	{
		cout << "번호를 입력해 주세요: ";
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
			cout << "다시입력해주세요" << endl;
		}
	}

}

void App::selectEnemyPokemon()
{
	cout << "적군 포켓몬 3마리를 선택해 주세요" << endl;
	
	
	showPokemonList();
	
	
	int i = 0;
	while(i < 3)
	{
		cout << "번호를 입력해 주세요: ";
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
			cout << "다시입력해 주세요" << endl;
		}
	}
	
}

void App::printAllPokemon()
{
	cout << "나의 포켓몬 " << endl;
	for(vector<Pokemon*>::size_type i = 0; i < allyList.size(); i++)
	{
		allyList[i]->printStatus();
		cout << endl;
	}

	cout  << "상대방의 포켓몬 " << endl;
	for(vector<Pokemon*>::size_type i = 0; i < enemyList.size(); i++)
	{
		enemyList[i]->printStatus();
		cout << endl;
	}
	
	/*
	allyList와 enemyList에 있는 것들을 curAlly와 curEnemy로 이동 시키면서 보여 준 후 
	위치를 처음으로 리셋시키고 배틀을 시작한다.
	*/
}

void App::showPokemonList()
{
	for(int i = 0; i < 20; i++)
		cout << '-';
	cout << endl;

	cout << "포켓몬 리스트" <<endl;
	cout << "1.리자몽"<<endl;
	cout << "2.이상해씨"<<endl;
	cout << "3.거북왕"<<endl;
	cout << "4.단데기"<<endl;
	cout << "5.구구"<<endl;
	cout << "6.잉어킹"<<endl;

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
			cout << "배틀이 끝났습니다" << endl;
			cout << "승자는 적입니다." << endl;
			return ;
		}
		else if(enemyList.empty())
		{
		
			cout << "배틀이 끝났습니다" << endl;
			cout << "승자는 나입니다." << endl;
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
			cout << "나의 턴" << endl;
			curAlly->printStatus();
			curEnemy->printStatus();
		for( int i = 0; i < 20; i++)
			cout << '-';
		cout << endl;
		
		cout << "이번 턴에 무엇을 하시겠습니까?" << endl;
		cout <<"1. 일반 공격" << endl;
		cout <<"2. 휴식" << endl;
		cout <<"3. 스킬 공격" << endl;
		
		for( int i = 0; i < 20; i++)
			cout << '-';
		cout << endl;
		cout << "번호를 입력해 주세요: ";
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
				cout << "다시입력해 주세요" << endl;
		}
		}
		else {
			cout << "적의 턴" << endl;

		
		curAlly->printStatus();
		curEnemy->printStatus();
		for( int i = 0; i < 20; i++)
			cout << '-';
		cout << endl;
		
		cout << "이번 턴에 무엇을 하시겠습니까?" << endl;
		cout <<"1. 일반 공격" << endl;
		cout <<"2. 휴식" << endl;
		cout <<"3. 스킬 공격" << endl;
		
		for( int i = 0; i < 20; i++)
			cout << '-';
		cout << endl;
		cout << "번호를 입력해 주세요: ";
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
				cout << "다시입력해 주세요" << endl;
		}
		}
	}
}