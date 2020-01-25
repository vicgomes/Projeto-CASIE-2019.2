#include "higrometro.h"

Higro_object::Higro_object(){}

Higro_object::Higro_object(int p)
{
    pino = p;
}

int Higro_object::get_pino()
{
    return pino;
}

void Higro_object::ler()
{
    umidade = analogRead(get_pino());
}

float Higro_object::valor_umidade_solo()
{
    return umidade;
}
