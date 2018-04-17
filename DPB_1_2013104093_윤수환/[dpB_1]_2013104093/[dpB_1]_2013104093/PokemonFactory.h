#pragma once
#include "Pokemon.h"
#include "Charizard.h"
#include "Bulbasaur.h"
#include "Blastoise.h"
#include "Pidgey.h"
#include "Metapod.h"
#include "Magikarp.h"

class PokemonFactory
{
public:
	PokemonFactory();
	~PokemonFactory();

	Pokemon* create_pokemon(int pokemon_id);
};

