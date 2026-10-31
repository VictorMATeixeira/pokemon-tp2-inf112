#include "Fortificante.hpp"

Fortificante::Fortificante() : Item("Fortificante") {}

bool Fortificante::usar(Pokemon& alvo) {
    if(alvo.derrotado()){
        return false;
    }
    if(alvo.getFortalecido()){
        return false;
    }
    alvo.fortalecer();
    return true;
}