#ifndef NODOJUGADOR_H
#define NODOJUGADOR_H
#include <string>
using namespace std;

class NodoJugador
{
public:
    NodoJugador();
    NodoJugador(string, NodoJugador* sig);
    NodoJugador(string);

    string getJugador() const;
    void setJugador(string carta);
    NodoJugador* getSig() const;
    void setSig(NodoJugador* sig);

protected:
    string jugador;
    NodoJugador* sig;
};

#endif