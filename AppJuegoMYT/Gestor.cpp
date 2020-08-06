#include "Gestor.h"

string Gestor::insertarJugadorALista(string pjugador) {
	bool msg;
	string resp;
	msg = listaJugadores.agregarAlInicio(pjugador);
	if (msg) {
		resp = "Jugador registrado correctamente.";
	}
	else {
		resp = "Jugador no se pudo agregar. Intente de nuevo.";
	}
	return resp;
}