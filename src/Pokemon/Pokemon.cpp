#include "Pokemon.hpp"
#include "Golpe.hpp"

Pokemon::Pokemon(std::string nome, int idPokemon, int vida, int ataque, int defesa, std::string tipo) 
: _nome(nome), _idPokemon(idPokemon), _vida(vida), _ataque(ataque), _defesa(defesa), _tipo(tipo),
 _vidaMaxima(vida), _reducaoProximoAtaque(0), _fortalecido(false) {
    golpes[0] = nullptr;
    golpes[1] = nullptr;
}

Pokemon::~Pokemon() {
    delete golpes[1];
    delete golpes[0];
    golpes[1] = nullptr;
    golpes[0] = nullptr;
}

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
Golpe* Pokemon::getGolpe(int indice) const {
    if(indice >= 0 && indice <= 1){
        if(golpes[indice]!=nullptr){
            return golpes[indice];
        }
    }
    return nullptr;
}
//demais metodos
bool Pokemon::derrotado() const{
    if(_vida <=0){
        return true;
    }
    return false;
}
//aloca dinamicamente um novo golpe na posicao selecionada do array Golpe[2]
void Pokemon::definirGolpe(int indice, Golpe* golpe) {
    if(indice >=0 && indice <=1){
        if(golpes[indice]!=nullptr){//caso haja algum objeto na posicao selecionada o mesmo eh destruido
            delete golpes[indice];
        }
         golpes[indice] = golpe; //define propriamente o golpe na posicao selecionada
    }
    else{
        delete golpe;
    }
    
}

int Pokemon::perderVida(int quantidade) {
    //verificar se não há ataques com dano negativo
    if(quantidade < 0){
        return 0;
    }
    int vidaAnterior = _vida; 
    _vida -= quantidade;
    if(_vida<0){
        _vida=0;
    }
    return vidaAnterior - _vida; //retorna a quantidade de vida que de fato foi subtraida 
}

int Pokemon::curar(int quantidade) {
    //verifcar se já não esta fora de combate
    if(derrotado()){
        return 0;
    }
    //verificar se não há cura com valor negativo
    if(quantidade < 0 ){
        return 0;
    }
    int vidaAnterior = _vida;
    _vida +=quantidade;
    if(_vida > _vidaMaxima){ //impede extrapolar a vida máxima do pokemon
        _vida = _vidaMaxima;
    }
    return _vida - vidaAnterior; //retorna a quantidade de vida que de fato foi incrementada pela cura
}

void Pokemon::reduzirAtaque(int quantidade){
    if(quantidade > 0){
        _reducaoProximoAtaque = quantidade; //quantidade padrao definida como 8
    }
}

int Pokemon::consumirReducaoAtaque() {
    if(_reducaoProximoAtaque > 0){
        int reducao = _reducaoProximoAtaque;
        _reducaoProximoAtaque = 0;
        return reducao;
    }
    return 0;
}

bool Pokemon::fortalecer() {
    if(derrotado() || _fortalecido){
        return false;
    }
    _fortalecido = true;
    return true;
}

double Pokemon::consumirFortalecimento() {
    if(_fortalecido){
        _fortalecido = false;
        return 1.1; //fortalecimento em 10%
    }
    return 1.0;
}
