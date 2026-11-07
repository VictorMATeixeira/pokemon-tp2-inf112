#include "Pokemon.hpp"
#include "PokemonAgua.hpp"
#include "GolpeDano.hpp"
#include "GolpeCura.hpp"
#include <algorithm>
#include <cmath>

//construtor definindo o golpe de cada pokemon pelo nome
PokemonAgua::PokemonAgua(std::string nome, int idPokemon, int vida, int ataque, int defesa) 
: Pokemon(nome, idPokemon, vida, ataque, defesa, "agua") { //aquatico 
    if (nome == "Squirtle") {
    definirGolpe(0, new GolpeDano("Jato d'Água", 12));
    } else if (nome == "Psyduck") {
    definirGolpe(0, new GolpeDano("Pulso de Água", 12));
    }
    definirGolpe(1, new GolpeCura("Aqua Cura", 6, 5));
} 
//calculando o dano por meio de um multiplicador 
int PokemonAgua::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double mult = 1.0;

    if (tipoAtacante == "fogo") {
        mult = 0.5;
    } else if (tipoAtacante == "eletrico" || tipoAtacante == "planta") {
        mult = 2.0;
    }

    return std::max(1, static_cast<int>(std::round(dano * mult))); 
}