#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include "peca.hpp"
#include "peao.hpp"
#include "bispo.hpp"
#include "cavalo.hpp"
#include "torre.hpp"
#include "dama.hpp"
#include "rei.hpp"

#include <vector>
#include <iostream>

#define TAMANHO_DO_TABULEIRO 8

class Tabuleiro 
{
    public:
        /**
        * @brief Construtor de um objeto tabuleiro
        * @param tamanho define o tamanho para as n colunas e n linhas do tabuleiro
        */
        Tabuleiro(int tamanho);
        
        /**
        * @brief Destrutor de um objeto tabuleiro
        */
        ~Tabuleiro();
        
        /**
        * @brief Imprime o estado atual do tabuleiro 
        */
        void imprime();
        
        /**
        * @brief Adiciona a peca naquela posicao
        * @param peca string do nome da peca
        * @param linha posição na linha
        * @param coluna posição na coluna
        * @param cor  cor da peca
        */
        void adiciona_peca(const std::string &peca, int linha, int coluna, Cor cor);
        
        /**
         * @brief Adiciona uma peça existente ao tabuleiro
         * @param peca o endereço da peça que vai ser adicionada
         * @param linha posição na linha
         * @param coluna posição na coluna
         */
        void adiciona_peca_existente(Peca *peca, int linha, int coluna);
        
        /**
        * @brief Deleta a peça se houver
        * @param linha
        * @param coluna 
        */
        void limpa_casa( int linha, int coluna); 

        /**
        * @brief Retorna o ponteiro da casa do tabuleiro
        */
        Peca* get_casa(int linha, int coluna);
        
        /**
         * @brief Retorna o tamanho do tabuleiro
         */
        int get_tamanho(); 
        /**
         * @brief Constroi cada casa do tabuleiro
         */
        void constroi_tabuleiro();

    private:
        /**
        * @brief Matriz de coordenadas que contem os enderecos das pecas existentes
        */
        std::vector <std::vector <Peca *>> casas;
        
        /**
        * @brief Tamanho do tabuleiro
        * 
        */
        const int tamanho;

        std::vector<std::string> L {"A", "B", "C", "D", "E", "F", "G", "H"};
};

#endif