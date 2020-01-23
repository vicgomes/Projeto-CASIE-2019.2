#include "valvula..h"

const string LIGADO    = "LIGADO";
const string DESLIGADO = "DESLIGADO";

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
        return LIGADO;
    }
    else
    {
        return DESLIGADO;
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