#ifndef LISTA_H
#define LISTA_H
#include "NodoJugador.h"
#include <string>
using namespace std;

class Lista
{
public:
    Lista();

    NodoJugador* getCabeza() const;
    void setCabeza(NodoJugador* cabeza);
    int getLongitud();
    void setLongitud(int);

    bool agregarAlInicio(string);
    string recorrerListaEnlazada();
    bool eliminarJugador(string);
    int buscarPosicionJugador(string);
    bool eliminarJugadorPorPosicion(int);
    bool verificarListaVacia();
    string buscarJugadorPosicion(int);

protected:
    NodoJugador* cabeza;
    int longitud;
};

#endif