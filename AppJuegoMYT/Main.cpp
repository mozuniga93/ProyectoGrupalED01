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
int menuTurno(int,int,int);
void imprimirMenuFinalJuego();


//PROTOTIPOS METODOS DEL JUEGO
void iniciarJuego();
void tomarCartaPilaCentro(int);
void tirarCarta(int);
void mostrarCartasDisponiblesCola();
void mostrarMejoresRecords();
void guardarGanadores();
string nombreJugadorTurnoActual(int);
int puntosJugadorTurnoActual(int);
void terminarJuego();
int menuFinalJuego(int);

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
        if (popcion == 1) {
        cout << "1. Tomar una carta de pila de cartas." << endl;
        cout << "2. Tirar una carta al centro." << endl;
        }
        else if (popcion == 2) {
        cout << "1. Tomar una carta de pila de cartas." << endl;
        }
        else if (popcion == 3) {
        cout << "1. Tirar una carta al centro." << endl;
        }
        cout << "0. Salir." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;

        menuTurno(answer, popcion, pjugadorTurnoActual);

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
 
    if (cantCartasPilaCentro == 52) {
            terminarJuego();
    }
    else {
        if (cantCartasCola > 0 && cantCartasPilaCartas > 0) {
            gestor->imprimirTablero(pjugadorTurnoActual, nombreJugadorTurnoActual(pjugadorTurnoActual), puntosJugadorTurnoActual(pjugadorTurnoActual));
            imprimirMenuTurno(1, pjugadorTurnoActual);
        }
        else if (cantCartasCola == 0 && cantCartasPilaCartas > 0) {
            gestor->imprimirTablero(pjugadorTurnoActual, nombreJugadorTurnoActual(pjugadorTurnoActual), puntosJugadorTurnoActual(pjugadorTurnoActual));
            imprimirMenuTurno(2, pjugadorTurnoActual);
        }
        else if (cantCartasCola > 0 && cantCartasPilaCartas == 0) {
            gestor->imprimirTablero(pjugadorTurnoActual, nombreJugadorTurnoActual(pjugadorTurnoActual), puntosJugadorTurnoActual(pjugadorTurnoActual));
            imprimirMenuTurno(3, pjugadorTurnoActual);
        }
        else if (cantCartasCola == 0 && cantCartasPilaCartas == 0) {
            if (pjugadorTurnoActual == 1) {
                validarTurno(2);
            }
            else {
                validarTurno(1);
            }
        }
    }
}

int menuTurno(int answer, int popcion, int pjugador) {
    if (popcion == 1) {
        switch (answer)
        {
        case 1:
            tomarCartaPilaCentro(pjugador);
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
    else if (popcion == 2) {
        switch (answer)
        {
        case 1:
            tomarCartaPilaCentro(pjugador);
            break;
        case 0:
            cout << "Gracias por usar el sistema." << endl;
            break;
        default:
            cout << "Opcion incorrecta. Favor digite de nuevo." << endl;
        }
        return answer;
    }
    else if (popcion == 3) {
        switch (answer)
        {
        case 1:
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
}

void imprimirMenuFinalJuego()
{
    int answer;
    bool keepLooping = true;

    do
    {
        cout << "La partida ha finalizado. Favor digite opcion:" << endl;
        cout << "1. Guardar partida." << endl;
        cout << "2. Terminar partida." << endl;
        cout << "-------------------------------------" << endl;
        cin >> answer;

        menuFinalJuego(answer);

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

int menuFinalJuego(int answer)
{
    switch (answer)
    {
    case 1:
        guardarGanadores();
        break;
    case 2:
        exit(0);
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


    gestor->crearMazoCartas();
    gestor->imprimirCartas();
    gestor->rebajarCartas();
    gestor->pasarCartasBarajadasAPilaCartas();
    //gestor->imprimirCartasBarajadas();
    imprimirMenuTurno(1);  
    cin >> nombreJugador2;
    cout << gestor->insertarJugadorALista(nombreJugador2) << endl;

    gestor->pasarCartasBarajadasAPilaCartas2();
    gestor->pasarPilaCartasAColas();
    validarTurno(1);  
}

void tomarCartaPilaCentro(int pJugador) {
    int puntosObtenidos = gestor->tomarCartaPilaCartas(pJugador);
    if (pJugador == 1) {
        puntuacionJugador1 = puntuacionJugador1 + puntosObtenidos;
        cout << "Puntos obtenidos en este turno del jugador 1: " << puntosObtenidos << endl;
        cout << "Puntos totales del jugador 1: " << puntuacionJugador1 << endl;
        validarTurno(2);
    }
    else {
        puntuacionJugador2 = puntuacionJugador2 + puntosObtenidos;
        cout << "Puntos obtenidos en este turno del jugador 2: " << puntosObtenidos << endl;
        cout << "Puntos totales del jugador 2: " << puntuacionJugador2 << endl;
        validarTurno(1);
    }
}

void mostrarCartasDisponiblesCola() {

}

void tirarCarta(int pJugador) {
    int puntosObtenidos = gestor->tirarCartaAlCentro(pJugador);
    if (pJugador == 1) {
        puntuacionJugador1 = puntuacionJugador1 + puntosObtenidos;
        cout << "Puntos obtenidos en este turno del jugador 1: " << puntosObtenidos << endl;
        cout << "Puntos totales del jugador 1: " << puntuacionJugador1 << endl;
        validarTurno(2);
    }
    else {
        puntuacionJugador2 = puntuacionJugador2 + puntosObtenidos;
        cout << "Puntos obtenidos en este turno del jugador 2: " << puntosObtenidos << endl;
        cout << "Puntos totales del jugador 2: " << puntuacionJugador2 << endl;
        validarTurno(1);
    }
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

int puntosJugadorTurnoActual(int pjugadorTurnoActual) {
    int puntosJugadorActual = 0;
    if (pjugadorTurnoActual == 1) {
        puntosJugadorActual = puntuacionJugador1;
    }
    else {
        puntosJugadorActual = puntuacionJugador2;
    }
    return puntosJugadorActual;
}

void terminarJuego() {
    if (puntuacionJugador1 > puntuacionJugador2) {
        cout << "¡FELICIDAD JUGADOR " << nombreJugadorTurnoActual(1) << " HAS GANADO! Con un total de "<< puntuacionJugador1 << " puntos."<< endl;
    }
    else if (puntuacionJugador2 > puntuacionJugador1) {
        cout << "¡FELICIDAD JUGADOR " << nombreJugadorTurnoActual(2) << " HAS GANADO! Con un total de " << puntuacionJugador2 << " puntos." << endl;
    }
    else if (puntuacionJugador2 == puntuacionJugador1) {
        cout << "Ha sido un empate." << endl;
    }

    imprimirMenuFinalJuego();
}

void mostrarMejoresRecords() {

}

void guardarGanadores() {

}