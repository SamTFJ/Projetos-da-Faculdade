#include <iostream>
#include "bordados.h"

using namespace std;

  Bordados::Bordados() {}
  Bordados::~Bordados() {}

  Bordados::Bordados(string nome, string id_produto, float preco, string descricao, int qtd_estoque, int tipo_produto, char tamanho) : Produto::Produto(nome, id_produto, preco, descricao, qtd_estoque, tipo_produto) {
    m_tamanho = tamanho;
  }

  void Bordados::setTamanho(char tamanho) {
  m_tamanho = tamanho;
  }

  char Bordados::getTamanho() {
    return m_tamanho;
  }