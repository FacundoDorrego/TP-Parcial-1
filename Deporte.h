#include <iostream>
#include <cstring>
#include "cargarCadenas.h"
#include "fecha.h"
using namespace std;
#ifndef DEPORTE_H_INCLUDED
#define DEPORTE_H_INCLUDED

class Deporte{
private:
    //atributos
    char nombre[30];
    int tipo,id;
    Fecha anioOrigen;
    bool estado;

public:
    //metodos
    Deporte (int t=0,int i=0,const char *nom="???",Fecha anio=Fecha() ,bool e = false){
        strcpy(nombre,nom);
        id=i;
        tipo=t;
        anioOrigen=anio;
        estado=e;
    }

    void CargarDatos();
    void MostrarDatos();
    bool borrarID();
    bool ListarID();
    int buscarID(int numid);
    bool modOrigen();

    void guardar() {
        FILE* archivo = fopen("deportes.dat", "ab");
        if (archivo != NULL) {
                fwrite(this, sizeof(Deporte), 1, archivo);
                fclose(archivo);
        } else {
            cout << "Error al abrir el archivo para escritura." << endl;
            }
    }

    void ListarTodo() {
        FILE* archivo = fopen("deportes.dat", "rb");
        if (archivo != NULL) {
            while (fread(this, sizeof(Deporte), 1, archivo)) {
                if(getEstado()==true){
                    MostrarDatos();
                    cout << "-------------------------" << endl;
                    }
            }
        fclose(archivo);
        } else {
            cout << "Error al abrir el archivo para lectura." << endl;
        }
    }

    Deporte leerID(int pos){
        Deporte reg;
        reg.setEstado(false);
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
        reg.setEstado(false);
        return reg;
}
        //Mostrar datos solo de ese ID

    //setters
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

    //getters
    const char *getNombre(){
        return nombre;
        }
    int getTipo(){
        return tipo;
        }
     int getID(){
        return id;
        }
    Fecha getyear(){
        return anioOrigen;
        }
    bool getEstado(){
        return estado;
        }
};

void Deporte::CargarDatos(){
    int day,month,year;
    Deporte reg;
    setEstado(true);
    cout<<"ID:"<<id;
    id++;
    int posExistente = reg.buscarID(id);
    if (posExistente != -1) {
        Deporte regExistente = leerID(posExistente);
        if (regExistente.getEstado() != false) {
            cout << "El ID ya existe en el registro. No se permite duplicar ID." << endl;
            return;
        }
    }
    cout<<"NOMBRE: ";
    cargarCadenas(nombre,30);
    cout<<"TIPO DE DEPORTE: ";
    cin>>tipo;
    if(tipo<=0||tipo>21){
        cout << "Error claustro incorrecto." << endl;
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

int Deporte::buscarID(int numid){
    FILE* archivo = fopen("deportes.dat", "rb");
    int pos=0;
    if (archivo != NULL) {
            Deporte reg;
            while (fread(&reg, sizeof(Deporte), 1, archivo)) {
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

bool Deporte::ListarID(){
        int numid;
        int pos=0;
        cout<<"Introducir ID a buscar: ";
        cin>>numid;
        pos=buscarID(numid);
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

bool Deporte::borrarID(){
    int numid;
    FILE* archivo = fopen("deportes.dat", "rb+");
    if(archivo == NULL){
        return false;
    }
    cout<<"Introducir ID a borrar: ";
    cin>>numid;
    int pos = buscarID(numid);
    if(pos==-1){
            cout<<"No existe ese ID"<<endl;
            return false;
            }
    fseek(archivo,pos * sizeof(Deporte),0);
        Deporte deporteborrado;
        deporteborrado.setEstado(false);
        fwrite(&deporteborrado,sizeof(Deporte),1,archivo);
        fclose(archivo);
        cout<<"Deporte con ID "<< numid <<" borrado exitosamente."<<endl;
        return true;
}

bool Deporte::modOrigen(){
    int numid,day,month,year;
    FILE* archivo = fopen("deportes.dat", "rb+");
    if(archivo == NULL){
        return false;
    }
    cout<<"Introducir ID del registro a modificar: ";
    cin>>numid;
    int pos = buscarID(numid);
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

#endif // DEPORTE_H_INCLUDED