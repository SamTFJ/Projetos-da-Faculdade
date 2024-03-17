#include <iostream>
#include "pelucia.h"

using namespace std;

  Pelucia::Pelucia() {}
  Pelucia::~Pelucia() {}

  Pelucia::Pelucia(string nome, string id_produto, float preco, string descricao, int qtd_estoque, int tipo_produto, string material, char tamanho) : Produto::Produto(nome, id_produto, preco, descricao, qtd_estoque, tipo_produto) {
    m_material = material;
    m_tamanho = tamanho;
  }

  void Pelucia::setMaterial(string material) {
  m_material = material;
}

  void Pelucia::setTamanho(char tamanho) {
  m_tamanho = tamanho;
}
  string Pelucia::getMaterial() {
    return m_material;
  }
  char Pelucia::getTamanho() {
    return m_tamanho;
  }