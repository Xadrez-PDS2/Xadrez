#include "doctest.h"
#include "tabuleiro.hpp"
#include <exception>
#include "peca.hpp"
#include "peao.hpp"


TEST_CASE("testa getters"){
    Tabuleiro tabuleiro;
    CHECK_EQ(8,tabuleiro.get_tamanho());
    CHECK_EQ(nullptr,tabuleiro.get_casa(3,3));
    

}
TEST_CASE("testa funcao limpa casa"){
    Tabuleiro tabuleiro= Tabuleiro();
    tabuleiro.limpa_casa(0, 0);

    CHECK_EQ(nullptr,tabuleiro.get_casa(0, 0));
}

TEST_CASE("testa funcao adiciona peca"){
    Tabuleiro tabuleiro= Tabuleiro();
    tabuleiro.adiciona_peca(" PAO ", 0, 0, BRANCAS);

    
}