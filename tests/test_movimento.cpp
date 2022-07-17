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
#include <exception>

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
    
    delete tabuleiro;
    delete jogador1;
    delete jogador2;
}
TEST_CASE("testa checagem do movimento torre casos negativos"){
    Tabuleiro *tabuleiro= new Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro->constroi_tabuleiro();

    Jogador *jogador1=new Jogador(tabuleiro,BRANCAS);
    Jogador *jogador2=new Jogador(tabuleiro,PRETAS);
    tabuleiro->limpa_tabuleiro();

    tabuleiro->adiciona_peca(" TOR ", 1, 1, BRANCAS);
    tabuleiro->adiciona_peca(" TOR ", 5, 1, PRETAS);

    Movimento mov1(tabuleiro,jogador1,1,1,6,1);
    Movimento mov2(tabuleiro,jogador2,5,1,0,1);
    Movimento mov3(tabuleiro,jogador1,1,1,2,2);
    Movimento mov4(tabuleiro,jogador2,5,1,6,6);
    CHECK_THROWS_AS(mov1.validar_movimento(), std::exception);
    CHECK_THROWS_AS(mov2.validar_movimento(), std::exception);
    CHECK_THROWS_AS(mov3.validar_movimento(), std::exception);
    CHECK_THROWS_AS(mov4.validar_movimento(), std::exception);
    delete tabuleiro;
    delete jogador1;
    delete jogador2;
}
TEST_CASE("testa checagem do movimento torre casos positivos"){
    Tabuleiro *tabuleiro= new Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro->constroi_tabuleiro();

    Jogador *jogador1=new Jogador(tabuleiro,BRANCAS);
    Jogador *jogador2=new Jogador(tabuleiro,PRETAS);
    tabuleiro->limpa_tabuleiro();

    tabuleiro->adiciona_peca(" TOR ", 1, 1, BRANCAS);
    tabuleiro->adiciona_peca(" TOR ", 5,1, PRETAS);
    //ataque
    
    Movimento mov1(tabuleiro,jogador1, 1,1,5 ,1);
    Movimento mov2(tabuleiro,jogador2, 5,1,1,1);
    //movimenta longe
    Movimento mov3(tabuleiro, jogador1, 1,1,1,6);
    Movimento mov4(tabuleiro, jogador2, 5,1,5,6);
    Movimento mov5(tabuleiro, jogador2, 5,1,2,1);
    Movimento mov6(tabuleiro, jogador1, 1,1,4,1);
    Movimento mov7(tabuleiro, jogador2, 5,1,7,1);
    Movimento mov8(tabuleiro, jogador1, 1,1,0,1);
    Movimento mov9(tabuleiro, jogador2, 5,1,5,0);
    Movimento mov10(tabuleiro, jogador1, 1,1,1,0);
    CHECK_NOTHROW(mov1.validar_movimento());
    CHECK_NOTHROW(mov2.validar_movimento());
    CHECK_NOTHROW(mov3.validar_movimento());
    CHECK_NOTHROW(mov4.validar_movimento());
    CHECK_NOTHROW(mov5.validar_movimento());
    CHECK_NOTHROW(mov6.validar_movimento());
    CHECK_NOTHROW(mov7.validar_movimento());
    CHECK_NOTHROW(mov8.validar_movimento());
    CHECK_NOTHROW(mov9.validar_movimento());
    CHECK_NOTHROW(mov10.validar_movimento());

    delete tabuleiro;
    delete jogador1;
    delete jogador2;
}

TEST_CASE("testa checagem do movimento dama casos negativos"){
    Tabuleiro *tabuleiro= new Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro->constroi_tabuleiro();

    Jogador *jogador1=new Jogador(tabuleiro,BRANCAS);
    Jogador *jogador2=new Jogador(tabuleiro,PRETAS);
    tabuleiro->limpa_tabuleiro();
    tabuleiro->adiciona_peca(" DAM ", 1, 1, BRANCAS);
    tabuleiro->adiciona_peca(" DAM ", 5, 5, PRETAS);

    Movimento mov1(tabuleiro,jogador1,1,1,3,2);
    Movimento mov2(tabuleiro,jogador1,1,1,5,4);
    Movimento mov3(tabuleiro,jogador2,5,5,3,4);
    Movimento mov4(tabuleiro,jogador2,5,5,6,7);

    CHECK_THROWS_AS(mov1.validar_movimento(),std::exception);
    CHECK_THROWS_AS(mov2.validar_movimento(),std::exception);
    CHECK_THROWS_AS(mov3.validar_movimento(),std::exception);
    CHECK_THROWS_AS(mov4.validar_movimento(),std::exception);

}

TEST_CASE("testa checagem do movimento dama casos negativos"){
    Tabuleiro *tabuleiro= new Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro->constroi_tabuleiro();

    Jogador *jogador1=new Jogador(tabuleiro,BRANCAS);
    Jogador *jogador2=new Jogador(tabuleiro,PRETAS);
    tabuleiro->limpa_tabuleiro();
    tabuleiro->adiciona_peca(" DAM ", 1, 1, BRANCAS);
    tabuleiro->adiciona_peca(" DAM ", 5, 5, PRETAS);

    Movimento mov1(tabuleiro,jogador1,1,1,3,3);
    Movimento mov2(tabuleiro,jogador1,1,1,1,5);
    Movimento mov3(tabuleiro,jogador2,5,5,3,3);
    Movimento mov4(tabuleiro,jogador2,5,5,5,1); 
    CHECK_NOTHROW(mov1.validar_movimento());
    CHECK_NOTHROW(mov2.validar_movimento());
    CHECK_NOTHROW(mov3.validar_movimento());
    CHECK_NOTHROW(mov4.validar_movimento());
}

TEST_CASE("testa checagem do movimento cavalo casos negativos"){
    Tabuleiro *tabuleiro= new Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro->constroi_tabuleiro();

    Jogador *jogador1=new Jogador(tabuleiro,BRANCAS);
    Jogador *jogador2=new Jogador(tabuleiro,PRETAS);
    tabuleiro->limpa_tabuleiro();
    
    tabuleiro->adiciona_peca(" CAV ", 1, 1, BRANCAS);
    tabuleiro->adiciona_peca(" CAV ", 5, 5, PRETAS);

    Movimento mov1(tabuleiro,jogador1, 1,1,2,2 );
    Movimento mov2(tabuleiro,jogador2,5,5,6,6);

    CHECK_THROWS_AS(mov1.validar_movimento(),std::exception);
    CHECK_THROWS_AS(mov2.validar_movimento(),std::exception);
}

TEST_CASE("testa checagem do movimento cavalo casos positivo"){
    Tabuleiro *tabuleiro= new Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro->constroi_tabuleiro();

    Jogador *jogador1=new Jogador(tabuleiro,BRANCAS);
    Jogador *jogador2=new Jogador(tabuleiro,PRETAS);
    tabuleiro->limpa_tabuleiro();
    
    tabuleiro->adiciona_peca(" CAV ", 1, 1, BRANCAS);
    tabuleiro->adiciona_peca(" CAV ", 5, 5, PRETAS);

    Movimento mov1(tabuleiro,jogador1,1,1,3,2);
    Movimento mov2(tabuleiro,jogador1, 1,1,3,0);
    Movimento mov3(tabuleiro,jogador2,5,5,7,4);
    Movimento mov4(tabuleiro,jogador2,5,5,3,4);

    CHECK_NOTHROW(mov1.validar_movimento());
    CHECK_NOTHROW(mov2.validar_movimento());
    CHECK_NOTHROW(mov3.validar_movimento());
    CHECK_NOTHROW(mov4.validar_movimento());
}
TEST_CASE("testa checagem do movimento bispo casos negativos"){

    Tabuleiro *tabuleiro= new Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro->constroi_tabuleiro();

    Jogador *jogador1=new Jogador(tabuleiro,BRANCAS);
    Jogador *jogador2=new Jogador(tabuleiro,PRETAS);
    tabuleiro->limpa_tabuleiro();
    tabuleiro->adiciona_peca(" BIS ", 3, 3, BRANCAS);
    tabuleiro->adiciona_peca(" BIS ", 5, 5,  PRETAS);

    Movimento mov1(tabuleiro,jogador1,3,3,3,5);
    Movimento mov2(tabuleiro,jogador2,5,5,5,0);
    Movimento mov3(tabuleiro,jogador1, 3,3,0,3);
    Movimento mov4(tabuleiro,jogador2,5,5,0,5);
    Movimento mov5(tabuleiro,jogador2,5,5,2,2);

    CHECK_THROWS_AS(mov1.validar_movimento(),std::exception);
    CHECK_THROWS_AS(mov2.validar_movimento(),std::exception);
    CHECK_THROWS_AS(mov3.validar_movimento(),std::exception);
    CHECK_THROWS_AS(mov4.validar_movimento(),std::exception);
    CHECK_THROWS_AS(mov5.validar_movimento(),std::exception);
}
TEST_CASE("testa checagem do movimento bispo casos positivos"){
    
    Tabuleiro *tabuleiro= new Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro->constroi_tabuleiro();

    Jogador *jogador1=new Jogador(tabuleiro,BRANCAS);
    Jogador *jogador2=new Jogador(tabuleiro,PRETAS);
    tabuleiro->limpa_tabuleiro();
    tabuleiro->adiciona_peca(" BIS ", 3, 3, BRANCAS);
    tabuleiro->adiciona_peca(" BIS ", 5, 5,  PRETAS);

    Movimento mov1(tabuleiro,jogador1,3,3,5,5);
    Movimento mov2(tabuleiro,jogador1,3,3,0,6);
    Movimento mov3(tabuleiro,jogador2,5,5,7,3);
    Movimento mov4(tabuleiro,jogador2,5,5,3,7);

    CHECK_NOTHROW(mov1.validar_movimento());
    CHECK_NOTHROW(mov2.validar_movimento());
    CHECK_NOTHROW(mov3.validar_movimento());
    CHECK_NOTHROW(mov4.validar_movimento());

}

TEST_CASE("testa checagem do movimento rei casos negativos"){

    Tabuleiro *tabuleiro= new Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro->constroi_tabuleiro();

    Jogador *jogador1=new Jogador(tabuleiro,BRANCAS);
    Jogador *jogador2=new Jogador(tabuleiro,PRETAS);
    tabuleiro->limpa_tabuleiro();
    tabuleiro->adiciona_peca(" REI ", 4, 4, BRANCAS);
    tabuleiro->adiciona_peca(" REI ", 5, 5,  PRETAS);

    Movimento mov1(tabuleiro,jogador1,4,4,4,0);
    Movimento mov2(tabuleiro,jogador1,4,4,6,6);
    Movimento mov3(tabuleiro,jogador2,5,5,7,7);
    Movimento mov4(tabuleiro,jogador2,5,5,4,7);
    
    CHECK_THROWS_AS(mov1.validar_movimento(),std::exception);
    CHECK_THROWS_AS(mov2.validar_movimento(),std::exception);
    CHECK_THROWS_AS(mov3.validar_movimento(),std::exception);
    CHECK_THROWS_AS(mov4.validar_movimento(),std::exception);

}
TEST_CASE("testa checagem do movimento rei casos positivos"){

    Tabuleiro *tabuleiro= new Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro->constroi_tabuleiro();

    Jogador *jogador1=new Jogador(tabuleiro,BRANCAS);
    Jogador *jogador2=new Jogador(tabuleiro,PRETAS);
    tabuleiro->limpa_tabuleiro();
    tabuleiro->adiciona_peca(" REI ", 4, 4, BRANCAS);
    tabuleiro->adiciona_peca(" REI ", 5, 5,  PRETAS);

    Movimento mov1(tabuleiro, jogador1, 4,4,5,5);
    Movimento mov2(tabuleiro, jogador1, 4,4,3,5);
    Movimento mov3(tabuleiro, jogador1, 4,4,3,3);
    Movimento mov4(tabuleiro, jogador2, 5,5,6,6);
    Movimento mov5(tabuleiro, jogador2, 5,5,4,4);
    Movimento mov6(tabuleiro, jogador2, 5,5,4,6);
    
    CHECK_NOTHROW(mov1.validar_movimento());
    CHECK_NOTHROW(mov2.validar_movimento());
    CHECK_NOTHROW(mov3.validar_movimento());
    CHECK_NOTHROW(mov4.validar_movimento());
    CHECK_NOTHROW(mov5.validar_movimento());
    CHECK_NOTHROW(mov6.validar_movimento());
}

TEST_CASE("testa executar movimento"){
    Tabuleiro *tabuleiro= new Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro->constroi_tabuleiro();

    Jogador *jogador1=new Jogador(tabuleiro,BRANCAS);
   
    tabuleiro->limpa_tabuleiro();
    tabuleiro->adiciona_peca(" REI ", 4, 4, BRANCAS);

    Movimento mov1(tabuleiro,jogador1,4,4,5,5);
    mov1.executar_movimento();
    CHECK(tabuleiro->get_casa(4, 4)==nullptr);
    CHECK(tabuleiro->get_casa(5, 5)!=nullptr);
}
