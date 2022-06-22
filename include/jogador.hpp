#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include <map>

#include "tabuleiro.hpp"



class Jogador {
public:
    /**
     * @brief Construtor de um objeto jogador
     * @param tabuleiro Endereço do tabuleiro em que seram colocadas as pecas do jogador
     * @param cor Define se o jogador jogara com as brancas ou com as pecas pretas
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
     * @brief Set que conta todas as pecas do jogador
     */
    std::map <std::string, int> pecas;
    /**
     * @brief A cor das pecas do jogador
     * 
     */
    Cor cor;
};

#endif