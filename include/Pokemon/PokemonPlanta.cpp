#include "Pokemon.hpp"
#include "PokemonPlanta.hpp"

PokemonPlanta::PokemonPlanta(std::string nome, int idPokemon, int vida, int ataque, int defesa) 
: Pokemon(nome, idPokemon, vida, ataque, defesa, "planta") {
    
}

int PokemonPlanta::calcularDanoRecebido(int dano, std::string tipoAtacante) {
     if(dano < 0){
        return 0;
    }
    if(tipoAtacante == "agua"){
        dano /= 2;
    }
    else if(tipoAtacante == "fogo"){
        dano *= 2;
    }
    return dano;
}