#include "jogo.hpp"
#include "jogador.hpp"
#include "movimento.hpp"
#include <iostream>
#include <utility>

Jogo::Jogo(){
    Tabuleiro* tabuleiro = new Tabuleiro(8);
    Jogador* p1 = new Jogador(tabuleiro, Cor::BRANCAS);
    Jogador* p2 = new Jogador(tabuleiro, Cor::PRETAS);
    Jogador* da_vez = p1;
    this->p1 = p1;
    this->p2 = p2;
    this->tabuleiro = tabuleiro;
    jogo_ativo = true;
    
}

Jogo::~Jogo(){
    delete tabuleiro;
    delete p1;
    delete p2;
    delete da_vez;
}

void Jogo::imprime(){
    p2->imprime();
    tabuleiro->imprime();
    p1->imprime();
    std::cout << std::endl;
}
bool Jogo::ativo(){
    return jogo_ativo;
}
void Jogo::jogada(){
    int linha_inicial;
    int coluna_inicial;
    int linha_final;
    int coluna_final;
    std::cout<<"insira:linha_inicial coluna_inicial linha_final coluna_final"<<std::endl;
    std::cin>>linha_inicial>>coluna_inicial>>linha_final>>coluna_final;
    std::cout<<"posicoes escolhidas: "<< linha_inicial<<","<<coluna_inicial<<" para "<< linha_final<<","<<coluna_final<<std::endl;
    
    Movimento movimento = Movimento(tabuleiro,da_vez,linha_inicial, coluna_inicial, linha_final, coluna_final);
    std::cout<<"movimento valido:"<< movimento.movimento_valido()<<std::endl;
   if(movimento.movimento_valido()){
        movimento.executar_movimento();
    }

}