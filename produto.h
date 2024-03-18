#include <iostream>
#include <string>
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
      
    public:

      Produto ();
      ~Produto ();

      Produto (string nome, string id_produto, float preco, string descricao, int qtd_estoque, int tipo_produto);
      
      void setNome(string nome);
      void setPreco(float preco);
      void setDescricao(string descricao);
      void setQtdEstoque(int qtd_estoque);
      void setTipoProduto(int tipo_produto);
      void setIDProduto(string id_produto);
      virtual void atualizarItem();

      string getNome();
      float getPreco();
      string getDescricao();
      int getQtdEstoque();
      int getTipoProduto();
      string getIDProduto();
    
};

#endif 