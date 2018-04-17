#include"PokemonFactory.h"

PokemonFactory::PokemonFactory()
{
}

PokemonFactory::~PokemonFactory()
{
}
Pokemon* PokemonFactory::create_pokemon(int pokemon_id)
{
	Pokemon *newPoketmon;
	switch(pokemon_id)
	{
	case 1://리자몽
		newPoketmon = new Charizard;
		return newPoketmon;
		break;
	case 2://이상해씨
		newPoketmon = new Bulbasaur;
		return newPoketmon;
		break;
	case 3://거북왕
		newPoketmon = new Blastoise;
		return newPoketmon;
		break;
	case 4://단데기
		newPoketmon = new Metapod;
		return newPoketmon;;
		break;
	case 5://구구
		newPoketmon = new Pidgey;
		return newPoketmon;
		break;
	case 6://잉어킹
		newPoketmon = new Magikarp;
		return newPoketmon;
		break;
	default:
		cout << "다시입력해주세요"<<endl;
		break;
	}
}