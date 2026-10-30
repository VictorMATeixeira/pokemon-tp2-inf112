#ifndef GOLPECURA_HPP
#define GOLPECURA_HPP

#include <string>
#include "Golpe.hpp"

class GolpeCura : public Golpe{
private:
    int _poder, _quantidade;
public:
    //inicialização
    GolpeCura(std::string nome, int poder, int quantidade);
    //metodos herança
    std::string aplicar(Pokemon& atacante, Pokemon& alvo) override;
};

#endif