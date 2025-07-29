#include "../include/Apostador.hpp"
#include <iostream>
#include <algorithm>

Apostador::Apostador(int saldoInicial)
    : saldo(saldoInicial), apostaValor(0), apostaAtiva(false) {}

bool Apostador::apostar(int valor, const std::string& nomeCachorro) {
    if (valor > saldo || valor <= 0) {
        return false;
    }

    apostaValor = valor;
    cachorroApostado = nomeCachorro;
    apostaAtiva = true;
    saldo -= valor;
    return true;
}

void Apostador::processarResultado(const std::vector<int>& ordemChegada,
                                  const std::vector<std::string>& nomesCachorros) {
    if (!apostaAtiva) return;

    apostaAtiva = false;
    int posicao = -1;

    // Encontrar a posição do cachorro apostado na ordem de chegada
    for (int i = 0; i < ordemChegada.size(); i++) {
        if (nomesCachorros[ordemChegada[i]] == cachorroApostado) {
            posicao = i;
            break;
        }
    }

    // Calcular prêmio baseado na posição
    if (posicao == 0) {
        saldo += apostaValor * 3; // 3x o valor apostado
        std::cout << cachorroApostado << " ficou em 1o! Voce ganhou "
                  << apostaValor * 3 << " moedas!\n";
    } else if (posicao == 1) {
        saldo += apostaValor * 2; // 2x o valor apostado
        std::cout << cachorroApostado << " ficou em 2o! Voce ganhou "
                  << apostaValor * 2 << " moedas!\n";
    } else if (posicao == 2) {
        saldo += apostaValor; // Devolve a aposta
        std::cout << cachorroApostado << " ficou em 3o! Voce recebeu de volta "
                  << apostaValor << " moedas.\n";
    } else {
        std::cout << cachorroApostado << " nao ficou no podium. Voce perdeu "
                  << apostaValor << " moedas.\n";
    }
}

int Apostador::getSaldo() const {
    return saldo;
}

bool Apostador::temApostaAtiva() const {
    return apostaAtiva;
}

void Apostador::resetAposta() {
    apostaAtiva = false;
}
