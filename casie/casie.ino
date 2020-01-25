#include "interlocutor.h"
#include "higrometro.h"
#include "sensor_LDR.h"
#include "valv.h"

const char* WIFI  = "ESP32";
const char* CHAVE = "senhacriativa";

Interlocutor interlocutor(WIFI, CHAVE);
Higro_object sensor_umidade(34);
LDR_object sensorLDR(32);
Valvula solenoide(12);

#define LUM_MIN 15
#define UMIDADE_SOLO_MIN 400
#define UMIDADE_SOLO_MAX 679

void setup()
{
  Serial.begin(115200);

  interlocutor.inicializador_web();
  interlocutor.set_velocidades(500,500);
}

void loop()
{ 
  sensorLDR.ler();
  sensor_umidade.ler();
  interlocutor.vigia(sensorLDR, sensor_umidade, solenoide);
  
  switch(interlocutor.get_modo())
  {
    case 1:
      automatico();
      break;
    case 2:
      manual();
      break;
  }  
}

//////////////////////////////////////////////////////////////
//Funções

void automatico()
{
  
  if(sensorLDR.valor_LDR() < 15)
  {
    solenoide.desativar();    
  }
  
  else if(sensorLDR.valor_LDR() > 15)
  {
    
    if(sensor_umidade.valor_umidade_solo() < UMIDADE_SOLO_MIN)
    {
      solenoide.desativar();
    }
    
    else if(sensor_umidade.valor_umidade_solo() > UMIDADE_SOLO_MAX)
    {
      solenoide.desativar();
    }
    
    else if(sensor_umidade.valor_umidade_solo() > UMIDADE_SOLO_MIN and
            sensor_umidade.valor_umidade_solo() < UMIDADE_SOLO_MAX)
    {
      solenoide.ativar();
    }
    
  }
}



void manual()
{
  
}
