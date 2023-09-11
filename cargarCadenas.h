#ifndef CARGARCADENAS_H_INCLUDED
#define CARGARCADENAS_H_INCLUDED
#include <iostream>
#include <cstring>
using namespace std;

void cargarCadenas(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\o';
    fflush(stdin);
}

#endif // CARGARCADENAS_H_INCLUDED
