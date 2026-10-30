#ifndef CURA_HPP
#define CURA_HPP

#include <string>
#include "Item.hpp"

class Cura : public Item{
public:
    //inicialização
    Cura();
    //metodos herança
    bool usar(Pokemon& alvo) override;
};

#endif