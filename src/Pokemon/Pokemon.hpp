#ifndef POKEMON_HPP
#define POKEMON_HPP

#include "Golpe.hpp"
#include <string>

class Pokemon{
private:
    std :: string _nome, _tipo;
    int _idPokemon, _vida, _vidaMaxima, _ataque, _defesa;
    unsigned int _reducaoProximoAtaque;
    bool _fortalecido;
    Golpe* golpes[2];  
public:
    //inicialização
    Pokemon(std::string nome, int idPokemon, int vida, int ataque, int defesa, std::string tipo);
    virtual ~Pokemon();
    //gets
    std::string getNome() const;
    std::string getTipo() const;
    int getIdPokemon() const;
    int getVida() const;
    int getVidaMaxima() const;
    int getAtaque() const;
    int getDefesa() const;
    unsigned int getReducaoProximoAtaque() const;
    bool getFortalecido() const;
    Golpe* getGolpe(int indice);
    //metodos exclusivos
    bool derrotado();
    void definirGolpe(int indice, Golpe* golpe);
    int perderVida(int quantidade);
    int curar(int quantidade);
    void reduzirAtaque(int quantidade);
    int consumirReducaoAtaque();
    bool fortalecer();
    double consumirFortalecimento();
    virtual int calcularDanoRecebido(int dano, std::string tipoAtacante) = 0;
};

#endif