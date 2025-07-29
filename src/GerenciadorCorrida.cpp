#include "GerenciadorCorrida.hpp"
#include <thread>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype> // Para system("clear") no Linux/Mac

constexpr int TEMPO_ESPERA = 500;

void GerenciadorCorrida::adicionarCachorro(const Cachorro& cachorro) {
    cachorros.push_back(cachorro);
}

void GerenciadorCorrida::executar() {
    ordemChegada.clear();
    int totalTerminados = 0;
    const int totalCachorros = cachorros.size();

    while (totalTerminados < totalCachorros) {
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif

        totalTerminados = 0;

        for (auto& cachorro : cachorros) {
            if (!cachorro.venceu()) {
                cachorro.mover();
            }

            if (cachorro.venceu()) {
                // Se ainda não está na lista de chegada, adiciona
                int index = &cachorro - &cachorros[0];
                if (std::find(ordemChegada.begin(), ordemChegada.end(), index) == ordemChegada.end()) {
                    ordemChegada.push_back(index);
                }
                totalTerminados++;
            }

            cachorro.imprimir();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(TEMPO_ESPERA));
    }
}

const std::vector<int>& GerenciadorCorrida::getOrdemChegada() const {
    return ordemChegada;
}

const std::vector<Cachorro>& GerenciadorCorrida::getCachorros() const {
    return cachorros;
}

void GerenciadorCorrida::reset() {
    for (auto& c : cachorros) {
        c.reset();
    }
    ordemChegada.clear();
}
