#include "Pokemon.hpp"
#include "PokemonAgua.hpp"

PokemonAgua::PokemonAgua(std::string nome, int idPokemon, int vida, int ataque, int defesa) 
: Pokemon(nome, idPokemon, vida, ataque, defesa, "agua") { //aquatico fica melhor

} 

int PokemonAgua::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    if(dano < 0){
        return 0;
    }
    if(tipoAtacante == "fogo"){
        dano /= 2;
    }
    else if(tipoAtacante == "eletrico" || tipoAtacante == "planta"){
        dano *= 2;
    }
    return dano;
}