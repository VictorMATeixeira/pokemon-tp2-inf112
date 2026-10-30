#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include "Pokemon.hpp"

class Item{
private:
    std :: string _nome;
public:
    //inicialização
    Item(std::string nome);
    virtual ~Item();
    //gets
    std::string getNome() const;
    //metodos exclusivos
    virtual bool usar(Pokemon& alvo) = 0;
};

#endif