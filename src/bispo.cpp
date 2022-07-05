#include "bispo.hpp"

Bispo::Bispo(int linha, int coluna, Cor cor): 
    Peca(linha, coluna, cor){}

std::string Bispo::get_representacao()
{
    return " BIS ";
}

Bispo::~Bispo(){}