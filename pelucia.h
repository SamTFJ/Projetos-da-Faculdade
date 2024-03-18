#include <iostream>
#include <string>
#include "produto.h"
#ifndef PELUCIA_H
#define PELUCIA_H

using namespace std;

class Pelucia : public Produto{
  
  private:

    string m_material;
    string m_tamanho;

  public:

    Pelucia();
    ~Pelucia();

    Pelucia(string nome, string id_produto, float preco, string descricao, int qtd_estoque, int tipo_produto, string material, string tamanho);

    void setMaterial(string material);
    void setTamanho(string tamanho);
    string getMaterial();
    string getTamanho();
  
};

#endif 