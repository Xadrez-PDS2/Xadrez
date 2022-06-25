#include "rei.hpp"

Rei::Rei(int linha, int coluna, Cor cor): 
    Peca(linha, coluna, cor){}

std::string Rei::get_representacao()
{
    return " REI ";
}