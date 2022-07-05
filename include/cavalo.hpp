#ifndef CAVALO_HPP
#define CAVALO_HPP

#include "peca.hpp"


/**
* @brief classe que define  o comportamento do cavalo
*/
class Cavalo : public Peca
{
    public:
        /**
        * @brief Construtor de um objeto cavalo
        * @param linha Posicao inicial da linha que o cavalo ocupa no tabuleiro
        * @param coluna Posicao inicial da coluna que o cavalo ocupa no tabuleiro
        * @param cor Cor da peca
        */
        Cavalo(int linha, int coluna, Cor cor);
        
        /**
        * @brief Destrutor de um objeto cavalo
        * 
        */
        virtual ~Cavalo() override;
        
        /** 
        * @return retorna a representacao do cavalo em forma de string
        */
        virtual std::string get_representacao() override;
};

#endif