#ifndef JOGO_HPP
#define JOGO_HPP

#include "jogador.hpp"
#include "movimento.hpp"
#include "tabuleiro.hpp"

#include <iostream>
#include <regex>
#include <sstream>
#include <algorithm>


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
        void jogada(std::string entrada);
        /**
         * @brief Processa os comandos do terminal
         * @return retorna uma string com a jogada
         */
        const std::string processa_terminal();
        /**
         * @brief Processa a jogada valida
         * 
         * @param entrada Paramentro que contem o comando
         * @return const std::string o comando valido
         */
        const std::string processa_jogada(const std::string entrada);

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
        /**
         * @brief O comando aceitavel deve incluir os dados da posição atual da peça e sua posição final.
         */
        std::regex comando_valido;
};

#endif