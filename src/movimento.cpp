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

void Movimento::executar_movimento(){    
    tabuleiro->limpa_casa(linha_final, coluna_final);
    tabuleiro->adiciona_peca_existente(peca, linha_final, coluna_final); 
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
        checa_movimento_peao();
    //cavalo
    else if(peca->get_representacao() == " CAV ")
        checa_movimento_cavalo();
    //bispo
    else if(peca->get_representacao() == " BIS ")
        checa_movimento_bispo();
    //torre
    else if(peca->get_representacao() == " TOR ")
        checa_movimento_torre();
    //dama
    else if(peca->get_representacao() == " DAM ")
        checa_movimento_dama();
    //rei
    else if(peca->get_representacao() == " REI ")
        checa_movimento_rei();
}
/**
 *@todo Implementar a promoção e o 'en passant'
*/
void Movimento::checa_movimento_peao(){
    switch (peca->get_cor()){
        case Cor::BRANCAS:
            //verifica se o peao andou mais de duas casas ou para trás
            if (linha_final > linha_inicial+2 || linha_final < linha_inicial)
                throw MovimentoInvalidoException();
            //verifica se a posição final esta vazia 
            if (tabuleiro->get_casa(linha_final, coluna_final) == nullptr){
                //verifica se o peao se manteve na coluna
                if (coluna_final != coluna_inicial)
                    throw MovimentoInvalidoException();
                //verifica se o peao parou em uma posição duas linhas a frente 
                else if (linha_final == linha_inicial+2){
                    //verifica se é o primeiro movimento
                    if (peca->get_primeiro_movimento()){
                        //verifica se existe qualquer peca no caminho do peão
                        if (tabuleiro->get_casa(linha_inicial+1, coluna_inicial) != nullptr)
                            throw PecaNaFrenteException();
                    }
                    //Se não for o primeiro movimento
                    else {
                        throw MovimentoInvalidoException();
                    } 
                }
            }
            //caso haja alguma peça na posição final
            else {
                //verifica se o peao mudou para uma coluna adjacente
                if (coluna_final != coluna_inicial-1 && coluna_final != coluna_inicial+1)
                    throw MovimentoInvalidoException();
                //verifica se o peao parou em uma posição a frente 
                else if (linha_final != linha_inicial+1)
                    throw MovimentoInvalidoException();
            }
            break;
        case Cor::PRETAS:
            //verifica se o peao andou mais de duas casas ou para trás 
            if (linha_final < linha_inicial-2 || linha_final > linha_inicial)
                throw MovimentoInvalidoException();
            //verifica se a posição final esta vazia 
            if (tabuleiro->get_casa(linha_final, coluna_final) == nullptr){
                //verifica se o peao se manteve na coluna
                if (coluna_final != coluna_inicial)
                    throw MovimentoInvalidoException();
                //verifica se o peao parou em uma posição duas linhas a frente
                else if (linha_final == linha_inicial-2){
                    //verifica se é o primeiro movimento
                    if (peca->get_primeiro_movimento()){
                        //verifica se existe qualquer peca no caminho do peão
                        if (tabuleiro->get_casa(linha_inicial-1, coluna_inicial) != nullptr)
                            throw PecaNaFrenteException();
                    }
                    //Se não for o primeiro movimento
                    else {
                        throw MovimentoInvalidoException();
                    } 
                } 
            }
            //caso haja alguma peça na posição final
            else {
                //verifica se o peao mudou para uma coluna adjacente
                if (coluna_final != coluna_inicial-1 && coluna_final != coluna_inicial+1)
                    throw MovimentoInvalidoException();
                //verifica se o peao parou em uma posição a frente 
                else if (linha_final != linha_inicial-1)
                    throw MovimentoInvalidoException();
            }
            break;
    }
    peca->set_primeiro_movimento(false);
}
/**
 *@todo Implementar este metodo
*/
void Movimento::checa_movimento_cavalo(){
    
}
/**
 *@todo Implementar este metodo
*/
void Movimento::checa_movimento_torre(){
    
}
/**
 *@todo Implementar este metodo
*/
void Movimento::checa_movimento_bispo(){
    
}
/**
 *@todo Implementar este metodo
*/
void Movimento::checa_movimento_dama(){
    
}
/**
 *@todo Implementar este metodo
*/
void Movimento::checa_movimento_rei(){
    
}