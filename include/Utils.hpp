#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>
#include <iomanip>

namespace Utils {
    inline void clearScreen() {
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
    }

    inline std::string trim(const std::string& str) {
        auto start = str.begin();
        auto end = str.end();

        while (start != end && std::isspace(*start)) start++;
        while (end != start && std::isspace(*(end - 1))) end--;

        return std::string(start, end);
    }

    inline void clearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    inline int getValidatedInt(int min, int max) {
        int value;
        while (!(std::cin >> value) || value < min || value > max) {
            clearInputBuffer();
            std::cout << "Entrada inválida! Digite um número entre "
            << min << " e " << max << ": ";
        }
        return value;
    }

    // Função para encontrar o nome mais longo
    inline size_t maxNameLength(const std::vector<std::string>& names) {
        size_t max_len = 0;
        for (const auto& name : names) {
            if (name.length() > max_len) {
                max_len = name.length();
            }
        }
        return max_len;
    }
}

#endif
