#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
struct dados{
    string nome;
    string cpf;
    string matricula;
    string endereco;
    string telefone;
    string email;
};
dados* aloca(dados vet[], int &t){
    dados *novo=new dados[t+3];
    copy(vet, vet+t, novo);
    t=t+3;
    delete[] vet;
    return novo;
}

struct emprestimo{
    double numMatricula;
    string nomeLivro;
    string dataDev;
};

int main(){
    system("clear");
    bool reinicio=false;
    do{
        cout<<" -------------->> BIBLIOTECA CULTURA VIRTUAL <<------------" << endl; 
        cout << "|| 1 - Cadastrar Usuário                                  ||"<< endl;
        cout << "|| 2 - Consultar empréstimos e devoluções                 ||" << endl;
        cout << "|| 3 - Listar dados cadastrados ativos                    ||" << endl;
        cout << "|| 4 - Excluir dados                                      ||" << endl;
        cout << "|| 5 - Efetuar empréstimo                                 ||"<< endl;
        cout << "|| 6 - Efetuar devolução                                  ||" << endl;
        cout << "|| 7 - Exportar contas para arquivo binário               ||"<< endl;
        cout << "|| 8 - Sair                                               ||" << endl;
        cout << "----------------------------------------------------------"<<endl;
        unsigned short escolha;
        cout<<"--->> CULTURA VIRTUAL version: 1.0 <<---" << endl; 
        cout<<"Insira um valor do menu: ";cin >> escolha;
        system("clear");

        int qtdDado=3, qtdEmp=3;
        int indice=0;
        dados *cadastro=new dados[qtdDado];
        emprestimo* livroEmprestado = NULL;

        switch(escolha){
            char sn;
            case 1:
                bool inserir;
                do{
                    if(indice<qtdDado){
                        cout<<"Insira nome: ";cin.ignore();getline(cin,cadastro[indice].nome);
                        cout<<"Insira CPF: ";cin>>cadastro[indice].cpf;
                        cout<<"Insira matricula: ";cin>>cadastro[indice].matricula;
                        cout<<"Insira endereço: ";cin.ignore();getline(cin,cadastro[indice].endereco);
                        cout<<"Insira telefone: ";cin.ignore();getline(cin,cadastro[indice].telefone);
                        cout<<"Insira e-mail: ";cin.ignore();getline(cin,cadastro[indice].email);
                        system("clear");
                        cout<<"Deseja cadastrar novo usuário? 1-sim 2-nao ";cin>>sn;
                        if(sn=='1'){
                            system("clear");
                            indice++;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        cadastro=aloca(cadastro, qtdDado);
                        inserir=true;
                    }
                } while(inserir==true);
                break;
            case 2:
                int busca;
                cin>>busca;
                
                for(int i=0; i<qtdEmp; i++){
                    if (busca == livroEmprestado[i].numMatricula){
                        cout<<"Livros a serem devolvidos:"<<endl;
                        cout<<livroEmprestado[i].nomeLivro<<" - Devolução prevista: "<<livroEmprestado[i].dataDev<<endl;
                    }
                    else{
                        cout<<"Não há livros a serem devolvidos!";
                    }
                }
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                qtdEmp=3; indice=0; inserir=true;
                livroEmprestado = new emprestimo[qtdEmp];

                do {
                    cout<<qtdEmp<<endl;
                    if(indice<qtdEmp){
                        cin>>livroEmprestado[indice].numMatricula;
                        cin.ignore();getline(cin, livroEmprestado[indice].nomeLivro);
                        cin>>livroEmprestado[indice].dataDev;
                
                        system("clear");
                        cout<<"Deseja registrar mais um empréstimo? 1-sim 2-nao ";cin>>sn;
                        if(sn=='1'){
                            system("clear");
                            indice++;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        livroEmprestado=aloca(livroEmprestado, qtdEmp);
                        inserir=true;
                    }

                } while(inserir==true);

                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                cout<<"Valor inválido!!!..."<<endl;
                break;
        }
        //======REINICIANDO O SISTEMA ======
        system("clear");
        escolha=0;
        cout<<"Deseja voltar ao menu principal?"<<endl<<"Digite 1 para Sim ou 2 para não: ";cin>>escolha;
        if(escolha==1){
            reinicio=true;
        }
        else{
            reinicio=false;
        }
    }while(reinicio==true);
    system("clear;");
    return 0;
}
