#ifndef GERENCIADOR_CORRIDA_HPP
#define GERENCIADOR_CORRIDA_HPP

#include "Cachorro.hpp"
#include <vector>

class GerenciadorCorrida {
private:
    std::vector<Cachorro> cachorros;
    std::vector<int> ordemChegada;

public:
    void adicionarCachorro(const Cachorro& cachorro);
    void executar();
    const std::vector<int>& getOrdemChegada() const;
    const std::vector<Cachorro>& getCachorros() const;
    void reset();
};

#endif
