#include <iostream>
#include <cstring>
#include "functpn1.h"
using namespace std;

int main(){
    Jugador jugador;
    int opc;
    while(true){
        cout<<"MENU"<<endl;
        cout<<"1. AGREGAR JUGADOR"<<endl;
        cout<<"2. LISTAR JUGADOR POR DNI"<<endl;
        cout<<"3. LISTAR TODOS LOS JUGADORES"<<endl;
        cout<<"4. MODIFICAR FECHA"<<endl;
        cout<<"5. ELIMINAR REGISTRO DE JUGADOR"<<endl;
        cout<<"0. SALIR"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch (opc){
            case 1:
                jugador.CargarDatos();
                jugador.guardar();
                break;

            case 2:
                jugador.ListarDNI();
                break;

            case 3:
                jugador.ListarTodo();
                break;

            case 4:
                jugador.modFecha();
                break;

            case 5:
                jugador.borrarJugador();
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

