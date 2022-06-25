#ifndef JOGO_HPP
#define JOGO_HPP

#include "jogador.hpp"
#include "movimento.hpp"
#include "tabuleiro.hpp"

#include <iostream>

using namespace std;


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

/**
* @brief Define os funcionamentos de um jogo padrao
*/
class Jogo
{
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