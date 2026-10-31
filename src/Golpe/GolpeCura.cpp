#include "GolpeCura.hpp"

GolpeCura::GolpeCura(std::string nome, int poder, int quantidade) 
: Golpe(nome), _poder(poder), _quantidade(quantidade) {}

std::string GolpeCura::aplicar(Pokemon& atacante, Pokemon& alvo) {
    int danoCalculado = calcularDano(atacante, alvo, this->_poder);
    int danoEfetivo = alvo.perderVida(danoCalculado);
    int curaEfetiva = atacante.curar(this->_quantidade);
    return atacante.getNome() + " usou " + this->getNome() + " e causou " + std::to_string(danoEfetivo) + " de dano " +
    atacante.getNome() + " recuperou " + std::to_string(curaEfetiva) + " de vida!";
}