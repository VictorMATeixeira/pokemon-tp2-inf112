#ifndef POKEMONAGUA_HPP
#define POKEMONAGUA_HPP

#include <string>
#include "Pokemon.hpp"

class PokemonAgua : public Pokemon{
public:
    PokemonAgua(std::string nome, int idPokemon, int vida, int ataque, int defesa);
};

#endif