#ifndef VALV_H
#define VALV_H

#include "Arduino.h"

class Valvula
{
public:
    Valvula();
    Valvula(int p);

    int get_pino();
    bool get_status();
    String get_estado();

    void ativar();
    void desativar();

private:
    int pino;
    bool status;
};

#endif
