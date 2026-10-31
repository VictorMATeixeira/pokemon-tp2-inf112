# ⚔️ Pokémon Battle System (INF 112 - TP2)

![C++11](https://img.shields.io/badge/C%2B%2B-11-blue.svg)
![Raylib](https://img.shields.io/badge/GUI-Raylib-red.svg)
![Build](https://img.shields.io/badge/Build-Makefile-green.svg)

Um sistema de batalha por turnos inspirado nos jogos clássicos da franquia Pokémon (*FireRed / LeafGreen*), desenvolvido em **C++11** e integrado a uma interface gráfica moderna utilizando a biblioteca **Raylib**.

---

## 📌 Sobre o Projeto

O objetivo principal deste projeto é aplicar e consolidar os conceitos fundamentais de **Programação Orientada a Objetos (POO)** em C++, tais como:

* **Herança e Polimorfismo:** Representação de tipos de Pokémon, golpes com diferentes efeitos e itens utilizáveis através de métodos virtuais puros e sobrescrita (`override`).
* **Encapsulamento e Abstração:** Isolamento das regras de negócio (cálculo de dano, ordem de turnos, efeitos temporários) das camadas de renderização gráfica.
* **Gerenciamento Seguro de Memória:** Alocação dinâmica de ponteiros (`new`/`delete`), destrutores virtuais em cadeia e ausência total de vazamentos de memória (*memory leaks* testados via Valgrind).

---

## 🎯 Funcionalidades e Regras de Negócio

* **Mecânica de Batalha por Turnos:** Confronto entre dois treinadores, cada um gerenciando uma equipe de 3 Pokémons e um inventário de itens.
* **Tipos e Vantagens Elementais:** Tabela de multiplicadores de dano baseada nos tipos Fogo, Água, Planta e Elétrico.
* **Categorias de Golpes:**
  * **Dano Direto:** Inflige dano baseado nas estatísticas do atacante e defensor.
  * **Cura:** Causa dano ao oponente e recupera pontos de vida do atacante.
  * **Redução de Ataque:** Reduz temporariamente o poder do próximo ataque adversário.
* **Sistema de Itens:** Uso único por partida de itens de *Cura* e *Fortificante* (aumento percentual de dano).

---

## 🏗️ Arquitetura e Estrutura do Projeto

O código é estruturado de forma modular em diretórios bem definidos:

```text
.
├── src/                      # Código-fonte das classes desenvolvidas
│   ├── Pokemon/              # Hierarquia das classes de Pokémon (Fogo, Agua, Planta, Eletrico)
│   ├── Golpe/                # Hierarquia dos golpes (Dano, Cura, ReducaoAtaque)
│   ├── Item/                 # Hierarquia dos itens (Cura, Fortificante)
│   └── Treinador/            # Gestão de equipe, inventário e estado de jogo
├── lib/                      # Dependências, suporte à interface e recursos
│   ├── assets/               # Texturas, fontes e áudios do jogo
│   ├── interface/            # Modulo gráfico em Raylib
│   └── apoio/                # Utilitários e manipuladores de arquivos
├── pokemons.txt              # Arquivo de dados das estatísticas base dos Pokémons
└── Makefile                  # Script de compilação e automação

---

## 🚀 Como Compilar e Executar

### 1. Pré-requisitos
Certifique-se de que possui o compilador `g++` (com suporte a C++11), o `make` e as bibliotecas de desenvolvimento da Raylib instaladas no ambiente Linux/WSL:

```bash
sudo apt update
sudo apt install build-essential libraylib-dev

⚙️ Passo 2: Compilar e Iniciar a Aplicação
Para compilar todo o código fonte e abrir o jogo imediatamente, execute o comando a seguir na raiz do repositório:

make run
make compilar
make clean
make compilar
valgrind --leak-check=full --show-leak-kinds=all ./lib/.build/pokemon (opcional)

🛠️ Tecnologias Utilizadas

-Linguagem: C++11
-Biblioteca Gráfica e Som: Raylib
-Automação de Build: GNU Make
-Verificação de Memória: Valgrind
