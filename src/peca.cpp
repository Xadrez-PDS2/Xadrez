#include "peca.hpp"

Peca::Peca(int linha, int coluna, Cor cor):
    linha(linha),
    coluna(coluna),
    cor(cor),
    primeiro_movimento(true),
    en_passant(false){}

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
