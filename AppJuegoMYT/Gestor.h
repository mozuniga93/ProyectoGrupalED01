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
    void pasarPilaCartasAColas();
    bool validarColaNoVacia(int);
    int cantidadCartasCola(int);
    string nombreJugador(int);
    bool validarPilaCentroNoVacia();
    bool validarPilaCartasNoVacia();
    int cantidadCartasPilaCentro();
    int cantidadCartasPilaCartas();
    int tirarCartaAlCentro(int);
    int tomarCartaPilaCartas(int);
    void imprimirTablero(int, string, int);
    //METODOS YESLIN
};

#endif