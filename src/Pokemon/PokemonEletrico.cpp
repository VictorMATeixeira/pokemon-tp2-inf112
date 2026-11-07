#include "Pokemon.hpp"
#include "PokemonEletrico.hpp"
#include "GolpeDano.hpp"
#include "GolpeReducaoAtaque.hpp"
#include <algorithm>
#include <cmath>

//construtor definindo o golpe de cada pokemon pelo nome
PokemonEletrico::PokemonEletrico(std::string nome, int idPokemon, int vida, int ataque, int defesa) 
: Pokemon(nome, idPokemon, vida, ataque, defesa, "eletrico") {
    if (nome == "Pikachu") {
    definirGolpe(0, new GolpeDano("Choque do Trovão", 12));
    } else if (nome == "Voltorb") {
    definirGolpe(0, new GolpeDano("Bola Elétrica", 12));
    } else if (nome == "Magnemite") {
    definirGolpe(0, new GolpeDano("Faísca", 12));
    }    
    definirGolpe(1, new GolpeReducaoAtaque("Onda de Choque", 6));
}
//calculando o dano por meio de um multiplicador 
int PokemonEletrico::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double mult = 1.0;

    if (tipoAtacante == "agua") {
        mult = 0.5;
    }

    return std::max(1, static_cast<int>(std::round(dano * mult)));
}