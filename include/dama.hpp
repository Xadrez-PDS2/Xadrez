#ifndef DAMA_HPP
#define DAMA_HPP

#include "peca.hpp"


/**
* @brief classe que define o comportamento da dama
*/
class Dama : public Peca
{
    public:
        /**
        * @brief Construtor de um objeto dama
        * @param linha Posicao inicial da linha que a dama ocupa no tabuleiro
        * @param coluna Posicao inicial da coluna que a dama ocupa no tabuleiro
        * @param cor Cor da peca
        */
        Dama(int linha, int coluna, Cor cor);
        
        /**
        * @brief Destrutor de um objeto dama
        * 
        */
        virtual ~Dama() override;
        
        /** 
        * @return retorna a representacao da dama em forma de string
        */
        virtual std::string get_representacao() override;
};

#endif