#ifndef GOLPE_HPP
#define GOLPE_HPP

#include "Pokemon.hpp"
#include <string>

class Golpe{
private:
    std :: string _nome;
public:
    //inicialização
    Golpe(std::string nome);
    virtual ~Golpe();
    //gets
    std::string getNome() const;
    //metodos exclusivos
    virtual std::string aplicar(Pokemon& atacante, Pokemon& alvo);
protected:
    int calcularDano(Pokemon& atacante, Pokemon& alvo, int poder);
};

#endif