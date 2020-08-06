#include "Cola.h"
#include "stddef.h"
#include <string>
using namespace std;

Cola::Cola(void) {
	frente = NULL;
	final = NULL;
	longitud = 0;
}

int Cola::getLongitud(void) const {
	return longitud;
}
NodoCarta* Cola::getFrente(void) const { 
	return frente;
}
NodoCarta* Cola::getFinal(void) const { 
	return final;
}
void Cola::setLongitud(int longitud) {
	longitud = longitud;
}

void Cola::setFrente(NodoCarta* frente) { 
	frente = frente;
}
void Cola::setFinal(NodoCarta* final) {
	final = final;
}

void Cola::insertarElem(Carta pcarta) {
	NodoCarta* nuevo = new NodoCarta(pcarta);
	if (this->esVacia()) {
		frente = nuevo;
		final = nuevo;
	}
	else {
		final->setSig(nuevo);
		final = nuevo;
	}
	longitud++;
}

bool Cola::esVacia() {
	bool colaVacia = false;
	if (getFrente() == NULL && getFinal() == NULL) {
		colaVacia = true;
	}
	return colaVacia;
}

bool Cola::eliminarElem() {
	NodoCarta* aux;
	if (!(this->esVacia())) {
		aux = frente;
		frente = frente->getSig();
		longitud--;
		delete aux;
		return true;
	}
	else {
		return false;
	}
}

Carta Cola::pasarColaAPila() {
	NodoCarta* aux;
	Carta carta;
	if (!(this->esVacia())) {
		aux = frente;
		carta = frente->getCarta();
		frente = frente->getSig();
		longitud--;
		delete aux;
	}
	return carta;
}