#ifndef TORRE_HPP
#define TORRE_HPP

#include "peca.hpp"


/**
* @brief classe que define o comportamento da torre
*/
class Torre : public Peca
{
    public:
        /**
        * @brief Construtor de um objeto torre
        * @param linha Posicao inicial da linha que a torre ocupa no tabuleiro
        * @param coluna Posicao inicial da coluna que a torre ocupa no tabuleiro
        * @param cor Cor da peca
        */
        Torre(int linha, int coluna, Cor cor);
        /**
        * @brief Destrutor de um objeto torre
        * 
        */
        virtual ~Torre() override;
        /** 
        * @return retorna a representacao da torre em forma de string
        */
        virtual std::string get_representacao() override;
};

#endif