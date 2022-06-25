#ifndef MOVIMENTO_HPP
#define MOVIMENTO_HPP

#include "tabuleiro.hpp"
#include "jogador.hpp"

#include <iostream>


class Movimento
{
    public:
        /**
        *@brief construtor do movimento
        */ 
        Movimento(
            Tabuleiro *tabuleiro,
            Jogador *jogador,
            int linha_inicial,
            int coluna_inicial,
            int linha_final,
            int coluna_final);
        /**
        *@brief executa o movimento, modificando o tabuleiro
        */
        void executar_movimento();

    private:
        Tabuleiro *tabuleiro;
        Jogador *jogador;
        Peca *peca;
        int linha_inicial;
        int coluna_inicial;
        int linha_final;
        int coluna_final;
};

#endif