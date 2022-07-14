#include "doctest.h"
#include "jogador.hpp"
#include "movimento.hpp"
#include "tabuleiro.hpp"
#include "peca.hpp"
#include "peao.hpp"
#include "bispo.hpp"
#include "cavalo.hpp"
#include "torre.hpp"
#include "dama.hpp"
#include "rei.hpp"

TEST_CASE("testa checagem do movimento peao casos negativos"){
    Tabuleiro *tabuleiro= new Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro->constroi_tabuleiro();
    Jogador *jogador1= new Jogador(tabuleiro,BRANCAS);
    Jogador *jogador2= new Jogador(tabuleiro, PRETAS);
    Movimento movimento1= Movimento(tabuleiro, jogador1, 1, 1, 2, 2);
    Movimento movimento2= Movimento(tabuleiro, jogador1, 1, 1, 0 , 0);
    Movimento movimento3= Movimento(tabuleiro, jogador1, 1, 1, 2, 2);
    CHECK_THROWS_AS(movimento1.checa_movimento_peao(), std::exception);
    CHECK_THROWS_AS(movimento2.checa_movimento_peao(), std::exception);
    CHECK_THROWS_AS(movimento3.checa_movimento_peao(), std::exception);

    tabuleiro->constroi_tabuleiro();
    tabuleiro->adiciona_peca(" PEA ", 1, 1, BRANCAS);
    tabuleiro->adiciona_peca(" PEA ", 1, 2, PRETAS);
    
    Peca *peca= tabuleiro->get_casa(1, 1);
    peca->set_en_passant(false);
    peca= tabuleiro->get_casa(1, 2);
    peca->set_en_passant(false);
    
    Movimento movimento4= Movimento(tabuleiro,jogador1,1,1,1,2);
    Movimento movimento5= Movimento(tabuleiro,jogador2,1,2,1,1);
    
    Movimento movimento6= Movimento(tabuleiro,jogador1,1,1,0,1);
    Movimento movimento7= Movimento(tabuleiro,jogador2,1,2,2,2);
   
    Movimento movimento8= Movimento(tabuleiro,jogador1,1,1,0,1);
    Movimento movimento9= Movimento(tabuleiro,jogador2,1,2,2,2);
    Movimento movimento10= Movimento(tabuleiro,jogador1,1,1,4,1);
    

    CHECK_THROWS_AS(movimento4.checa_movimento_peao(), std::exception);
    CHECK_THROWS_AS(movimento5.checa_movimento_peao(), std::exception);
    CHECK_THROWS_AS(movimento6.checa_movimento_peao(), std::exception);
    CHECK_THROWS_AS(movimento7.checa_movimento_peao(), std::exception);
    CHECK_THROWS_AS(movimento8.checa_movimento_peao(), std::exception);
    CHECK_THROWS_AS(movimento9.checa_movimento_peao(), std::exception);
    CHECK_THROWS_AS(movimento6.checa_movimento_peao(), std::exception);
    CHECK_THROWS_AS(movimento10.checa_movimento_peao(), std::exception);
    delete tabuleiro;
    delete jogador1;
    delete jogador2;
}

TEST_CASE("testa checagem do movimento peao casos positivos"){
    Tabuleiro *tabuleiro= new Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro->constroi_tabuleiro();

    Jogador *jogador1=new Jogador(tabuleiro,BRANCAS);
    Jogador *jogador2=new Jogador(tabuleiro,PRETAS);
    tabuleiro->limpa_tabuleiro();
    tabuleiro->imprime();

    tabuleiro->adiciona_peca(" PEA ", 5, 5, BRANCAS);
    tabuleiro->adiciona_peca(" PEA ", 5,6, PRETAS);

    //Duas casas para frente
    Movimento movimento1(tabuleiro,jogador1,5,5,7,5);
    Movimento movimento2(tabuleiro,jogador2,5,6,3,6);
    //Uma casa para frente
    Movimento movimento3(tabuleiro,jogador1,5,5,6,5);
    Movimento movimento4(tabuleiro,jogador2,5,6,4,6);
    //Movimento de passant
    tabuleiro->get_casa(5, 5)->set_en_passant(true);
    Movimento movimento5(tabuleiro,jogador2,5,6,4,5);
    
    CHECK_NOTHROW(movimento1.validar_movimento());
    CHECK_NOTHROW(movimento2.validar_movimento());
    CHECK_NOTHROW(movimento4.validar_movimento());
    CHECK_NOTHROW(movimento3.validar_movimento());
    CHECK_NOTHROW(movimento5.validar_movimento());
    
    
}