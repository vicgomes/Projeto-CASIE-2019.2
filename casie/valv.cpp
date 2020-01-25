#include "valv.h"

const String ATIVADA    = "ATIVADA";
const String DESATIVADA = "DESATIVADA";

Valvula::Valvula(){}

Valvula::Valvula(int p)
{
    pino = p;
}

int Valvula::get_pino()
{
    return pino;
}

bool Valvula::get_status()
{
    return status;
}

String Valvula::get_estado()
{
    if(get_status() == true)
    {
        return ATIVADA;
    }
    else
    {
        return DESATIVADA;
    }    
}

void Valvula::ativar()
{
    digitalWrite(get_pino(), HIGH);
    status = true;
}

void Valvula::desativar()
{
    digitalWrite(get_pino(), LOW);
    status = false;
}
