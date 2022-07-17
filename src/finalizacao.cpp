#include "finalizacao.hpp"

Finalizacao::Finalizacao(Tabuleiro *tabuleiro)
{
    this->jogador_da_vez(Cor::BRANCAS);
    this->jogadas = 1;
    this->flag_fim_de_jogo = false;

}
Finalizacao::~Finalizacao()
{

}
void Finalizacao::conta_jogada()
{
    this->jogadas++;
}
void Finalizacao::atualiza_tabuleiro()
{

}
void Finalizacao::jogador_da_vez(Cor da_vez)
{
    this->da_vez = da_vez;
}
void Finalizacao::monitora_movimento(Tabuleiro *tabuleiro,
                                    Jogador *jogador,
                                    int linha_inicial,
                                    int coluna_inicial,
                                    int linha_final,
                                    int coluna_final)
{
    Xeque* xeque = new Xeque(tabuleiro, jogador, linha_inicial, coluna_inicial, linha_final, coluna_final);
    this->jogador_da_vez(jogador->get_cor());
    bool oponente_atacado = xeque->checa_por_xeque();
    if (oponente_atacado)
    {
        bool fuga = xeque->checa_fuga();
        if (!fuga)
        {
            this->flag_fim_de_jogo = true;
        }
        else
        {
        }
    }
    delete xeque;
}
void Finalizacao::jogo_finalizado()
{
    if(this->flag_fim_de_jogo)
    {
        switch (da_vez)
            {
            case Cor::BRANCAS:
                throw VitoriaBrancas();
                break;
            case Cor::PRETAS:
                throw VitoriaPretas();
                break;
            }
    }
}





Xeque::Xeque(Tabuleiro *tabuleiro,
            Jogador* jogador,
            int linha_inicial,
            int coluna_inicial,
            int linha_final,
            int coluna_final)
{
    this->tabuleiro = new Tabuleiro(tabuleiro->get_tamanho());
    this->copia_tabuleiro(tabuleiro, this->tabuleiro);
    this->jogador = jogador;
    this->movimento = new Movimento(this->tabuleiro, this->jogador, linha_inicial, coluna_inicial, linha_final, coluna_final);
    this->linha_inicial = linha_inicial;
    this->coluna_inicial = coluna_inicial;
    this->linha_final = linha_final;
    this->coluna_final = coluna_final;
    this->movimento->validar_movimento();
    this->movimento->executar_movimento();
    this->da_vez = jogador->get_cor();
    this->oponente = (da_vez == Cor::BRANCAS) ? Cor::PRETAS : Cor::BRANCAS;
    this->procura_reis();
}
Xeque::~Xeque()
{
    delete this->tabuleiro;
    delete this->movimento;

}

bool Xeque::checa_por_xeque()
{
    this->da_vez_xeque();
    return this->oponente_xeque();
}
bool Xeque::oponente_xeque()
{
    for (int linha = 0; linha < this->tabuleiro->get_tamanho(); linha++)
    {
        for (int coluna = 0; coluna < this->tabuleiro->get_tamanho(); coluna++)
        {
            Peca* peca = this->tabuleiro->get_casa(linha, coluna);
            if(peca != nullptr)
            {
                Jogador pteste = Jogador(tabuleiro,peca->get_cor(), false);
                Movimento mov(this->tabuleiro, &pteste, linha, coluna, posicao_rei_oponente.first, posicao_rei_oponente.second);
                if ( peca->get_representacao() != " REI " && this->da_vez == peca->get_cor())
                {
                    try
                    {
                        mov.validar_movimento();
                    }
                    catch(...)
                    {
                        continue; 
                    }
                    return true;
                }
            }

        }
    }
    return false;
}
void Xeque::da_vez_xeque()
{
    for (int linha = 0; linha < this->tabuleiro->get_tamanho(); linha++)
    {
        for (int coluna = 0; coluna < this->tabuleiro->get_tamanho(); coluna++)
        {
            Peca* peca = this->tabuleiro->get_casa(linha, coluna);
            if(peca != nullptr)
            {
                Jogador pteste = Jogador(tabuleiro,peca->get_cor(), false);
                Movimento mov(this->tabuleiro, &pteste, linha, coluna, posicao_rei_da_vez.first, posicao_rei_da_vez.second);
                if (peca->get_representacao() != " REI " && this->oponente == peca->get_cor())
                {
                  
                    try
                    {
                        mov.validar_movimento();
                    }
                    catch(...)
                    {
                        continue; 
                    }
                    throw(ErroDeXequeException());
                }
            }
        }
    }

}
void Xeque::procura_reis()
{
    for (int linha = 0; linha < this->tabuleiro->get_tamanho(); linha++)
    {
        for (int coluna = 0; coluna < this->tabuleiro->get_tamanho(); coluna++)
        {
            Peca* peca = this->tabuleiro->get_casa(linha, coluna);
            if (peca != nullptr && peca->get_representacao() == " REI ")
            {
                if (peca->get_cor() == da_vez)
                    this->posicao_rei_da_vez = peca->get_casas();
                else
                    this->posicao_rei_oponente = peca->get_casas();
            }
        }
    }
    
}
void Xeque::copia_tabuleiro(Tabuleiro* tab_copiado, Tabuleiro* tab)
{
    for (int linha = 0; linha < this->tabuleiro->get_tamanho(); linha++)
    {
        for (int coluna = 0; coluna < this->tabuleiro->get_tamanho(); coluna++)
        {
            Peca* peca = tab_copiado->get_casa(linha, coluna);
            if (peca != nullptr)
                tab->adiciona_peca(peca->get_representacao(), peca->get_casas().first, peca->get_casas().second, peca->get_cor());
            else
                tab->limpa_casa(linha, coluna);
        }
    }

}
bool Xeque::checa_fuga()
{
    int linha_inicial = this->posicao_rei_oponente.first;
    int coluna_inicial = this->posicao_rei_oponente.second;
    std::pair<int, int> amplitude_linha;  
    std::pair<int, int> amplitude_coluna;
    if (linha_inicial == 0)
        amplitude_linha.first = 0;
    else
        amplitude_linha.first = linha_inicial-1;
    if (linha_inicial == (this->tabuleiro->get_tamanho()-1))
        amplitude_linha.second = this->tabuleiro->get_tamanho()-1;
    else
        amplitude_linha.second = linha_inicial+1;
    if (coluna_inicial == 0)
        amplitude_coluna.first = 0;
    else
        amplitude_coluna.first = coluna_inicial-1;
    if (coluna_inicial == (this->tabuleiro->get_tamanho()-1))
        amplitude_coluna.second = this->tabuleiro->get_tamanho()-1;
    else
        amplitude_coluna.second = coluna_inicial+1;
    for (int linha = amplitude_linha.first; linha <= amplitude_linha.second; linha++)
    {
        for (int coluna = amplitude_coluna.first; coluna <= amplitude_coluna.second; coluna++)
        {
            Peca* peca = this->tabuleiro->get_casa(linha_inicial, coluna_inicial);
            if (peca != nullptr)
            {
                Tabuleiro* tab = new Tabuleiro(this->tabuleiro->get_tamanho());
                this->copia_tabuleiro(this->tabuleiro, tab);
                Jogador pteste = Jogador(tabuleiro,peca->get_cor(), false);
                Movimento mov(this->tabuleiro, &pteste, linha_inicial, coluna_inicial, linha, coluna);
                bool ainda_atacado;
                try
                {
                    mov.validar_movimento();
                    mov.executar_movimento();
                    this->procura_reis();
                    ainda_atacado = this->oponente_xeque();
                    if (!ainda_atacado)
                        return true;
                    this->copia_tabuleiro(tab, this->tabuleiro);
                    this->procura_reis();
                    
                }
                catch(...)
                {
                    delete tab;
                    continue;
                }
                

            }
        }
    }
    return false;  
}