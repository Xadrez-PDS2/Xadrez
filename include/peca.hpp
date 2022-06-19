#ifndef PECA_HPP
#define PECA_HPP

#include <string>

enum Cor {
    BRANCAS, PRETAS
};


class Peca {
    /**
     * @brief Classe que cuida de todas as funcionalidades gerais de uma peca
     */
    public:
        /**
        * @brief construtor padrão de uma peca
        * @param linha Posicao inicial da linha que a peca ocupa no tabuleiro
        * @param coluna Posicao inicial da coluna que a peca ocupa no tabuleiro
        * @param cor Cor da peca
        */
        Peca(int linha, int coluna, Cor cor);
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
            * @brief posicoes de coluna e de linha da peca  
            */
        int linha, coluna;
        /**
         * @brief Cor da peca
         * 
         */
        Cor cor;
};

#endif