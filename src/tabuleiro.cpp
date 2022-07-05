
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

void Tabuleiro::adiciona_peca_existente(Peca *peca, int linha, int coluna)
{
    this->casas[peca->get_casas().first][peca->get_casas().second] = nullptr;
    peca->set_casas(linha, coluna);
    this->casas[linha][coluna] = peca;
}

void Tabuleiro::limpa_casa(int linha, int coluna)
{
    if(casas[linha][coluna]!=nullptr)
        delete casas[linha][coluna];
  
    casas[linha][coluna] = nullptr;
}

void Tabuleiro::limpa_casa_inicial(int linha, int coluna)
{  
    casas[linha][coluna] = nullptr;
}

void Tabuleiro::imprime()
{
    for (int i = 0; i < this->tamanho; i++)
    {
        for (int j = 0; j < this->tamanho;j++)
        {
            if(this->casas[i][j] != nullptr)
            {
                if (this->casas[i][j]->get_cor() == Cor::BRANCAS)
                    std::cout << "\033[7m";
                std::cout << " [" << this->casas[i][j]->get_representacao() << "] ";
            }

            else
                std::cout << " [     ] ";
            std::cout << "\033[0m";
        }
      
        std::cout << "  " << L[i] << std::endl;
    }
    
    for (int i = 0; i < this->tamanho; i++)
    {
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

 int Tabuleiro::get_tamanho(){
    return this->tamanho;
} 

