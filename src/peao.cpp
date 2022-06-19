#include "peao.hpp"

Peao::Peao(int linha, int coluna, Cor cor): 
    Peca(linha, coluna, cor){}

std::string Peao::get_representacao(){
    return " PAO ";
}