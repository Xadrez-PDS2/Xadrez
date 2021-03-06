#include "doctest.h"
#include "peca.hpp"
#include "peao.hpp"
#include "bispo.hpp"
#include "cavalo.hpp"
#include "torre.hpp"
#include "dama.hpp"
#include "rei.hpp"
#include <exception>
#include <utility>


TEST_CASE("testa construtor do peao e seus getters casos negativos")
{
    CHECK_THROWS_AS( Peao peao = Peao(-1, -1,BRANCAS), std::exception);
    CHECK_THROWS_AS( Peao peao = Peao(8, -1,BRANCAS), std::exception);
    CHECK_THROWS_AS( Peao peao = Peao(8, 9,BRANCAS), std::exception);
    CHECK_THROWS_AS( Peao peao = Peao(2, 20, PRETAS), std::exception);
}

TEST_CASE("test getters peao")
{
    Peao peao = Peao(1,1,BRANCAS);
    std::pair<int, int>casas; 
    casas.first = 1;
    casas.second = 1;
    CHECK_EQ(" PEA ", peao.get_representacao());
    CHECK_EQ(casas,peao.get_casas());
    CHECK_EQ(BRANCAS,peao.get_cor());
    CHECK_EQ(true, peao.get_primeiro_movimento());
}

TEST_CASE("testa set movimento peca")
{
    Peao peao = Peao(1,1,BRANCAS);
    CHECK_EQ(true,peao.get_primeiro_movimento());
    peao.set_primeiro_movimento(false);
    CHECK_EQ(false, peao.get_primeiro_movimento());
}

TEST_CASE("testa set casas peao")
{
    Peao peao = Peao(1,1,BRANCAS);
    std::pair<int, int>casas; 
    casas.first=1;
    casas.second=1;

    CHECK_EQ(casas,peao.get_casas());

    peao.set_casas(2, 2);
    casas.first=2;
    casas.second=2;

    CHECK_EQ(casas, peao.get_casas());
}

TEST_CASE("testa construtor das subclasses")
{
    Peao peao=Peao(0,0,PRETAS);
    CHECK(peao.get_representacao()==" PEA ");
    Torre torre=Torre(1,1,BRANCAS);
    CHECK(torre.get_representacao()==" TOR ");
    Rei rei= Rei(0,0,BRANCAS);
    CHECK(rei.get_representacao()==" REI ");
    Bispo bispo=Bispo(0,0,BRANCAS);
    CHECK(bispo.get_representacao()==" BIS ");
    Cavalo cavalo=Cavalo(0,0, BRANCAS);
    CHECK(cavalo.get_representacao()==" CAV ");
    Dama dama= Dama(0,0,BRANCAS);
    CHECK(dama.get_representacao()==" DAM ");
}
