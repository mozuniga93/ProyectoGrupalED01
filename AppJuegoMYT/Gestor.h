#ifndef GESTOR_H
#define GESTOR_H
#include "NodoJugador.h"
#include "NodoCarta.h"
#include "Lista.h"
#include "Pila.h"
#include "Cola.h"
#include <string>
using namespace std;

class Gestor
{
private:
    Lista listaJugadores;
    Cola colaJugador1;
    Cola colaJugador2;
    Pila pilaCentro;
    Pila pilaCartas;

public:
    //METODOS TRACY
    string insertarJugadorALista(string);
    //METODOS MONICA

    //METODOS YESLIN
};

#endif