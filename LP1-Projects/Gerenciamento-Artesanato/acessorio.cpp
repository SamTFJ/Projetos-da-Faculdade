#include <iostream>
#include "acessorio.h"

using namespace std;

  Acessorio::Acessorio() {}
  Acessorio::~Acessorio() {}

  Acessorio::Acessorio(string nome, string id_produto, float preco, string descricao, int qtd_estoque, int tipo_produto, Data data_de_fabricacao,  string material, string tipo) : Produto::Produto(nome, id_produto, preco, descricao, qtd_estoque, tipo_produto, data_de_fabricacao) {
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

void Acessorio::atualizarItem(){
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
    cout << "| --> Material = 6                |" << endl;
    cout << "| --> Tipo = 7                    |" << endl;
    cout << "| --> Data de Fabricação = 8      |" << endl;
    cout << "| --> Cancelar = 9                |" << endl;
    cout << "|=================================|" << endl;
    cout << "--> Opção desejada: ";
    int opcao = 0;
    cin >> opcao;

    string xnome, xid, xdescricao, xmaterial, xtipo;
    int xquant;
    float xpreco;
    string xdia, xmes, xano;

    switch (opcao) {
    case 1:
      cin.ignore();
      cout << "--> Insira o nome atualizado: ";
      getline(cin, xnome);
      Acessorio::setNome(xnome);
      condicao = 0;
      break;

    case 2:
      cin.ignore();
      cout << "--> Insira o ID atualizado: ";
      getline(cin, xid);
      Acessorio::setIDProduto(xid);
      condicao = 0;
      break;

    case 3:
      cout << "--> Insira o preço atualizado: ";
      cin >> xpreco;
      Acessorio::setPreco(xpreco);
      condicao = 0;
      break;

    case 4:
      cin.ignore();
      cout << "--> Insira a descrição atualizada: ";
      getline(cin, xdescricao);
      Acessorio::setDescricao(xdescricao);
      condicao = 0;
      break;

    case 5:
      cout << "--> Insira a quantidade no estoque atualizada: ";
      cin >> xquant;
      Acessorio::setQtdEstoque(xquant);
      condicao = 0;
      break;

    case 6:
      cout << "--> Insira o tipo atualizado: ";
      cin >> xtipo;
      Acessorio::setTipo(xtipo);
      condicao = 0;
      break;

    case 7:
      cin.ignore();
      cout << "--> Insira o material atualizado: ";
      getline(cin, xmaterial);
      Acessorio::setMaterial(xmaterial);
      condicao = 0;
      break;

    case 8:
      cin.ignore();
      cout << "--> Insira a data de fabricação atualizada: ";
      getline(cin, xdia);
      getline(cin, xmes);
      getline(cin, xano);
      Acessorio::setDataDeFabricacao(xdia, xmes, xano);
      condicao = 0;
      break;

    case 9:
      cout << "Operação cancelada" << endl;
      condicao = 0;
      break;

    default:
      cout << "Opção inválida, tente novamente!" << endl;
      break;
    }
  } while(condicao);
}
