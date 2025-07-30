#ifndef CACHORRO_HPP
#define CACHORRO_HPP

#include <string>

class Cachorro {
private:
    int posicao;
    char simbolo;
    std::string nome;

public:
    Cachorro(char s, std::string  n);
    void mover();
    bool venceu() const;
    void imprimir(size_t nameWidth) const;  // Adicionado parâmetro para largura
    const std::string& getNome() const;
    int getPosicao() const;
    void reset();
};

#endif
