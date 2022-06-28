
#include "tabuleiro.hpp"

Tabuleiro::Tabuleiro(int tamanho):
tamanho(tamanho)
{
    for(int i = 0; i < this->tamanho; i++)
    {
        this->casas.push_back(std::vector<Peca *>());

        for(int j = 0; j < this->tamanho; j++)
        {
            this->casas[i].push_back(nullptr);
        }
    }
}

void Tabuleiro::adiciona_peca(const std::string &peca, int linha, int coluna, Cor cor)
{
    if (peca == " PEA ")
        this->casas[linha][coluna] = new Peao(linha, coluna, cor);

    else if (peca == " TOR ")
        this->casas[linha][coluna] = new Torre(linha, coluna, cor);

    else if (peca == " CAV ")
        this->casas[linha][coluna] = new Cavalo(linha, coluna, cor);

    else if (peca == " BIS ")
        this->casas[linha][coluna] = new Bispo(linha, coluna, cor);

    else if (peca == " DAM ")
        this->casas[linha][coluna] = new Dama(linha, coluna, cor);

    else if (peca == " REI ")
        this->casas[linha][coluna] = new Rei(linha, coluna, cor);
}

void Tabuleiro::limpa_casa(int linha, int coluna){
  
  if(casas[linha][coluna]!=nullptr){delete casas[linha][coluna];}
  casas[linha][coluna]=nullptr;
}

void Tabuleiro::imprime()
{
    for (int i = 0; i < this->tamanho; i++)
    {
        for (int j = 0; j < this->tamanho;j++)
        {
            if(this->casas[i][j] != nullptr){
                if (this->casas[i][j]->get_cor() == Cor::BRANCAS)
                    std::cout << "\033[7m";
                std::cout << " [" << this->casas[i][j]->get_representacao() << "] ";
            }
            else
                std::cout << " [     ] ";
            std::cout << "\033[0m";
        }
        std::cout << "  "<< i << std::endl;
    }
    for (int i = 0; i < this->tamanho; i++){
      std::cout << "    " << i << "    ";
    }
    std::cout << std::endl;
}

Tabuleiro::~Tabuleiro() 
{
    for(std::vector<Peca *> linha : this->casas) 
    {
        for(Peca *peca_ptr : linha) 
        {
            if(peca_ptr != nullptr) 
            {
                delete peca_ptr;
            }
        }
    }
}

Peca* Tabuleiro::get_casa(int linha, int coluna)
{
  return casas[linha][coluna]; 
}

/*
Tabuleiro::Tabuleiro() {
  int tamanho = 8;
  int inicio = 3;

  for (int i = 0; i < tamanho; i++) {
    _casas.push_back(vector<Peca *>());
    for (int j = 0; j < tamanho; j++) {
      _casas[i].push_back(nullptr);
    }
  }

  for (int i = 0; i < inicio; i++) {
    for (int j = 0; j < tamanho - 1; j+=2) {
      if (i % 2 == 0)
        _casas[i][j] = new Peca(Cor::VERMELHA);
      else
        _casas[i][j+1] = new Peca(Cor::VERMELHA);
    }
  }

  for (int i = tamanho - 1; i >= tamanho - inicio; i--) {
    for (int j = 0; j < tamanho - 1; j+=2) {
      if (i % 2 == 0)
        _casas[i][j] = new Peca(Cor::PRETA);
      else
        _casas[i][j+1] = new Peca(Cor::PRETA);
    }
  }

  _da_vez = Cor::VERMELHA;
}

Tabuleiro::~Tabuleiro() {
  for (vector<Peca *> linha : _casas) {
    for (Peca *peca_ptr : linha) {
      if (peca_ptr != nullptr) {
        delete peca_ptr;
      }
    }
  }
}

bool Tabuleiro::movimenta(int x, int y, bool diag_esq) {
  int tamanho = _casas.size();
  if (x < 0 || y < 0) return false;
  if (x >= tamanho || y >= tamanho) return false;
  if (_casas[x][y] == nullptr) return false;
  if (_casas[x][y]->get_cor() != _da_vez) return false;

  int delta = 1;
  if (diag_esq) {
    delta = -1;
  }

  if (_da_vez == Cor::VERMELHA) {
    _da_vez = Cor::PRETA;
  } else {
    _da_vez = Cor::VERMELHA;
  }
}

void Tabuleiro::imprime() {
  for (vector<Peca *> linha : _casas) {
    for (Peca *peca_ptr : linha) {
      if (peca_ptr == nullptr) {
        cout << " [" << " " << "] ";  
      } else {
        cout << " [" << peca_ptr->get_cor() << "] ";
      }
    }
    cout << endl;
  }
}*/