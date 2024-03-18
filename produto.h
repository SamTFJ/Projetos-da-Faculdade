#include <iostream>
#include <string>
#include "data.h"
#ifndef PRODUTO_H
#define PRODUTO_H

using namespace std;

class Produto {
    protected:
      string m_nome;
      string m_id_produto;
      float m_preco;
      string m_descricao;
      int m_qtd_estoque;
      int m_tipo_produto; //Recebe qual tipo de porduto a ser inserido
      Data m_data_de_fabricacao = Data();

    public:

      Produto ();
      ~Produto ();

      Produto (string nome, string id_produto, float preco, string descricao, int qtd_estoque, int tipo_produto, Data data_de_fabricacao);
      
      void setNome(string nome);
      void setPreco(float preco);
      void setDescricao(string descricao);
      void setQtdEstoque(int qtd_estoque);
      void setTipoProduto(int tipo_produto);
      void setIDProduto(string id_produto);
      void setDataDeFabricacao(string dia, string mes, string ano);

      virtual void atualizarItem();

      string getNome();
      float getPreco();
      string getDescricao();
      int getQtdEstoque();
      int getTipoProduto();
      string getIDProduto();
      string getDataDeFabricacao();
    
};

#endif 