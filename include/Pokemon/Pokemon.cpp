#include "Pokemon.hpp"
#include <iostream>

Pokemon::Pokemon(std::string nome, int idPokemon, int vida, int ataque, int defesa, std::string tipo) 
: _nome(nome), _idPokemon(idPokemon), _vida(vida), _ataque(ataque), _defesa(defesa), _tipo(tipo)  {}

Pokemon::~Pokemon() {}

//gets
std::string Pokemon::getNome() const {return _nome;}
std::string Pokemon::getTipo() const {return _tipo;}
int Pokemon::getIdPokemon() const {return _idPokemon;}
int Pokemon::getVida() const {return _vida;}
int Pokemon::getVidaMaxima() const {return _vidaMaxima;}
int Pokemon::getAtaque() const {return _ataque;}
int Pokemon::getDefesa() const {return _defesa;}
unsigned int Pokemon::getReducaoProximoAtaque() const {return _reducaoProximoAtaque;}
bool Pokemon::getFortalecido() const {return _fortalecido;}
Golpe* Pokemon::getGolpe(int indice) {
    if(indice == 0 || indice == 1)
        return golpes[indice];
    return;
}