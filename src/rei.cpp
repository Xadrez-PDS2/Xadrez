#include "rei.hpp"

Rei::Rei(int linha, int coluna): 
    Peca(linha, coluna){}

std::string Rei::get_representacao(){
    return " REI ";
}