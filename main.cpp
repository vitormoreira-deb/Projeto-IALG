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
void pausing(){
#ifdef __linux__
    usleep(2350*1000);
#elif _WIN32
    #include <windows.h>
    Sleep(2350);
#else

#endif
}
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

void menu1(dados* cadastro, int &qtdDado){
    int indice=0;
    bool inserir=true;
    char sn;
    cadastro = new dados[qtdDado];

    do{
        string nome, cpf, matricula;
        if(indice<qtdDado){
            cout<<"Insira nome: ";cin.ignore();getline(cin,nome);
            cout<<"Insira CPF: ";cin>>cpf;
            cout<<"Insira matricula: ";cin>>matricula;
            
            int i=0;
            bool achou=false;
            while(i<indice && !achou){
                if(matricula == cadastro[i].matricula){
                    cout<<"Esse usuário já foi cadastrado no sistema!"<<endl;
                    achou=true;
                }
                i++;
            }
            if (achou==false){
                cadastro[indice].nome = nome;
                cadastro[indice].cpf = cpf;
                cadastro[indice].matricula = matricula;
                cout<<"Insira endereço: ";cin.ignore();getline(cin,cadastro[indice].endereco);
                cout<<"Insira telefone: ";cin.ignore();getline(cin,cadastro[indice].telefone);
                cout<<"Insira e-mail: ";cin.ignore();getline(cin,cadastro[indice].email);
            }
            else{
                pausing();
            }
            limpa();

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

void menu5(emprestimo* livroEmprestado, int &qtdEmp){
    int indice=0, cont=0;
    bool inserir=true;
    char sn;
    livroEmprestado = new emprestimo[qtdEmp];

    do {
        if(indice<qtdEmp){
            cin>>livroEmprestado[indice].numMatricula;
            cin.ignore();getline(cin, livroEmprestado[indice].nomeLivro);
            cin>>livroEmprestado[indice].dataDev;
            cont++;
            cout<<"Empréstimo realizado com sucesso!";
    
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
    limpa();
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

        char escolha;
        cout<<"Insira um valor do menu: ";cin >> escolha;
        limpa();

        int qtdDado=3, qtdEmp=3;
        dados* cadastro = NULL;
        emprestimo* livroEmprestado = NULL;

        switch(escolha){
            case '1':
                menu1(cadastro, qtdDado);
                break;
            case '2':
                menu2(livroEmprestado, qtdEmp);
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                menu5(livroEmprestado, qtdEmp);
                break;
            case '6':
                break;
            case '7':
                break;
            case '8':
                break;
            default:
                cout<<"Valor inválido!!!..."<<endl;
                break;
        }
        //======REINICIANDO O SISTEMA ======
        limpa();
        escolha='0';
        cout<<"Deseja voltar ao menu principal?"<<endl<<"Digite 1 para Sim ou 2 para não: ";cin>>escolha;
        if(escolha=='1'){
            reinicio=true;
        }
        else{
            reinicio=false;
        }
    }while(reinicio==true);
    system("clear;");

    // ACEITO QUE VC ME PAGUE UM MONSTER
    return 0;
}
