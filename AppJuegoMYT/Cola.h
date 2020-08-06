#ifndef COLA_H
#define COLA_H
#include "NodoCarta.h"

class Cola
{
public:
  
    Cola(void); 

    NodoCarta* getFrente(void) const; 
    void setFrente(NodoCarta*);
    NodoCarta* getFinal(void) const; 
    void setFinal(NodoCarta*);
    int getLongitud(void) const;
    void setLongitud(int l);

    void insertarElem(Carta);
    bool eliminarElem();
    Carta pasarColaAPila();
    bool esVacia();


protected:
    NodoCarta* frente;
    NodoCarta* final;
    int longitud;
};

#endif

