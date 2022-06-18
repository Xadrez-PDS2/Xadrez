#ifndef PECA_HPP
#define PECA_HPP

#include <string>


class Peca {
    /**
     * @brief Classe que cuida de todas as funcionalidades gerais de uma peca
     */
    public:
        /**
        * @brief construtor padrão de uma peca
        * @param linha Posicao inicial da linha que a peca ocupa no tabuleiro
        * @param coluna Posicao inicial da coluna que a peca ocupa no tabuleiro
        */
        Peca(int linha, int coluna);
        /**
        * @brief Destrutor da classe.
        */
        ~Peca();
        /**
         * @return retorna a reprentacao da peca em forma de string
         * A representacao da peca deve possuir 5 caracteres incluindo um espaco antes e depois
         */
        virtual std::string get_representacao() = 0;


    private:
        /**
        * @brief posicoes na coluna linha e na linha coluna da peca  
        */
    int linha, coluna;
};

#endif