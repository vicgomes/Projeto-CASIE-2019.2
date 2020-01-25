#include "valvula..h"

const string ATIVADA    = "ATIVADA";
const string DESATIVADA = "DESATIVADA";

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

string Valvula::get_estado()
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