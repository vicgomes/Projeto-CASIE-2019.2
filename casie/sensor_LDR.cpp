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

void LDR_object::ler()
{
    luminosidade = analogRead(get_pino());
}

int LDR_object::valor_LDR()
{    
    return luminosidade;
}

