#ifndef FUNGLOBALES_H_INCLUDED
#define FUNGLOBALES_H_INCLUDED
#include <iostream>
#include <cstring>
#include "functpn1.h"

//Prototipos
void cargaDeDatos(Persona *v, int cant);
void muestraDeDatos(Persona *v, int cant);

void cargaDeDatos(Persona *v, int cant){
    for(int i=0;i<cant;i++){
        v[i].CargarDatos();
        cout<<endl;
    }
}

void muestraDeDatos(Persona *v, int cant){
    for(int i=0;i<cant;i++){
        v[i].MostrarDatos();
        cout<<endl;
    }
}

#endif // FUNGLOBALES_H_INCLUDED
