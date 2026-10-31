# 1. Pega todas as pastas dentro de src/ sem pegar arquivos
PASTAS = src $(sort $(dir $(wildcard src/*/ src/*/*/)))
INCLUDES = $(addprefix -I,$(PASTAS))

# 2. Busca recursivamente todos os arquivos .cpp do seu código
FONTES = $(wildcard src/*.cpp) \
         $(wildcard src/*/*.cpp) \
         $(wildcard src/*/*/*.cpp)

# 3. Validação dos cabeçalhos base
CABECALHOS_MODELO = Treinador.hpp Pokemon.hpp Golpe.hpp Item.hpp
CABECALHOS_PRESENTES = $(notdir $(wildcard src/*.hpp src/*/*.hpp src/*/*/*.hpp))
CABECALHOS_FALTANTES = $(filter-out $(CABECALHOS_PRESENTES),$(CABECALHOS_MODELO))

ifneq ($(strip $(CABECALHOS_FALTANTES)),)
MODO_MODELO = 0
FONTES_COMPILACAO =
else
MODO_MODELO = 1
FONTES_COMPILACAO = $(FONTES)
endif

compilar: raylib
	@echo "Integração das classes: $(MODO_MODELO) (0 = somente interface, 1 = código dos alunos)"
	@echo "Arquivos de alunos a compilar: $(FONTES_COMPILACAO)"
	mkdir -p lib/.build
	g++ -std=c++11 -DMODELO_DISPONIVEL=$(MODO_MODELO) \
		$(INCLUDES) $(INCLUDES_BIBLIOTECAS) \
		$(FONTES_COMPILACAO) lib/apoio/*.cpp lib/interface/*.cpp \
		$(OBJETOS_RAYLIB) $(BIBLIOTECAS) \
		-o lib/.build/pokemon

run: compilar
	cd lib && ./.build/pokemon

clean:
	rm -rf lib/.build

all: compilar

.PHONY: compilar run clean all

include lib/bibliotecas.mk