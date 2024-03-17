#include <iostream>
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
    ~CRUD(){}

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

void InserirItem(){
      string nome;
      string id_item;
      float preco;
      string descricao;
      int qtd_estoque;
      int tipo_produto;

      //Pegando os Inputs para o objeto Produto
      cout << "--> ID do Item: ";
      cin.ignore();
      getline(std::cin, id_item);
      cout << "--> Nome do Item: ";
      getline(std::cin, nome);
      do {

        cout << "|=================================|" << endl;
        cout << "|        Tipos de Produtos        |" << endl;
        cout << "|=================================|" << endl;
        cout << "| --> Roupa = 1                   |" << endl;
        cout << "| --> Acessório = 1               |" << endl;
        cout << "| --> Pelúcia = 1                 |" << endl;
        cout << "| --> Bordado = 1                 |" << endl;
        cout << "|=================================|" << endl;
        cout << "--> Escolha o tipo de produto desejado: ";
        cin >> tipo_produto;

        if (tipo_produto < 1 || tipo_produto > 4) {
                cout << "Tipo inválido, tente novamente!" << endl;
            }

      } while (tipo_produto < 1 || tipo_produto > 4);

      cout << "--> Insira o valor a ser cobrado: ";
      cin >> preco;
      cout << "--> Insira a descrição do produto: ";
      cin.ignore();
      getline(cin, descricao);
      cout << "--> Diga quantos produtos do mesmo tipo serão adicionados: ";
      cin >> qtd_estoque;

        for (int i = 0; i < qtd_mercadorias; i++) {
            if (ItemID[i].empty()) {
            ItemID[i] = id_item;
            ItemName[i] = nome;

            //Alterado para fazer um casting implicito e, ao invés de criar um objeto antes de testar o tipo, o objeto é criado depois
            char xtamanho;
            string xmaterial, xtipo, xcor;

            if (tipo_produto == 1) {
                cout << "Para concluir a inserção informe atributos especificos do tipo Roupa" << endl;
                cin.ignore();
                cout << "Informe o tamanho: " << endl;
                cin >> xtamanho;
                cin.ignore();
                cout << "Informe o material: " << endl;
                getline(cin, xmaterial);
                cout << "Informe o tipo: " << endl;
                getline(cin, xtipo);
                cout << "Informe a cor: " << endl;
                getline(cin, xcor);

                mercadorias[i] = new Roupa(nome, id_item, preco, descricao, qtd_estoque, tipo_produto, xtamanho, xmaterial, xtipo, xcor);
            
            }
            
            else if (tipo_produto == 2){
                cout << "Para concluir a inserção informe atributos especificos do tipo Acessorio" << endl;
                cin.ignore();
                cout << "Informe o material: " << endl;
                getline(cin, xmaterial);
                cout << "Informe o tipo: " << endl;
                getline(cin, xtipo);

                mercadorias[i] = new Acessorio(nome, id_item, preco, descricao, qtd_estoque, tipo_produto, xmaterial, xtipo);

            }
            
            else if (tipo_produto == 3){
                cout << "Para concluir a inserção informe atributos especificos do tipo Pelucia" << endl;
                cin.ignore();
                cout << "Informe o material: " << endl;
                getline(cin, xmaterial);
                cout << "Informe o tamanho: " << endl;
                cin >> xtamanho;
                cin.ignore();

                mercadorias[i] = new Pelucia(nome, id_item, preco, descricao, qtd_estoque, tipo_produto, xmaterial, xtamanho);
            
            }
            
            else if (tipo_produto == 4){
                cout << "Para concluir a inserção informe atributos especificos do tipo Bordados" << endl;
                cout << "Informe o tamanho: " << endl;
                cin >> xtamanho;
                cin.ignore();
                mercadorias[i] = new Bordados(nome, id_item, preco, descricao, qtd_estoque, tipo_produto, xtamanho);
             }
        }
        break;
    }
    }

    void Estoque(){
      //system("CLS");
      cout << "Estoque" << endl;
      cout << "==========================================" << endl;

      int counter = 0;
      cout << " No.  |   ID   |         NOME        " << endl << "------------------------------------------\n";
      for (int i = 0; i < qtd_mercadorias; i++) {
          if (ItemID[i] != "\0") {
              counter++;
              cout << " " << counter << "        " << ItemID[i] << "            " << ItemName[i] << endl;
          }
      }

      if (counter == 0) {
          cout << "Estoque Vazio!" << endl;
      }

      cout << "=========================================" << endl;
    }

    void ProcurarItem(string pesquisa, int escolha){
        //Procura por ID
      if(escolha == 1) {
          //system("CLS");
          cout << "Produtos Correspondentes à Pesquisa" << endl;
          cout << "==========================================" << endl;
          int counter = 0;

          for (int i = 0; i < qtd_mercadorias; i++) {

              if (ItemID[i] == pesquisa) {
                  counter++;
                  cout << "   " << counter << "    " << ItemID[i] << "             " << ItemName[i] << endl;
                  cout << "==========================================" << endl;
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
          cout << "==========================================" << endl;
          int counter = 0;

          for (int i = 0; i < qtd_mercadorias; i++) {   
              //Modificação para letras minúsculas
              string item_name_comparation = ItemName[i];
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
                  cout << "   " << counter << "    " << ItemID[i] << "             " << item_name_comparation << endl;
                  cout << "==========================================" << endl;
                  break;
              }

              if (counter == 0) {
                  cout << "Nenhum produto encontrado!" << endl;
              }
            }
        }
    }

    void AtualizarItem(string pesquisa, int escolha){
          //Procura por ID
      if(escolha == 1) {
          string new_name;
          int counter = 0;

          for (int i = 0; i < qtd_mercadorias; i++) {
              if (ItemID[i] == pesquisa) {
                  counter++;
                  cout << "Novo Nome do Item: ";
                  getline(cin, new_name);

                  ItemName[i] = new_name;

                  cout << "\n" << "Atualização Completa!\n\n";
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
              string item_name_comparation = ItemName[i];
              auto it = find(item_name_comparation.begin(), item_name_comparation.end(), pesquisa[0]);

              if (it != item_name_comparation.end()) {
                  counter++;
                  cout << "Novo Nome do Item: ";
                  getline(cin, new_name);

                  ItemName[i] = new_name;

                  cout << "\n"
                      << "Atualização Completa!\n\n";
                  break;
              }

              if (counter == 0) {
                  cout << "Nenhum produto encontrado!" << endl;
              }
          }
      }
    }

    void DeletarItem(string pesquisa, int escolha){
        //Procura por ID
      if(escolha == 1) {
          int counter = 0;

          for (int i = 0; i < qtd_mercadorias; i++) {
                  
              if (ItemID[i] == pesquisa) {
                  counter++;

                  ItemName[i] = "";
                  ItemID[i] = "";

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
              string item_name_comparation = ItemName[i];
              auto it = find(item_name_comparation.begin(), item_name_comparation.end(), pesquisa[0]);

              if (it != item_name_comparation.end()) {
                  counter++;

                  ItemName[i] = "";
                  ItemID[i] = "";

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
};