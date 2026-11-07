#include "Pokemon.hpp"
#include "PokemonFogo.hpp"
#include "GolpeDano.hpp"
#include "GolpeReducaoAtaque.hpp"
#include <algorithm>
#include <cmath>

//construtor definindo o golpe de cada pokemon pelo nome
PokemonFogo::PokemonFogo(std::string nome, int idPokemon, int vida, int ataque, int defesa) 
: Pokemon(nome, idPokemon, vida, ataque, defesa, "fogo") {
    if (nome == "Charmander") {
    definirGolpe(0, new GolpeDano("Lança-Chamas", 12));
    } else if (nome == "Vulpix") {
    definirGolpe(0, new GolpeDano("Brasas", 12));
    } else if (nome == "Ponyta") {
    definirGolpe(0, new GolpeDano("Roda de Fogo", 12));
    } else if (nome == "Growlithe") {
    definirGolpe(0, new GolpeDano("Presa de Fogo", 12));
    }    
    definirGolpe(1, new GolpeReducaoAtaque("Cortina de Fumaça", 6));
}
//calculando o dano por meio de um multiplicador 
int PokemonFogo::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double mult = 1.0;

    if (tipoAtacante == "agua") {
        mult = 2.0;
    } else if (tipoAtacante == "planta") {
        mult = 0.5;
    }

    return std::max(1, static_cast<int>(std::round(dano * mult)));
}