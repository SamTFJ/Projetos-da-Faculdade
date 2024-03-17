#include <iostream>
#include <string>
#include "produto.h"
#ifndef BORDADOS_H
#define BORDADOS_H

using namespace std;

class Bordados : public Produto {
  private:

    char m_tamanho;

  public:

    Bordados();
    ~Bordados();

    Bordados(string nome, string id_produto, float preco, string descricao, int qtd_estoque, int tipo_produto, char tamanho);

    void setTamanho(char tamanho);
    char getTamanho();
};

#endif 