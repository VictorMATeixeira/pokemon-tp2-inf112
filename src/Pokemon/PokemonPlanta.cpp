#include "Pokemon.hpp"
#include "PokemonPlanta.hpp"
#include "GolpeDano.hpp"
#include "GolpeCura.hpp"
#include <algorithm>
#include <cmath>

PokemonPlanta::PokemonPlanta(std::string nome, int idPokemon, int vida, int ataque, int defesa) 
: Pokemon(nome, idPokemon, vida, ataque, defesa, "planta") {
    if (nome == "Bulbasaur") {
    definirGolpe(0, new GolpeDano("Chicote de Vinha", 12));
    } else if (nome == "Oddish") {
    definirGolpe(0, new GolpeDano("Absorção", 12));
    } else if (nome == "Bellsprout") {
    definirGolpe(0, new GolpeDano("Folha Navalha", 12));
    }    
    definirGolpe(1, new GolpeCura("Semente Sanguessuga", 6, 5));
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