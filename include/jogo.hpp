#ifndef JOGO_HPP
#define JOGO_HPP

#include <iostream>
#include "tabuleiro.hpp"
#include "jogador.hpp"

class Jogo{
/**
 * @brief Define os funcionamentos de um jogo padrao
 */
public:
    /**
     * @brief Construtor do jogo
     */
    Jogo();
    /**
     * @brief Destrutor do jogo
     */
    ~Jogo();
    /**
     * @brief Imprime o estado atual do jogo
     * 
     */
    void imprime();

private:
    /**
     * @brief Os dois jogadores
     */
    Jogador* p1 = nullptr;
    Jogador* p2 = nullptr;
    /**
     * @brief O tabuleiro
     */
    Tabuleiro* tabuleiro = nullptr;
};
#endif