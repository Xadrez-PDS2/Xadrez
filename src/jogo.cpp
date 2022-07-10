#include "jogo.hpp"
#include "peca.hpp"
#include "excecoes.hpp"

Jogo::Jogo()
{
    Tabuleiro* tabuleiro = new Tabuleiro();
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
    p1->atualiza_pecas(tabuleiro);
    p2->atualiza_pecas(tabuleiro);
    p1->imprime();
    tabuleiro->imprime();
    p2->imprime();
    std::cout << std::endl;
}

bool Jogo::ativo()
{
    return jogo_ativo;
}

void Jogo::jogada()
{
    try
    {
        char li, lf;
        int linha_inicial;
        int coluna_inicial;
        int linha_final;
        int coluna_final;

        std::cout << "Digite a coordenada da peça a ser movida e para onde ela deve ir: A-H(linha)0-7(coluna)" << std::endl;
        std::cin >> li >> coluna_inicial >> lf >> coluna_final;
        li = toupper(li);
        lf = toupper(lf);
        std::cout << "Posições escolhidas: de " << li << coluna_inicial << " para " << lf << coluna_final << std::endl;
        linha_inicial = li - 65;
        linha_final = lf - 65;
        Movimento movimento = Movimento(tabuleiro, da_vez, linha_inicial, coluna_inicial, linha_final, coluna_final);

        movimento.validar_movimento();
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

    catch(PecaAliadaException &e)
    {
        std::cout << e.what() << std::endl;
    }

    catch(MovimentoInvalidoException &e)
    {
        std::cout << e.what() << std::endl;
    }

    catch(PecaNaFrenteException &e)
    {
        std::cout << e.what() << std::endl;
    }
}
