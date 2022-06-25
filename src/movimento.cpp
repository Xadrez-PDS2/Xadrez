#include <iostream>

#include "movimento.hpp"
#include "tabuleiro.hpp"
#include "jogador.hpp"
#include "peca.hpp"
#include "peao.hpp"
#include "bispo.hpp"
#include "cavalo.hpp"
#include "torre.hpp"
#include "dama.hpp"
#include "rei.hpp"

Movimento::Movimento(
    Tabuleiro *tabuleiro,
    Jogador *jogador,
    int linha_inicial,
    int coluna_inicial,
    int linha_final,
    int coluna_final)
    {   
        this->tabuleiro = tabuleiro;
        this->linha_inicial = linha_inicial;
        this->linha_final = linha_final;
        this->coluna_inicial = coluna_inicial;
        this->coluna_final = coluna_final;
        this->peca = (tabuleiro->get_casa(linha_inicial, coluna_inicial));
        this->jogador = jogador;   
    }

void Movimento::executar_movimento()
{   
    const std::string &tipo = peca->get_representacao(); 
    tabuleiro->limpa_casa(linha_final, coluna_final);
    tabuleiro->adiciona_peca(tipo,linha_final, coluna_final, peca->get_cor());
    tabuleiro->limpa_casa(linha_inicial, coluna_inicial);   
}