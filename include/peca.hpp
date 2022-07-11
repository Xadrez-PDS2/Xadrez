#ifndef PECA_HPP
#define PECA_HPP

#include <string>
#include "excecoes.hpp"


enum Cor 
{
    BRANCAS, PRETAS
};

/**
* @brief Classe que cuida de todas as funcionalidades gerais de uma peca
*/
class Peca 
{
    public:
        /**
        * @brief construtor padrão de uma peca
        * @param linha Posicao inicial da linha que a peca ocupa no tabuleiro
        * @param coluna Posicao inicial da coluna que a peca ocupa no tabuleiro
        * @param cor Cor da peca
        */
        Peca(int linha, int coluna, Cor cor);
        
        /**
         * @brief Destrutor da peça
         */
        virtual ~Peca() {};
        
        /**
         * @return retorna a reprentacao da peca em forma de string
         * A representacao da peca deve possuir 5 caracteres incluindo um espaco antes e depois
         */
        virtual std::string get_representacao() = 0;        
        
        /**
        * @brief retorna Cor da peça
        */
        Cor get_cor();
        
        /**
         * @brief retorna true se a peça ainda não se movimentou
         */
        bool get_primeiro_movimento();
        
        /**
         * @brief seta o primeiro_movimento
         */
        void set_primeiro_movimento(bool primeiro_movimento);
        
        /**
         * @brief retorna um pair->first que representa a linha atual da peça e pair->second que representa a coluna atual da peça 
         */
        std::pair<int, int> get_casas();
        
        /**
         * @brief Seta as posições da peça
         * @param linha atual
         * @param coluna atual
         */
        void set_casas(int linha, int coluna);


    private:
        /**
        * @brief posicoes de coluna e de linha da peca  
        */
        unsigned int linha, coluna;
        
        /**
         * @brief Cor da peca
         * 
         */
        Cor cor;
        
        /**
         * @brief guarda true se a peça não se movimentou
         * 
         */
        bool primeiro_movimento;
};

#endif