//Autor: Facundo Nehuen Dorrego
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
        cout<<"3. MENU CONFIGURACIONES"<<endl;
        cout<<"4. MENU REPORTES"<<endl;
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

            case 3:
                menuconfiguraciones();
                break;

            case 4:
                menureportes();
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

