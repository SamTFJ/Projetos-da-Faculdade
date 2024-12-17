#include <iostream>
#include "produto.h"
#include "acessorio.h"
#include "roupa.h"
#include "bordados.h"
#include "pelucia.h"
#include "gerenciamento.h"

using namespace std;

int main() {
  CRUD* CRUD = new class CRUD();

  int escolha = 0;
  string procurar_ID;
  string procurar_Nome;
  //system("CLS");
  CRUD->AbrirArquivo();

  do
  {
    cout << "|=================================|" << endl;
    cout << "|             MENU                |" << endl;
    cout << "|=================================|" << endl;
    cout << "|     1 - Inserir Item novo       |" << endl;
    cout << "|     2 - Atualizar Item          |" << endl;  //Por Nome e ID
    cout << "|     3 - Deletar Item            |" << endl;  //Por Nome e ID
    cout << "|     4 - Pesquisar Item          |" << endl;  //Por Nome e ID
    cout << "|     5 - Exibir tudo             |" << endl;
    cout << "|     6 - Mostrar Relatório       |" << endl;
    cout << "|     7 - Sair e Salvar           |" << endl;
    cout << "|=================================|" << endl;

    cout << "--> Escolha uma opção: ";
    cin >> escolha;

    switch (escolha)
    {
        //Inserir
        case 1:
            CRUD->InserirItem();
            //system("CLS");
            break;

        //Atualizar
        case 2:
            int escolha_pesquisa1;
            cout << "--> Atualizar pelo ID (1) ou pelo Nome (2):  ";
            cin >> escolha_pesquisa1;

            //Por ID
            if(escolha_pesquisa1 == 1) {
                cin.ignore();
                cout << "--> Atualizar pelo ID: ";
                getline(cin, procurar_ID);
                CRUD->AtualizarItem(procurar_ID, escolha_pesquisa1);
                break;
            }

            //Por Nome
            else if(escolha_pesquisa1 == 2) {
                cin.ignore();
                cout << "--> Atualizar pelo Nome: ";
                getline(cin, procurar_Nome);
                CRUD->AtualizarItem(procurar_Nome, escolha_pesquisa1);
                break;
            }

            else {
                cout << "Opção Indisponível!" << endl;
                break;
            }

        //Deletar
        case 3:
            int escolha_pesquisa2;
            cout << "--> Deletar pelo ID (1) ou pelo Nome (2):  ";
            cin >> escolha_pesquisa2;

            //Por ID
            if(escolha_pesquisa2 == 1) {
                cin.ignore();
                cout << "--> Deletar pelo ID: ";
                getline(cin, procurar_ID);
                CRUD->DeletarItem(procurar_ID, escolha_pesquisa2);
                //system("CLS");
                break;
            }

            //Por Nome
            else if(escolha_pesquisa2 == 2) {
                cin.ignore();
                cout << "--> Deletar pelo Nome: ";
                getline(cin, procurar_Nome);
                CRUD->DeletarItem(procurar_Nome, escolha_pesquisa2);
                //system("CLS");
                break;
            }

            else {
                cout << "Opção Indisponível!" << endl;
                break;
            }

        //Pesquisar
        case 4:
            int escolha_pesquisa3;
            cout << "--> Pesquisar pelo ID (1) ou pelo Nome (2):  ";
            cin >> escolha_pesquisa3;

            //Por ID
            if(escolha_pesquisa3 == 1) {
                cin.ignore();
                cout << "--> Pesquisar pelo ID: ";
                getline(cin, procurar_ID);
                CRUD->ProcurarItem(procurar_ID, escolha_pesquisa3);
                break;
            }

            //Por Nome
            else if(escolha_pesquisa3 == 2) {
                cin.ignore();
                cout << "--> Pesquisar pelo Nome: ";
                getline(cin, procurar_Nome);
                CRUD->ProcurarItem(procurar_Nome, escolha_pesquisa3);
                break;
            }

            else {
                cout << "Opção Indisponível!" << endl;
                break;
            }

        //Listar
        case 5:
            //system ("CLS");
            CRUD->Estoque();
            break;

        //Mostrar Relatório
        case 6:
            //system ("CLS");
            CRUD->Relatorio();
            break;

        default:
            if(escolha != 7) {
              cout << "Opção Inválida!" << endl;
            }
            break;
      }

  } while (escolha != 7); //Sair

  //system("CLS");
  CRUD->SalvarArquivo();
  cout << "Salvando no arquivo..." << endl;
  delete CRUD;

  return 0;
}
