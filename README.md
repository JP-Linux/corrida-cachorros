# 🐕 Corrida de Cachorros com Apostas

Um jogo de terminal onde você pode apostar em corridas de cachorros! Gerencie seu saldo, escolha seu cachorro favorito e assista à corrida animada no terminal.

[![GitHub Pages](https://img.shields.io/badge/GitHub%20Pages-Live-brightgreen)](https://jp-linux.github.io)
![C++](https://img.shields.io/badge/-C++-blue?logo=cplusplus)

## 🚀 Como Executar

### Pré-requisitos
- Compilador C++ (g++ recomendado)
- Sistema Linux ou Windows

### Compilação e Execução
```bash
# Clone o repositório
git clone https://github.com/JP-Linux/corrida-cachorros.git
cd corrida-cachorros

# Compilar usando Makefile
make

# Executar o programa
./corrida_cachorros
```

## 🎮 Como Jogar
1. Você começa com **100 moedas**
2. Escolha um cachorro para apostar (1-5)
3. Defina o valor da aposta
4. Assista à corrida em tempo real!
5. Receba prêmios se seu cachorro ficar no pódio:
   - 🥇 1° lugar: 3x o valor apostado
   - 🥈 2° lugar: 2x o valor apostado
   - 🥉 3° lugar: devolução da aposta

## 🧩 Estrutura do Projeto
```
├── include
│   ├── Apostador.hpp
│   ├── Cachorro.hpp
│   └── GerenciadorCorrida.hpp
├── main.cpp
├── Makefile
├── README.md
└── src
    ├── Apostador.cpp
    ├── Cachorro.cpp
    └── GerenciadorCorrida.cpp
```

## 🔧 Funcionalidades Técnicas
- Sistema de apostas com gerenciamento de saldo
- Simulação de corrida com movimentos aleatórios
- Animação em tempo real no terminal
- Sistema multiplataforma (Linux/Windows)
- Mecânica de prêmios baseada em posição

## 👤 Autor
**Jorge Paulo Santos**  
[![GitHub](https://img.shields.io/badge/GitHub-JP--Linux-blue?style=flat&logo=github)](https://github.com/JP-Linux) 
[![LinkedIn](https://img.shields.io/badge/LinkedIn-jorgepaulo--santos-blue?style=flat&logo=linkedin)](https://www.linkedin.com/in/jorgepaulo-santos/)  
✉️ jorgepsan7@gmail.com

## 💝 Suporte ao Projeto

Se este projeto foi útil para você, considere apoiar meu trabalho através do GitHub Sponsors:

[![Sponsor](https://img.shields.io/badge/Sponsor-JP_Linux-ea4aaa?style=for-the-badge&logo=githubsponsors)](https://github.com/sponsors/JP-Linux)

> Projeto desenvolvido e testado no ArchLinux


## 📄 Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo [LICENSE](LICENSE) para detalhes.
