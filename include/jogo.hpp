#ifndef JOGO_HPP
#define JOGO_HPP

#include <iostream>
#include "tabuleiro.hpp"
#include "jogador.hpp"
#include "movimento.hpp"

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
    /**
     * @brief retorna verdadeiro se o jogo estiver atibo
     */
    bool ativo();

    /**
     * @brief encerra o jogo
     */
    void encerrar();

    /**
     *@brief realiza os procedimentos do jogador da vez
     */
    void jogada();

private:
    /**
     * @brief Os dois jogadores
     */
    Jogador* p1 = nullptr;
    Jogador* p2 = nullptr;
    /**
     * @brief retorna um ponteiro para o jogador do turno atual
     */
    Jogador* da_vez;
    /**
     * @brief O tabuleiro
     */
    Tabuleiro* tabuleiro = nullptr;
    bool jogo_ativo;


};
#endif