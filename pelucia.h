#include <iostream>
#include <string>
#include "produto.h"
#ifndef PELUCIA_H
#define PELUCIA_H

using namespace std;

class Pelucia : public Produto{
  
  private:

    string m_material;
    char m_tamanho;

  public:

    Pelucia();
    ~Pelucia();

    Pelucia(string nome, string id_produto, float preco, string descricao, int qtd_estoque, int tipo_produto, string material, char tamanho);

    void setMaterial(string material);
    void setTamanho(char tamanho);
    string getMaterial();
    char getTamanho();
  
};

#endif 