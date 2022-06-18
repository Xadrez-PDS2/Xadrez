#include "cavalo.hpp"

Cavalo::Cavalo(int linha, int coluna): 
    Peca(linha, coluna){}

std::string Cavalo::get_representacao(){
    return " CAV ";
}