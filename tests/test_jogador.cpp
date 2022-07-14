#include "doctest.h"
#include "jogador.hpp"
#include "peca.hpp"
#include "tabuleiro.hpp"
#include <array>
#include <map>

TEST_CASE("Construtor"){
    Tabuleiro *tabuleiro=new Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro->constroi_tabuleiro();
    Jogador jogador1 =Jogador(tabuleiro,BRANCAS);
    int limite_brancas=1;
    Peca *ponteiro;
    for (int i = 0; i<TAMANHO_DO_TABULEIRO; i++) {
        if (i<=limite_brancas) {
            for(int j =0; j<TAMANHO_DO_TABULEIRO; j++){
            ponteiro=tabuleiro->get_casa(i,j);
            CHECK_FALSE(ponteiro==nullptr);
            }
        }
        if(i> limite_brancas){
            for(int j =0; j<TAMANHO_DO_TABULEIRO; j++){
            ponteiro=tabuleiro->get_casa(i,j);
            CHECK(ponteiro==nullptr);   
            }      
        }
    }
    
    Jogador jogador2 =Jogador(tabuleiro,PRETAS);
    int limite_pretas=6;
    
    
    for (int i = limite_pretas; i<TAMANHO_DO_TABULEIRO; i++){
        for(int j =0; j<TAMANHO_DO_TABULEIRO ; j++){
            ponteiro= tabuleiro->get_casa(i, j);
            CHECK_FALSE(ponteiro==nullptr);   
        }      
        }
    delete tabuleiro;
};

TEST_CASE("get_cor"){
    Tabuleiro* tabuleiro= new Tabuleiro(TAMANHO_DO_TABULEIRO);
    Jogador jogador1= Jogador(tabuleiro,BRANCAS);
    Jogador jogador2= Jogador(tabuleiro,PRETAS);
    CHECK(jogador1.get_cor()==BRANCAS);
    CHECK(jogador2.get_cor()==PRETAS);
    
    delete tabuleiro;
};
TEST_CASE("get_pecas"){
    Tabuleiro* tabuleiro= new Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro->constroi_tabuleiro();
    Jogador jogador1= Jogador(tabuleiro,BRANCAS);
    int numero_de_peoes=8;
    map< string, int> mapa=jogador1.get_pecas();
    CHECK(mapa["Peao   "]==numero_de_peoes);
    
    delete tabuleiro;
};
TEST_CASE("testa zerar_pecas"){
    Tabuleiro* tabuleiro= new Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro->constroi_tabuleiro();
    Jogador jogador1= Jogador(tabuleiro,BRANCAS);
    
    jogador1.zera_pecas();
    map< string, int> mapa=jogador1.get_pecas();
    CHECK(mapa["Peao   "]==0);

    delete tabuleiro;
};

TEST_CASE("testa atualiza_pecas"){
    Tabuleiro *tabuleiro= new Tabuleiro(TAMANHO_DO_TABULEIRO);
    tabuleiro->constroi_tabuleiro();

    Jogador jogador=Jogador(tabuleiro,BRANCAS);
    tabuleiro->limpa_casa(1, 0);

    jogador.atualiza_pecas(tabuleiro);
    map<string, int> mapa= jogador.get_pecas();
    CHECK(mapa["Peao   "]==7);
    delete tabuleiro;
}