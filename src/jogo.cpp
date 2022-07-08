#include "jogo.hpp"
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
        std::regex comando_valido("[aA-hH]\\s*[1-8]\\s*[aA-hH]\\s*[1-8]");
        std::string entrada, aux;
        char ci, cf;
        int linha_inicial;
        int coluna_inicial;
        int linha_final;
        int coluna_final;

        std::cout << "Digite a coordenada da peça a ser movida e para onde ela deve ir: A-H(coluna)1-8(linha)" << std::endl;
        while(!std::regex_search(entrada, comando_valido))
        {
            std::cin >> aux;
            entrada = entrada + aux;
        }
        aux = entrada.at(0) + entrada.at(1) + entrada.at(2) + entrada.at(3);
        while(!std::regex_match(entrada, comando_valido))
        {
            entrada.erase(0, 1);
            if(entrada.empty())
                break;
        }
        if (std::regex_match(entrada, comando_valido))
        {
            ci = entrada[0];
            linha_inicial = std::atoi(&entrada[1]);
            cf = entrada[2];
            linha_final = std::atoi(&entrada[3]);
            ci = toupper(ci);
            cf = toupper(cf);
            coluna_inicial = ci - 65;
            coluna_final = cf - 65;            
            std::cout << "Posições escolhidas: de " << ci << linha_inicial << " para " << cf << linha_final << std::endl;
            linha_inicial -= 1;
            linha_final -= 1;
            Movimento movimento = Movimento(tabuleiro, da_vez, linha_inicial, coluna_inicial, linha_final, coluna_final);

            movimento.validar_movimento();
            movimento.executar_movimento();

            if(da_vez == p1) 
                da_vez = p2;
            
            else
                da_vez = p1;
        }
        else
        {
            std::cout << " O comando é invalido." << std::endl;
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
