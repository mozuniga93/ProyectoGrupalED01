#include "NodoJugador.h"
#include "stddef.h"

NodoJugador::NodoJugador()
{
    setSig(NULL);
}

NodoJugador::NodoJugador(string jugador, NodoJugador* sig) : jugador(jugador), sig(sig)
{
}

NodoJugador::NodoJugador(string jugador) : jugador(jugador), sig(NULL)
{
}

string NodoJugador::getJugador() const {
    return jugador;
}
void NodoJugador::setJugador(string jugador) {
    NodoJugador::jugador = jugador;
}

NodoJugador* NodoJugador::getSig() const {
    return sig;
}
void NodoJugador::setSig(NodoJugador* sig) {
    NodoJugador::sig = sig;
}
