#include "peao.hpp"

Peao::Peao(int linha, int coluna, Cor cor): 
    Peca(linha, coluna, cor), primeiro_movimento(true){}

std::string Peao::get_representacao()
{
    return " PEA ";
}

Peao::~Peao(){
    
}