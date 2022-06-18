#include "jogo.hpp"

Jogo::Jogo(){
    Tabuleiro* tabuleiro = new Tabuleiro(8);
    Jogador* p1 = new Jogador(tabuleiro, Cor::BRANCAS);
    Jogador* p2 = new Jogador(tabuleiro, Cor::PRETAS);
    this->p1 = p1;
    this->p2 = p2;
    this->tabuleiro = tabuleiro;
}

Jogo::~Jogo(){
    delete tabuleiro;
    delete p1;
    delete p2;
}

void Jogo::imprime(){
    p2->imprime();
    tabuleiro->imprime();
    p1->imprime();
    std::cout << std::endl;
}