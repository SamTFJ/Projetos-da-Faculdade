#include <iostream>
#include "pelucia.h"

using namespace std;

  Pelucia::Pelucia() {}
  Pelucia::~Pelucia() {}

  Pelucia::Pelucia(string nome, string id_produto, float preco, string descricao, int qtd_estoque, int tipo_produto, string material, string tamanho) : Produto::Produto(nome, id_produto, preco, descricao, qtd_estoque, tipo_produto) {
    m_material = material;
    m_tamanho = tamanho;
  }

  void Pelucia::setMaterial(string material) {
  m_material = material;
}

  void Pelucia::setTamanho(string tamanho) {
  m_tamanho = tamanho;
}
  string Pelucia::getMaterial() {
    return m_material;
  }
  string Pelucia::getTamanho() {
    return m_tamanho;
  }


void Pelucia::atualizarItem() {
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
    cout << "| --> Cancelar = 8                |" << endl;
    cout << "|=================================|" << endl;
    cout << "--> Opção desejada: ";
    int opcao = 0;
    cin >> opcao;

    string xnome, xid, xdescricao, xmaterial;
    string xtamanho;
    int xquant;
    float xpreco;
    switch (opcao){
    case 1:
      cout << "--> Insira o nome atualizado: ";
      getline(cin, xnome);
      Pelucia::setNome(xnome);
      condicao = 0;
      break;

    case 2:
      cin.ignore();
      cout << "--> Insira o ID atualizado: ";
      getline(cin, xid);
      Pelucia::setIDProduto(xid);
      condicao = 0;
      break;

    case 3:
      cout << "--> Insira o preço atualizado: ";
      cin >> xpreco;
      cin.ignore();
      Pelucia::setPreco(xpreco);
      condicao = 0;
      break;

    case 4:
      cin.ignore();
      cout << "--> Insira a descrição atualizada: ";
      getline(cin, xdescricao);
      Pelucia::setDescricao(xdescricao);
      condicao = 0;
      break;

    case 5:
      cout << "--> Insira a quantidade no estoque atualizada: ";
      cin >> xquant;
      cin.ignore();
      Pelucia::setQtdEstoque(xquant);
      condicao = 0;
      break;

    case 6:
      cin.ignore();
      cout << "--> Insira o tamanho atualizado: ";
      getline(cin,xtamanho);
      Pelucia::setTamanho(xtamanho);
      condicao = 0;
      break;

    case 7:
      cin.ignore();
      cout << "--> Insira o material atualizado: ";
      getline(cin, xmaterial);
      Pelucia::setMaterial(xmaterial);
      condicao = 0;
      break;

    case 8:
      cout << "Operação cancelada" << endl;
      condicao = 0;
      break;

    default:
      cout << "Opção inválida, tente novamente!" << endl;
      break;
    }
  }while(condicao);
}