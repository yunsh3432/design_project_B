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
	case 1://���ڸ�
		newPoketmon = new Charizard;
		return newPoketmon;
		break;
	case 2://�̻��ؾ�
		newPoketmon = new Bulbasaur;
		return newPoketmon;
		break;
	case 3://�źϿ�
		newPoketmon = new Blastoise;
		return newPoketmon;
		break;
	case 4://�ܵ���
		newPoketmon = new Metapod;
		return newPoketmon;;
		break;
	case 5://����
		newPoketmon = new Pidgey;
		return newPoketmon;
		break;
	case 6://�׾�ŷ
		newPoketmon = new Magikarp;
		return newPoketmon;
		break;
	default:
		cout << "�ٽ��Է����ּ���"<<endl;
		break;
	}
}