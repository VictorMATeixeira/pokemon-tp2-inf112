#include "Item.hpp"

Item::Item(std::string nome) : _nome(nome) {}
Item::~Item() {}
//gets
std::string Item::getNome() const {return _nome;}