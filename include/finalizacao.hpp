#ifndef FINALIZACAO_HPP
#define FINALIZACAO_HPP
/*
reis não podem ficar um em frente ao outro
executar o movimento em uma copia do tabuleiro antes de executar no real
o movimento checa se a peca é do jogador que esta tentando movimentar


*/
#include "jogador.hpp"
#include "movimento.hpp"

class Finalizacao
{
    public:
        /**
        * @brief Construct a new finalizacao object 
        */
        Finalizacao(Tabuleiro* Tabuleiro);
        /**
         * @brief Destroy the finalizacao object
         * 
         */
        ~Finalizacao();
        void monitora_movimento(Tabuleiro *tabuleiro,
            Jogador *jogador,
            int linha_inicial,
            int coluna_inicial,
            int linha_final,
            int coluna_final);

        /**
         * @brief Checa a igualdade entre as posições de tabuleiros
         * 
         * @param tabuleiro o tabuleiro que ira comparar com o guardado estaticamente
         * @return true se não encontrar diferença na comparação
         */
        bool igual_tabuleiro(Tabuleiro tabuleiro);
        /**
         * @brief Atualiza os valores do tabuleiro guardado estaticamente
         */
        void atualiza_tabuleiro();
        /**
         * @brief Contabiliza as jogadas
         */
        void conta_jogada();
        /**
         * @brief Atualiza o valor que guarda a Cor da vez
         * 
         */
        void jogador_da_vez(Cor da_vez);
        void jogo_finalizado();
        

    private:
        static Tabuleiro tabuleiro;
        int jogadas;
        Cor da_vez;
        bool flag_fim_de_jogo;
        
};
/**
 * @brief classe que cuida de verificar se o jogador esta aplicando um xeque ou sofrendo
 * 
 */
class Xeque
{
    public:
        /**
         * @brief Construct a new Xeque object
         * 
         */
        Xeque(Tabuleiro *tabuleiro,
            Jogador* jogador,
            int linha_inicial,
            int coluna_inicial,
            int linha_final,
            int coluna_final);
        /**
         * @brief Destroy the Xeque object
         * 
         */
        ~Xeque();
        /**
         * @brief Checa se houve xeque com a execução deste movimento
         * @return true se o oponente esta em xeque
         */
        bool checa_por_xeque();
        /**
         * @brief Checa se o oponente esta em xeque
         */
        bool oponente_xeque();
        /**
         * @brief Checa se o jogador se colocou em xeque
         * 
         */
        void da_vez_xeque();
        /**
         * @brief Procura a posição do Rei de ambos jogadores e armazena
         * 
         */
        void procura_reis();
        /**
         * @brief Faz uma copia do tabuleiro
         * 
         */
        void copia_tabuleiro(Tabuleiro* tab_copiado, Tabuleiro*tab);
        bool checa_fuga();
        
        

    private:
        Tabuleiro* tabuleiro = nullptr;
        Movimento* movimento = nullptr;
        Jogador* jogador;
        Cor da_vez;
        Cor oponente;
        std::pair <int, int> posicao_rei_da_vez;
        std::pair <int, int> posicao_rei_oponente;
        int linha_inicial;
        int coluna_inicial;
        int linha_final;
        int coluna_final;
        



};


#endif