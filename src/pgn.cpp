#include "pgn.hpp"

//======================================PGN======================================//

Pgn::Pgn(const std::string &nome_do_arquivo)
{
    this->nome_do_arquivo = nome_do_arquivo;
    this->jogo_valido = ("\\s\\d+\\..+[\\s\\S]*");
    this->comandos_da_rodada = ("\\d+\\.\\s*\\w*[a-h][1-8][+#]*\\s*\\w*[a-h]*[1-8]*\\+*\\s*"); 
    this->casa_final = ("[a-h][1-8]");
    this->rodada = ("\\d+\\.");     //cuidado para não pegar a data

}

Pgn::~Pgn()
{

}
//=================================LEITOR DE PGN=================================//


LeitorDePgn::LeitorDePgn(const std::string &nome_do_arquivo):
Pgn(nome_do_arquivo)
{
    std::string aux = this->nome_do_arquivo.substr(0, 8);
    if (aux != "./pgn/")
        this->nome_do_arquivo = "./pgn/" + this->nome_do_arquivo;
    this->abre_arquivo();

}

LeitorDePgn::~LeitorDePgn()
{

}

void LeitorDePgn::abre_arquivo()
{
    std::string aux;
    arquivo.open(this->nome_do_arquivo);
    if (!arquivo.is_open())
        throw ErroAoAbrirException();
    while(getline(arquivo, aux))
    {
        conteudo = conteudo + aux + '\n';
    }
    this->fecha_arquivo();
}

void LeitorDePgn::fecha_arquivo()
{
    arquivo.close();
    if (arquivo.is_open())
        throw ErroAoFecharException();
}

void LeitorDePgn::imprime_comandos()
{
    std::string aux1, aux2, aux3, aux4;
    std::smatch _jogo_valido;
    std::smatch _comando_da_rodada;
    std::smatch _casa_final;
    std::smatch _rodada;
    while(std::regex_search(this->conteudo, _jogo_valido, this->jogo_valido))
    {
        std::cout << "O conteudo obtido dentro do arquivo é: " << std::endl << this->conteudo << std::endl;
        aux1 = _jogo_valido.str();
        std::cout << "Dentro de jogo válido temos:" << std::endl << aux1 << std::endl;
        while(std::regex_search(aux1, _comando_da_rodada, this->comandos_da_rodada))
        {
            aux2 = _comando_da_rodada.str();
            std::cout << "Dentro de uma rodada valida temos:" << aux2 << std::endl;
            aux1 = _comando_da_rodada.suffix().str();
        }
        this->conteudo = _jogo_valido.suffix().str();
    }
}

//================================ESCRITOR DE PGN================================//


EscritorDePgn::EscritorDePgn(const std::string &nome_do_arquivo):
Pgn(nome_do_arquivo)
{
    
}

EscritorDePgn::~EscritorDePgn()
{

}
void EscritorDePgn::abre_arquivo()
{

}

void EscritorDePgn::fecha_arquivo()
{
    
}