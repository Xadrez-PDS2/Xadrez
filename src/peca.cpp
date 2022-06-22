#include "peca.hpp"

Peca::Peca(int linha, int coluna, Cor cor):
    linha(linha),
    coluna(coluna),
    cor(cor){}

Peca::~Peca(){
    
}
Cor Peca::get_cor(){
    return cor;
}
