#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "tabuleiro.hpp"
#include "peca.hpp"

#include <string>
#include <map>


class Jogador 
{
    public:
        /**
        * @brief Construtor de um objeto jogador
        * @param tabuleiro Endereço do tabuleiro em que serão colocadas as pecas do jogador
        * @param cor Define se o jogador jogará com as brancas ou com as pecas pretas
        */
        Jogador(Tabuleiro* tabuleiro, Cor cor);
        /**
        * @brief Destrutor de um objeto jogador
        */
        ~Jogador();
        /**
        * @brief Imprime o status do Jogador
        * 
        */
        void imprime();
        /**
        * @brief Constroi as pecas do jogador no tabuleiro de acordo com a cor fornecida 
        * @param tabuleiro endereco do tabuleiro utilizado
        */
        void constroi_pecas(Tabuleiro* tabuleiro);
        /**
        * @brief retorna cor do jogador
        **/
        Cor get_cor();

    private:
        /**
        * @brief Set que conta todas as peças do jogador
        */
        std::map <std::string, int> pecas;
        /**
        * @brief A cor das peças do jogador
        * 
        */
        Cor cor;
};

#endif