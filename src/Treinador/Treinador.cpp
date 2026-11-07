#include <fstream>
#include <string>

#include "Pokemon.hpp"
#include "PokemonAgua.hpp"
#include "PokemonEletrico.hpp"
#include "PokemonFogo.hpp"
#include "PokemonPlanta.hpp"
#include "Treinador.hpp"
#include "Item.hpp"
#include "Cura.hpp"
#include "Fortificante.hpp"

Treinador::Treinador(std::string nome, int pokemons[3]) : _nome(nome) {
  for (int indice = 0; indice < 3; indice++) {
    _equipe[indice] = nullptr;
  }

  std::ifstream arquivo("../pokemons.txt");

  int id, vida, ataque, defesa;
  std::string tipo, nomePokemon;

  while (arquivo >> id >> tipo >> nomePokemon >> vida >> ataque >> defesa) {
    for (int indice = 0; indice < 3; indice++) {
      if (pokemons[indice] != id || _equipe[indice] != nullptr) continue;

      if (tipo == "fogo") {
        _equipe[indice] =
            new PokemonFogo(nomePokemon, id, vida, ataque, defesa);
      } else if (tipo == "agua") {
        _equipe[indice] =
            new PokemonAgua(nomePokemon, id, vida, ataque, defesa);
      } else if (tipo == "planta") {
        _equipe[indice] =
            new PokemonPlanta(nomePokemon, id, vida, ataque, defesa);
      } else if (tipo == "eletrico") {
        _equipe[indice] =
            new PokemonEletrico(nomePokemon, id, vida, ataque, defesa);
      }
    }
  }
  //pokemon no indice 0 começa como ativo
  _ativo = 0;
  //preset item[0]=cura item[1]=fortificante
  itens[0] = new Cura();
  itens[1] = new Fortificante();
}
//destrutor 
Treinador::~Treinador() {
  for(int i=0 ; i<3 ; i++){
    if(_equipe[i] !=nullptr){
      delete _equipe[i];
      _equipe[i] = nullptr;
    }
  }
  for(int i=0; i<2; i++){
    if(itens[i] !=nullptr){
      delete itens[i];
      itens[i] = nullptr;
    }
  }
}

//gets
std::string Treinador::getNome() const {return _nome;}
Pokemon* Treinador::getPokemon(int indice) const {
  if(indice >=0 && indice <=2){
    return _equipe[indice];
  }
  return nullptr;
}

Pokemon* Treinador::getAtivo() const {return _equipe[_ativo];}
Item* Treinador::getItem(int indice) const {
  if(indice >=0 && indice <=1){
    return itens[indice];
  }
  return nullptr;
}

int Treinador::getIndiceAtivo() const {
  for(int i=0; i<3 ;i++){
    if(_equipe[i]==getAtivo()){
      return i;
    }
  }
  return _ativo;
}

//demais metodos

bool Treinador::trocar(int indice) {
  if(indice <0 || indice >2){
    return false;
  }
  if(indice == getIndiceAtivo()){
    return false;
  }
  if(_equipe[indice]->derrotado()){
    return false;
  }
  _ativo = indice;
  return true;
}

bool Treinador::perdeu() const {
  for(int i=0; i<3 ;i++){
    if(!_equipe[i]->derrotado()){
      return false;
    }
  }
  return true;
}

bool Treinador::usarItem(int item, int alvo) {
  if(item < 0 || item >1) return false;
  if(alvo < 0 || alvo >2) return false;
  if(itens[item] == nullptr || _equipe[alvo]->derrotado()) return false; //verifica se o alvo ja nao foi derrotado
  
  bool sucesso = itens[item]->usar(*_equipe[alvo]);
  if(sucesso){ //caso haja sucesso no uso ja destruimos o objeto item respectivo
    delete itens[item];
    itens[item] = nullptr;
  }
  return true;
}