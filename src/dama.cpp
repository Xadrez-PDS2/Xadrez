#include "dama.hpp"

Dama::Dama(int linha, int coluna): 
    Peca(linha, coluna){}

std::string Dama::get_representacao(){
    return " DAM ";
}