#include "higrometro.h"

Higro_object::Higro_object(){}

Higro_object::Higro_object(int p)
{
    pino = p;
}

int Higro_object::get_ pino()
{
    return pino;
}

float Higro_object::umidade_solo()
{
    float umidade = analogRead(get_pino());
    return umidade;
}