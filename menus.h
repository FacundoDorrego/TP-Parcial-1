using namespace std;
#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include "Jugador.h"
#include "Deporte.h"
int menujugadores();
int menudeportes();
int menujugadores(){
    Jugador deporte;
    int opc;
    while(true){
        cout<<"MENU JUGADORES"<<endl;
        cout << "-------------------------" << endl;
        cout<<"1. AGREGAR JUGADOR"<<endl;
        cout<<"2. LISTAR JUGADOR POR DNI"<<endl;
        cout<<"3. LISTAR TODOS LOS JUGADORES"<<endl;
        cout<<"4. MODIFICAR FECHA"<<endl;
        cout<<"5. ELIMINAR REGISTRO DE JUGADOR"<<endl;
        cout << "-------------------------" << endl;
        cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch (opc){
            case 1:
                deporte.CargarDatos();
                deporte.guardar();
                break;

            case 2:
                deporte.ListarDNI();
                break;

            case 3:
                deporte.ListarTodo();
                break;

            case 4:
                deporte.modFecha();
                break;

            case 5:
                deporte.borrarJugador();
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

int menudeportes(){
    Deporte deporte;
    int opc;
    while(true){
        cout<<"MENU DEPORTES"<<endl;
        cout << "-------------------------" << endl;
        cout<<"1. AGREGAR DEPORTE"<<endl;
        cout<<"2. LISTAR DEPORTE POR ID"<<endl;
        cout<<"3. LISTAR TODO"<<endl;
        cout<<"4. MODIFICAR ANIO DE ORIGEN"<<endl;
        cout<<"5. ELIMINAR REGISTRO"<<endl;
        cout << "-------------------------" << endl;
        cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch (opc){
            case 1:
                deporte.CargarDatos();
                deporte.guardar();
                break;

            case 2:
                deporte.ListarID();
                break;

            case 3:
                deporte.ListarTodo();
                break;

            case 4:
                deporte.modOrigen();
                break;

            case 5:
                deporte.borrarID();
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
#endif // MENUS_H_INCLUDED