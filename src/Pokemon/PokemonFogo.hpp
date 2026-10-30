#ifndef POKEMONFOGO_HPP
#define POKEMONFOGO_HPP

#include <string>
#include "Pokemon.hpp"

class PokemonFogo : public Pokemon{
public:
    //inicialização
    PokemonFogo(std::string nome, int idPokemon, int vida, int ataque, int defesa);
    //metodos herança
    int calcularDanoRecebido(int dano, std::string tipoAtacante) override;
};

#endif