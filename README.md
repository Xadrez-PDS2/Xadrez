# 👑 Xadrez

<div align="center">
   <img height="300em" src="https://user-images.githubusercontent.com/100887395/179021605-daa5f792-a058-48b7-b737-06e0bb209700.png"/>
</div>

<div align="center">
   <img src="https://img.shields.io/github/repo-size/Xadrez-PDS2/Xadrez?style=for-the-badge"/>
   <img src="http://img.shields.io/static/v1?label=MADE%20WITH&message=C++&color=blue&style=for-the-badge"/>
   <img src="https://img.shields.io/github/last-commit/Xadrez-PDS2/Xadrez?style=for-the-badge"/>
   <img src="http://img.shields.io/static/v1?label=STATUS&message=FINALIZADO&color=GREEN&style=for-the-badge"/>
</div>
   
   
## 📄 Descrição do projeto

Este projeto foi desenvolvido como requisito avaliativo para a disciplina Programação e Desenvolvimento de Software II, ministrada pelo professor Flávio Vinícius Diniz de Figueiredo que leciona na Universidade Federal de Minas Gerais - UFMG. 

O projeto consiste em um protótipo do jogo de xadrez, desenvolvido na linguagem C++, com o objetivo de aplicar os conceitos e técnicas vistos ao longo de toda a disciplina em um único sistema. Neste protótipo, dois jogadores podem jogar uma partida de xadrez a partir de linhas de comando e visualizando as representações do tabuleiro (matriz 8x8) e das peças (nomes abreviados).


## ⚠️ Pré-requisitos

- Ter o MinGW na versão 11.2.0
- Ter o CMake 
- Ter o GitHub Desktop
- Possuir um compilador para C++
- Estar em um ambiente Linux


## 📁 Acesso 

1. Abra o terminal.

2. Clone o repositório.

```bash
git clone https://github.com/Xadrez-PDS2/Xadrez.git
```

3. Entre no diretório do repositório.

```bash
cd Xadrez
```

4. Execute o comando make para compilar o projeto.

```bash
make
```

5. Execute o comando ./bin./main para executar o jogo.

```bash
./bin./main
```


## ♟️ Funcionalidade

Para iniciar o jogo deve-se antes decidir quem irá comandar as peças brancas e as peças pretas, lembrando que quem comandar as peças brancas sempre inicia a partida. Após definir quem comanda cada peça, as jogadas iniciam. Para realizar uma jogada deve-se inserir no terminal de execução a posição (A-H 0-7) da peça que você deseja movimentar e a posição que ela irá assumir. 

Este jogo foi programado para realizar todas as jogadas do jogo de xadrez tradicional, inclusive as jogadas especiais.


## 💻 Técnicas e tecnologias utilizadas

- C++
- Visual Studio Code
- Programação orientada a objetos
- Programação defensiva


## 📋 User stories

### Jogo
- Eu como jogo inicio quando a primeira peça for movimentada.
- Eu como jogo finalizo quando houver um empate ou uma vitória.

### Jogador
- Eu como jogador tenho a preferência na primeira jogada se minhas peças forem da cor branca.
- Eu como jogador não posso movimentar minha peça caso tenha alguma peça minha no caminho, com excessão da peça cavalo que pode pular peças na movimentação
- Eu como jogador empato o jogo quando, ao iniciar minha rodada, não possuo nenhum movimento válido para nenhuma das minhas peças remanescentes.
- Eu como jogador empato o jogo quando ambos os jogadores não possuem peças o suficiente para conseguir aplicar o xeque mate, por exemplo possuindo apenas o rei e o cavalo.
- Eu como jogador empato o jogo quando ocorrerem 50 lances em que não foram capturadas nenhuma peça ou que nenhum peão se moveu.
- Eu como jogador empato o jogo quando ambos os jogadores repetem o mesmo movimento três vezes consecutivas.
- Eu como jogador ganho a partida quando ataco o rei inimigo e, durante a rodada inimiga, o oponente não possui movimentos possíveis para o rei ou que interrompam a sua eliminação (seja capturando a peça atacante ou bloqueando o "caminho" até o rei)

### Peça
- Eu como peça que está atacando tenho que ficar na posição da peça atacada.

### Peão
- Eu como peão que ainda não se movimentou, posso me mover em até duas casas para frente.
- Eu como peão após a primeira movimentação posso me mover e atacar uma casa na diagonal para frente.
- Eu como peão posso fazer o movimento chamado "en passant" se estiver a duas linhas de distância da casa inicial dos peões oponentes e algum dos peões das colunas adjacentes realizar o seu primeiro movimento de duas casas, eu posso captura-lo como se tivesse se movido apenas uma única casa (somente imediatamente depois dele ter feito este movimento).

### Torre
- Eu como torre posso movimentar e atacar na vertical e horizontal.

### Bispo
- Eu como bispo posso atacar e movimentar  na diagonal.

### Cavalo
- Eu como cavalo posso movimentar e atacar uma casa para frente e três na horizontal ou três para frente e uma na horizontal.

### Rei
- Eu como rei posso movimentar e atacar nas casas adjacentes.
- Eu como rei posso realizar o “roque” se tanto eu quanto a torre aliada alvo não tiver realizado nenhum movimento nesta partida e que necessariamente não haja nenhuma peça entre nós, o movimento consiste em andar duas casas a esquerda ou direita com o rei (dependendo da torre escolhida) e posicionar a torre na casa adjacente imediatamente oposta ao movimento do rei.

### Dama
- Eu como dama posso movimentar e atacar nas diagonais, na horizontal e na vertical.


## 😁 Autores

| [<img src="https://avatars.githubusercontent.com/u/101598349?v=4" width=115><br><sub>Érick Santos</sub>](https://github.com/ErickSantosRodrigues) |  [<img src="https://avatars.githubusercontent.com/u/83253023?v=4" width=115><br><sub>Igor Braga</sub>](https://github.com/igorbraga20) |  [<img src="https://avatars.githubusercontent.com/u/100887395?v=4" width=115><br><sub>Stéphanie Barbosa</sub>](https://github.com/Stephanie7l) | [<img src="https://avatars.githubusercontent.com/u/103759032?v=4" width=115><br><sub>Vitor Lima</sub>](https://github.com/vbclima) |
| :---: | :---: | :---: | :---: |
