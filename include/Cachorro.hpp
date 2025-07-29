#ifndef CACHORRO_HPP
#define CACHORRO_HPP

#include <string>

class Cachorro {
private:
    int posicao;
    char simbolo;
    std::string nome;

public:
    Cachorro(char s, const std::string& n);
    void mover();
    bool venceu() const;
    void imprimir() const;
    std::string getNome() const;
    int getPosicao() const;
    void reset();
};

#endif
