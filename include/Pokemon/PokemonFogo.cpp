#include "Pokemon.hpp"
#include "PokemonFogo.hpp"
#include <algorithm>
#include <cmath>

PokemonFogo::PokemonFogo(std::string nome, int idPokemon, int vida, int ataque, int defesa) 
: Pokemon(nome, idPokemon, vida, ataque, defesa, "fogo") {
    
}

int PokemonFogo::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double mult = 1.0;

    if (tipoAtacante == "agua") {
        mult = 2.0;
    } else if (tipoAtacante == "planta") {
        mult = 0.5;
    }

    return std::max(1, static_cast<int>(std::round(dano * mult)));
}