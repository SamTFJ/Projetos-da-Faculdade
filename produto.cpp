#include <iostream>
#include "produto.h"

using namespace std;

  Produto::Produto() {}
  Produto::~Produto() {}

  Produto::Produto(string nome, string id_produto, float preco, string descricao, int qtd_estoque, int tipo_produto) {
    m_nome = nome;
    m_id_produto = id_produto;
    m_preco = preco;
    m_descricao = descricao;
    m_qtd_estoque = qtd_estoque;
    m_tipo_produto = tipo_produto;
  }

  void Produto::setNome(string nome){
   m_nome = nome;
  }
  void Produto::setPreco(float preco){
   m_preco = preco;
  }
  void Produto::setDescricao(string desc){
   m_descricao = desc;
  }
  void Produto::setQtdEstoque(int qtd_estoque){
  m_qtd_estoque = qtd_estoque;
  }
  void Produto::setTipoProduto(int tipo_produto) {
  m_tipo_produto = tipo_produto;
    //Tipo para Roupa = 1
    //Tipo para Acessorio = 2
    //Tipo para Pelucia = 3
    //Tipo para Bordado = 4
  }


  string Produto::getNome() {
    return m_nome;
  }

  float Produto::getPreco() {
    return m_preco;
  }

  string Produto::getDescricao() {
    return m_descricao;
  }

  int Produto::getQtdEstoque() {
    return m_qtd_estoque;
  }

  int Produto::getTipoProduto() {
    return m_tipo_produto;
  }