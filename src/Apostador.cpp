#include "Apostador.hpp"
#include <algorithm>
#include <iostream>

Apostador::Apostador(int saldoInicial)
: saldo(saldoInicial), apostaValor(0),
indiceCachorroApostado(-1), apostaAtiva(false) {}

bool Apostador::apostar(int valor, int indiceCachorro) {
    if (valor <= 0 || valor > saldo) return false;

    apostaValor = valor;
    indiceCachorroApostado = indiceCachorro;
    apostaAtiva = true;
    saldo -= valor;
    return true;
}

void Apostador::processarResultado(const std::vector<int>& ordemChegada) {
    if (!apostaAtiva) return;

    apostaAtiva = false;
    auto it = std::find(ordemChegada.begin(), ordemChegada.end(), indiceCachorroApostado);

    if (it == ordemChegada.end()) {
        std::cout << "Erro: Cachorro apostado não encontrado nos resultados!\n";
        return;
    }

    const int posicao = std::distance(ordemChegada.begin(), it);

    switch(posicao) {
        case 0:
            saldo += apostaValor * 3;
            std::cout << "\n\033[1;32m» 1º lugar! Ganhou " << apostaValor * 3 << " moedas!\033[0m\n";
            break;
        case 1:
            saldo += apostaValor * 2;
            std::cout << "\n\033[1;33m» 2º lugar! Ganhou " << apostaValor * 2 << " moedas!\033[0m\n";
            break;
        case 2:
            saldo += apostaValor;
            std::cout << "\n\033[1;34m» 3º lugar! Recebeu de volta " << apostaValor << " moedas.\033[0m\n";
            break;
        default:
            std::cout << "\n\033[1;31m» Fora do pódio! Perdeu " << apostaValor << " moedas.\033[0m\n";
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
    indiceCachorroApostado = -1;
    apostaValor = 0;
}
