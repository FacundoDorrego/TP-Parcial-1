//Autor: Facundo Nehuen Dorrego
using namespace std;
#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include "Jugador.h"
#include "Deporte.h"
#include "Configuracion.h"
int menujugadores();
int menudeportes();
int menujugadores(){
    Jugador jugador;
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
                jugador.CargarDatos();
                jugador.guardar();
                break;

            case 2:
                ListarDNIJugador();
                break;

            case 3:
                ListarTodoJugador();
                break;

            case 4:
                modFechaJugador();
                break;

            case 5:
                borrarJugador();
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
                ListarIDDeporte();
                break;

            case 3:
                ListarTodoDeporte();
                break;

            case 4:
                modOrigenDeporte();
                break;

            case 5:
                borrarIDDeporte();
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

int menuconfiguraciones(){
    Deporte deporte;
    int opc;
    while(true){
        cout<<"MENU DEPORTES"<<endl;
        cout << "-------------------------" << endl;
        cout<<"1. CREAR COPIA DE SEGURIDAD DEL ARCHIVO JUGADORES"<<endl;
        cout<<"2. CREAR COPIA DE SEGURIDAD DEL ARCHIVO DEPORTES"<<endl;
        cout<<"3. RESTAURAR COPIA DE SEGURIDAD DEL ARCHIVO JUGADORES"<<endl;
        cout<<"4. RESTAURAR COPIA DE SEGURIDAD DEL ARCHIVO DEPORTES"<<endl;
        cout<<"5. ESTABLECER DATOS DE INICIO"<<endl;
        cout << "-------------------------" << endl;
        cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch (opc){
            case 1:
                crearBackupJugadores();
                break;

            case 2:
                crearBackupDeportes();
                break;

            case 3:
                restaurarBackupJugadores();
                break;

            case 4:
                restaurarBackupDeportes();
                break;

            case 5:
                establecerDatosInicio();
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