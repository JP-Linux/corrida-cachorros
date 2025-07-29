CXX = g++
CXXFLAGS = -Iinclude -std=c++11
OBJ_DIR = obj
SRC_DIR = src

OBJS = $(OBJ_DIR)/Cachorro.o \
       $(OBJ_DIR)/GerenciadorCorrida.o \
       $(OBJ_DIR)/Apostador.o \
       $(OBJ_DIR)/main.o

all: corrida_cachorros

corrida_cachorros: $(OBJS)
	$(CXX) $^ -o $@

$(OBJ_DIR)/Cachorro.o: $(SRC_DIR)/Cachorro.cpp include/Cachorro.hpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/GerenciadorCorrida.o: $(SRC_DIR)/GerenciadorCorrida.cpp include/GerenciadorCorrida.hpp include/Cachorro.hpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/Apostador.o: $(SRC_DIR)/Apostador.cpp include/Apostador.hpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: main.cpp include/GerenciadorCorrida.hpp include/Apostador.hpp include/Cachorro.hpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) corrida_cachorros
