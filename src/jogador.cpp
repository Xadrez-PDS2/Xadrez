#include "jogador.hpp"


Jogador::Jogador(Tabuleiro* tabuleiro, Cor cor):
    cor(cor){
    this->constroi_pecas(tabuleiro);
}

void Jogador::constroi_pecas(Tabuleiro* tabuleiro){
    this->pecas["Peao   "] = 8;
    this->pecas["Cavalo "] = 2;
    this->pecas["Bispo  "] = 2;
    this->pecas["Torre  "] = 2;
    this->pecas["Dama   "] = 1;
    this->pecas["Rei    "] = 1;
    switch (this->cor)
    {
    case Cor::BRANCAS:
        tabuleiro->adciona_peca("torre", 0, 0);
        tabuleiro->adciona_peca("torre", 0, 7);
        tabuleiro->adciona_peca("cavalo", 0, 1);
        tabuleiro->adciona_peca("cavalo", 0, 6);
        tabuleiro->adciona_peca("bispo", 0, 2);
        tabuleiro->adciona_peca("bispo", 0, 5);
        tabuleiro->adciona_peca("dama", 0, 3);
        tabuleiro->adciona_peca("rei", 0, 4);
        for (int i = 0; i < tabuleiro->get_tamanho(); i++)
            tabuleiro->adciona_peca("peao", 1, i);
        break;

    case Cor::PRETAS:
        tabuleiro->adciona_peca("torre", 7, 0);
        tabuleiro->adciona_peca("torre", 7, 7);
        tabuleiro->adciona_peca("cavalo", 7, 1);
        tabuleiro->adciona_peca("cavalo", 7, 6);
        tabuleiro->adciona_peca("bispo", 7, 2);
        tabuleiro->adciona_peca("bispo", 7, 5);
        tabuleiro->adciona_peca("dama", 7, 3);
        tabuleiro->adciona_peca("rei", 7, 4);
        for (int i = 0; i < tabuleiro->get_tamanho(); i++)
            tabuleiro->adciona_peca("peao", 6, i);
        break;
    }
}

void Jogador::imprime(){
    std::cout << std::endl << "Jogador: ";
    switch (this->cor)
    {
    case Cor::BRANCAS:
        std::cout << "BRANCAS" << std::endl;
        break;
    case Cor::PRETAS:
        std::cout << "PRETAS" << std::endl;
        break;
    }
    std::cout << "PECA    :  QUANTIDADE" << std::endl;
    for (auto it = this->pecas.begin(); it != this->pecas.end(); it++){
        std::cout << it->first << " :  " << it->second <<std::endl;
    }
    std::cout << std::endl;
}

Jogador::~Jogador(){

}