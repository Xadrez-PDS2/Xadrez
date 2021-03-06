#ifndef EXCECOES_HPP
#define EXCECOES_HPP

#include <exception>


class ErroDeJogoException : public std::exception
{
    public:
        virtual const char* what() const noexcept
        {
            return "Movimentação Inválida!";
        }
};

class ForaDoMapaException : public ErroDeJogoException
{
    public:
        virtual const char* what() const noexcept
        {
            return "A peça não pode ficar fora do tabuleiro.";
        }
};

class SemPecaParaMovimentarException : public ErroDeJogoException
{
    public:
        virtual const char* what() const noexcept
        {
            return "Não há peça na casa selecionada para realizar a movimentação.";
        }
};

class NaoESuaVezException : public ErroDeJogoException
{
    public:
        virtual const char* what() const noexcept
        {
            return "Não é sua vez de realizar a movimentação.";
        }
};

class PecaNaFrenteException : public ErroDeJogoException
{
    public:
        virtual const char* what() const noexcept
        {
            return "A peça não pode ser movimentada para a casa selecionada porque tem uma peça no caminho.";
        }
};

class PecaAliadaException : public ErroDeJogoException
{
    public:
        virtual const char* what() const noexcept
        {
            return "O jogador não pode tomar as suas próprias pecas.";
        }
};

class MovimentoInvalidoException : public ErroDeJogoException
{
    public:
        virtual const char* what() const noexcept
        {
            return "A peça não pode realizar este movimento.";
        }
};

class ErroDeLogicaException : public std::exception
{
    public:
        virtual const char* what() const noexcept
        {
            return "Procedimento inesperado.";
        }
};

class ErroDeRoqueException : public std::exception
{
    public:
        virtual const char* what() const noexcept
        {
            return "Não é possivel realizar o roque nesta situação";
        }
};
class ErroDeXequeException : public ErroDeJogoException
{
    public:
        virtual const char* what() const noexcept
        {
            return "Não é possivel realizar o movimento, pois colocaria seu rei em xeque";
        }
};


class FimDeJogo : public std::exception
{
    public:
        virtual const char* what() const noexcept
        {
            return "Encerramento do jogo.";
        }
};

class VitoriaBrancas : public FimDeJogo
{
    public:
        virtual const char* what() const noexcept
        {
            return "1 - 0 \nVitoria das Brancas!";
        }
};
class VitoriaPretas : public FimDeJogo
{
    public:
        virtual const char* what() const noexcept
        {
            return "0 - 1 \nVitoria das Pretas!";
        }
};
class Empate : public FimDeJogo
{
    public:
        virtual const char* what() const noexcept
        {
            return "1/2 - 1/2 \nEmpate";
        }
};






class ErroPgnException : public std::exception
{
    public:
        virtual const char* what() const noexcept
        {
            return "Erro ao manipular os arquivos!";
        }
};

class ErroAoAbrirException : public ErroPgnException
{
    public:
        virtual const char* what() const noexcept
        {
            return "Não foi possivel realizar a abertura do arquivo";
        }
};

class ErroAoFecharException : public ErroPgnException
{
    public:
        virtual const char* what() const noexcept
        {
            return "Não foi possivel realizar o fechamento do arquivo";
        }
};

#endif