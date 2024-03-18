#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <ctype.h>
#include "produto.h"
#include "acessorio.h"
#include "roupa.h"
#include "bordados.h"
#include "pelucia.h"

using namespace std;

const int qtd_mercadorias = 100;

class CRUD {

  private:
        string ItemName[qtd_mercadorias] = {};
        string ItemID[qtd_mercadorias] = {};
        Produto** mercadorias = new Produto*[qtd_mercadorias];

  public:
    ~CRUD() {

    }

    void AbrirArquivo(){
      string linha;
      ifstream meu_arquivo("gerenciamento.txt");
      if (meu_arquivo.is_open()) {
          int i = 0;
          linha.length();
          while (getline(meu_arquivo, linha)) {
              ItemID[i] = linha.substr(0, 4);
              ItemName[i] = linha.substr(4, 1 - 4);
              i++;
          }
      }
      else {
          cout << "Incapaz de abrir o Arquivo" << endl;
      }
    }

    void SaveToFile(){
      ofstream meu_arquivo;
      meu_arquivo.open("gerenciamento.txt");

      for (int i = 0; i < qtd_mercadorias; i++) {
          if (ItemID[i] == "\0") {
              break;
          }

          else {
              meu_arquivo << ItemID[i] + "," + ItemName[i] << endl;
          }
      }
    }

    void InserirItem() {
      string nome;
      string id_item;
      float preco;
      string descricao;
      int qtd_estoque;
      int tipo_produto;
      string dia, mes, ano;
      Data data_fabricacao;


      //Pegando os Inputs para o objeto Produto
      cout << "|=================================|" << endl;
      cout << "|           Tipos de ID           |" << endl;
      cout << "|=================================|" << endl;
      cout << "| --> Roupa = RP(Número)          |" << endl;
      cout << "| --> Acessório = AC(Número)      |" << endl;
      cout << "| --> Pelúcia = PL(Número)        |" << endl;
      cout << "| --> Bordado = BD(Número)        |" << endl;
      cout << "|=================================|" << endl;
      cout << "--> ID do Item: ";
      cin.ignore();
      getline(cin, id_item);
      cout << "--> Nome do Item: ";
      getline(cin, nome);
      int control = 1;
        do {
          cout << "|=================================|" << endl;
          cout << "|        Tipos de Produtos        |" << endl;
          cout << "|=================================|" << endl;
          cout << "| --> Roupa = 1                   |" << endl;
          cout << "| --> Acessório = 2               |" << endl;
          cout << "| --> Pelúcia = 3                 |" << endl;
          cout << "| --> Bordado = 4                 |" << endl;
          cout << "|=================================|" << endl;
          cout << "--> Escolha o tipo de produto desejado: ";

          if (!(cin >> tipo_produto) || cin.peek() != '\n') {
              cout << "Tipo inválido, tente novamente!" << endl;
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
            } 

          else {
            switch(tipo_produto) {
              case 1:
              case 2:
              case 3:
              case 4:
                control = 0;
                break;
              default:
                cout << "Tipo inválido, tente novamente!" << endl;
                break;
                }
            }
        } while (control != 0);


      cout << "--> Insira o valor a ser cobrado: ";
      cin >> preco;
      cin.ignore();
      cout << "--> Insira a descrição do produto: ";
      getline(cin, descricao);
      cout << "--> Diga quantos produtos do mesmo tipo serão adicionados: ";
      cin >> qtd_estoque;

      cin.ignore();

      cout << "--> Informe a data de fabricação do produto --> Dia: ";
      getline(cin, dia);
      cout << "--> Informe a data de fabricação do produto --> Mes: ";
      getline(cin, mes);
      cout << "--> Informe a data de fabricação do produto --> Ano: ";
      getline(cin, ano);
      data_fabricacao.setDia(dia);
      data_fabricacao.setMes(mes);
      data_fabricacao.setAno(ano);

        for (int i = 0; i < qtd_mercadorias; i++) {
            if (ItemID[i].empty()) {
              ItemID[i] = id_item;
              ItemName[i] = nome;

            //Alterado para fazer um casting implicito e, ao invés de criar um objeto antes de testar o tipo, o objeto é criado depois
              string xtamanho;
              string xmaterial, xtipo, xcor;

              if (tipo_produto == 1) {
                  cout << "--> Para concluir a inserção informe atributos especificos do tipo Roupa" << endl;
                  cout << "--> Informe o tamanho: ";
                  getline(cin, xtamanho);
                  cout << "--> Informe o material: ";
                  getline(cin, xmaterial);
                  cout << "--> Informe o tipo: ";
                  getline(cin, xtipo);
                  cout << "--> Informe a cor: ";
                  getline(cin, xcor);

                  mercadorias[i] = new Roupa(nome, id_item, preco, descricao, qtd_estoque, tipo_produto, data_fabricacao, xtamanho, xmaterial, xtipo, xcor);

              }

              else if (tipo_produto == 2) {
                  cout << "--> Para concluir a inserção informe atributos especificos do tipo Acessorio" << endl;
                  cout << "--> Informe o material: ";
                  getline(cin, xmaterial);
                  cout << "--> Informe o tipo: ";
                  getline(cin, xtipo);

                  mercadorias[i] = new Acessorio(nome, id_item, preco, descricao, qtd_estoque, tipo_produto, data_fabricacao, xmaterial, xtipo);

              }

              else if (tipo_produto == 3) {
                  cout << "--> Para concluir a inserção informe atributos especificos do tipo Pelucia" << endl;
                  cout << "--> Informe o material: ";
                  getline(cin, xmaterial);
                  cout << "--> Informe o tamanho: ";
                  getline(cin, xtamanho);

                  mercadorias[i] = new Pelucia(nome, id_item, preco, descricao, qtd_estoque, tipo_produto, data_fabricacao, xmaterial, xtamanho);

              }

              else if (tipo_produto == 4) {
                  cout << "--> Para concluir a inserção informe atributos especificos do tipo Bordados" << endl;
                  cout << "--> Informe o tamanho: ";
                  getline(cin, xtamanho);
                  mercadorias[i] = new Bordados(nome, id_item, preco, descricao, qtd_estoque, tipo_produto, data_fabricacao, xtamanho);
               }
              break;
            }
    }
    }

    void Estoque() {
      //system("CLS");
      cout << "Estoque" << endl;
      cout << "=================================================================================================================" << endl;

      int counter = 0;
      cout << " No.  |   ID   |           NOME           |       PREÇO        |      QTD_ESTOQUE       |       FABRICAÇÃO" << endl;
      cout << "-----------------------------------------------------------------------------------------------------------------\n";
      for (int i = 0; i < qtd_mercadorias; i++) {
          if (!ItemID[i].empty()) {
              counter++;
              cout << " " << counter << "        " << mercadorias[i]->getIDProduto() << "            " << mercadorias[i]->getNome() << "                R$ " << mercadorias[i]->getPreco() << "                 " << mercadorias[i]->getQtdEstoque() << " und. " << "                 " << mercadorias[i]->getDataDeFabricacao() << endl;
          }
      }

      if (counter == 0) {
          cout << "Estoque Vazio!" << endl;
      }

      cout << "=================================================================================================================" << endl;
    }

    void ProcurarItem(string pesquisa, int escolha) {
        //Procura por ID
      if(escolha == 1) {
          //system("CLS");
          cout << "Produtos Correspondentes à Pesquisa" << endl;
          cout << "===========================================================" << endl;
          int counter = 0;

          for (int i = 0; i < qtd_mercadorias; i++) {

              if (mercadorias[i]->getIDProduto() == pesquisa) {
                  counter++;
                  cout << "   " << counter << "    " << mercadorias[i]->getIDProduto() << "             " << mercadorias[i]->getNome() << "            R$ " << mercadorias[i]->getPreco() << endl;
                  cout << "===========================================================" << endl;
                  break;
              }

              if (counter == 0) {
                  cout << "ID não encontrado!" << endl;
              }
          }
      }

      //Procura por Nome
      else if(escolha == 2) {
          //system("CLS");
          cout << "Produtos Correspondentes à Pesquisa" << endl;
          cout << "===========================================================" << endl;
          int counter = 0;

          for (int i = 0; i < qtd_mercadorias; i++) {   
              //Modificação para letras minúsculas
              string item_name_comparation = mercadorias[i]->getNome();
              for (char& ItemName_c : item_name_comparation) {
                  ItemName_c = tolower(ItemName_c);
              }

              for (char& pesquisa_c : pesquisa) {
                  pesquisa_c = tolower(pesquisa_c);
              }

              //Comparação
              auto it = find(item_name_comparation.begin(), item_name_comparation.end(), pesquisa[0]);
              if (it != item_name_comparation.end()) {
                  counter++;
                  cout << "   " << counter << "    " << mercadorias[i]->getIDProduto() << "             " << mercadorias[i]->getNome() << "          R$ "<< mercadorias[i]->getPreco() << endl;
                  cout << "===========================================================" << endl;
                  break;
              }

              if (counter == 0) {
                  cout << "Nenhum produto encontrado com esse nome!" << endl;
              }
            }
        }
    }

    void AtualizarItem(string pesquisa, int escolha) {
      //Procura por ID
      if(escolha == 1) {
          string new_name;
          int counter = 0;

          for (int i = 0; i < qtd_mercadorias; i++) {
              if (mercadorias[i]->getIDProduto() == pesquisa) {
                  counter++;
                  mercadorias[i]->atualizarItem();
                  ItemName[i] = mercadorias[i]->getNome();
                  ItemID[i] = mercadorias[i]->getIDProduto();
                  cout << "Atualização completa!" << endl;
                  break;
              }
          }

          if (counter == 0) {
              cout << "ID não encontrado!" << endl;
          }
      }

      //Procura por Nome
      else if(escolha == 2) {
          string new_name;
          int counter = 0;

        for (int i = 0; i < qtd_mercadorias; i++) {   
              //Comparação
              string item_name_comparation = mercadorias[i]->getNome();
              auto it = find(item_name_comparation.begin(), item_name_comparation.end(), pesquisa[0]);

            if (it != item_name_comparation.end()) {
                counter++;
                mercadorias[i]->atualizarItem();
                ItemName[i] = mercadorias[i]->getNome();
                ItemID[i] = mercadorias[i]->getIDProduto();
                cout << "Atualização completa!" << endl;
                break;
            }
        }

        if (counter == 0) {
                cout << "Nenhum produto encontrado!" << endl;
        }
      }
  }

    void DeletarItem(string pesquisa, int escolha) {
        //Procura por ID
      if(escolha == 1) {
          int counter = 0;

          for (int i = 0; i < qtd_mercadorias; i++) {

              if (mercadorias[i]->getIDProduto() == pesquisa) {
                  counter++;

                  ItemName[i] = "";
                  ItemID[i] = "";
                  mercadorias[i] = nullptr;

                  cout << "Produto Deletado Completamente!\n\n";
                  break;
              }

              if (counter == 0) {
                  cout << "ID não encontrado!" << endl;
              }
          }
      }

      //Procura por Nome
      else if(escolha == 2) {
          int counter = 0;

          for (int i = 0; i < qtd_mercadorias; i++)
          {   
              //Comparação
              string item_name_comparation = mercadorias[i]->getNome();
              auto it = find(item_name_comparation.begin(), item_name_comparation.end(), pesquisa[0]);

              if (it != item_name_comparation.end()) {
                  counter++;

                  ItemName[i] = "";
                  ItemID[i] = "";
                  mercadorias[i] = nullptr;

                  cout << "Produto Deletado Completamente!\n\n";
                  break;
              }

              if (counter == 0)
              {
                  cout << "Nenhum produto encontrado!" << endl;
              }
          }
      }
    }

    void Relatorio() {
      float valor_estoque = 0;
      int qtd_total_produtos = 0;

        for(int i = 0; i < qtd_mercadorias; i++) {
            if(!ItemID[i].empty()) {
            valor_estoque += (mercadorias[i]->getPreco() * mercadorias[i]->getQtdEstoque());
            }
        }

        for(int i = 0; i < qtd_mercadorias; i++) {
            if(!ItemID[i].empty()) {
            qtd_total_produtos += mercadorias[i]->getQtdEstoque();
            }
        }
      cout << "========================================================" << endl;
      cout << "               --> RELATÓRIO GERAL <--                  " << endl;
      cout << "========================================================" << endl;
      cout << "     VALOR DO ESTOQUE        |    QTD. TOTAL DO ESTOQUE " << endl;
      cout << "--------------------------------------------------------\n";
      cout << "            R$" << valor_estoque << "                       " << qtd_total_produtos << endl;
      cout << "========================================================" << endl;
    }
};