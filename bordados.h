#include <iostream>
#include <string>
#include "produto.h"
#ifndef BORDADOS_H
#define BORDADOS_H

using namespace std;

class Bordados : public Produto {
  private:

    string m_tamanho;

  public:

    Bordados();
    ~Bordados();

    Bordados(string nome, string id_produto, float preco, string descricao, int qtd_estoque, int tipo_produto, string tamanho);

    void setTamanho(string tamanho);
    string getTamanho();
};

#endif 