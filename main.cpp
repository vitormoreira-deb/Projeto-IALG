#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
struct dados{
    string nome;
    string cpf;
    int matricula;
    string endereco;
    string telefone;
    string email;
};
void inserir(int &i, int &qt){
    for(i;i<qt; i++){
        dados user[qt];
    }
}
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
        int i=0;
        unsigned short escolha;
        cout<<"--->> CULTURA VIRTUAL <<--- " << endl; 
        
        cout << "1 - Cadastrar Usuário." << endl;
        cout << "2 - Consultar empréstimos e devoluções." << endl;
        cout << "3 - Listar dados cadastrados ativos." << endl;
        cout << "4 - Excluir dados." << endl;
        cout << "5 - Efetuar empréstimo." << endl;
        cout << "6 - Efetuar devolução." << endl;
        cout << "7 - Exportar contas para arquivo binário." << endl;
        cout << "8 - Sair." << endl;
        
        cout<<"--->> CULTURA VIRTUAL version: 1.0 <<---" << endl; 
        cin >> escolha;
        dados *cadastro=new dados[t];
        switch(escolha){
            case 1:
            bool inserir;
            do{
                if(i<(t)){
                    cout<<"Insira nome: ";cin>>cadastro[i].nome;
                    cout<<"Insira CPF: ";cin>>cadastro[i].cpf;
                    cout<<"Insira matricula: ";cin>>cadastro[i].matricula;
                    cout<<"Insira endereço: ";cin>>cadastro[i].endereco;
                    cout<<"Insira telefone: ";cin>>cadastro[i].telefone;
                    cout<<"Insira e-mail: ";cin>>cadastro[i].email;
                    while(cadastro.email.size()>0){
                        //continua 
                    }
                }
                else{
                    char valores;
                    cout<<"Armazenamento cheio!!!. Posso aumentar o armazenamento em mais 3 valores?"<<endl<<"1-Sim, 2-Não    "cin>>valores;

                    if(valores=='1'){
                        cadastro=aloca(cadastro, t);
                        inserir=true;
                    }
                    else{
                        inserir=false;
                    }
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








        unsigned t=3;
        vector<dados>usuario(t);
        unsigned controle=0;
        cin>>escolha;
        switch(escolha){
            case 1:
            if(controle<t){

            }
            else{
                
            }
            break;
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            break;
        }
        //======Reinicio--------------
        //======REINICIANDO O SISTEMA ======
        //system("clear");
        escolha=0;
        cout<<"Deseja voltar ao menu principal?"<<endl<<"Digite 1 para Sim ou 2 para não: ";cin>>escolha;
        if(escolha==1){
            reinicio=true;
        }
        else{
            reinicio=false;
        }
    }while(reinicio==true);
    return 0;
}
