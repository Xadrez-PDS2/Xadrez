#include "jogador.hpp"


Jogador::Jogador(Tabuleiro* tabuleiro, Cor cor):
    cor(cor)
    {
        this->constroi_pecas(tabuleiro);
    }

Jogador::~Jogador()
{

}

void Jogador::imprime()
{
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
    for (auto it = this->pecas.begin(); it != this->pecas.end(); it++)
        std::cout << it->first << " :  " << it->second <<std::endl;
    std::cout << std::endl;
}

void Jogador::constroi_pecas(Tabuleiro* tabuleiro)
{
    this->pecas["Peao   "] = 8;
    this->pecas["Cavalo "] = 2;
    this->pecas["Bispo  "] = 2;
    this->pecas["Torre  "] = 2;
    this->pecas["Dama   "] = 1;
    this->pecas["Rei    "] = 1;
    
    switch (this->cor)
    {
        case Cor::BRANCAS:
            tabuleiro->adiciona_peca(" TOR ", 0, 0, this->cor);
            tabuleiro->adiciona_peca(" TOR ", 0, 7, this->cor);
            tabuleiro->adiciona_peca(" CAV ", 0, 1, this->cor);
            tabuleiro->adiciona_peca(" CAV", 0, 6, this->cor);
            tabuleiro->adiciona_peca(" BIS ", 0, 2, this->cor);
            tabuleiro->adiciona_peca(" BIS ", 0, 5, this->cor);
            tabuleiro->adiciona_peca(" DAM ", 0, 3, this->cor);
            tabuleiro->adiciona_peca(" REI ", 0, 4, this->cor);
            for (int i = 0; i < 8; i++)
                tabuleiro->adiciona_peca(" PEA ", 1, i, this->cor);
            break;

        case Cor::PRETAS:
            tabuleiro->adiciona_peca(" TOR ", 7, 0, this->cor);
            tabuleiro->adiciona_peca(" TOR ", 7, 7, this->cor);
            tabuleiro->adiciona_peca(" CAV ", 7, 1, this->cor);
            tabuleiro->adiciona_peca(" CAV ", 7, 6, this->cor);
            tabuleiro->adiciona_peca(" BIS ", 7, 2, this->cor);
            tabuleiro->adiciona_peca(" BIS ", 7, 5, this->cor);
            tabuleiro->adiciona_peca(" DAM ", 7, 3, this->cor);
            tabuleiro->adiciona_peca(" REI ", 7, 4, this->cor);
            for (int i = 0; i < 8; i++)
                tabuleiro->adiciona_peca(" PEA ", 6, i, this->cor);
            break;
    }
}

Cor Jogador::get_cor()
{
    return cor;
}
