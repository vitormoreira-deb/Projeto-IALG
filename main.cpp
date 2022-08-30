#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale.h>
#include <string>
#include <vector>
using namespace std;
struct dados{
    string nome;
    string cpf;
    int matricula;
    string endereco;
    string telefone;
    vector <string>email;
};

int main(){
    bool reinicio=false;
    do{
        unsigned short escolha;
        int opcao;
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

        cin >> opcao;








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
