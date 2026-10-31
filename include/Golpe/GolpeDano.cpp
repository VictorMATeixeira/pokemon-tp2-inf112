#include "GolpeDano.hpp"


GolpeDano::GolpeDano(std::string nome, int poder) : Golpe(nome), _poder(poder) {}

std::string GolpeDano::aplicar(Pokemon& atacante, Pokemon& alvo) {
    int danoCalculado = calcularDano(atacante, alvo, this->_poder);
    int danoEfetivo = alvo.perderVida(danoCalculado);

    return atacante.getNome() + "usou" + this->getNome() + "e causou" + std::to_string(danoEfetivo) + "de dano!";
}