#include "peao.hpp"

Peao::Peao(int linha, int coluna): 
    Peca(linha, coluna){}

std::string Peao::get_representacao(){
    return " PAO ";
}