#ifndef MOVIMENTO_HPP
#define MOVIMENTO_HPP

#include "tabuleiro.hpp"
#include "jogador.hpp"

#include <iostream>


class ErroDeJogoException : public std::exception
{
    public:
        virtual const char* what() const noexcept
        {
            return "Movimentação Inválida!";
        }
};

class ForaDoMapaException : public ErroDeJogoException
{
    public:
        virtual const char* what() const noexcept
        {
            return "A peça não pode ser movimentada para fora do tabuleiro.";
        }
};

class SemPecaParaMovimentarException : public ErroDeJogoException
{
    public:
        virtual const char* what() const noexcept
        {
            return "Não há peça na casa selecionada para realizar a movimentação.";
        }
};

class NaoESuaVezException : public ErroDeJogoException
{
    public:
        virtual const char* what() const noexcept
        {
            return "Não é sua vez de realizar a movimentação.";
        }
};

class PecaNaFrenteException : public ErroDeJogoException
{
    public:
        virtual const char* what() const noexcept
        {
            return "A peça não pode ser movimentada para a casa selecionada porque tem uma peça no caminho.";
        }
};

class PecaAliadaException : public ErroDeJogoException
{
    public:
        virtual const char* what() const noexcept
        {
            return "O jogador não pode tomar as suas próprias pecas";
        }
};

class MovimentoInvalidoException : public ErroDeJogoException
{
    public:
        virtual const char* what() const noexcept
        {
            return "A peça não pode realizar este movimento.";
        }
};


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
        
        void validar_movimento();
        /**
         * @brief Checa se a movimentação da peça é válida 
         */
        void checa_movimento_peca();
        
        /**
         * @brief Checa se a movimentação do peão é válida 
         */
        void checa_movimento_peao();
        
        /**
         * @brief Checa se a movimentação do cavalo é válida 
         */
        void checa_movimento_cavalo();
        
        /**
         * @brief Checa se a movimentação da torre é válida 
         */
        void checa_movimento_torre();
        
        /**
         * @brief Checa se a movimentação do bispo é válida 
         */
        void checa_movimento_bispo();
        
        /**
         * @brief Checa se a movimentação da dama é válida 
         */
        void checa_movimento_dama();
        
        /**
         * @brief Checa se a movimentação do rei é válida 
         */
        void checa_movimento_rei();
        /**
         * @brief Promove o peão
         * @param mensagem Se verdadeiro, a mensagem é exibida
         */
        void promove_peao(bool mensagem = true);

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