#ifndef POKEMONPLANTA_HPP
#define POKEMONPLANTA_HPP

#include <string>
#include "Pokemon.hpp"

class PokemonPlanta : public Pokemon{
public:
    //inicialização
    PokemonPlanta(std::string nome, int idPokemon, int vida, int ataque, int defesa);
    //metodos herança
    int calcularDanoRecebido(int dano, std::string tipoAtacante) override;
};

#endif