#ifndef REPORTE_H_INCLUDED
#define REPORTE_H_INCLUDED
#include "deporte.h"
#include "jugador.h"
#include "fecha.h"
class Punto2
{
private:
    int id,cantidadInscriptos;
    char nombre[30];
    Fecha anioOrigen;
public:
    Punto2 (int c=0,int i=0,const char *nom="???",Fecha anio=Fecha()){
        strcpy(nombre,nom);
        id=i;
        anioOrigen=anio;
        cantidadInscriptos=c;
    }
    void setNombre(const char *nom){
        strcpy(nombre,nom);
        }
    void setID(int i){
        id=i;
        }
    void setCantidadInscriptos(int cantidad) {
        cantidadInscriptos = cantidad;
    }
    void setOrigen(Fecha fecha){
        anioOrigen=fecha;
        }
    int getAnioOrigen(){
        return anioOrigen.getYear();
    }
    int getCantidadInscriptos() {
        return cantidadInscriptos;
    }
    int getID(){
        return id;
        }
    const char *getNombre(){
        return nombre;
        }
    Fecha getOrigen(){
        return anioOrigen;
        }
};

void punto1() {
    int minJugadores = 999;
    int deporteMinJugadores = -1;
    Deporte regD;
    FILE* deporte = fopen("deportes.dat", "rb");
    if (deporte != NULL) {
        while (fread(&regD, sizeof(Deporte), 1, deporte)) {
            int contJugadores = 0;
            Jugador regJ;
            FILE* jugador = fopen("jugadores.dat", "rb"); 
            if (jugador != NULL) {
                while (fread(&regJ, sizeof(Jugador), 1, jugador)) {
                    if (regJ.getEstado() && regJ.getDeporte() == regD.getID()) {
                        int year = regJ.getFecha().getYear();
                        cout << "Anio de inscripcion: " << year << "Nombre del jugador"<<" "<<regJ.getNombre()<< endl; 
                        if (year == 2023) {
                            cout<<"INSCRIPCION ANIO 2023"<<endl;
                            cout<<"NOMBRE DEL JUGADOR "<<regJ.getNombre()<< endl;
                            cout<<"ID DE DEPORTE "<<regD.getID();
                            contJugadores++;
                        }
                        if (contJugadores < minJugadores&&year==2023) {
                            minJugadores = contJugadores;
                            deporteMinJugadores = regD.getID();
                            }
                    }
                }
                fclose(jugador); 
            } else {
                cout << "Error al abrir el archivo de jugadores para lectura." << endl;
            }
        }

        fclose(deporte);

        if (deporteMinJugadores != -1) {
            cout << "Deporte con la menor cantidad de jugadores inscritos en 2023: " << deporteMinJugadores << endl;
            cout << "Cantidad de jugadores inscritos: " << minJugadores << endl;
        } else {
            cout << "No se encontraron deportes con jugadores inscritos en 2023." << endl;
        }
    } else {
        cout << "Error al abrir el archivo de deportes para lectura." << endl;
    }
}



void punto2(){
    int minGraduados = 50;
    bool deporteconClaustro2 = false;
    FILE* deportes = fopen("deportes.dat", "rb");
    if (deportes != NULL) {
        FILE* registro = fopen("registro.dat", "wb");
        if (registro!=NULL) {
            Deporte regD;
            while (fread(&regD, sizeof(Deporte), 1, deportes)) {
                if (regD.getTipo() == 1) {
                    int contGraduados = 0;
                    Jugador regJ;
                    FILE* jugadores = fopen("jugadores.dat", "rb");
                    if (jugadores != NULL) {
                        while (fread(&regJ, sizeof(Jugador), 1, jugadores)) {
                            if (regJ.getEstado() == true && regJ.getDeporte() == regD.getID() && regJ.getClaustro() == 2) {
                                contGraduados++;
                            }
                        }
                        fclose(jugadores);
                        if (contGraduados > minGraduados) {
                            Punto2 auxGuardar;
                            auxGuardar.setID(regD.getID());
                            auxGuardar.setNombre(regD.getNombre());
                            auxGuardar.setOrigen(regD.getOrigen());
                            auxGuardar.setCantidadInscriptos(contGraduados);
                            deporteconClaustro2=true;
                           fwrite(&auxGuardar, sizeof(Punto2), 1, registro);
                        }
                    }
                }
            }
            fclose(registro);
        } else {
            cout  << "Error al abrir el archivo ." << endl;
        }

        fclose(deportes);
        if(deporteconClaustro2){
                cout << "Archivo generado " << endl;
            } else {
                cout << "No se encontraron deportes de tipo 1 con mas de 50 graduados inscritos." << endl;
            }
    } else {
        cout  << "Error al abrir el archivo de deportes" << endl;
        return;
    }

}

void mostrarPunto2() {
    FILE* registro = fopen("registro.dat", "rb");

    if (registro != NULL) {
        Punto2 punto2obj;
        while (fread(&punto2obj, sizeof(Punto2), 1, registro)) {
            cout << "ID de deporte: " << punto2obj.getID() << endl;
            cout << "Nombre: " << punto2obj.getNombre() << endl;
            cout << "Anio de origen: " << punto2obj.getOrigen().getYear() << endl;
            cout << "Cantidad de alumnos inscriptos: " << punto2obj.getCantidadInscriptos() << endl;
            cout << "-------------------------" << endl;
        }
        fclose(registro);
    } else {
        cout << "Error al abrir el archivo de registro para lectura." << endl;
    }
}

#endif // REPORTE_H_INCLUDED
