#include <iostream>
#include "bordados.h"

using namespace std;

  Bordados::Bordados() {}
  Bordados::~Bordados() {}

  Bordados::Bordados(string nome, string id_produto, float preco, string descricao, int qtd_estoque, int tipo_produto, Data data_de_fabricacao, string tamanho) : Produto::Produto(nome, id_produto, preco, descricao, qtd_estoque, tipo_produto, data_de_fabricacao) {
    m_tamanho = tamanho;
  }

  void Bordados::setTamanho(string tamanho) {
  m_tamanho = tamanho;
  }

  string Bordados::getTamanho() {
    return m_tamanho;
  }

  void Bordados::atualizarItem() {
  int condicao = 1;
  do{
    cout << "|=================================|" << endl;
    cout << "|     O que deseja atualizar?     |" << endl;
    cout << "|=================================|" << endl;
    cout << "| --> Nome = 1                    |" << endl;
    cout << "| --> ID = 2                      |" << endl;
    cout << "| --> Preço = 3                   |" << endl;
    cout << "| --> Descrição = 4               |" << endl;
    cout << "| --> Quantidade no estoque = 5   |" << endl;
    cout << "| --> Tamanho = 6                 |" << endl;
    cout << "| --> Data de Fabricação = 7      |" << endl;
    cout << "| --> Cancelar = 8                |" << endl;
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
        Bordados::setNome(xnome);
        condicao = 0;
        break;

      case 2:
        cin.ignore();
        cout << "--> Insira o ID atualizado: ";
        getline(cin, xid);
        Bordados::setIDProduto(xid);
        condicao = 0;
        break;

      case 3:
        cout << "--> Insira o preço atualizado: ";
        cin >> xpreco;
        Bordados::setPreco(xpreco);
        condicao = 0;
        break;

      case 4:
        cin.ignore();
        cout << "--> Insira a descrição atualizada: ";
        getline(cin, xdescricao);
        Bordados::setDescricao(xdescricao);
        condicao = 0;
        break;

      case 5:
        cout << "--> Insira a quantidade no estoque atualizada: ";
        cin >> xquant;
        Bordados::setQtdEstoque(xquant);
        condicao = 0;
        break;

      case 6:
        cin.ignore();
        cout << "--> Insira o tamanho atualizado: ";
        getline(cin, xtamanho);
        Bordados::setTamanho(xtamanho);
        condicao = 0;
        break;

      case 7:
        cin.ignore();
        cout << "--> Insira a data de fabricação atualizada: ";
        getline(cin, xdia);
        getline(cin, xmes);
        getline(cin, xano);
        Bordados::setDataDeFabricacao(xdia, xmes, xano);
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
  } while(condicao != 0);
}