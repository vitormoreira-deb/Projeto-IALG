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
        system("clear");
        unsigned short escolha;
        cout<<"CULTURA VIRTUAL" << endl;
        cout<< "#######"
        



        //======Reinicip--------------
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
    return 0;
}