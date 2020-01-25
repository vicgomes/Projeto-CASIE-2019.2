
#ifndef HIGROMETRO_H
#define HIGROMETRO_H

#include "Arduino.h"

class Higro_object
{
public:
    Higro_object();
    Higro_object(int p);

    int get_pino();
    void ler();
    float valor_umidade_solo();

private:
    int pino;
    float umidade;
};

#endif
