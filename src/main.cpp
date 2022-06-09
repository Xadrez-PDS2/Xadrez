#include "tabuleiro.h"

int main() {
  Tabuleiro *tab = new Tabuleiro();
  tab->imprime();
  while(tab->jogo_valido()) {
    tab->movimenta();
  }
  delete tab;
  return 0;
}