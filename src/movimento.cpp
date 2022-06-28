#include <iostream>

#include "movimento.hpp"
#include "tabuleiro.hpp"
#include "jogador.hpp"
#include "peca.hpp"
#include "peao.hpp"
#include "bispo.hpp"
#include "cavalo.hpp"
#include "torre.hpp"
#include "dama.hpp"
#include "rei.hpp"

const int TAMANHO_MAPA=8;

Movimento::Movimento(
    Tabuleiro *tabuleiro,
    Jogador *jogador,
    int linha_inicial,
    int coluna_inicial,
    int linha_final,
    int coluna_final)
    {   
        this->tabuleiro = tabuleiro;
        this->linha_inicial = linha_inicial;
        this->linha_final = linha_final;
        this->coluna_inicial = coluna_inicial;
        this->coluna_final = coluna_final;
        this->peca = (tabuleiro->get_casa(linha_inicial, coluna_inicial));
        this->jogador = jogador;   
    }

void Movimento::executar_movimento()
{   
    const std::string &tipo = peca->get_representacao(); 
    tabuleiro->limpa_casa(linha_final, coluna_final);
    tabuleiro->adiciona_peca(tipo,linha_final, coluna_final, peca->get_cor());
    tabuleiro->limpa_casa(linha_inicial, coluna_inicial);   
}
void Movimento::validar_movimento(){
    //Confere se o movimento está dentro do tabuleiro
    if(linha_final < 0 || coluna_final < 0) 
        throw ForaDoMapaException();
    //Confere se o movimento está dentro do tabuleiro
    if(linha_final >= TAMANHO_MAPA || coluna_final >= TAMANHO_MAPA) 
        throw ForaDoMapaException();
    //Confere se tem peça para movimentar  
    if(tabuleiro->get_casa(linha_inicial, coluna_inicial) == nullptr) 
        throw SemPecaParaMovimentarException();
    //Confere se está movimentando peça aliada
    if(peca->get_cor()!=jogador->get_cor()) 
        throw NaoESuaVezException();
    //Confere se a peca a ser tomada é da mesma cor que o jogador atual
    if(tabuleiro->get_casa(linha_final, coluna_final) != nullptr && jogador->get_cor() ==  tabuleiro->get_casa(linha_final, coluna_final)->get_cor())
        throw PecaAliadaException();
    //Confere se movimentação desejada é passível de ser realizada pela peça
    checa_movimento_peca();
    
        

}
void Movimento::checa_movimento_peca(){
    //peão
    if(peca->get_representacao() == " PEA ")
        if(!checa_movimento_peao())
            throw MovimentoInvalidoException();
    //cavalo
    else if(peca->get_representacao() == " CAV ")
        if(!checa_movimento_cavalo())
            throw MovimentoInvalidoException();
    //bispo
    else if(peca->get_representacao() == " BIS ")
        if(!checa_movimento_bispo())
            throw MovimentoInvalidoException();
    //torre
    else if(peca->get_representacao() == " TOR ")
        if(!checa_movimento_torre())
            throw MovimentoInvalidoException();
    //dama
    else if(peca->get_representacao() == " DAM ")
        if(!checa_movimento_dama())
            throw MovimentoInvalidoException();
    //rei
    else if(peca->get_representacao() == " REI ")
        if(!checa_movimento_rei())
            throw MovimentoInvalidoException();
}
/**
 *@todo Implementar a promoção e o 'en passant'
 *@todo bug:Peca consegue realizar o movimento inicial a qualquer momento da partida
*/
bool Movimento::checa_movimento_peao(){
    Peao peao = Peao(linha_inicial, coluna_inicial, jogador->get_cor());
    switch (peao.get_cor()){
        case Cor::BRANCAS:
            //verifica se o peao andou mais de duas casas ou para trás
            if (linha_final > linha_inicial+2 || linha_final < linha_inicial)
                return false;
            //verifica se a posição final esta vazia 
            if (tabuleiro->get_casa(linha_final, coluna_final) == nullptr){
                //verifica se o peao se manteve na coluna
                if (coluna_final != coluna_inicial)
                    return false;
                //verifica se o peao parou em uma posição duas linhas a frente e se é o primeiro movimento
                else if (linha_final == linha_inicial+2 && peao.primeiro_movimento){
                    //verifica se existe qualquer peca no caminho do peão
                    if (tabuleiro->get_casa(linha_inicial+1, coluna_inicial) != nullptr)
                        return false;
                }
            }
            //caso haja alguma peça na posição final
            else {
                //verifica se o peao mudou para uma coluna adjacente
                if (coluna_final != coluna_inicial-1 && coluna_final != coluna_inicial+1)
                    return false;
                //verifica se o peao parou em uma posição a frente 
                else if (linha_final != linha_inicial+1)
                    return false;
            }
            break;
        case Cor::PRETAS:
            //verifica se o peao andou mais de duas casas ou para trás 
            if (linha_final < linha_inicial-2 || linha_final > linha_inicial)
                return false;
            //verifica se a posição final esta vazia 
            if (tabuleiro->get_casa(linha_final, coluna_final) == nullptr){
                //verifica se o peao se manteve na coluna
                if (coluna_final != coluna_inicial)
                    return false;
                //verifica se o peao parou em uma posição duas linhas a frente e se é o primeiro movimento
                else if (linha_final == linha_inicial-2 && peao.primeiro_movimento){
                    //verifica se existe qualquer peca no caminho do peão
                    if (tabuleiro->get_casa(linha_inicial-1, coluna_inicial) != nullptr)
                        return false;
                } 
            }
            //caso haja alguma peça na posição final
            else {
                //verifica se o peao mudou para uma coluna adjacente
                if (coluna_final != coluna_inicial-1 && coluna_final != coluna_inicial+1)
                    return false;
                //verifica se o peao parou em uma posição a frente 
                else if (linha_final != linha_inicial-1)
                    return false;
            }
            break;
    }
    return true;
}
/**
 *@todo Implementar este metodo
*/
bool Movimento::checa_movimento_cavalo(){
    return true;
}
/**
 *@todo Implementar este metodo
*/
bool Movimento::checa_movimento_torre(){
    return true;
}
/**
 *@todo Implementar este metodo
*/
bool Movimento::checa_movimento_bispo(){
    return true;
}
/**
 *@todo Implementar este metodo
*/
bool Movimento::checa_movimento_dama(){
    return true;
}
/**
 *@todo Implementar este metodo
*/
bool Movimento::checa_movimento_rei(){
    return true;
}