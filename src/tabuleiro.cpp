
#include "tabuleiro.hpp"
#include "peca.hpp"

Tabuleiro::Tabuleiro(int tamanho):
tamanho(tamanho)
{
    for (int i = 0; i < this->tamanho; i++){
      this->casas.push_back(std::vector<Peca *>());
      for(int j = 0; j < this->tamanho; j++){
          this->casas[i].push_back(nullptr);
      }
    }
}

void Tabuleiro::adciona_peca(const std::string &peca, int linha, int coluna, Cor cor){
    if (peca == "peao")
        this->casas[linha][coluna] = new Peao(linha, coluna, cor);
    else if (peca == "torre")
        this->casas[linha][coluna] = new Torre(linha, coluna, cor);
    else if (peca == "cavalo")
        this->casas[linha][coluna] = new Cavalo(linha, coluna, cor);
    else if (peca == "bispo")
        this->casas[linha][coluna] = new Bispo(linha, coluna, cor);
    else if (peca == "dama")
        this->casas[linha][coluna] = new Dama(linha, coluna, cor);
    else if (peca == "rei")
        this->casas[linha][coluna] = new Rei(linha, coluna, cor);
}

void Tabuleiro::limpa_casa( int linha, int coluna){
  
  if(casas[linha][coluna]!=nullptr){delete casas[linha][coluna];}
  casas[linha][coluna]=nullptr;
}

int Tabuleiro::get_tamanho(){
  
    return this->tamanho;
}

void Tabuleiro::imprime(){
  for (int i = 0; i < this->tamanho; i++){
    for (int j = 0; j < this->tamanho;j++){
        if(this->casas[i][j] != nullptr)
            std::cout << " [" << this->casas[i][j]->get_representacao() << "] ";
        else
            std::cout << " [     ] ";
    }
    std::cout << std::endl;
  }
}

Tabuleiro::~Tabuleiro() {
  for (std::vector<Peca *> linha : this->casas) {
    for (Peca *peca_ptr : linha) {
      if (peca_ptr != nullptr) {
        delete peca_ptr;
      }
    }
  }
}
Peca* Tabuleiro::get_casa(int linha,int coluna){
  return casas[linha][coluna]; 
}