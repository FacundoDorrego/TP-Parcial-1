#ifndef FUNGLOBALES_H_INCLUDED
#define FUNGLOBALES_H_INCLUDED
#include <iostream>
#include <cstring>
#include "Jugador.h"

//Prototipos
void cargaDeDatos(Jugador *v, int cant);
void muestraDeDatos(Jugador *v, int cant);

void cargaDeDatos(Jugador *v, int cant){
    for(int i=0;i<cant;i++){
        v[i].CargarDatos();
        cout<<endl;
    }
}

void muestraDeDatos(Jugador *v, int cant){
    for(int i=0;i<cant;i++){
        v[i].MostrarDatos();
        cout<<endl;
    }
}

#endif // FUNGLOBALES_H_INCLUDED
