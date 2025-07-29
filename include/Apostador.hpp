#ifndef APOSTADOR_HPP
#define APOSTADOR_HPP

#include <string>
#include <vector>

class Apostador {
private:
    int saldo;
    int apostaValor;
    std::string cachorroApostado;
    bool apostaAtiva;

public:
    Apostador(int saldoInicial);
    bool apostar(int valor, const std::string& nomeCachorro);
    void processarResultado(const std::vector<int>& ordemChegada,
                            const std::vector<std::string>& nomesCachorros);
    int getSaldo() const;
    bool temApostaAtiva() const;
    void resetAposta();
};

#endif
