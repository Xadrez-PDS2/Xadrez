#include "torre.hpp"

Torre::Torre(int linha, int coluna): 
    Peca(linha, coluna){}

std::string Torre::get_representacao(){
    return " TOR ";
}