#ifndef POKEMONELETRICO_HPP
#define POKEMONELETRICO_HPP

#include <string>
#include "Pokemon.hpp"

class PokemonEletrico : public Pokemon{
public:
    //inicialização
    PokemonEletrico(std::string nome, int idPokemon, int vida, int ataque, int defesa);
    //metodos herança
    int calcularDanoRecebido(int dano, std::string tipoAtacante) override;
};

#endif