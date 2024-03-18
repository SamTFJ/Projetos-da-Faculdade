#include <iostream>
#include <string>
#include "produto.h"
#ifndef ROUPA_H
#define ROUPA_H

using namespace std;

class Roupa : public Produto {

  private:
    
    string m_tamanho;
    string m_material, m_tipo, m_cor;
    
  public:

    Roupa();
    ~Roupa();

    Roupa(string nome, string id_produto, float preco, string descricao, int qtd_estoque, int tipo_produto, string tamanho, string material, string tipo, string cor);

    void setTamanho(string tamanho);
    void setMaterial(string material);
    void setTipo(string tipo);
    void setCor(string cor);
    string getTamanho();
    string getMaterial();
    string getTipo();
    string getCor();
};

#endif 