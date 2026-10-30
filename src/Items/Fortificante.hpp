#ifndef FORTIFICANTE_HPP
#define FORTIFICANTE_HPP

#include <string>
#include "Item.hpp"

class Fortificante : public Item{
public:
    Fortificante();
    bool usar(Pokemon& alvo) override;
};

#endif