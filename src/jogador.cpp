#include "jogador.hpp"
#include "peca.hpp"


Jogador::Jogador(Tabuleiro* tabuleiro, Cor cor)
{   
    this->cor = cor;
    this->constroi_pecas(tabuleiro);
}

Jogador::~Jogador(){}

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
    this->zera_pecas();
    switch (this->cor)
    {
        case Cor::BRANCAS:
            tabuleiro->adiciona_peca(" TOR ", 0, 0, this->cor);
            tabuleiro->adiciona_peca(" TOR ", 0, 7, this->cor);
            tabuleiro->adiciona_peca(" CAV ", 0, 1, this->cor);
            tabuleiro->adiciona_peca(" CAV ", 0, 6, this->cor);
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

    this->atualiza_pecas(tabuleiro);
}

Cor Jogador::get_cor()
{
    return cor;
}

void Jogador::atualiza_pecas(Tabuleiro* tabuleiro) 
{
    this->zera_pecas();
    for(int linha = 0; linha < tabuleiro->get_tamanho(); linha++) 
    {
        for(int coluna = 0; coluna < tabuleiro->get_tamanho(); coluna++) 
        {
            if (tabuleiro->get_casa(linha, coluna) != nullptr)
            {
                std::string peca = tabuleiro->get_casa(linha, coluna)->get_representacao();
                Cor cor_da_peca = tabuleiro->get_casa(linha, coluna)->get_cor();
                if (peca == " PEA " && cor_da_peca == this->cor)
                    pecas["Peao   "]++;

                else if (peca == " TOR " && cor_da_peca == this->cor)
                    pecas["Torre  "]++;

                else if (peca == " CAV " && cor_da_peca == this->cor)
                    pecas["Cavalo "]++;

                else if (peca == " BIS " && cor_da_peca == this->cor)
                    pecas["Bispo  "]++;

                else if (peca == " DAM " && cor_da_peca == this->cor)
                    pecas["Dama   "]++; 
                    
                else if (peca == " REI " && cor_da_peca == this->cor)
                    pecas["Rei    "]++; 
            }
        }
    }
}

void Jogador::zera_pecas()
{
    this->pecas["Peao   "] = 0;
    this->pecas["Cavalo "] = 0;
    this->pecas["Bispo  "] = 0;
    this->pecas["Torre  "] = 0;
    this->pecas["Dama   "] = 0;
    this->pecas["Rei    "] = 0;
}