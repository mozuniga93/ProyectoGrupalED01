#ifndef PILA_H
#define PILA_H
#include "NodoCarta.h"

class Pila
{
public:
    Pila(void); 

    int getLongitud(void) const;
    void setLongitud(int l);
    NodoCarta* getTope(void) const; 
    void setTope(NodoCarta*); 

    bool pushElem(Carta);
    bool popElem();
    Carta pasarPilaACola();
    bool esVacia();

protected:
    int longitud;
    NodoCarta* tope;
};

#endif
