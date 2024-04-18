#include <iostream>
#include "roupa.h"

using namespace std;

  Roupa::Roupa() {}
  Roupa::~Roupa() {}

  Roupa::Roupa(string nome, string id_produto, float preco, string descricao, int qtd_estoque, int tipo_produto, Data data_de_fabricacao, string tamanho, string material, string tipo, string cor) : Produto::Produto(nome, id_produto, preco, descricao, qtd_estoque, tipo_produto, data_de_fabricacao) {
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

  void Roupa::atualizarItem() {
  int condicao = 1;
  do{
    cout << "|=================================|" << endl;
    cout << "|     O que deseja atualizar?     |" << endl;
    cout << "|=================================|" << endl;
    cout << "| --> Nome = 1                    |" << endl;
    cout << "| --> ID = 2                      |" << endl;
    cout << "| --> Preço = 3                   |" << endl;
    cout << "| --> Descrição = 4               |" << endl;
    cout << "| --> quantidade no estoque = 5   |" << endl;
    cout << "| --> Tamanho = 6                 |" << endl;
    cout << "| --> Material = 7                |" << endl;
    cout << "| --> Tipo = 8                    |" << endl;
    cout << "| --> Cor = 9                     |" << endl;
    cout << "| --> Data de Fabricação = 10     |" << endl;
    cout << "| --> Cancelar = 11               |" << endl;
    cout << "|=================================|" << endl;
    cout << "--> Opção desejada: ";
    int opcao = 0;
    cin >> opcao;

    string xnome, xid, xdescricao, xmaterial, xtipo, xcor;
    string xtamanho;
    int xquant;
    float xpreco;
    string xdia, xmes, xano;

    switch (opcao){
    case 1:
      cin.ignore();
      cout << "--> Insira o nome atualizado: ";
      getline(cin, xnome);
      Roupa::setNome(xnome);
      condicao = 0;
      break;

    case 2:
      cin.ignore();
      cout << "--> Insira o ID atualizado: ";
      getline(cin, xid);
      Roupa::setIDProduto(xid);
      condicao = 0;
      break;

    case 3:
      cout << "--> Insira o preço atualizado: ";
      cin >> xpreco;
      Roupa::setPreco(xpreco);
      condicao = 0;
      break;

    case 4:
      cin.ignore();
      cout << "--> Insira a descrição atualizada: ";
      getline(cin, xdescricao);
      Roupa::setDescricao(xdescricao);
      condicao = 0;
      break;

    case 5:
      cout << "--> Insira a quantidade no estoque atualizada: ";
      cin >> xquant;
      Roupa::setQtdEstoque(xquant);
      condicao = 0;
      break;

    case 6:
      cin.ignore();
      cout << "--> Insira o tamanho atualizado: ";
      getline(cin, xtamanho);
      Roupa::setTamanho(xtamanho);
      condicao = 0;
      break;

    case 7:
      cin.ignore();
      cout << "--> Insira o material atualizado: ";
      getline(cin, xmaterial);
      Roupa::setMaterial(xmaterial);
      condicao = 0;
      break;

    case 8:
      cin.ignore();
      cout << "--> Insira o tipo atualizado: ";
      getline(cin, xtipo);
      Roupa::setTipo(xtipo);
      condicao = 0;
      break;

    case 9:
      cin.ignore();
      cout << "--> Insira a cor atualizada: ";
      getline(cin, xcor);
      Roupa::setCor(xcor);
      condicao = 0;
      break;

    case 10:
      cin.ignore();
      cout << "--> Insira a data de fabricação atualizada: ";
      getline(cin, xdia);
      getline(cin, xmes);
      getline(cin, xano);
      Roupa::setDataDeFabricacao(xdia, xmes, xano);
      condicao = 0;
      break;

    case 11:
      cout << "Operação cancelada" << endl;
      condicao = 0;
      break;

    default:
      cout << "Opção inválida, tente novamente!" << endl;
      break;
    }
  } while(condicao);
}
