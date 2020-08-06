#include "Lista.h"
#include "stddef.h"
#include <string>
using namespace std;

Lista::Lista()
{
    setCabeza(NULL);
    setLongitud(0);
}

NodoJugador* Lista::getCabeza() const {
    return cabeza;
}
void Lista::setCabeza(NodoJugador* cabeza) {
    Lista::cabeza = cabeza;
}

int Lista::getLongitud() {
    return longitud;
}
void Lista::setLongitud(int longitud) {
    Lista::longitud = longitud;
}

std::string Lista::recorrerListaEnlazada() {
    string rslt = "";
    if (getCabeza() == NULL) {
        rslt = "Lista vacia";
    }
    else {
        NodoJugador* aux = getCabeza();
        int contador = 1;
        do {
            rslt += "Nombre del jugador #" + to_string(contador) + " =" + aux->getJugador() + "\n";
            aux = aux->getSig();
            contador++;
        } while (aux != NULL);
    }
    return rslt;
}

bool Lista::agregarAlInicio(string pjugador) {
    NodoJugador* nuevo = new NodoJugador();
    nuevo->setJugador(pjugador);
    if (getCabeza() == NULL) {
        setCabeza(nuevo);
    }
    else {
        nuevo->setSig(this->cabeza);
        setCabeza(nuevo);
    }
    setLongitud(getLongitud() + 1);
    return true;
}

int Lista::buscarPosicionJugador(string pjugador) {
    NodoJugador* aux;
    int pos;
    for (aux = getCabeza(), pos = 1; aux != NULL; aux = aux->getSig(), pos++) {
        if (aux->getJugador() == pjugador) {
            return pos;
        }
    }
    if (aux == 0) {
        pos = -1;
    }
    return pos;
}

bool Lista::eliminarJugador(string pjugador) {
    NodoJugador* aux, * ant;
    int i, pos = buscarPosicionJugador(pjugador);
    if (pos == -1) {
        return false;
    }
    else {
        for (i = 1, ant = 0, aux = getCabeza(); i < pos; i++) {
            ant = aux;
            aux = aux->getSig();
        }

        if (ant != 0) {
            ant->setSig(aux->getSig());
        }
        else {
            setCabeza(aux->getSig());
        }

        delete aux;
        setLongitud(getLongitud() - 1);
        return true;
    }
}


bool Lista::eliminarJugadorPorPosicion(int pPosicion) {
    NodoJugador* aux, * ant;
    int i;
    if (getCabeza() == NULL) {
        return false;
    }
    else {
        for (i = 1, ant = 0, aux = getCabeza(); aux->getSig() != NULL, i < pPosicion; i++) {
            ant = aux;
            aux = aux->getSig();
        }

        if (ant != 0) {
            ant->setSig(aux->getSig());
        }
        else {
            setCabeza(aux->getSig());
        }

        delete aux;
        setLongitud(getLongitud() - 1);
        return true;
    }
}

bool Lista::verificarListaVacia() {
    if (getCabeza() == NULL) {
        return true;
    }
    else {
        return false;
    }
}

