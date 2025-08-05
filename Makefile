CXX := g++
CXXFLAGS := -Iinclude -std=c++17 -Wall -Wextra -O2
OBJ_DIR := obj
SRC_DIR := src
TARGET := corrida_cachorros

# Buscar todos os .cpp no src/ e main.cpp na raiz
SRCS := $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regra genérica para compilar qualquer .cpp
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra específica para main.cpp (está na raiz)
$(OBJ_DIR)/main.o: main.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
