#ifndef GESTOR_H
#define GESTOR_H
#include "NodoJugador.h"
#include "NodoCarta.h"
#include "Lista.h"
#include "Pila.h"
#include "Cola.h"
#include "Carta.h"
#include <string>
#include <algorithm> 
#include <iostream>
#include <iomanip>
#include <vector> 
using namespace std;

class Gestor
{
private:
    Lista listaJugadores;
    Cola colaJugador1;
    Cola colaJugador2;
    Pila pilaCentro;
    Pila pilaCartas;
    Carta cartasOrdenadas[52] = {};
    Carta cartasBarajadas[52] = {};
    int posicionesAleatorias[52] = {};

public:
    //METODOS TRACY
    void crearMazoCartas();
    void rebajarCartas();
    void arregloAleatorio();
    void pasarCartasBarajadasAPilaCartas();
    string insertarJugadorALista(string);
    void imprimirCartas();
    void imprimirCartasBarajadas();
    //METODOS MONICA
    void pasarCartasBarajadasAPilaCartas2();
    void pasarPilaCartasAColas();
    bool validarColaNoVacia(int pjugador);
    int cantidadCartasCola(int pjugador);
    string nombreJugador(int pjugador);
    bool validarPilaCentroNoVacia();
    int cantidadCartasPilaCentro();
    int cantidadCartasPilaCartas();
    int tirarCartaAlCentro(int pjugador);
    void imprimirTablero(int pjugador);
    //METODOS YESLIN
};

#endif