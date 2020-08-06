#ifndef CARTA_H
#define CARTA_H
#include <string>
using namespace std;

class Carta
{
public:
    Carta();
    Carta(int, string);

    int getNumero();
    void setNumero(int);
    string getSigno();
    void setSigno(string);

protected:
    int numero;
    string signo;
};

#endif



