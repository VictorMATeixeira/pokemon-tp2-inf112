#include "Pokemon.hpp"
#include "PokemonAgua.hpp"
#include <algorithm>
#include <cmath>

PokemonAgua::PokemonAgua(std::string nome, int idPokemon, int vida, int ataque, int defesa) 
: Pokemon(nome, idPokemon, vida, ataque, defesa, "agua") { //aquatico fica melhor

} 

int PokemonAgua::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double mult = 1.0;

    if (tipoAtacante == "fogo") {
        mult = 0.5;
    } else if (tipoAtacante == "eletrico" || tipoAtacante == "planta") {
        mult = 2.0;
    }

    return std::max(1, static_cast<int>(std::round(dano * mult)));
}