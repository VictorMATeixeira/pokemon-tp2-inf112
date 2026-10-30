#include <fstream>
#include <string>

#include "Pokemon.hpp"
#include "PokemonAgua.hpp"
#include "PokemonEletrico.hpp"
#include "PokemonFogo.hpp"
#include "PokemonPlanta.hpp"
#include "Treinador.hpp"

Treinador::Treinador(std::string nome, int pokemons[3]) {
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
}