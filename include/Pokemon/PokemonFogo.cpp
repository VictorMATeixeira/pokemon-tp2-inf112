#include "Pokemon.hpp"
#include "PokemonFogo.hpp"

PokemonFogo::PokemonFogo(std::string nome, int idPokemon, int vida, int ataque, int defesa) 
: Pokemon(nome, idPokemon, vida, ataque, defesa, "fogo") {
    
}

int PokemonFogo::calcularDanoRecebido(int dano, std::string tipoAtacante) {
     if(dano < 0){
        return 0;
    }
    if(tipoAtacante == "planta"){
        dano /= 2;
    }
    else if(tipoAtacante == "agua"){
        dano *= 2;
    }
    return dano;
}