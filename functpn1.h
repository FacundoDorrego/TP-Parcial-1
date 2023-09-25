#include <iostream>
#include <cstring>
#include "cargarCadenas.h"
#include "fecha.h"
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
    Fecha fechainscrip;
    float matricula;
    bool estado;

public:
    //metodos
    Jugador(int docuDni=0,const char *nom="???",const char *apelli="???",const char *ema="???",const char *telef="0000",int c=0,int d=0,int nume=0,Fecha fecha=Fecha(),float matri=0,bool e = false){
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
    estado=e;
    }

    void CargarDatos();
    void MostrarDatos();
    bool borrarJugador();
    bool ListarDNI();
    int buscarDNI(int docuDni);
    bool modFecha();

    void guardar() {
        FILE* archivo = fopen("jugadores.dat", "ab");
        if (archivo != NULL) {
                fwrite(this, sizeof(Jugador), 1, archivo);
                fclose(archivo);
        } else {
            cout << "Error al abrir el archivo para escritura." << endl;
            }
    }


    void ListarTodo() {
        FILE* archivo = fopen("jugadores.dat", "rb");
        if (archivo != NULL) {
            while (fread(this, sizeof(Jugador), 1, archivo)) {
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


    Jugador leerDNI(int pos){
        Jugador reg;
        reg.setEstado(false);
        FILE* archivo = fopen("jugadores.dat", "rb");
        int posLectura=0;
        if(archivo==NULL){
                cout<<"Error al abrir el archivo de lectura";
                return reg;
        }
        while (fread(&reg, sizeof(Jugador), 1, archivo)==1) {
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
        //Mostrar datos solo de ese dni

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
    void setFecha(Fecha fecha){
        fechainscrip=fecha;
        }
    void setMatricula(float matri){
       matricula=matri;
        }
    void setEstado(bool e){
        estado=e;
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
    Fecha getFecha(){
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
    Jugador reg;
    setEstado(true);
    cout<<"DNI: ";
    cin>>dni;
    int posExistente = reg.buscarDNI(dni);
    if (posExistente != -1) {
        Jugador regExistente = leerDNI(posExistente);
        if (regExistente.getEstado() != false) {
            cout << "El DNI ya existe en el registro. No se permite duplicar DNI." << endl;
            return;
        }
    }
    cout<<"NOMBRE: ";
    cargarCadenas(nombre,30);
    cout << "APELLIDO: ";
    cargarCadenas(apellido, 30);
    cout << "EMAIL: ";
    cargarCadenas(email, 30);
    cout << "TELEFONO: ";
    cargarCadenas(telefono, 30);
    cout<<"CLAUSTRO: (1: docente; 2 alumno; 3 no docente; 4 graduado) ";
    cin>>claustro;
    cout<<"DEPORTE: ";
    cin>>deporte;
    cout<<"NUMERO DE EQUIPO: ";
    cin>>numeroequipo;
    cout<<"FECHA DE INSCRIPCION (DIA,MES,ANIO): ";
    int day,month,year;
    cin>>day>>month>>year;
    Fecha fechaInscripcion(day,month,year);
    setFecha(fechaInscripcion);
    cout<<"MATRICULA: $";
    cin>>matricula;
}

void Jugador::MostrarDatos(){
    cout<<"DNI: "<<dni<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Email: " << email << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Claustro: (1: docente; 2 alumno; 3 no docente; 4 graduado) " << claustro << endl;
    cout << "Deporte: " << deporte << endl;
    cout << "Numero de equipo: " << numeroequipo << endl;
    cout << "Fecha de inscripcion (DIA,MES,ANIO): " << fechainscrip.getDay() <<"/"<< fechainscrip.getMonth() <<"/"<<fechainscrip.getYear() << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Estado: " << estado << endl;
}

int Jugador::buscarDNI(int docuDni){
    FILE* archivo = fopen("jugadores.dat", "rb");
    int pos=0;
    if (archivo != NULL) {
            Jugador reg;
            while (fread(&reg, sizeof(Jugador), 1, archivo)) {
                    if(docuDni==reg.getDNI()){
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

bool Jugador::ListarDNI(){
        int docuDni;
        int pos=0;
        cout<<"Introducir DNI a buscar: ";
        cin>>docuDni;
        pos=buscarDNI(docuDni);
        if(pos==-1&&pos!=-2){
            cout<<"No existe ese DNI"<<endl;
            return false;
        }
        if(pos==-2){
            cout << "Error al abrir el archivo para lectura." << endl;
            return false;
        }
        Jugador reg;
        reg=leerDNI(pos);
        if(reg.getEstado()==true){
            cout<<"DNI encontrado y es el siguiente:"<<endl;
            reg.MostrarDatos();
        } else {cout<<"El DNI no existe"<<endl;}
        reg.setEstado(false);
        return true;
    }

bool Jugador::borrarJugador(){
    int docuDni;
    FILE* archivo = fopen("jugadores.dat", "rb+");
    if(archivo == NULL){
        return false;
    }
    cout<<"Introducir DNI a borrar: ";
    cin>>docuDni;
    int pos = buscarDNI(docuDni);
    if(pos==-1){
            cout<<"No existe ese DNI"<<endl;
            return false;
            }
    fseek(archivo,pos * sizeof(Jugador),0);
        Jugador jugadorborrado;
        jugadorborrado.setEstado(false);
        fwrite(&jugadorborrado,sizeof(Jugador),1,archivo);
        fclose(archivo);
        cout<<"Jugador con DNI "<< docuDni <<" borrado exitosamente."<<endl;
        return true;
}

bool Jugador::modFecha(){
    int docuDni,day,month,year;
    FILE* archivo = fopen("jugadores.dat", "rb+");
    if(archivo == NULL){
        return false;
    }
    cout<<"Introducir DNI del registro a modificar: ";
    cin>>docuDni;
    int pos = buscarDNI(docuDni);
    if(pos==-1){
            cout<<"No existe ese DNI"<<endl;
            return false;
            }
    Jugador jugadorfecha;
    fseek(archivo,pos * sizeof(Jugador),0);
    fread(&jugadorfecha, sizeof(Jugador),1,archivo);
    cout<<"Introducir fecha (DIA,MES,ANIO) "<<endl;
    cin>>day>>month>>year;
    Fecha fechaInscripcion(day,month,year);
    jugadorfecha.setFecha(fechaInscripcion);
    fseek(archivo,pos * sizeof(Jugador),0);
    fwrite(&jugadorfecha,sizeof(Jugador),1,archivo);
    fclose(archivo);
    cout<<"La fecha del registro del jugador con DNI "<< docuDni <<" se ha cambiado exitosamente."<<endl;
    return true;
}

#endif // FUNCTPN1_H_INCLUDED
