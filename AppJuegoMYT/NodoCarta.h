#ifndef NODOCARTA_H
#define NODOCARTA_H
#include "Carta.h"

class NodoCarta
{
public:
    NodoCarta();
    NodoCarta(Carta, NodoCarta* sig);
    NodoCarta(Carta);

    Carta getCarta() const;
    void setCarta(Carta carta);
    NodoCarta* getSig() const;
    void setSig(NodoCarta* sig);

protected:
    Carta carta;
    NodoCarta* sig;
};

#endif