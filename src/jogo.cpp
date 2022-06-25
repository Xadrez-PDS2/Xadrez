#include "jogo.hpp"

Jogo::Jogo()
{
    Tabuleiro* tabuleiro = new Tabuleiro(8);
    Jogador* p1 = new Jogador(tabuleiro, Cor::BRANCAS);
    Jogador* p2 = new Jogador(tabuleiro, Cor::PRETAS);
    Jogador* da_vez = p1;
    this->p1 = p1;
    this->p2 = p2;
    this->tabuleiro = tabuleiro;
    jogo_ativo = true;
}

Jogo::~Jogo()
{
    delete tabuleiro;
    delete p1;
    delete p2;
    delete da_vez;
}

void Jogo::imprime()
{
    p2->imprime();
    tabuleiro->imprime();
    p1->imprime();
    std::cout << std::endl;
}

bool Jogo::ativo()
{
    return jogo_ativo;
}

void Jogo::jogada()
{
    int linha_inicial;
    int coluna_inicial;
    int linha_final;
    int coluna_final;
    std::cout << "Insira:linha_inicial coluna_inicial linha_final coluna_final" << std::endl;
    std::cin >> linha_inicial >> coluna_inicial >> linha_final >> coluna_final;
    std::cout << "Posições escolhidas: " << linha_inicial << coluna_inicial << " para " << linha_final << coluna_final << std::endl;
    Movimento movimento = Movimento(tabuleiro, da_vez, linha_inicial, coluna_inicial, linha_final, coluna_final);
    
    int tamanho = 8;

    try
    {
        //confere se o movimento está dentro do tabuleiro
        if(linha_final < 0 || coluna_final < 0) 
            throw ForaDoMapaException;

        //confere se o movimento está dentro do tabuleiro
        if(linha_final >= tamanho || coluna_final >= tamanho) 
            throw ForaDoMapaException;
  
        //confere se tem peça para movimentar  
        if(tabuleiro->get_casa(linha_inicial, coluna_inicial) == nullptr) 
            throw SemPecaParaMovimentarException;
  
        //confere se está na vez daquele jogador movimentar  
        if(p1->get_cor() != da_vez->get_cor()) 
            throw NaoESuaVezException;

        movimento.executar_movimento();

        if(da_vez == p1) 
            da_vez = p2;
        else
            da_vez = p1;
    }

    catch(ForaDoMapaException &e)
    {
        std::cout << e.what() << std::endl;
    }

    catch(SemPecaParaMovimentarException &e)
    {
        std::cout << e.what() << std::endl;
    }

    catch(NaoESuaVezException &e)
    {
        std::cout << e.what() << std::endl;
    }

    /*catch(PecaNaFrenteException &e)
    {
        std::cout << e.what() << std::endl;
    }*/
}