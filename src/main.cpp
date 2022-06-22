#include "jogo.hpp"

int main() {
  Jogo* jogo = new Jogo();
  jogo->imprime();
  while (jogo->ativo()) {
    jogo->jogada();
    jogo->imprime();
  }
  delete jogo;
  return 0;
}