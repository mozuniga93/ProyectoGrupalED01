#include "Pila.h"
#include "stddef.h"
#include <string>
using namespace std;

Pila::Pila(void) {
	longitud = 0;
	tope = NULL;
}
int Pila::getLongitud(void) const { 
	return longitud;
}
NodoCarta* Pila::getTope(void) const { 
	return tope;
}
void Pila::setLongitud(int longitud) { 
	longitud = longitud;
}

void Pila::setTope(NodoCarta* tope) { 
	tope = tope;
}

bool Pila::popElem() {
	NodoCarta* aux;
	if (!(this->esVacia())) {
		aux = tope;
		tope = tope->getSig();
		longitud--;
		delete aux;
		return true;
	}
	else {
		return false;
	}
}

bool Pila::pushElem(Carta pcarta) {
	NodoCarta* nuevo = new NodoCarta(pcarta);
	if (nuevo == NULL) {
		return false;
	}
	else {
		if (this->esVacia()) {
			tope = nuevo;
		}
		else {
			nuevo->setSig(tope);
			tope = nuevo;
		}
		longitud++;
		return true;
	}
}

bool Pila::esVacia() {
	bool pilaVacia = false;
	if (getTope() == NULL) {
		pilaVacia = true;
	}
	return pilaVacia;
}

Carta Pila::pasarPilaACola() {
	NodoCarta* aux;
	Carta carta;
	if (!(this->esVacia())) {
		aux = tope;
		carta = tope->getCarta();
		tope = tope->getSig();
		longitud--;
		delete aux;
	}
	return carta;
}

Carta Pila::obtenerCartaTope() {
	NodoCarta* aux;
	Carta carta;
	if (!(this->esVacia())) {
		aux = tope;
		carta = tope->getCarta();
	}
	return carta;
}