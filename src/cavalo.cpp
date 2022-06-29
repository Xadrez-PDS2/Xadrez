#include "cavalo.hpp"

Cavalo::Cavalo(int linha, int coluna, Cor cor): 
    Peca(linha, coluna, cor){}

std::string Cavalo::get_representacao(){
    return " CAV ";
}

Cavalo::~Cavalo(){

}