#include "GolpeReducaoAtaque.hpp"

GolpeReducaoAtaque::GolpeReducaoAtaque(std::string nome, int poder) : Golpe(nome) , _poder(poder) {}

std::string GolpeReducaoAtaque::aplicar(Pokemon& atacante, Pokemon& alvo) {
    int danoCalculado = calcularDano(atacante, alvo, this->_poder);
    int danoEfetivo = alvo.perderVida(danoCalculado);
    if(alvo.derrotado()){
       return atacante.getNome() + "usou" + this->getNome() + "e causou" + std::to_string(danoEfetivo) + "de dano!"; 
    }
    alvo.reduzirAtaque(8);
    return atacante.getNome() + "usou" + this->getNome() + "e causou" + std::to_string(danoEfetivo)
    + "de dano" + atacante.getNome() + "aplicou uma reducao de dano!";
}