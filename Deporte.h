//Autor: Facundo Nehuen Dorrego
#include <iostream>
#include <cstring>
#include "cargarCadenas.h"
#include "fecha.h"
using namespace std;
#ifndef DEPORTE_H_INCLUDED
#define DEPORTE_H_INCLUDED
void ListarTodoDeporte();
bool borrarIDDeporte();
bool ListarIDDeporte();
int buscarIDDeporte(int numid);
bool modOrigenDeporte();
int obtenerNuevoIDDeporte();

class Deporte{
private:

    char nombre[30];
    int tipo,id;
    Fecha anioOrigen;
    bool estado;
    int cantidadInscriptos;
public:
    Deporte (int t=0,int i=0,const char *nom="???",Fecha anio=Fecha() ,bool e = false){
        strcpy(nombre,nom);
        id=i;
        tipo=t;
        anioOrigen=anio;
        estado=e;
    }
    void CargarDatos();
    void MostrarDatos();

    void guardar() {
        FILE* archivo = fopen("deportes.dat", "ab");
        if (archivo != NULL) {
                fwrite(this, sizeof(Deporte), 1, archivo);
                fclose(archivo);
        } else {
            cout << "Error al abrir el archivo para escritura." << endl;
            }
    }
    
    void setNombre(const char *nom){
        strcpy(nombre,nom);
        }
    void setTipo(int t){
        tipo=t;
        }
    void setID(int i){
        id=i;
        }
    void setEstado(bool e){
        estado=e;
        }
    void setOrigen(Fecha fecha){
        anioOrigen=fecha;
        }


    const char *getNombre(){
        return nombre;
        }
    int getTipo(){
        return tipo;
        }
     int getID(){
        return id;
        }
    Fecha getOrigen(){
        return anioOrigen;
        }

    bool getEstado(){
        return estado;
        }

};

Deporte leerID(int pos);

Deporte leerID(int pos){
    Deporte reg;
    FILE* archivo = fopen("deportes.dat", "rb");
    int posLectura=0;
    if(archivo==NULL){
        cout<<"Error al abrir el archivo de lectura";
        return reg;
        }
    while (fread(&reg, sizeof(Deporte), 1, archivo)==1) {
        if(pos==posLectura){
            fclose(archivo);
            return reg;
            }

        posLectura++;
    }
    fclose(archivo);
    return reg;
}

void Deporte::CargarDatos(){
    int day,month,year;
    Deporte reg;
    setEstado(true);
    int nuevoID = obtenerNuevoIDDeporte();
    cout << "ID:" << nuevoID << endl;
    if (nuevoID < 1 || nuevoID > 10) {
        cout << "El ID debe estar en el rango de 1 al 10." << endl;
        setEstado(false);
        return;
    }
    setID(nuevoID);
    int posExistente = buscarIDDeporte(id);
    if (posExistente != -1) {
        Deporte regExistente = leerID(posExistente);
        if (regExistente.getEstado() != false) {
            cout << "El ID ya existe en el registro. No se permite duplicar ID." << endl;
            setEstado(false);
            return;
        }
    }
    cout<<"NOMBRE: ";
    cargarCadenas(nombre,30);
    cout<<"TIPO DE DEPORTE: ";
    cin>>tipo;
    if(tipo<=0||tipo>21){
        cout << "Error tipo incorrecto." << endl;
        setEstado(false);
        return;
    }
    cout<<"ANIO DE ORIGEN: ";
    cin>>year;
    Fecha fechaorigen(day,month,year);
    setOrigen(fechaorigen);
}

void Deporte::MostrarDatos(){
    cout<<"ID: "<<id<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout << "TIPO DE DEPORTE: " << tipo << endl;
    cout << "ANIO DE ORIGEN: "<<anioOrigen.getYear() << endl;
    cout << "ESTADO: " << estado << endl;
}

int buscarIDDeporte(int numid){
    FILE* archivo = fopen("deportes.dat", "rb");
    int pos=0;
    if (archivo != NULL) {
        Deporte reg;
        while (fread(&reg, sizeof(Deporte), 1, archivo)){
            if(numid==reg.getID()){
                fclose(archivo);
                return pos;
            }
            pos++;
        }
    }
    if (archivo == NULL){
        return -2;
    }
    return -1;
}

bool ListarIDDeporte(){
        int numid;
        int pos=0;
        cout<<"Introducir ID a buscar: ";
        cin>>numid;
        pos=buscarIDDeporte(numid);
        if(pos==-1&&pos!=-2){
            cout<<"No existe ese ID"<<endl;
            return false;
        }
        if(pos==-2){
            cout << "Error al abrir el archivo para lectura." << endl;
            return false;
        }
        Deporte reg;
        reg=leerID(pos);
        if(reg.getEstado()==true){
            cout<<"ID encontrado y es el siguiente:"<<endl;
            reg.MostrarDatos();
        } else {cout<<"El ID no existe"<<endl;}
        reg.setEstado(false);
        return true;
    }

bool borrarIDDeporte(){
    int numid;
    FILE* archivo = fopen("deportes.dat", "rb+");
    if(archivo == NULL){
        return false;
    }
    cout<<"Introducir ID a borrar: ";
    cin>>numid;
    int pos = buscarIDDeporte(numid);
    if(pos==-1){
            cout<<"No existe ese ID"<<endl;
            return false;
            }
    fseek(archivo,pos * sizeof(Deporte),0);
        Deporte deporteborrado;
        deporteborrado.setEstado(false);
        deporteborrado.setID(0);
        fwrite(&deporteborrado,sizeof(Deporte),1,archivo);
        fclose(archivo);
        cout<<"Deporte con ID "<< numid <<" borrado exitosamente."<<endl;
        return true;
}

bool modOrigenDeporte(){
    int numid,day,month,year;
    FILE* archivo = fopen("deportes.dat", "rb+");
    if(archivo == NULL){
        return false;
    }
    cout<<"Introducir ID del registro a modificar: ";
    cin>>numid;
    int pos = buscarIDDeporte(numid);
    if(pos==-1){
        cout<<"No existe ese ID"<<endl;
        return false;
        }
    Deporte deportefecha;
    fseek(archivo,pos * sizeof(Deporte),0);
    fread(&deportefecha, sizeof(Deporte),1,archivo);
    cout<<"Introducir anio a cambiar "<<endl;
    cin>>year;
    Fecha fechaOrigen(day,month,year);
    deportefecha.setOrigen(fechaOrigen);
    fseek(archivo,pos * sizeof(Deporte),0);
    fwrite(&deportefecha,sizeof(Deporte),1,archivo);
    fclose(archivo);
    cout<<"La fecha del registro del deporte con ID "<< numid <<" se ha cambiado exitosamente."<<endl;
    return true;
}

int obtenerNuevoIDDeporte() {
    FILE* archivo = fopen("deportes.dat", "rb");
    if (archivo != NULL) {
        // Se guardan los id utilizados, cambiando el valor del vector - ID a true o false.
        bool idsUtilizados[10] = {false};
        int nuevoID = 1;
        Deporte reg;
        while (fread(&reg, sizeof(Deporte), 1, archivo)) {
            if (reg.getEstado() && reg.getID() >= 1 && reg.getID() <= 10) {
                // Carga el id como usado en el vector.
                idsUtilizados[reg.getID() - 1] = true;
            }
        }
        // Busca el primer ID no utilizado en el rango de 1 a 10
        for (int i = 0; i < 10; i++) {
            if (!idsUtilizados[i]) {
                nuevoID = i + 1;
                break;
            }
        }
        fclose(archivo);
        return nuevoID;
    } else {
        return 1;
    }
}


void ListarTodoDeporte() {
    Deporte reg;
    FILE* archivo = fopen("deportes.dat", "rb");
    if (archivo != NULL) {
        while (fread(&reg, sizeof(Deporte), 1, archivo)) {
            if(reg.getEstado()==true){
                reg.MostrarDatos();
                cout << "-------------------------" << endl;
                }
            }
        fclose(archivo);
        } else {
            cout << "Error al abrir el archivo para lectura." << endl;
        }
    }
#endif
