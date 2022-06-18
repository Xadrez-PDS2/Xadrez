#include "bispo.hpp"

Bispo::Bispo(int linha, int coluna): 
    Peca(linha, coluna){}

std::string Bispo::get_representacao(){
    return " BIS ";
}