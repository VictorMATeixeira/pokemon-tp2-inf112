#ifndef TREINADOR_HPP
#define TREINADOR_HPP

#include <string>
#include "Pokemon.hpp"
#include "Item.hpp"

class Treinador{
private:
    std :: string _nome;
    Pokemon* _equipe[3];
    Item* itens[2];
    int _ativo;
public:
    //inicialização
    Treinador(std::string nome, int pokemons[3]);
    virtual ~Treinador();
    //gets
    std::string getNome() const;
    Pokemon* getPokemon(int indice) const;
    Pokemon* getAtivo() const;
    Item* getItem(int indice) const;
    int getIndiceAtivo() const;
    //metodos exclusivos
    bool trocar(int indice);
    bool perdeu();
    bool usarItem(int item, int alvo);
};

#endif