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
int main(){
    bool reinicio=false;
    do{
        int t=3;
        int indice=0;
        unsigned short escolha;
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
        cout<<"Insira um valor do menu: ";cin >> escolha;
        system("clear");
        dados *cadastro=new dados[t];
        switch(escolha){
            case 1:
            bool inserir;
            do{
                if(indice<(t)){
                    char sn;
                    cout<<"Insira nome: ";cin.ignore();getline(cin,cadastro[indice].nome);
                    cout<<"Insira CPF: ";cin>>cadastro[indice].cpf;
                    cout<<"Insira matricula: ";cin>>cadastro[indice].matricula;
                    cout<<"Insira endereço: ";cin.ignore();getline(cin,cadastro[indice].endereco);
                    cout<<"Insira telefone: ";cin.ignore();getline(cin,cadastro[indice].telefone);
                    cout<<"Insira e-mail: ";cin.ignore();getline(cin,cadastro[indice].email);
                    system("clear");
                    cout<<"Deseja cadastrar novo usuário? 1-sim 2-nao ";cin>>sn;
                    if(sn=='1'){
                        indice++;
                    }
                    else{
                        break;
                    }
                }
                else{
                    cadastro=aloca(cadastro, t);
                    inserir=true;
                }
            }while(inserir=true);
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
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