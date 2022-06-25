#ifndef PEAO_HPP
#define PEAO_HPP

#include "peca.hpp"


/**
* @brief classe que define o comportamento do peao
*/
class Peao : public Peca
{
    public:
        /**
        * @brief Construtor de um objeto peao
        * @param linha Posicao inicial na linha que o peao ocupa no tabuleiro
        * @param coluna Posicao inicial na coluna que o peao ocupa no tabuleiro
        * @param cor Cor da peca
        */
        Peao(int linha, int coluna, Cor cor);
        /**
        * @brief Destrutor de um objeto peao
        * 
        */
        ~Peao();
        /** 
        * @return retorna a representacao do peao em forma de string
        */
        virtual std::string get_representacao() override;
};

#endif