#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "tabuleiro.hpp"
#include "peca.hpp"

#include <string>
#include <map>
using namespace std;

class Jogador 
{
    public:
        /**
        * @brief Construtor de um objeto jogador
        * @param tabuleiro Endereço do tabuleiro em que serão colocadas as pecas do jogador
        * @param cor Define se o jogador jogará com as brancas ou com as pecas pretas
        * @param ad_pecas Se true adciona as pecas do jogador ao tabuleiro
        */
        Jogador(Tabuleiro* tabuleiro, Cor cor, bool ad_pecas=true);
        
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
        
        /**
         * @brief Atualiza a quantidades de peças do jogador
         */
        void atualiza_pecas(Tabuleiro* tabuleiro);
       
        /**
         * @brief Zera os valores de todas pecas
         */
        void zera_pecas();
        
        /**
         * @brief Retorna um mapa com as peças do jogador
         */
        std::map<std::string, int> get_pecas();

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