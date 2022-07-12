#include "peca.hpp"
#include "excecoes.hpp"
#include <exception>
 int tamanho_tabuleiro=8;

Peca::Peca( int linha, int coluna, Cor cor){
        if (linha>=tamanho_tabuleiro ||
            coluna>= tamanho_tabuleiro ||
            linha<0 ||
            coluna<0) {
            throw ForaDoMapaException();
        }
        this->linha=linha;
        this->coluna=coluna;
        this->cor=cor;
        this->primeiro_movimento=true;
    }

Cor Peca::get_cor()
{
    return cor;
}

bool Peca::get_primeiro_movimento()
{
    return this->primeiro_movimento;
}

void Peca::set_primeiro_movimento(bool primeiro_movimento)
{
    this->primeiro_movimento = primeiro_movimento;
}

void Peca::set_en_passant(bool en_passant)
{
    this->en_passant = en_passant;
}

bool Peca::get_en_passant()
{
    return this->en_passant;
}

std::pair<int, int> Peca::get_casas()
{
    std::pair<int, int> casas;
    casas.first = this->linha;
    casas.second = this->coluna;
    return casas;
}

void Peca::set_casas(int linha, int coluna)
{
    this->linha = linha;
    this->coluna = coluna;
}
