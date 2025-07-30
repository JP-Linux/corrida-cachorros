#include "GerenciadorCorrida.hpp"
#include "Utils.hpp"
#include <thread>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

constexpr int TEMPO_ESPERA = 300;

void GerenciadorCorrida::adicionarCachorro(Cachorro&& cachorro) {
    cachorros.push_back(std::move(cachorro));
}

void GerenciadorCorrida::executar() {
    ordemChegada.clear();
    ordemChegada.reserve(cachorros.size());
    int totalTerminados = 0;
    const int totalCachorros = cachorros.size();

    // Calcular largura máxima dos nomes para alinhamento
    std::vector<std::string> nomes;
    for (const auto& c : cachorros) {
        nomes.push_back(c.getNome());
    }
    size_t nameWidth = Utils::maxNameLength(nomes) + 2;

    while (totalTerminados < totalCachorros) {
        Utils::clearScreen();
        totalTerminados = 0;

        for (auto& cachorro : cachorros) {
            if (!cachorro.venceu()) {
                cachorro.mover();
            }

            if (cachorro.venceu()) {
                const int index = &cachorro - &cachorros[0];
                if (std::find(ordemChegada.begin(), ordemChegada.end(), index) == ordemChegada.end()) {
                    ordemChegada.push_back(index);
                }
                totalTerminados++;
            }

            // Passar a largura para alinhamento
            cachorro.imprimir(nameWidth);
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
