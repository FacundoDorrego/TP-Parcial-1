#include <iostream>
#include <cstring>
#include "cargarCadenas.h"
using namespace std;
#ifndef FUNCTPN1_H_INCLUDED
#define FUNCTPN1_H_INCLUDED

class Jugador{
private:
    //atributos
    char nombre[30];
    char apellido[30];
    char email[30];
    char telefono[30];
    int dni;
    int claustro;
    int deporte;
    int numeroequipo;
    int fechainscrip;
    float matricula;
    bool estado;

public:
    //metodos
    Jugador(int docuDni=0,const char *nom="???",const char *apelli="???",const char *ema="???",const char *telef="0000",int c=0,int d=0,int nume=0,int fecha=0,float matri=0){
        dni=docuDni;
        strcpy(nombre,nom);
        strcpy(apellido,apelli);
        strcpy(email,ema);
        strcpy(telefono,telef);
        claustro=c;
        deporte=d;
        numeroequipo=nume;
        fechainscrip=fecha;
        matricula=matri;
        estado=false;
    }

    void CargarDatos();
    void MostrarDatos();
    void agregarRegistro();
    void guardar() {
    FILE* archivo = fopen("jugadores.dat", "ab");
    if (archivo != nullptr) {
            fwrite(this, sizeof(Jugador), 1, archivo);
            fclose(archivo);
        } else {
            cout << "Error al abrir el archivo para escritura." << endl;
            }
    }
    static void mostrar() {
        FILE* archivo = fopen("jugadores.dat", "rb");
        if (archivo != nullptr) {
            Jugador jugador;
            while (fread(&jugador, sizeof(Jugador), 1, archivo)) {
                jugador.MostrarDatos();
                cout << "-------------------------" << endl;
            }
            fclose(archivo);
        } else {
            cout << "Error al abrir el archivo para lectura." << endl;
        }
    }

    //setters
    void setNombre(const char *nom){
        strcpy(nombre,nom);
        }
    void setApellido(const char *apelli){
        strcpy(apellido,apelli);
        }
    void setEmail(const char *ema){
        strcpy(email,ema);
        }
    void setTelefono(const char *telef){
        strcpy(telefono,telef);
        }
    void setDNI(int docuDni){
        dni=docuDni;
        }
    void setClaustro(int c){
            claustro=c;
        }
    void setDeporte(int d){
            deporte=d;
        }
    void setNumEquipo(int nume){
            numeroequipo=nume;
        }
    void setFecha(int fecha){
            fechainscrip=fecha;
        }
    void setMatricula(float matri){
            matricula=matri;
        }

    //getters
    const char *getNombre(){
        return nombre;
        }
    const char *getApellido(){
        return apellido;
        }
    const char *getEmail(){
        return email;
        }
    const char *getTelefono(){
        return telefono;
        }
    int getDNI(){
        return dni;
        }
    int getClaustro(){
        return claustro;
        }
    int getDeporte(){
        return deporte;
        }
    int getNumeroEquipo(){
        return numeroequipo;
        }
    int getFecha(){
        return fechainscrip;
        }
    int getMatricula(){
        return matricula;
        }
    bool getEstado(){
        return estado;
        }
};

void Jugador::CargarDatos(){
    cout<<"DNI: ";
    cin>>dni;
    cout<<"NOMBRE: ";
    cargarCadenas(nombre,30);
    cout << "APELLIDO: ";
    cargarCadenas(apellido, 30);
    cout << "EMAIL: ";
    cargarCadenas(email, 30);
    cout << "TELEFONO: ";
    cargarCadenas(telefono, 30);
    cout<<"CLAUSTRO: ";
    cin>>claustro;
    cout<<"DEPORTE: ";
    cin>>deporte;
    cout<<"NUMERO DE EQUIPO: ";
    cin>>numeroequipo;
    cout<<"FECHA DE INSCRIPCION (DIA): ";
    cin>>fechainscrip;
    cout<<"MATRICULA: $";
    cin>>matricula;
    estado=true;
}

void Jugador::MostrarDatos(){
    cout<<"DNI: "<<dni<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Email: " << email << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Claustro: " << claustro << endl;
    cout << "Deporte: " << deporte << endl;
    cout << "Numero de equipo: " << numeroequipo << endl;
    cout << "Fecha de inscripcion (DIA): " << fechainscrip << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Estado: " << estado << endl;
}


#endif // FUNCTPN1_H_INCLUDED
