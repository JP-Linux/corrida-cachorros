#include "Cachorro.hpp"
#include <iostream>
#include <random>
#include <algorithm> // Para std::min

constexpr int TAMANHO_PISTA = 50;

Cachorro::Cachorro(char s, const std::string& n)
: simbolo(s), nome(n), posicao(0) {}

void Cachorro::mover() {
    static std::mt19937 eng(std::random_device{}());
    static std::uniform_int_distribution<> dist(1, 6);
    int num = dist(eng);

    // Movimento mais variado: 50% chance de 1 passo, 30% de 2 passos, 20% de 3 passos
    if (num <= 3) {
        posicao = std::min(posicao + 1, TAMANHO_PISTA - 1);
    } else if (num <= 5) {
        posicao = std::min(posicao + 2, TAMANHO_PISTA - 1);
    } else {
        posicao = std::min(posicao + 3, TAMANHO_PISTA - 1);
    }
}

bool Cachorro::venceu() const {
    return posicao >= TAMANHO_PISTA - 1;
}

void Cachorro::imprimir() const {
    std::cout << nome << ": ";
    for (int i = 0; i < TAMANHO_PISTA; i++) {
        std::cout << (i == posicao ? simbolo : '-');
    }
    std::cout << std::endl;
}

std::string Cachorro::getNome() const {
    return nome;
}

int Cachorro::getPosicao() const {
    return posicao;
}

void Cachorro::reset() {
    posicao = 0;
}
