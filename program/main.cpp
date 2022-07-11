#include "jogo.hpp"

int main(int argc, char* argv[])
{
    Jogo* jogo = new Jogo();
    jogo->imprime();
    std::string comando;
    while (jogo->ativo()) 
    {
        comando = jogo->processa_terminal();
        jogo->jogada(comando);
        jogo->imprime();
    }

    delete jogo;
    
    return 0;
}