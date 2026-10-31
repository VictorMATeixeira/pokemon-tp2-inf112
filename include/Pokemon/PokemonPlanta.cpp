#include "Pokemon.hpp"
#include "PokemonPlanta.hpp"
#include <algorithm>
#include <cmath>

PokemonPlanta::PokemonPlanta(std::string nome, int idPokemon, int vida, int ataque, int defesa) 
: Pokemon(nome, idPokemon, vida, ataque, defesa, "planta") {
    
}

int PokemonPlanta::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double mult = 1.0;

    if (tipoAtacante == "fogo") {
        mult = 2.0;
    } else if (tipoAtacante == "agua") {
        mult = 0.5;
    }

    return std::max(1, static_cast<int>(std::round(dano * mult)));
}