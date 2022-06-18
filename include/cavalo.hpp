#ifndef CAVALO_HPP
#define CAVALO_HPP

#include "peca.hpp"


class Cavalo : public Peca{
/**
* @brief classe que define  o comportamento do cavalo
*/
public:
    /**
     * @brief Construtor de um objeto cavalo
     * @param linha Posicao inicial da linha que o cavalo ocupa no tabuleiro
     * @param coluna Posicao inicial da coluna que o cavalo ocupa no tabuleiro
     */
    Cavalo(int linha, int coluna);
    /**
     * @brief Destrutor de um objeto cavalo
     * 
     */
    ~Cavalo();
    /** 
     * @return retorna a representacao do cavalo em forma de string
     */
    virtual std::string get_representacao() override;
private:

};

#endif