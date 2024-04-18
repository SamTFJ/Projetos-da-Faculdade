#include <iostream>
#include <string>
#include "produto.h"
#ifndef ACESSORIO_H
#define ACESSORIO_H

using namespace std;

class Acessorio : public Produto{

  private:

    string m_material, m_tipo;

  public:

    Acessorio();
    ~Acessorio();

    Acessorio(string nome, string id_produto, float preco, string descricao, int qtd_estoque, int tipo_produto, Data data_de_fabricacao, string material, string tipo);

    void setMaterial(string material);
    void setTipo(string tipo);
    string getMaterial();
    string getTipo();
    void atualizarItem() override;
};

#endif 
