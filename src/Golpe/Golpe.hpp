#ifndef GOLPE_HPP
#define GOLPE_HPP

#include "../Pokemon/Pokemon.hpp"
#include <string>
class Pokemon;

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
    virtual std::string aplicar(Pokemon& atacante, Pokemon& alvo) = 0;
protected:
    int calcularDano(Pokemon& atacante, Pokemon& alvo, int poder);
};

#endif