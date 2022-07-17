#include "jogo.hpp"
#include "doctest.h"
#include "jogador.hpp"
#include "movimento.hpp"
#include "tabuleiro.hpp"

TEST_CASE("testa desativar jogo"){

    Jogo *jogo=new Jogo;
    CHECK(jogo->ativo()==true);
    jogo->encerrar();
    CHECK(jogo->ativo()==false);


};