#include "jogo.hpp"
#include "peca.hpp"
#include "excecoes.hpp"

Jogo::Jogo()
{
    
    Tabuleiro* tabuleiro = new Tabuleiro(TAMANHO_DO_TABULEIRO);
    Jogador* p1 = new Jogador(tabuleiro, Cor::BRANCAS);
    Jogador* p2 = new Jogador(tabuleiro, Cor::PRETAS);
    this->comando_valido = ("[aA-hH]\\s*[1-8]\\s*[aA-hH]\\s*[1-8]");
    this->da_vez = p1;
    this->p1 = p1;
    this->p2 = p2;
    this->tabuleiro = tabuleiro;
    this->jogo_ativo = true;
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

const std::string Jogo::processa_jogada(const std::string entrada)
{
    std::string aux, entrada2;
    entrada2 = entrada;
    remove(entrada2.begin(), entrada2.end(), ' ');
    int tamanho = entrada2.length();
    
    for(int i = 0; i < tamanho-3; i++)
    {
        aux = entrada2.substr(i, 4);
        if(std::regex_match(aux, this->comando_valido))
            break;
    }

    return aux;
}

const std::string Jogo::processa_terminal()
{
    std::string entrada, aux;
    std::cout << "Digite a coordenada da peça a ser movida e para onde ela deve ir: A-H(coluna)1-8(linha)" << std::endl;
    
    while(!std::regex_search(entrada, this->comando_valido))
    {
        std::cin >> aux;
        entrada = entrada + aux;
    }

    aux = this->processa_jogada(entrada);
    
    return aux;
}

void Jogo::jogada(std::string entrada)
{
    try
    {
        char ci, cf;
        int linha_inicial;
        int coluna_inicial;
        int linha_final;
        int coluna_final;        
        
        if(std::regex_match(entrada, this->comando_valido))
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
            std::cout << " O comando é invalido." << std::endl;
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
    catch(ErroDeRoqueException &e)
    {
        std::cout << e.what() << std::endl;
    }
}
