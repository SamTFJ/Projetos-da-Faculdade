#include <iostream>
#include <limits>
#include <string>
#include <cstring>
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
        Data data_fabricacao[qtd_mercadorias] = {};
        string preco[qtd_mercadorias] = {};
        float preco_float[qtd_mercadorias] = {};
        string descricao[qtd_mercadorias] = {};
        string qtd_estoque[qtd_mercadorias] = {};
        int qtd_estoque_int[qtd_mercadorias] = {};
        string dia[qtd_mercadorias] = {};
        string mes[qtd_mercadorias] = {};
        string ano[qtd_mercadorias] = {};
        string xtamanho[qtd_mercadorias] = {}; 
        string xmaterial[qtd_mercadorias] = {};
        string xtipo[qtd_mercadorias] = {};
        string xcor[qtd_mercadorias] = {};
        
        Produto** mercadorias = new Produto*[qtd_mercadorias];

  public:
    ~CRUD() {

    }

    void AbrirArquivo() {
      string linha;
      ifstream meu_arquivo("gerenciamento.txt");

      if (meu_arquivo.is_open()) {
        int i = 0;
          while (getline(meu_arquivo, linha)) {
            char tipo = linha[0];
            if(tipo == 'R') {
              size_t pos = linha.find(',');
              size_t pos2 = linha.find(',', pos + 1);
              size_t pos3 = linha.find(',', pos2 + 1);
              size_t pos4 = linha.find(',', pos3 + 1);
              size_t pos5 = linha.find(',', pos4 + 1);
              size_t pos6 = linha.find(',', pos5 + 1);
              size_t pos7 = linha.find(',', pos6 + 1);
              size_t pos8 = linha.find(',', pos7 + 1);
              size_t pos9 = linha.find(',', pos8 + 1);
              size_t pos10 = linha.find(',', pos9 + 1);
              size_t pos11 = linha.find(',', pos10 + 1);

              ItemID[i] = linha.substr(0, pos);
              ItemName[i] = linha.substr(pos+1, pos2);
              preco[i] = linha.substr(pos2+1, pos3);
              descricao[i] = linha.substr(pos3+1, pos4);
              qtd_estoque[i] = linha.substr(pos4+1, pos5);
              dia[i] = linha.substr(pos5+1, pos6);
              mes[i] = linha.substr(pos6+1, pos7);
              ano[i] = linha.substr(pos7+1, pos8);
              xtamanho[i] = linha.substr(pos8+1, pos9);
              xmaterial[i] = linha.substr(pos9+1, pos10);
              xtipo[i] = linha.substr(pos10+1, pos11);
              xcor[i] = linha.substr(pos11+1, ',');

              data_fabricacao[i] = Data(dia[i], mes[i], ano[i]);
              qtd_estoque_int[i] = stoi(qtd_estoque[i]);
              preco_float[i] = stof(preco[i]);
              
              mercadorias[i] = new Roupa(ItemName[i], ItemID[i], preco_float[i], descricao[i], qtd_estoque_int[i], 1, data_fabricacao[i], xtamanho[i], xmaterial[i], xtipo[i], xcor[i]); 

            }
            
            else if(tipo == 'A') {
              size_t pos  = linha.find(',');
              size_t pos2 = linha.find(',', pos + 1);
              size_t pos3 = linha.find(',', pos2 + 1);
              size_t pos4 = linha.find(',', pos3 + 1);
              size_t pos5 = linha.find(',', pos4 + 1);
              size_t pos6 = linha.find(',', pos5 + 1);
              size_t pos7 = linha.find(',', pos6 + 1);
              size_t pos8 = linha.find(',', pos7 + 1);
              size_t pos9 = linha.find(',', pos8 + 1);

              ItemID[i] = linha.substr(0, pos);
              ItemName[i] = linha.substr(pos+1, pos2);
              preco[i] = linha.substr(pos2+1, pos3);
              descricao[i] = linha.substr(pos3+1, pos4);
              qtd_estoque[i] = linha.substr(pos4+1, pos5);
              dia[i] = linha.substr(pos5+1, pos6);
              mes[i] = linha.substr(pos6+1, pos7);
              ano[i] = linha.substr(pos7+1, pos8);
              xmaterial[i] = linha.substr(pos8+1, pos9);
              xtipo[i] = linha.substr(pos9+1, ',');

              data_fabricacao[i] = Data(dia[i], mes[i], ano[i]);
              qtd_estoque_int[i] = stoi(qtd_estoque[i]);
              preco_float[i] = stof(preco[i]);
              
              mercadorias[i] = new Acessorio(ItemName[i], ItemID[i], preco_float[i], descricao[i], qtd_estoque_int[i], 2, data_fabricacao[i], xmaterial[i], xtipo[i]); 
            }
            else if(tipo == 'P'){
              size_t pos = linha.find(',');
              size_t pos2 = linha.find(',', pos + 1);
              size_t pos3 = linha.find(',', pos2 + 1);
              size_t pos4 = linha.find(',', pos3 + 1);
              size_t pos5 = linha.find(',', pos4 + 1);
              size_t pos6 = linha.find(',', pos5 + 1);
              size_t pos7 = linha.find(',', pos6 + 1);
              size_t pos8 = linha.find(',', pos7 + 1);
              size_t pos9 = linha.find(',', pos8 + 1);

              ItemID[i] = linha.substr(0, pos);
              ItemName[i] = linha.substr(pos+1, pos2);
              preco[i] = linha.substr(pos2+1, pos3);
              descricao[i] = linha.substr(pos3+1, pos4);
              qtd_estoque[i] = linha.substr(pos4+1, pos5);
              dia[i] = linha.substr(pos5+1, pos6);
              mes[i] = linha.substr(pos6+1, pos7);
              ano[i] = linha.substr(pos7+1, pos8);
              xmaterial[i] = linha.substr(pos8+1, pos9);
              xtamanho[i] = linha.substr(pos9+1, ',');

              data_fabricacao[i] = Data(dia[i], mes[i], ano[i]);
              qtd_estoque_int[i] = stoi(qtd_estoque[i]);
              preco_float[i] = stof(preco[i]);
              
              mercadorias[i] = new Pelucia(ItemName[i], ItemID[i], preco_float[i], descricao[i], qtd_estoque_int[i], 3, data_fabricacao[i], xmaterial[i], xtamanho[i]);

            }
            else if (tipo == 'B'){
              size_t pos = linha.find(',');
              size_t pos2 = linha.find(',', pos + 1);
              size_t pos3 = linha.find(',', pos2 + 1);
              size_t pos4 = linha.find(',', pos3 + 1);
              size_t pos5 = linha.find(',', pos4 + 1);
              size_t pos6 = linha.find(',', pos5 + 1);
              size_t pos7 = linha.find(',', pos6 + 1);
              size_t pos8 = linha.find(',', pos7 + 1);

              ItemID[i] = linha.substr(0, pos);
              ItemName[i] = linha.substr(pos+1, pos2);
              preco[i] = linha.substr(pos2+1, pos3);
              descricao[i] = linha.substr(pos3+1, pos4);
              qtd_estoque[i] = linha.substr(pos4+1, pos5);
              dia[i] = linha.substr(pos5+1, pos6);
              mes[i] = linha.substr(pos6+1, pos7);
              ano[i] = linha.substr(pos7+1, pos8);
              xtamanho[i] = linha.substr(pos8+1, ',');

              data_fabricacao[i] = Data(dia[i], mes[i], ano[i]);
              qtd_estoque_int[i] = stoi(qtd_estoque[i]);
              preco_float[i] = stof(preco[i]);
              
              mercadorias[i] = new Bordados(ItemName[i], ItemID[i], preco_float[i], descricao[i], qtd_estoque_int[i], 4, data_fabricacao[i], xtamanho[i]);
            }
            i++;
          }
      }
      else {
          cout << "Incapaz de abrir o Arquivo" << endl;
      }
    }

    void SalvarArquivo() {
      ofstream meu_arquivo;
      meu_arquivo.open("gerenciamento.txt");

      for (int i = 0; i < qtd_mercadorias; i++) {
          if (ItemID[i][0] == '\0') {
              continue;
          }
          char tipo = ItemID[i][0];
          if(tipo == 'R') {
            Roupa* roupa = dynamic_cast<Roupa*>(mercadorias[i]);
              meu_arquivo << roupa->getIDProduto() + "," + roupa->getNome() + "," + to_string(roupa->getPreco()) + "," + roupa->getDescricao() + "," + to_string(roupa->getQtdEstoque()) + "," + roupa->getDataDeFabricacao2().getDia() + "," + roupa->getDataDeFabricacao2().getMes() + "," + roupa->getDataDeFabricacao2().getAno() + "," + roupa->getTamanho() + "," + roupa->getMaterial() + "," + roupa->getTipo() + "," + roupa->getCor() + "," << endl;

          }
            
          else if(tipo == 'A') {
            Acessorio* acessorio = dynamic_cast<Acessorio*>(mercadorias[i]);
            
            meu_arquivo << acessorio->getIDProduto() + "," + acessorio->getNome() + "," + to_string(acessorio->getPreco()) + "," + acessorio->getDescricao() + "," + to_string(acessorio->getQtdEstoque()) + "," + acessorio->getDataDeFabricacao2().getDia() + "," + acessorio->getDataDeFabricacao2().getMes() + "," + acessorio->getDataDeFabricacao2().getAno() + "," + acessorio->getMaterial() + "," + acessorio->getTipo() + "," << endl;
          }
          else if(tipo == 'P') {
            Pelucia* pelucia = dynamic_cast<Pelucia*>(mercadorias[i]);

              meu_arquivo << pelucia->getIDProduto() + "," + pelucia->getNome() + "," + to_string(pelucia->getPreco()) + "," + pelucia->getDescricao() + "," + to_string(pelucia->getQtdEstoque()) + "," + pelucia->getDataDeFabricacao2().getDia() + "," + pelucia->getDataDeFabricacao2().getMes() + "," + pelucia->getDataDeFabricacao2().getAno() + "," + pelucia->getMaterial() + "," + pelucia->getTamanho() + "," << endl; 
          }
          else if(tipo == 'B') {
            Bordados* bordados = dynamic_cast<Bordados*>(mercadorias[i]);

            meu_arquivo << bordados->getIDProduto() + "," + bordados->getNome() + "," + to_string(bordados->getPreco()) + "," + bordados->getDescricao() + "," + to_string(bordados->getQtdEstoque()) + "," + bordados->getDataDeFabricacao2().getDia() + "," + bordados->getDataDeFabricacao2().getMes() + "," + bordados->getDataDeFabricacao2().getAno() + "," + bordados->getTamanho() + "," << endl;
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