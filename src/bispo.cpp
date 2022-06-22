#include "bispo.hpp"

Bispo::Bispo(int linha, int coluna, Cor cor): 
    Peca(linha, coluna, cor){}

std::string Bispo::get_representacao(){
    return " BIS ";
}

std::string Bispo::get_tipo(){
    return "bispo";
}