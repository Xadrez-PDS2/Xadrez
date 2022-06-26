#include "jogo.hpp"
#include <cstddef>
#include "peca.hpp"

Jogo::Jogo()
{
    Tabuleiro* tabuleiro = new Tabuleiro(8);
    Jogador* p1 = new Jogador(tabuleiro, Cor::BRANCAS);
    Jogador* p2 = new Jogador(tabuleiro, Cor::PRETAS);
    this->da_vez = p1;
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
{try{
    int linha_inicial;
    int coluna_inicial;
    int linha_final;
    int coluna_final;
    std::cout << "Insira:linha_inicial coluna_inicial linha_final coluna_final" << std::endl;
    std::cin >> linha_inicial >> coluna_inicial >> linha_final >> coluna_final;
    std::cout << "Posições escolhidas: " << linha_inicial << coluna_inicial << " para " << linha_final << coluna_final << std::endl;
    Movimento movimento = Movimento(tabuleiro, da_vez, linha_inicial, coluna_inicial, linha_final, coluna_final);
    
    int tamanho = 8;

    movimento.validar_movimento();
    movimento.executar_movimento();

    if(da_vez == p1) 
        da_vez = p2;
    else
        {da_vez = p1;
    }
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
}
