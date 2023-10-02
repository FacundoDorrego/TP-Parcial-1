#include <iostream>
#include <cstring>
#include "menus.h"
using namespace std;

int main(){
    int opc;
    while(true){
        cout<<"MENU PRINCIPAL"<<endl;
        cout << "-------------------------" << endl;
        cout<<"1. MENU JUGADORES"<<endl;
        cout<<"2. MENU DEPORTES"<<endl;
        cout << "-------------------------" << endl;
        cout<<"0. FIN DEL PROGRAMA"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch (opc){
            case 1:
                menujugadores();
                break;

            case 2:
                menudeportes();
                break;

            case 0:
                return 0;
                break;

            default:
                cout<<"OPCION INCORRECTA";
                system("pause");
                break;
        }
    }

    return 0;
}

