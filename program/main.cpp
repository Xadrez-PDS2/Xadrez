#include "jogo.hpp"
#include "pgn.hpp"


int main(int argc, char* argv[])
{
    if (argc < 2){
        Jogo* jogo = new Jogo();
        jogo->imprime();
        std::string comando;
        while (jogo->ativo()) 
        {
            try
            {
                comando = jogo->processa_terminal();
                jogo->jogada(comando);
                jogo->imprime();
            }
            catch(VitoriaBrancas &e)
            {
                jogo->set_ativo(false);
                jogo->imprime();
                std::cout << e.what() << '\n';
            }
            catch(VitoriaPretas &e)
            {
                jogo->set_ativo(false);
                jogo->imprime();
                std::cout << e.what() << '\n';
            }
            
        }

        delete jogo;
    }
    else
    {
        std::string nome_do_arquivo = argv[1];
        try
        {
            LeitorDePgn* leitor = new LeitorDePgn(nome_do_arquivo);
            leitor->imprime_comandos();
            delete leitor;
        }
        catch(const ErroAoAbrirException &e)
        {
            std::cout << e.what() << std::endl;
        }
        catch(const ErroAoFecharException &e)
        {
            std::cout << e.what() << std::endl;
        }
        
    }
    return 0;
}