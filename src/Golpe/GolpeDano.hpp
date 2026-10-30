#ifndef GOLPEDANO_HPP
#define GOLPEDANO_HPP

#include <string>
#include "Golpe.hpp"

class GolpeDano : public Golpe{
private:
    int _poder;
public:
    //inicialização
    GolpeDano(std::string nome, int poder);
    //metodos herança
    std::string aplicar(Pokemon& atacante, Pokemon& alvo) override;
};

#endif