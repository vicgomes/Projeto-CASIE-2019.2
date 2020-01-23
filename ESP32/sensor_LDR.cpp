#include "sensor_LDR.h"

LDR_object::LDR_object(){}

LDR_object::LDR_object(int p)
{
    pino = p;
}

int LDR_object::get_pino()
{
    return pino;
}

int LDR_object::valor_LDR()
{
    int luminosidade = analogRead(get_pino());
    return luminosidade;
}

