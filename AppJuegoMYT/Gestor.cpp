#include "Gestor.h"

void Gestor::pasarCartasBarajadasAPilaCartas() {
	//Se crea el mazo (array) de cartas pero de manera ordenada.
	crearMazoCartas();
	//Se rebaja el mazo de cartas de manera random.
	rebajarCartas();
	//Ahora se debe pasar del array cartasBarajadas a la pila pilaCentro

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

void  Gestor::pasarPilaCartasAColas() {
	Carta carta = Carta();
	for (int j = 0; j < 7; j++) {
		carta = pilaCartas.pasarPilaACola();
		colaJugador1.insertarElem(carta);
	}
	for (int j = 0; j < 7; j++) {
		carta = pilaCartas.pasarPilaACola();
		colaJugador2.insertarElem(carta);
	}
}

bool  Gestor::validarColaNoVacia(int pjugador) {
	bool rslt = false;
	if (pjugador == 1) {
		rslt = colaJugador1.esVacia();
	}
	else {
		rslt = colaJugador2.esVacia();
	}
	return rslt;
}

int Gestor::cantidadCartasCola(int pjugador) {
	int resp = 0;
	if (pjugador == 1) {
		resp = colaJugador1.getLongitud();
	}
	else {
		resp = colaJugador2.getLongitud();
	}
	return resp;
}

string Gestor::nombreJugador(int pjugador) {
	string resp = "";
	if (pjugador == 1) {
		resp = listaJugadores.buscarJugadorPosicion(2);
	}
	else {
		resp = listaJugadores.buscarJugadorPosicion(1);
	}
	return resp;
}

bool Gestor::validarPilaCentroNoVacia() {
	bool rslt;
	rslt = pilaCentro.esVacia();
	return rslt;
}

int Gestor::cantidadCartasPilaCentro() {
	int resp = 0;
	resp = pilaCentro.getLongitud();
	return resp;
}

int Gestor::cantidadCartasPilaCartas() {
	int resp = 0;
	resp = pilaCartas.getLongitud();
	return resp;
}

void Gestor::pasarCartasBarajadasAPilaCartas2() {
	//Se crea el mazo (array) de cartas pero de manera ordenada.
	crearMazoCartas();
	//Se rebaja el mazo de cartas de manera random.
	rebajarCartas();
	//Ahora se debe pasar del array cartasBarajadas a la pila pilaCentro

	for (int i = 0; i < (sizeof(cartasBarajadas) / sizeof(*cartasBarajadas)); i++) {
		pilaCartas.pushElem(cartasBarajadas[i]);
	}

}

int Gestor::tirarCartaAlCentro(int pjugador) {
	Carta cartaJugador = Carta();
	Carta cartaTopePilaCentro = Carta();
	cartaTopePilaCentro = pilaCentro.obtenerCartaTope();
	int valorCartaTope = cartaTopePilaCentro.getNumero();
	int valorAnt = valorCartaTope - 1;
	int valorPos = valorCartaTope + 1;
	int puntosObtenidos = 0;

	if (pjugador == 1) {
		cartaJugador = colaJugador1.pasarColaAPila();
	}
	else {
		cartaJugador = colaJugador2.pasarColaAPila();
	}

	if (cartaJugador.getNumero() == valorAnt) {
		puntosObtenidos = 1;
	}
	else if (cartaJugador.getNumero() == valorPos) {
		puntosObtenidos = 1;
	}
	else if (cartaJugador.getNumero() == valorCartaTope) {
		puntosObtenidos = 2;
	}
	pilaCentro.pushElem(cartaJugador);
	return puntosObtenidos;
}

void Gestor::imprimirTablero(int pjugador) {
	string carta = "";
	Carta cartaTopePilaCentro = Carta();
	cartaTopePilaCentro = pilaCentro.obtenerCartaTope();
	int valorCartaTope = cartaTopePilaCentro.getNumero();
	string signo = cartaTopePilaCentro.getSigno();
	int cartasCola = cantidadCartasCola(pjugador);
	int cartasPilaCartas = cantidadCartasPilaCartas();

	if (!validarPilaCentroNoVacia()) {
		if (valorCartaTope == 1) {
			carta = "A    ";
		}
		else if (valorCartaTope == 11) {
			carta = "J    ";
		}
		else if (valorCartaTope == 12) {
			carta = "Q    ";
		}
		else if (valorCartaTope == 13) {
			carta = "K    ";
		}
		else {
			carta += to_string(valorCartaTope) + "     ";
		}
	}
	else {
		carta = "-------";
		signo = "-------";
	}

		cout << "_________________________________________________________________________________________" << endl;
		cout << "                                ESTATUS DEL JUEGO " << endl;
		cout << "_________________________________________________________________________________________" << endl;
		cout << " COLA DEL JUGADOR                    PILA DEL CENTRO                    PILA DE CARTA" << endl;
		cout << "  Cant cartas                           " << carta << "                          Cant cartas" << endl;
		cout << "       "<<cartasCola<< "                                " << signo << "                                " << cartasPilaCartas << endl;
		cout << "_________________________________________________________________________________________" << endl;
	
}