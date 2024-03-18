#include <iostream>
#include "roupa.h"

using namespace std;

  Roupa::Roupa() {}
  Roupa::~Roupa() {}

  Roupa::Roupa(string nome, string id_produto, float preco, string descricao, int qtd_estoque, int tipo_produto, string tamanho, string material, string tipo, string cor) : Produto::Produto(nome, id_produto, preco, descricao, qtd_estoque, tipo_produto) {
    m_tamanho = tamanho;
    m_material = material;
    m_tipo = tipo;
    m_cor = cor;
  }

  void Roupa::setTamanho(string tamanho) {
    m_tamanho = tamanho;
  }

  void Roupa::setMaterial(string material) {
    m_material = material;
  }

  void Roupa::setTipo(string tipo) {
    m_tipo = tipo;
  }

  void Roupa::setCor(string cor) {
    m_cor = cor;
  }

  string Roupa::getTamanho() {
    return m_tamanho;
  }

  string Roupa::getMaterial() {
    return m_material;
  }

  string Roupa::getTipo() {
    return m_tipo;
  }

  string Roupa::getCor() {
    return m_cor;
  }