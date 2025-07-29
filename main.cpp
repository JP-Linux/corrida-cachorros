#include "include/GerenciadorCorrida.hpp"
#include "include/Apostador.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

std::string remove_espacos(std::string str) {
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

int main() {
    GerenciadorCorrida corrida;
    Apostador jogador(100); // Começa com 100 moedas

    // Adicionar cachorros
    corrida.adicionarCachorro(Cachorro('#', "Rex    "));
    corrida.adicionarCachorro(Cachorro('#', "Lucky  "));
    corrida.adicionarCachorro(Cachorro('#', "Bolt   "));
    corrida.adicionarCachorro(Cachorro('#', "Flash  "));
    corrida.adicionarCachorro(Cachorro('#', "Speedy "));

    while (jogador.getSaldo() > 0) {
        corrida.reset();
        jogador.resetAposta();

        // Mostrar status
        std::cout << "===== CORRIDA DE CACHORROS =====\n";
        std::cout << "Seu saldo: " << jogador.getSaldo() << " moedas\n\n";

        // Listar cachorros
        const auto& cachorros = corrida.getCachorros();
        std::cout << "Cachorros disponiveis:\n";
        for (int i = 0; i < cachorros.size(); i++) {
            std::cout << i+1 << ". " << remove_espacos(cachorros[i].getNome()) << "\n";
        }

        // Obter aposta
        int escolha;
        int valor;

        std::cout << "\nEscolha um cachorro (1-" << cachorros.size() << "): ";
        std::cin >> escolha;

        if (escolha < 1 || escolha > cachorros.size()) {
            std::cout << "Escolha invalida!\n";
            continue;
        }

        const std::string& nCachorro = cachorros[escolha-1].getNome();
        const std::string nomeCachorro = remove_espacos(nCachorro);
        std::cout << "Quanto quer apostar em " << nomeCachorro << "? ";
        std::cin >> valor;

        if (!jogador.apostar(valor, nomeCachorro)) {
            std::cout << "Aposta invalida! Saldo insuficiente ou valor negativo.\n";
            continue;
        }

        // Executar corrida
        corrida.executar();

        // Processar resultados
        const auto& ordem = corrida.getOrdemChegada();
        std::vector<std::string> nomes;
        for (const auto& c : cachorros) {
            nomes.push_back(c.getNome());
        }

        jogador.processarResultado(ordem, nomes);

        // Verificar se o jogador quer continuar
        if (jogador.getSaldo() <= 0) {
            std::cout << "Faliu! Game over.\n";
            break;
        }

        char continuar;
        std::cout << "\nContinuar apostando? (s/n): ";
        std::cin >> continuar;

        if (continuar != 's' && continuar != 'S') {
            std::cout << "Voce saiu com " << jogador.getSaldo() << " moedas!\n";
            break;
        }

        // Limpar buffer de entrada
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
