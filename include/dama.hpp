#ifndef DAMA_HPP
#define DAMA_HPP

#include "peca.hpp"


class Dama : public Peca{
/**
* @brief classe que define o comportamento da dama
*/
public:
    /**
     * @brief Construtor de um objeto dama
     * @param linha Posicao inicial da linha que a dama ocupa no tabuleiro
     * @param coluna Posicao inicial da coluna que a dama ocupa no tabuleiro
     */
    Dama(int linha, int coluna);
    /**
     * @brief Destrutor de um objeto dama
     * 
     */
    ~Dama();
    /** 
     * @return retorna a representacao da dama em forma de string
     */
    virtual std::string get_representacao() override;
private:

};

#endif