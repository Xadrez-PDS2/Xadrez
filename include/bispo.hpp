#ifndef BISPO_HPP
#define BISPO_HPP

#include "peca.hpp"


/**
* @brief classe que define  o comportamento do bispo
*/
class Bispo : public Peca
{
    public:
        /**
        * @brief Construtor de um objeto bispo
        * @param linha Posicao inicial da linha que o bispo ocupa no tabuleiro
        * @param coluna Posicao inicial da coluna que o bispo ocupa no tabuleiro
        * @param cor Cor da peca
        */
        Bispo(int linha, int coluna, Cor cor);
        
        /**
        * @brief Destrutor de um objeto bispo
        * 
        */
        virtual ~Bispo() override;
        
        /** 
        * @return retorna a representacao do bispo em forma de string
        */
        virtual std::string get_representacao() override;
};

#endif