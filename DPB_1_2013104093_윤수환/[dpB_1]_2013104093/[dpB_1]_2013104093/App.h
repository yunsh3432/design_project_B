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

	void selectAllyPokemon();//아군 포켓몬 선택
	void selectEnemyPokemon();//적군 포켓몬 선택
	void showPokemonList();//내가 선택할 수 있는 포켓몬 출력
	void startBattle();//배틀 시작
	void selectTurnBehavior();//어떤 행동을 선택 할것인가에 대한 선택
	void printAllPokemon();//선택한 아군 적군 포켓몬 출력
	//void executeTrun();//턴 수행및 다음턴 진행

private:
	
	vector<Pokemon*> allyList;//아군 포켓몬 리스트
	vector<Pokemon*> enemyList;//적군 포켓몬 리스트
	PokemonFactory pf;//포켓몬 팩토리객체 
	TurnBehavior *tb;//행동 객체
	Pokemon* curAlly;//현재 배틀중인 아군 포켓몬 객체
	Pokemon* curEnemy;//현제 배틀중인 적군 포켓몬 객체
	
	bool isMyTurn;
};

