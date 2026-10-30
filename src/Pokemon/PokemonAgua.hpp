#ifndef POKEMONAGUA_HPP
#define POKEMONAGUA_HPP

#include <string>
#include "Pokemon.hpp"

class PokemonAgua : public Pokemon{
public:
    //inicialização
    PokemonAgua(std::string nome, int idPokemon, int vida, int ataque, int defesa);
    //metodos herança
    int calcularDanoRecebido(int dano, std::string tipoAtacante) override;
};

#endif