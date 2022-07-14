#include "doctest.h"
#include "tabuleiro.hpp"
#include <exception>
#include "peca.hpp"
#include "peao.hpp"

TEST_CASE("testa constroi_tabuleiro")
{
    Tabuleiro tabuleiro = Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro.constroi_tabuleiro();

    for (int i=0; i<TAMANHO_DO_TABULEIRO; i++) {
        for (int j; j<TAMANHO_DO_TABULEIRO; j++) {
            CHECK(tabuleiro.get_casa(i, j)==nullptr);
        }
    }   
}

TEST_CASE("testa getters")
{
    Tabuleiro tabuleiro = Tabuleiro(TAMANHO_DO_TABULEIRO);
    CHECK(tabuleiro.get_tamanho() == TAMANHO_DO_TABULEIRO);
    CHECK(tabuleiro.get_casa(3,3) == nullptr);
}
TEST_CASE("testa funcao limpa casa")
{
    Tabuleiro tabuleiro = Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro.limpa_casa(0, 0);
    CHECK(tabuleiro.get_casa(0, 0) == nullptr);
}

TEST_CASE("testa funcao adiciona peca")
{
    Tabuleiro tabuleiro = Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro.adiciona_peca(" PEA ", 0, 0, BRANCAS);
    Peca* ponteiro = tabuleiro.get_casa(0, 0);
    CHECK_FALSE(ponteiro == nullptr);
}

TEST_CASE("testa funcao adicion_peca_existente")
{
    Tabuleiro tabuleiro= Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro.constroi_tabuleiro();
    tabuleiro.adiciona_peca(" REI ", 0, 0, BRANCAS);
    Peca *peca= tabuleiro.get_casa(0, 0);
    tabuleiro.adiciona_peca_existente(peca, 3, 3);
    Peca *ponteiro=tabuleiro.get_casa(3, 3);
    CHECK_FALSE(ponteiro==nullptr);
    CHECK(peca->get_cor()==ponteiro->get_cor());
    CHECK(peca->get_representacao()==ponteiro->get_representacao());
}
