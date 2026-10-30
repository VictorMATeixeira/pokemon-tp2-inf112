#include "Pokemon.hpp"
#include "PokemonEletrico.hpp"

PokemonEletrico::PokemonEletrico(std::string nome, int idPokemon, int vida, int ataque, int defesa) 
: Pokemon(nome, idPokemon, vida, ataque, defesa, "eletrico") {
    
}

int PokemonEletrico::calcularDanoRecebido(int dano, std::string tipoAtacante) {
     if(dano < 0){
        return 0;
    }
    if(tipoAtacante == "agua"){
        dano /= 2;
    }
    return dano;
}