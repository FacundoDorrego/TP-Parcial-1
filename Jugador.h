//Autor: Facundo Nehuen Dorrego
#include <iostream>
#include <cstring>
#include "cargarCadenas.h"
#include "fecha.h"
#include "Deporte.h"
using namespace std;
#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
void ListarTodoJugador();
bool ListarDNIJugador();
int buscarDNIJugador(int docuDni);
bool borrarJugador();
bool modFechaJugador();

class Jugador{
private:
    //atributos
    char nombre[30],apellido[30],email[30],telefono[30];
    int dni,claustro,deporte,numeroequipo;
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
    //Funcion para guardar los datos en su respectivo archivo.
    void guardar() {
        FILE* archivo = fopen("jugadores.dat", "ab");
        if (archivo != NULL) {
            fwrite(this, sizeof(Jugador), 1, archivo);
            fclose(archivo);
        } else {
            cout << "Error al abrir el archivo para escritura." << endl;
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
Jugador leerDNIJugador(int pos);
//Carga de datos
void Jugador::CargarDatos(){
    int day,month,year;
    Deporte reg;
    setEstado(true);
    do {
        int dni;
        cout << "DNI: ";
        cin >> dni;
        //llama a buscarDNIJugador para saber si existe o no dicho dni
        int posExistente = buscarDNIJugador(dni);
        if (posExistente != -1) {
            //en caso de ser distinto a falso el estado, Avisa al usuario y pone el registro en falso para que no se use
            if (getEstado() != false) {
            cout << "El DNI ya existe en el registro. No se permite duplicar DNI." << endl;
            setEstado(false);
            return;
            } 
        }
        //Si pasa la comprobacion, se asigna el DNI
        setDNI(dni);
    }
    while (dni <= 0);
    cout<<"NOMBRE: ";
    cargarCadenas(nombre,30);
    cout << "APELLIDO: ";
    cargarCadenas(apellido, 30);
    cout << "EMAIL: ";
    cargarCadenas(email, 30);
    cout << "TELEFONO: ";
    cargarCadenas(telefono, 30);
    //Comprobacion para que el claustro sea del 1 al 4
    do{
        cout<<"CLAUSTRO: (1: docente; 2 alumno; 3 no docente; 4 graduado) ";
        cin>>claustro;
    }
    while (claustro<=0||claustro>4);
    //Comprobacion para que el deporte sea del 1 al 10
    do{
        cout<<"DEPORTE (1 al 10): ";
        cin>>deporte;
        //Abre deportes.dat en archivoDeportes
        FILE* archivoDeportes = fopen("deportes.dat", "rb");
        if (archivoDeportes != NULL) {
            //Verifica si existe dicha ID en deportes.dat
            int posExistenteID = buscarIDDeporte(deporte);
            //Guarda el registro encontrado en el objeto Reg
            reg=leerID(posExistenteID);
            //Cierra el archivo
            fclose(archivoDeportes);
            //Si no existe el ID o existe pero su estado es falso
            if (posExistenteID == -1||reg.getEstado()==false) {
                cout << "Este ID no se encuentra en el registro de Deportes." << endl;
                setEstado(false);
                return;
                }
            //Error de apertura
            } else {
                cout << "Error al abrir el archivo de deportes para lectura." << endl;
                setEstado(false);
                return;
                }
    //Si pasa las verificaciones, el Deporte es asignado y el archivo se cierra.
    fclose(archivoDeportes);
    } while (deporte<1||deporte>10);
    cout<<"NUMERO DE EQUIPO: ";
    cin>>numeroequipo;
    //Comprobacion de fecha valida
    do {
        cout << "FECHA DE INSCRIPCION (dd/mm/aaaa): ";
        cin >> day >> month >> year;
        //Objeto con la fecha actual
        Fecha fechaActual;
        //Objeto con la fecha ingresada
        Fecha fechaInscripcion(day, month, year);
        //Llama a la funcion esFechaValida() para comparar los valores ingresados.
        //Tambien se comprueba que la fecha ingresada es mayor a la actual.
        if (!fechaInscripcion.esFechaValida() || fechaInscripcion > fechaActual) {
            cout << "La fecha de inscripción no es valida o es mayor que la fecha actual." << endl;
            setEstado(false);
            return;
        }
        //Si pasa la comprobacion, se guarda la fecha.
        setFecha(fechaInscripcion);
    } while (day <= 0 || month <= 0 || year <= 0);
    //Comprobacion de matricula valida (Acepta valor 0 o positivos.)
    do{
        cout<<"MATRICULA: $";
        cin>>matricula;
    } while (matricula<0);
}
//Muestra los datos.
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
//Busca si el DNI se encuentra en jugadores.dat
int buscarDNIJugador(int docuDni){
    //Apertura de archivo
    FILE* archivo = fopen("jugadores.dat", "rb");
    int pos=0;
    if (archivo != NULL) {
        Jugador reg;
        //Lectura de todo el archivo
        while (fread(&reg, sizeof(Jugador), 1, archivo)) {
            //En caso de encontrar el DNI en el registro devuelve esa posicion
            if(docuDni==reg.getDNI()){
                fclose(archivo);
                return pos;
            }
            //En caso de no encontrar el DNI, aumenta la posicion.
            pos++;
        }
    }
    //.2 Significa que no pudo abrir el archivo
    if (archivo == NULL){
        return -2;
    }
    //-1 Significa que no pudo encontrar el ID en el registro
    return -1;
}



bool borrarJugador(){
    int docuDni;
    FILE* archivo = fopen("jugadores.dat", "rb+");
    if(archivo == NULL){
        return false;
    }
    cout<<"Introducir DNI a borrar: ";
    cin>>docuDni;
    //Guarda la posicion del jugador en el registro en pos
    int pos = buscarDNIJugador(docuDni);
    if(pos==-1){
        cout<<"No existe ese DNI"<<endl;
        return false;
    }
    fseek(archivo,pos * sizeof(Jugador),0);
    //Aca guardo el estado falso
    Jugador jugadorborrado;
    jugadorborrado.setEstado(false);
    //Se escribre en el archivo el objeto
    fwrite(&jugadorborrado,sizeof(Jugador),1,archivo);
    fclose(archivo);
    cout<<"Jugador con DNI "<< docuDni <<" borrado exitosamente."<<endl;
    return true;
}

//Modifica la fecha de inscripcion del jugador elegido.
bool modFechaJugador(){
    int docuDni,day,month,year;
    //Apertura de archivo
    FILE* archivo = fopen("jugadores.dat", "rb+");
    if(archivo == NULL){ 
        return false;
    }
    cout<<"Introducir DNI del registro a modificar: ";
    cin>>docuDni;
    //Se guarda la posicion en la que esta el jugador.
    int pos = buscarDNIJugador(docuDni);
    //Si la pos es -1 es porque no se encontro el DNI.
    if(pos==-1){
        cout<<"No existe ese DNI"<<endl;
        return false;
        }
    //crea un objeto para guardar el cambio
    Jugador jugadorfecha;
    //busca en el registro, la posicion en la cual esta el jugador
    fseek(archivo,pos * sizeof(Jugador),0);
    //lee ese registro y se guarda en jugadorfecha
    fread(&jugadorfecha, sizeof(Jugador),1,archivo);
    cout<<"Introducir fecha (DIA,MES,ANIO) "<<endl;
    cin>>day>>month>>year;
    //carga la fecha que se ingreso
    Fecha fechaInscripcion(day,month,year);
    //guarda esa fecha en el objeto jugadorfecha
    jugadorfecha.setFecha(fechaInscripcion);
    //busca la posicion en la que se encontraba dicho jugador
    fseek(archivo,pos * sizeof(Jugador),0);
    //escribe en esa posicion el objeto jugadorfecha con la fecha actualizada
    fwrite(&jugadorfecha,sizeof(Jugador),1,archivo);
    //cierra el archivo.
    fclose(archivo);
    cout<<"La fecha del registro del jugador con DNI "<< docuDni <<" se ha cambiado exitosamente."<<endl;
    return true;
}

//Lista todos los jugadores
void ListarTodoJugador() {
    Jugador reg;
    //Apertura de archivo
    FILE* archivo = fopen("jugadores.dat", "rb");
    if (archivo != NULL) {
        //Lectura de todo el archivo
        while (fread(&reg, sizeof(Jugador), 1, archivo)) {
            //Si el estado es true, muestra los datos
            if(reg.getEstado()==true){
                reg.MostrarDatos();
                cout << "-------------------------" << endl;
                }
            }
        //Cierre de archivo
        fclose(archivo);
        //Mensaje de error
        } else {
            cout << "Error al abrir el archivo para lectura." << endl;
        }
    }
//LeerDNIJugador busca la posicion indicada en el archivo jugadores.dat y devuelve dicho registro.
Jugador leerDNIJugador(int pos) {
    Jugador reg;
    reg.setEstado(false);
    //Abre el archivo
    FILE* archivo = fopen("jugadores.dat", "rb");
    int posLectura = 0;
    //En caso de no poder abrir el archivo
    if (archivo == NULL) {
        cout << "Error al abrir el archivo de lectura";
        return reg;
    }
    while (fread(&reg, sizeof(Jugador), 1, archivo) == 1) {
        //En caso de que pos sea igual a posLectura, cierra el archivo y devuelve ese registro
        if (pos == posLectura) {
            fclose(archivo);
            return reg; 
        }
        //En caso de no encontrar la posicion indicada, aumenta posLectura.
        posLectura++;
    }
    //Cierre de archivo
    fclose(archivo);
    return reg; 
}



bool ListarDNIJugador() {
    int docuDni;
    cout << "Introducir DNI a buscar: ";
    cin >> docuDni;
    FILE* archivo = fopen("jugadores.dat", "rb");
    if (archivo == NULL) {
        cout << "Error al abrir el archivo para lectura." << endl;
        return false;
    }
    Jugador reg;
    bool encontrado = false;
    while (fread(&reg, sizeof(Jugador), 1, archivo) == 1) {
        if (docuDni == reg.getDNI() && reg.getEstado() == true) {
            encontrado = true;
            cout << "DNI encontrado y es el siguiente:" << endl;
            reg.MostrarDatos();
            break; 
        }
    }
    fclose(archivo);
    if (!encontrado) {
        cout << "El DNI no existe o no esta habilitado" << endl;
    }

    return encontrado;
}
#endif // JUGADOR_H_INCLUDED
