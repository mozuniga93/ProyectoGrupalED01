#include "Carta.h"
#include "stddef.h"

Carta::Carta()
{
    setNumero(0);
    setSigno("");

}

Carta::Carta(int numero, string signo) : numero(numero), signo(signo)
{

}

int Carta::getNumero() {
    return numero;
}
void Carta::setNumero(int numero) {
    Carta::numero = numero;
}
string Carta::getSigno() {
    return signo;
}
void Carta::setSigno(string signo) {
    Carta::signo = signo;
}
