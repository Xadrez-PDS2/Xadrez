#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <vector>
#include <iostream>

#include "peca.hpp"
#include "peao.hpp"
#include "bispo.hpp"
#include "cavalo.hpp"
#include "torre.hpp"
#include "dama.hpp"
#include "rei.hpp"


class Tabuleiro {
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
     * 
     */
    void imprime();
    /**
     * @brief Adiciona a peca naquela posicao
     * @param peca string do nome da peca
     * @param linha posicao na linha
     * @param coluna posicao na coluna
     */
    void adciona_peca(const std::string &peca, int linha, int coluna);
    /**
     * @return retorna o tamanho do tabuleiro
     * 
     */
    int get_tamanho();

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

};

#endif