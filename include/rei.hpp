#ifndef REI_HPP
#define REI_HPP

#include "peca.hpp"


class Rei : public Peca{
/**
* @brief classe que define o comportamento do rei
*/
public:
    /**
     * @brief Construtor de um objeto rei
     * @param linha Posicao inicial da linha que o rei ocupa no tabuleiro
     * @param coluna Posicao inicial da coluna que o rei ocupa no tabuleiro
     * @param cor Cor da peca
     */
    Rei(int linha, int coluna, Cor cor);
    /**
     * @brief Destrutor de um objeto rei
     * 
     */
    ~Rei();
    /** 
     * @return retorna a representacao do rei em forma de string
     */
    virtual std::string get_representacao() override;

    virtual std::string get_tipo() override;
    
private:
};

#endif