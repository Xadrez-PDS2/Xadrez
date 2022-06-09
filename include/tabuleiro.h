#ifndef TAB_PDS2
#define TAB_PDS2

#include <vector>

#include "peca.h"

using namespace std;

class Tabuleiro {
  private:
    vector<vector<Peca *>> _casas;
    Cor _da_vez;
  public:
    Tabuleiro();
    ~Tabuleiro();
    void imprime();
    bool movimenta(int x, int y, bool diag_esq);
};

#endif