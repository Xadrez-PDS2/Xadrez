#ifndef PGN_HPP
#define PGN_HPP

#include "excecoes.hpp"

#include <string>
#include <chrono>
#include <regex>
#include <fstream>
#include <iostream>

class Pgn
{
    public:
        /**
         * @brief Construtor de um objeto Pgn
         * @param nome_do_arquivo Recebe o nome do arquivo em que realizará a gravação ou leitura dos dados da partida
         */
        Pgn(const std::string &nome_do_arquivo);
        /**
         * @brief Destrutor de objetos Pgn
         */
        virtual ~Pgn();
        /**
         * @brief Abre o arquivo
         */
        virtual void abre_arquivo() = 0;
        /**
         * @brief fecha arquivo
         */
        virtual void fecha_arquivo() = 0;

    protected:
        std::string nome_do_arquivo;
        std::regex jogo_valido;
        std::regex comandos_da_rodada;
        std::regex casa_final;
        std::regex rodada;
        std::string conteudo;
};

class LeitorDePgn: public Pgn
{
    public:
        /**
         * @brief Construtor do objeto Leitor De Pgn
         * @param nome_do_arquivo Recebe o nome do arquivo em que realizará leitura dos dados da partida
         */
        LeitorDePgn(const std::string &nome_do_arquivo);
        /**
         * @brief Destrutor do objeto Leitor De Pgn
         */
        virtual ~LeitorDePgn() override;
        /**
         * @brief Abre o arquivo para leitura
         */
        virtual void abre_arquivo() override;
        /**
         * @brief fechamento do arquivo utilizado para leitura
         */
        virtual void fecha_arquivo() override;
        /**
         * @brief Função teste para verificar o que esta sendo lido 
         */
        void imprime_comandos();

    private:
        std::ifstream arquivo;
    

};

class EscritorDePgn: public Pgn
{
    public:
        /**
         * @brief Construtor do objeto Esritor de Pgn
         * @param nome_do_arquivo Recebe o nome do arquivo em que realizará a gravação dos dados da partida
         */
        EscritorDePgn(const std::string &nome_do_arquivo);
        /**
         * @brief Destrutor do objeto Escritor de Pgn
         */
        virtual ~EscritorDePgn() override;
        /**
         * @brief Abre o arquivo para escrita
         */
        virtual void abre_arquivo() override;
        /**
         * @brief fechamento do arquivo utilizado para escrita
         */
        virtual void fecha_arquivo() override;

    private:
    std::ofstream arquivo;
};


#endif