// Proyecto grupal: juego MYT
#include <iostream>
#include <iomanip>
#include <string>
#include "Gestor.h"

using namespace std;

//PROTOTIPO DE MENUS
void imprimirMenuPrincipal();
int menuPrincipal(int);
void imprimirMenuTurno(int);
int menuTurno(int);

//PROTOTIPOS METODOS DEL JUEGO
void iniciarJuego();
void tomarCartaPilaCentro();
void tirarCarta();
void mostrarCartasDisponiblesCola();
void mostrarMejoresRecords();
void guardarGanadores();

//VARIABLES ESTATICAS
static Gestor* gestor = new Gestor();
static int jugadorActual = 1;
static string nombreJugadorActual;
static int puntuacionJugador1 = 0;
static int puntuacionJugador2 = 0;

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

void imprimirMenuTurno(int pjugadorTurnoActual)
{
    int answer;
    bool keepLooping = true;

    do
    {
        cout << "-------------------------------------" << endl;
        cout << "Favor digite una opcion:" << endl;
        cout << "1. Tomar una carta de pila de cartas." << endl;
        cout << "2. Tirar una carta al centro ." << endl;
        cout << "0. Salir." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;

        menuTurno(answer);

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

int menuTurno(int answer)
{
    switch (answer)
    {
    case 1:
        tomarCartaPilaCentro();
        break;
    case 2:
        tirarCarta();
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
    string jugador1;
    string jugador2;
    cout << "Favor digite el nombre del jugador 1: " << flush;
    cin >> jugador1;
    cout << gestor->insertarJugadorALista(jugador1) << endl;
    cout << "Favor digite el nombre del jugador 2: " << flush;
    cin >> jugador2;
    cout << gestor->insertarJugadorALista(jugador2) << endl;

    imprimirMenuTurno(1);  
}

void tomarCartaPilaCentro() {
    cout << "Tomaste una carta del centro." << endl;
}

void mostrarCartasDisponiblesCola() {

}

void tirarCarta() {
    cout << "Tiraste una carta al centro." << endl;
}

void mostrarMejoresRecords() {

}

void guardarGanadores() {

}
