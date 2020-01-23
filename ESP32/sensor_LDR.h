#ifndef SENSOR_LDR_H
#define SENSOR_LDR_H

#include <Arduino.h>

class LDR_object
{
public:
    LDR_object();
    LDR_object(int p);

    int get_pino();
    int valor_LDR();

private:
    int _pino;
};

#endif