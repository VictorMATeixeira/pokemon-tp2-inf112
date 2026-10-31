#include "Cura.hpp"

Cura::Cura() : Item("Cura") {}

bool Cura::usar(Pokemon& alvo) {
    if(alvo.derrotado()){
        return false;
    }
    else if(alvo.getVida()==alvo.getVidaMaxima()){
        return false;
    }
    alvo.curar(20);
    return true;
}