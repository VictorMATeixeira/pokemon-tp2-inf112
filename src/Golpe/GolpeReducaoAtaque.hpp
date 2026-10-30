#ifndef GOLPEREDUCAOATAQUE_HPP
#define GOLPEREDUCAOATAQUE_HPP

#include <string>
#include "Golpe.hpp"

class GolpeReducaoAtaque : public Golpe{
private:
    int _poder;
public:
    //inicialização
    GolpeReducaoAtaque(std::string nome, int poder);
    //metodos herança
    std::string aplicar(Pokemon& atacante, Pokemon& alvo) override;
};

#endif