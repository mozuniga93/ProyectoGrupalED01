// Proyecto grupal: juego MYT
#include <iostream>
#include <iomanip>
#include <string>
#include "Gestor.h"
//prueba del repo

using namespace std;

//PROTOTIPO DE MENUS
void imprimirMenuPrincipal();
int menuPrincipal(int);
void imprimirMenuTurno(int,int);
void validarTurno(int);
int menuTurno(int,int);

//PROTOTIPOS METODOS DEL JUEGO
void iniciarJuego();
void tomarCartaPilaCentro();
void tirarCarta(int);
void mostrarCartasDisponiblesCola();
void mostrarMejoresRecords();
void guardarGanadores();
string nombreJugadorTurnoActual(int);

//VARIABLES ESTATICAS
static Gestor* gestor = new Gestor();
static int jugadorActual = 1;
static string nombreJugadorActual;
static int puntuacionJugador1 = 0;
static int puntuacionJugador2 = 0;
static string nombreJugador1;
static string nombreJugador2;

int main()
{
    imprimirMenuPrincipal();
}

//MENUS
void imprimirMenuPrincipal()
{
    int answer;
    bool keepLooping = true;

    do
    {
        cout << "-------------------------------------" << endl;
        cout << "    MENU PRINCIPAL DEL JUEGO" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Favor digite opcion:" << endl;
        cout << "1. Iniciar juego." << endl;
        cout << "2. Mostrar mejores records." << endl;
        cout << "0. Salir." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;

        menuPrincipal(answer);

        if (answer == 0)
        {
            keepLooping = false;
        }
        else
        {
            keepLooping = true;
        }
    } while (keepLooping);

}

int menuPrincipal(int answer)
{
    switch (answer)
    {
    case 1:
        iniciarJuego();
        break;
    case 2:
        mostrarMejoresRecords();
        break;
    case 0:
        cout << "Gracias por usar el sistema." << endl;
        break;
    default:
        cout << "Opcion incorrecta. Favor digite de nuevo." << endl;
    }
    return answer;
}

void imprimirMenuTurno(int popcion, int pjugadorTurnoActual) {
    int answer;
    bool keepLooping = true;
    do
    {
        cout << "-------------------------------------" << endl;
        cout << "Turno del jugador " << nombreJugadorTurnoActual(pjugadorTurnoActual) << endl;
        cout << "-------------------------------------" << endl;
        cout << "Favor digite una opcion:" << endl;
        cout << "1. Tomar una carta de pila de cartas." << endl;
        cout << "2. Tirar una carta al centro ." << endl;
        cout << "0. Salir." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;

        menuTurno(answer, pjugadorTurnoActual);

        if (answer == 0)
        {
            keepLooping = false;
        }
        else
        {
            keepLooping = true;
        }
    } while (keepLooping);
}

void validarTurno(int pjugadorTurnoActual)
{
    int cantCartasPilaCentro = gestor->cantidadCartasPilaCentro();
    int cantCartasPilaCartas = gestor->cantidadCartasPilaCartas();
    int cantCartasCola = gestor->cantidadCartasCola(pjugadorTurnoActual);
    gestor->imprimirTablero(pjugadorTurnoActual);
    if (cantCartasPilaCentro == 52) {

    }
    else {
        if (cantCartasCola>0 && cantCartasPilaCartas >0) {
            imprimirMenuTurno(1, pjugadorTurnoActual);
        }
        else if (cantCartasCola == 0 && cantCartasPilaCentro>0) {
            
        }
        else if (cantCartasCola>0 && cantCartasPilaCentro == 0) {
           
        }
    }
}

int menuTurno(int answer, int pjugador)
{
    switch (answer)
    {
    case 1:
        tomarCartaPilaCentro();
        break;
    case 2:
        tirarCarta(pjugador);
        break;
    case 0:
        cout << "Gracias por usar el sistema." << endl;
        break;
    default:
        cout << "Opcion incorrecta. Favor digite de nuevo." << endl;
    }
    return answer;
}

//METODOS DEL JUEGO
void iniciarJuego()
{
    cout << "Favor digite el nombre del jugador 1: " << flush;
    cin >> nombreJugador1;
    cout << gestor->insertarJugadorALista(nombreJugador1) << endl;
    cout << "Favor digite el nombre del jugador 2: " << flush;
    cin >> nombreJugador2;
    cout << gestor->insertarJugadorALista(nombreJugador2) << endl;

    gestor->pasarCartasBarajadasAPilaCartas2();
    gestor->pasarPilaCartasAColas();
    validarTurno(1);  
}

void tomarCartaPilaCentro() {
    cout << "Tomaste una carta de la pila." << endl;
}

void mostrarCartasDisponiblesCola() {

}

void tirarCarta(int pJugador) {
    int puntosObtenidos = gestor->tirarCartaAlCentro(pJugador);
    cout << "Puntos obtenidos: " << puntosObtenidos << endl;
    if (pJugador == 1) {
        validarTurno(2);
    }
    else {
        validarTurno(1);
    }
}

void mostrarMejoresRecords() {

}

void guardarGanadores() {

}

string nombreJugadorTurnoActual(int pjugadorTurnoActual) {
    string nombreJugadorActual = "";
    if (pjugadorTurnoActual == 1) {
        nombreJugadorActual = nombreJugador1;
    }
    else {
        nombreJugadorActual = nombreJugador2;
    }
    return nombreJugadorActual;
}