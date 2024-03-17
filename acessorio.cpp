#include <iostream>
#include "acessorio.h"

using namespace std;

  Acessorio::Acessorio() {}
  Acessorio::~Acessorio() {}

  Acessorio::Acessorio(string nome, string id_produto, float preco, string descricao, int qtd_estoque, int tipo_produto, string material, string tipo) : Produto::Produto(nome, id_produto, preco, descricao, qtd_estoque, tipo_produto) {
    m_material = material;
    m_tipo = tipo;
  }

  void Acessorio::setMaterial(string material) {
  m_material = material;
  }

  void Acessorio::setTipo(string tipo) {
  m_tipo = tipo;
  }
  string Acessorio::getMaterial() {
    return m_material;
  }
  string Acessorio::getTipo() {
    return m_tipo;
  }