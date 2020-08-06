#include "NodoCarta.h"
#include "stddef.h"

NodoCarta::NodoCarta()
{
    setSig(NULL);
}

NodoCarta::NodoCarta(Carta carta, NodoCarta* sig) : carta(carta), sig(sig)
{
}

NodoCarta::NodoCarta(Carta carta) : carta(carta), sig(NULL)
{
}

Carta NodoCarta::getCarta() const {
    return carta;
}
void NodoCarta::setCarta(Carta carta) {
    NodoCarta::carta = carta;
}

NodoCarta* NodoCarta::getSig() const {
    return sig;
}
void NodoCarta::setSig(NodoCarta* sig) {
    NodoCarta::sig = sig;
}
