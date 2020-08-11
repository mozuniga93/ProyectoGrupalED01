#include "Gestor.h"

void Gestor::pasarCartasBarajadasAPilaCartas() {
	//Se crea el mazo (array) de cartas pero de manera ordenada.
	//crearMazoCartas();
	//Se rebaja el mazo de cartas de manera random.
	//rebajarCartas();
	//Ahora se debe pasar del array cartasBarajadas a la pila pilaCentro
	for (int i = 0; i < 52; i++) {
		pilaCentro.pushElem(cartasBarajadas[i]);
		//cartasBarajadas[i] = cartasOrdenadas[posicionesAleatorias[i]];
	}
}


void Gestor::crearMazoCartas() {
	string signos[4] = { "Corazon", "Diamante", "Pica", "Trebol" };
	int limiteCarta = 13;
	string signo = "";

	for (int i = 0; i < (sizeof(signos)/sizeof(*signos)); i++) {
		for (int j = 0; j < limiteCarta; j++) {
			cartasOrdenadas[(i*limiteCarta)+j] = Carta(j+1, signos[i]);
		}
	}
	cout << "Listo ";
}

void Gestor::rebajarCartas() {
	arregloAleatorio();
	for (int i = 0; i < 52; i++) {
		cartasBarajadas[i] = cartasOrdenadas[posicionesAleatorias[i]];
	}

}

void Gestor::arregloAleatorio() {
	int numRandom;
	for (int i = 0; i < (sizeof(posicionesAleatorias) / sizeof(*posicionesAleatorias)); i++) {
		posicionesAleatorias[i] = i;
	}
	std::srand(std::time(0));
	random_shuffle(&posicionesAleatorias[0], &posicionesAleatorias[52]);
}

void Gestor::imprimirCartas() {
	string carta = "";
	for (int i = 0; i < (sizeof(cartasOrdenadas) / sizeof(*cartasOrdenadas)); i++) {
		if (cartasOrdenadas[i].getNumero() == 1) {
			carta = "A";
		}
		else if (cartasOrdenadas[i].getNumero() == 11) {
			carta = "J";
		}
		else if (cartasOrdenadas[i].getNumero() == 12) {
			carta = "Q";
		}
		else if (cartasOrdenadas[i].getNumero() == 13) {
			carta = "K";
		}
		else {
			carta = to_string(cartasOrdenadas[i].getNumero());
		}
		cout << "Posicion (" + to_string(i + 1) + "): " + carta << " " << cartasOrdenadas[i].getSigno() + "\n";
	}
}

void Gestor::imprimirCartasBarajadas() {
	string carta = "";
	for (int i = 0; i < (sizeof(cartasBarajadas) / sizeof(*cartasBarajadas)); i++) {
		if (cartasBarajadas[i].getNumero() == 1) {
			carta = "A";
		}
		else if (cartasBarajadas[i].getNumero() == 11) {
			carta = "J";
		}
		else if (cartasBarajadas[i].getNumero() == 12) {
			carta = "Q";
		}
		else if (cartasBarajadas[i].getNumero() == 13) {
			carta = "K";
		}
		else {
			carta = to_string(cartasBarajadas[i].getNumero());
		}
		cout << "Posicion (" + to_string(i+1) + "): " + carta << " " << cartasBarajadas[i].getSigno() + "\n";
	}
}

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