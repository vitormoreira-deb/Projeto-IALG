#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#ifdef __linux__
    #include <unistd.h>
#elif _WIN32
    #include <windows.h>
#else

#endif

using namespace std;
void limpa(){
#ifdef __linux__
    system("clear");
#elif _WIN32
    #include <windows.h>
    system("cls");
#else

#endif
}
struct dados{
    string nome;
    string cpf;
    string matricula;
    string endereco;
    string telefone;
    string email;
};
struct emprestimo{
    double numMatricula;
    string nomeLivro;
    string dataDev;
};
dados* aloca(dados vet[], int &t){
    dados *novo=new dados[t+3];
    copy(vet, vet+t, novo);
    t=t+3;
    delete[] vet;
    return novo;
}
emprestimo* aloca(emprestimo vet[], int &t){
    emprestimo *novo=new emprestimo[t+3];
    copy(vet, vet+t, novo);
    t=t+3;
    delete[] vet;
    return novo;
}

void menu1(dados* cadastro, char sn, int qtdDado){
    int indice=0;
    bool inserir=true;
    qtdDado=3;

    do{
        if(indice<qtdDado){
            cout<<"Insira nome: ";cin.ignore();getline(cin,cadastro[indice].nome);
            cout<<"Insira CPF: ";cin>>cadastro[indice].cpf;
            cout<<"Insira matricula: ";cin>>cadastro[indice].matricula;
            cout<<"Insira endereço: ";cin.ignore();getline(cin,cadastro[indice].endereco);
            cout<<"Insira telefone: ";cin.ignore();getline(cin,cadastro[indice].telefone);
            cout<<"Insira e-mail: ";cin.ignore();getline(cin,cadastro[indice].email);
            limpa();

            for(int i=0; i<indice; i++){
                if(cadastro[indice].matricula == cadastro[i].matricula){
                    cout<<"Usuário já cadastrado no sistema!"<<endl;
                    indice--;
                }
            }
            cout<<"Deseja cadastrar novo usuário? 1-sim 2-nao ";cin>>sn;
            if(sn=='1'){
                limpa();
                indice++;
            }
            else{
                inserir=false;
            }
        }
        else{
            cadastro=aloca(cadastro, qtdDado);
        }
    } while(inserir);
}
void menu2(emprestimo* livroEmprestado, int &qtdEmp){
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
}

void menu5(emprestimo* livroEmprestado, char sn, int &qtdEmp){
    int indice, cont;
    bool inserir=true;
    qtdEmp=3; 
    livroEmprestado = new emprestimo[qtdEmp];

    do {
        cout<<qtdEmp<<endl;
        if(indice<qtdEmp){
            cin>>livroEmprestado[indice].numMatricula;
            cin.ignore();getline(cin, livroEmprestado[indice].nomeLivro);
            cin>>livroEmprestado[indice].dataDev;
            cont++;
    
            limpa();
            cout<<"Deseja registrar mais um empréstimo? 1-sim 2-nao ";cin>>sn;
            if(sn=='1'){
                limpa();
                indice++;
            }
            else{
                inserir=false;
            }
        }
        else{
            livroEmprestado=aloca(livroEmprestado, qtdEmp);
        }

    } while(inserir);
}

//--------------------------------------------------- BEGIN MAIN
int main(){
    limpa();
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
        cout<<"--->> CULTURA VIRTUAL version: 1.0 <<---" << endl; 

        unsigned short escolha;
        cout<<"Insira um valor do menu: ";cin >> escolha;
        limpa();

        int qtdDado, qtdEmp;
        int indice=0;
        dados *cadastro=new dados[qtdDado];
        emprestimo* livroEmprestado = NULL;

        switch(escolha){
            char sn;
            case 1:
                menu1(cadastro, sn, qtdDado);
                break;
            case 2:
                menu2(livroEmprestado, qtdEmp);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                menu5(livroEmprestado, sn, qtdEmp);
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
        limpa();
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
