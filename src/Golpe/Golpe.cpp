#include "Golpe.hpp"
#include "Pokemon.hpp"
#include <algorithm>
#include <cmath>

Golpe::Golpe(std::string nome) : _nome(nome) {}

Golpe::~Golpe() {}

//gets
std::string Golpe::getNome() const {return _nome;}

//metodos
int Golpe::calcularDano(Pokemon& atacante, Pokemon& alvo, int poder) {
    int reducao = atacante.consumirReducaoAtaque();
    int ataqueEfetivo = std::max(0, atacante.getAtaque() - reducao);
    int danoBase = std::max(1, poder + ataqueEfetivo - alvo.getDefesa());
    int danoTipo = alvo.calcularDanoRecebido(danoBase, atacante.getTipo());
    double fatorFortalecimento = atacante.consumirFortalecimento();
    //ocorreu uma imcompatibilidade do std::max com std::round, logo um cast foi necessario
    int danoFinal = std::max(1, static_cast<int>(std::round(danoTipo * fatorFortalecimento)));
    return danoFinal;
}