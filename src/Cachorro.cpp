#include "Cachorro.hpp"
#include <iostream>
#include <random>
#include <algorithm>
#include <iomanip>

constexpr int TAMANHO_PISTA = 50;

Cachorro::Cachorro(char s, std::string n)
: posicao(0), simbolo(s), nome(std::move(n)) {}

void Cachorro::mover() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::discrete_distribution<> dist({5, 3, 2});

    const int movimento = dist(gen) + 1;
    posicao = std::min(posicao + movimento, TAMANHO_PISTA - 1);
}

bool Cachorro::venceu() const {
    return posicao >= TAMANHO_PISTA - 1;
}

void Cachorro::imprimir(size_t nameWidth) const {
    // Usar largura fixa para alinhar os nomes
    std::cout << std::left << std::setw(nameWidth) << nome << ": ";
    for (int i = 0; i < TAMANHO_PISTA; i++) {
        std::cout << (i == posicao ? simbolo : '-');
    }
    std::cout << '\n';
}

const std::string& Cachorro::getNome() const {
    return nome;
}

int Cachorro::getPosicao() const {
    return posicao;
}

void Cachorro::reset() {
    posicao = 0;
}
