#include "include/GerenciadorCorrida.hpp"
#include "include/Apostador.hpp"
#include "include/Utils.hpp"
#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>

void mostrarCabecalho(int saldo) {
    Utils::clearScreen();
    std::cout << "════════════════════════════════════════\n"
    << "         🐕 CORRIDA DE CACHORROS 🐕\n"
    << "════════════════════════════════════════\n"
    << " Saldo: \033[1;33m" << saldo << " moedas\033[0m\n\n";
}

int main() {
    GerenciadorCorrida corrida;
    Apostador jogador(100);

    // Adicionar cachorros com nomes alinhados
    corrida.adicionarCachorro(Cachorro('#', "Rex"));
    corrida.adicionarCachorro(Cachorro('#', "Lucky"));
    corrida.adicionarCachorro(Cachorro('#', "Bolt"));
    corrida.adicionarCachorro(Cachorro('#', "Flash"));
    corrida.adicionarCachorro(Cachorro('#', "Speedy"));

    while (jogador.getSaldo() > 0) {
        corrida.reset();
        jogador.resetAposta();
        mostrarCabecalho(jogador.getSaldo());

        // Listar cachorros
        const auto& cachorros = corrida.getCachorros();
        std::cout << "  🐶 CACHORROS DISPONÍVEIS:\n";
        for (size_t i = 0; i < cachorros.size(); ++i) {
            std::cout << "  " << i+1 << ". " << cachorros[i].getNome() << '\n';
        }

        // Obter aposta
        std::cout << "\n  ➡️  Escolha um cachorro (1-" << cachorros.size() << "): ";
        int escolha = Utils::getValidatedInt(1, cachorros.size()) - 1;

        std::cout << "  💰 Valor da aposta: ";
        int valor = Utils::getValidatedInt(1, jogador.getSaldo());

        if (!jogador.apostar(valor, escolha)) {
            std::cerr << "\n\033[1;31mERRO: Aposta inválida!\033[0m\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            continue;
        }

        // Executar corrida
        corrida.executar();

        // Processar resultados
        jogador.processarResultado(corrida.getOrdemChegada());

        // Verificar game over
        if (jogador.getSaldo() <= 0) {
            std::cout << "\n\033[1;31m» GAME OVER! Sem moedas restantes.\033[0m\n";
            break;
        }

        // Continuar jogando?
        std::cout << "\n  ▶️  Continuar apostando? (s/n): ";
        char continuar;
        std::cin >> continuar;
        Utils::clearInputBuffer();

        if (std::tolower(continuar) != 's') {
            std::cout << "\n  Saldo final: \033[1;33m" << jogador.getSaldo() << " moedas\033[0m\n";
            break;
        }
    }

    std::cout << "\n  Obrigado por jogar!\n";
    return 0;
}
