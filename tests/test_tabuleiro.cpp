#include "doctest.h"
#include "tabuleiro.hpp"
#include <exception>
#include "peca.hpp"
#include "peao.hpp"

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