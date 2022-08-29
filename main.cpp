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
        }
        //======Reinicio--------------
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