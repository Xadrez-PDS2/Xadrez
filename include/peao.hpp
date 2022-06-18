#ifndef PEAO_HPP
#define PEAO_HPP

#include "peca.hpp"


class Peao : public Peca{
/**
* @brief classe que define o comportamento do peao
*/
public:
    /**
     * @brief Construtor de um objeto peao
     * @param x Posicao inicial x que o peao ocupa no tabuleiro
     * @param y Posicao inicial y que o peao ocupa no tabuleiro
     */
    Peao(int x, int y);
    /**
     * @brief Destrutor de um objeto peao
     * 
     */
    ~Peao();
    /** 
     * @return retorna a representacao do peao em forma de string
     */
    virtual std::string get_representacao() override;
private:
};

#endif