#include "torre.hpp"

Torre::Torre(int linha, int coluna, Cor cor): 
    Peca(linha, coluna, cor){}

std::string Torre::get_representacao()
{
    return " TOR ";
}

Torre::~Torre(){}