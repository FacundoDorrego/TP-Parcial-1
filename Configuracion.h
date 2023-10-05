//Autor: Facundo Nehuen Dorrego
using namespace std;
#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

void crearBackupJugadores();
void crearBackupDeportes();
void restaurarBackupJugadores();
void restaurarBackupDeportes();
void establecerDatosInicio();

void crearBackupJugadores() {
    FILE* archivoOriginal = fopen("jugadores.dat", "rb");
    if (archivoOriginal == NULL) {
        cout << "Error al abrir el archivo original para lectura." << endl;
        return;
    }
    FILE* archivoBackup = fopen("jugadores.bak", "wb");
    if (archivoBackup == NULL) {
        cout << "Error al abrir el archivo de Backup para escritura." << endl;
        fclose(archivoOriginal);
        return;
    }
    Jugador backup;
    size_t bytesLeidos;
    do {
        bytesLeidos = fread(&backup, sizeof(backup), 1, archivoOriginal);
        if (bytesLeidos > 0) {
            fwrite(&backup, sizeof(backup), 1, archivoBackup);
        }
    } while (bytesLeidos > 0);
    fclose(archivoOriginal);
    fclose(archivoBackup);

    cout << "Copia de seguridad (.bak) creada con exito." << endl;
}

void crearBackupDeportes() {
    FILE* archivoOriginal = fopen("deportes.dat", "rb");
    if (archivoOriginal == NULL) {
        cout << "Error al abrir el archivo original para lectura." << endl;
        return;
    }
    FILE* archivoBackup = fopen("deportes.bak", "wb");
    if (archivoBackup == NULL) {
        cout << "Error al abrir el archivo de Backup para escritura." << endl;
        fclose(archivoOriginal); 
        return;
    }
    Deporte backup;
    size_t bytesLeidos;
    do {
        bytesLeidos = fread(&backup, sizeof(backup), 1, archivoOriginal);
        if (bytesLeidos > 0) {
            fwrite(&backup, sizeof(backup), 1, archivoBackup);
        }
    } while (bytesLeidos > 0);
    fclose(archivoOriginal);
    fclose(archivoBackup);

    cout << "Copia de seguridad (.bak) creada con exito." << endl;
}

void restaurarBackupJugadores() {
    FILE* archivoBackup = fopen("jugadores.bak", "rb");
    if (archivoBackup == NULL) {
        cout << "Error al abrir el archivo de Backup para Lectura." << endl;
        return;
    }
    FILE* archivoOriginal = fopen("jugadores.dat", "wb");
    if (archivoOriginal == NULL) {
        cout << "Error al abrir el archivo original para Escritura." << endl;
        fclose(archivoBackup);
        return;
    }
    Jugador backup;
    size_t bytesLeidos = fread(&backup, sizeof(backup), 1, archivoBackup);
    while (bytesLeidos > 0) {
        fwrite(&backup, sizeof(backup), 1, archivoOriginal);
        bytesLeidos = fread(&backup, sizeof(backup), 1, archivoBackup);
    }
    fclose(archivoOriginal);
    fclose(archivoBackup);

    cout << "Copia de seguridad (.bak) restaurada con exito." << endl;
}

void restaurarBackupDeportes() {
    FILE* archivoBackup = fopen("deportes.bak", "rb");
    if (archivoBackup == NULL) {
        cout << "Error al abrir el archivo de Backup para Lectura." << endl;
        return;
    }

    FILE* archivoOriginal = fopen("deportes.dat", "wb");
    if (archivoOriginal == NULL) {
        cout << "Error al abrir el archivo original para Escritura." << endl;
        fclose(archivoBackup);
        return;
    }
    Deporte backup;
    size_t bytesLeidos = fread(&backup, sizeof(backup), 1, archivoBackup);
    while (bytesLeidos > 0) {
        fwrite(&backup, sizeof(backup), 1, archivoOriginal);
        bytesLeidos = fread(&backup, sizeof(backup), 1, archivoBackup);
    }
    fclose(archivoOriginal);
    fclose(archivoBackup);

    cout << "Copia de seguridad (.bak) restaurada con exito." << endl;
}

void establecerDatosInicio() {
    FILE* archivoIniJ = fopen("jugadores.ini", "rb");
    if (archivoIniJ == NULL) {
        cout << "Error al abrir el archivo Ini para lectura." << endl;
        return;
    }
    FILE* archivoOriginalJ = fopen("jugadores.dat", "wb");
    if (archivoOriginalJ == NULL) {
        cout << "Error al abrir el archivo de Original para escritura." << endl;
        fclose(archivoIniJ);
        return;
    }
    FILE* archivoIniD = fopen("deportes.ini", "rb");
    if (archivoIniD == NULL) {
        cout << "Error al abrir el archivo Ini para lectura." << endl;
        return;
    }
    FILE* archivoOriginalD = fopen("deportes.dat", "wb");
    if (archivoOriginalD == NULL) {
        cout << "Error al abrir el archivo de Original para escritura." << endl;
        fclose(archivoIniD);
        return;
    }
    Jugador iniJ;
    Deporte iniD;
    size_t bytesLeidosJ;
    size_t bytesLeidosD;
    do {
        bytesLeidosJ = fread(&iniJ, sizeof(iniJ), 1, archivoIniJ);
        if (bytesLeidosJ > 0) {
            fwrite(&iniJ, sizeof(iniJ), 1, archivoOriginalJ);
        }
    } while (bytesLeidosJ > 0);
    do {
        bytesLeidosD = fread(&iniD, sizeof(iniD), 1, archivoIniD);
        if (bytesLeidosD > 0) {
            fwrite(&iniD, sizeof(iniD), 1, archivoOriginalD);
        }
    } while (bytesLeidosD > 0);
    fclose(archivoIniJ);
    fclose(archivoOriginalJ);
    fclose(archivoIniD);
    fclose(archivoOriginalD);

    cout << "Copia de seguridad (.bak) creada con exito." << endl;
}

#endif // CONFIGURACION_H_INCLUDED
