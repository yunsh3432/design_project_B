#pragma once
#include <vector>

#include "AttackBehavior.h"
#include "RestBehavior.h"
#include "SkillBehavior.h"
#include "PokemonFactory.h"


class App
{
public:
	App();
	~App();

	void run();

	void selectAllyPokemon();//�Ʊ� ���ϸ� ����
	void selectEnemyPokemon();//���� ���ϸ� ����
	void showPokemonList();//���� ������ �� �ִ� ���ϸ� ���
	void startBattle();//��Ʋ ����
	void selectTurnBehavior();//� �ൿ�� ���� �Ұ��ΰ��� ���� ����
	void printAllPokemon();//������ �Ʊ� ���� ���ϸ� ���
	//void executeTrun();//�� ����� ������ ����

private:
	
	vector<Pokemon*> allyList;//�Ʊ� ���ϸ� ����Ʈ
	vector<Pokemon*> enemyList;//���� ���ϸ� ����Ʈ
	PokemonFactory pf;//���ϸ� ���丮��ü 
	TurnBehavior *tb;//�ൿ ��ü
	Pokemon* curAlly;//���� ��Ʋ���� �Ʊ� ���ϸ� ��ü
	Pokemon* curEnemy;//���� ��Ʋ���� ���� ���ϸ� ��ü
	
	bool isMyTurn;
};

