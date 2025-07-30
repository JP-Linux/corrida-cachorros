#ifndef APOSTADOR_HPP
#define APOSTADOR_HPP

#include <vector>

class Apostador {
private:
    int saldo;
    int apostaValor;
    int indiceCachorroApostado;
    bool apostaAtiva;

public:
    explicit Apostador(int saldoInicial);
    bool apostar(int valor, int indiceCachorro);
    void processarResultado(const std::vector<int>& ordemChegada);
    int getSaldo() const;
    bool temApostaAtiva() const;
    void resetAposta();
};

#endif
