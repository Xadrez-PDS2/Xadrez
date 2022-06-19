#include "dama.hpp"

Dama::Dama(int linha, int coluna, Cor cor): 
    Peca(linha, coluna, cor){}

std::string Dama::get_representacao(){
    return " DAM ";
}